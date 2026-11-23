
#include "uincampus/calculs.hpp"
#include "uincampus/regles.hpp"
#include "uincampus/version.hpp"

#include <cstdlib>
#include <iostream>
#include <print>
#include <span>
#include <string_view>
#include <vector>

namespace {

enum class Suite { Continuer, Terminer, Erreur };

void afficherAide() {
    std::println("UIN-Campus — Aide");
    std::println("");
    std::println("Utilisation : uin-campus [option]");
    std::println("");
    std::println("Options disponibles :");
    std::println("  --version   Afficher la version");
    std::println("  --aide      Afficher cette aide");
}

Suite traiterOptions(std::span<char *> arguments) {
    if (arguments.size() <= 1) {
        return Suite::Continuer;
    }

    for (char *argument : arguments.subspan(1)) {
        const std::string_view option{argument};

        if (option == "--version") {
            std::println("UIN-Campus — Version {}", uin::version());
            return Suite::Terminer;
        }

        if (option == "--aide") {
            afficherAide();
            return Suite::Terminer;
        }

        std::println(stderr, "Option inconnue : {}", option);
        afficherAide();
        return Suite::Erreur;
    }

    return Suite::Continuer;
}

} // namespace

int main(int argc, char *argv[]) {
    const std::span arguments{argv, static_cast<std::size_t>(argc)};

    const Suite resultat = traiterOptions(arguments);

    if (resultat == Suite::Terminer) {
        return EXIT_SUCCESS;
    }

    if (resultat == Suite::Erreur) {
        return EXIT_FAILURE;
    }

    std::println("UIN-Campus — Système de gestion académique");
    std::println("Version {}", uin::version());

    std::vector<double> notes;
    notes.reserve(2);
    notes.push_back(12.0);
    notes.push_back(15.0);

    std::vector<double> coefficients;
    coefficients.reserve(2);
    coefficients.push_back(2.0);
    coefficients.push_back(1.0);

    std::println("Notes :");

    for (std::size_t i = 0; i < notes.size(); ++i) {
        std::println("  Note {} : {:.2f} (coefficient {:.1f})", i + 1, notes[i], coefficients[i]);
    }

    const double moyenneSimple = uin::moyenne(notes);
    const double moyennePonderee = uin::moyenne(notes, coefficients);

    const uin::Statistiques statistiques = uin::calculerStatistiques(notes);

    const int validees = uin::compterValidees(notes);

    const uin::Mention mention = uin::mentionPour(moyennePonderee);

    std::println("");
    std::println("Résultats :");
    std::println("  Moyenne simple     : {:.2f}", moyenneSimple);
    std::println("  Moyenne pondérée   : {:.2f}", moyennePonderee);
    std::println("  Note minimale      : {:.2f}", statistiques.minimum);
    std::println("  Note maximale      : {:.2f}", statistiques.maximum);
    std::println("  Écart-type         : {:.2f}", statistiques.ecartType);
    std::println("  Notes validées     : {}/{}", validees, notes.size());
    std::println("  Mention            : {}", uin::libelle(mention));

    return EXIT_SUCCESS;
}
