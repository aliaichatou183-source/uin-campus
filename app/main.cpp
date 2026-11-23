
#include "uincampus/calculs.hpp"
#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"

#include <cstdlib>
#include <format>
#include <print>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace {

enum class Suite { Continuer, Terminer, Erreur };

void afficherLigne(std::string_view libelle, std::string_view valeur) {
    std::println("{:<24}{:>20}", libelle, valeur);
}

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
            std::println("uin-campus {}", uin::version());
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

    std::println("UIN-Campus {} — Relevé d'un étudiant\n", uin::version());

    const std::string nom = uin::lireTexte("Nom de l'étudiant : ");
    const int nbUE = uin::lireEntier("Nombre d'UE (1 à 30) : ", 1, 30);

    std::vector<double> notes;
    std::vector<double> coefficients;

    notes.reserve(static_cast<std::size_t>(nbUE));
    coefficients.reserve(static_cast<std::size_t>(nbUE));

    for (int i{1}; i <= nbUE; ++i) {
        notes.push_back(uin::lireNote(std::format(" Note de l'UE {} : ", i)));

        coefficients.push_back(static_cast<double>(
            uin::lireEntier(std::format("Coefficient de l'UE {} : ", i), 1, 10)));
    }

    const double moyenneGenerale = uin::arrondir(uin::moyenne(notes, coefficients));

    const auto [mini, maxi, moyenneSimple, ecartType] = uin::calculerStatistiques(notes);

    const int validees = uin::compterValidees(notes);

    std::println("\n{:-<44}", "");
    afficherLigne("Étudiant", nom);
    afficherLigne("Moyenne pondérée", std::format("{:.2f}", moyenneGenerale));
    afficherLigne("Moyenne simple", std::format("{:.2f}", moyenneSimple));
    afficherLigne("Note min / max", std::format("{:.2f} / {:.2f}", mini, maxi));
    afficherLigne("Écart-type", std::format("{:.2f}", ecartType));
    afficherLigne("UE validées", std::format("{} / {}", validees, nbUE));
    afficherLigne("Mention", uin::libelle(uin::mentionPour(moyenneGenerale)));
    std::println("{:-<44}", "");

    return EXIT_SUCCESS;
}
