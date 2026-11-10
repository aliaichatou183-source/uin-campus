#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <format>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

enum class Mention
{
    Ajourne,
    Passable,
    AssezBien,
    Bien,
    TresBien
};

constexpr std::size_t nbMentions = 5;
constexpr double noteMin = 0.0;
constexpr double noteMax = 20.0;
constexpr double seuilValidation = 10.0;

Mention mentionPour(double note)
{
    if (note < seuilValidation) {
        return Mention::Ajourne;
    }
    if (note < 12.0) {
        return Mention::Passable;
    }
    if (note < 14.0) {
        return Mention::AssezBien;
    }
    if (note < 16.0) {
        return Mention::Bien;
    }
    return Mention::TresBien;
}

std::string_view libelle(Mention mention)
{
    using enum Mention;

    switch (mention) {
    case Ajourne:
        return "Ajourné";
    case Passable:
        return "Passable";
    case AssezBien:
        return "Assez bien";
    case Bien:
        return "Bien";
    case TresBien:
        return "Très bien";
    }
    return "Inconnue";
}

int lireEntier(std::string_view invite, int min, int max)
{
    while (true) {
        std::cout << invite;

        std::string ligne;
        if (!std::getline(std::cin, ligne)) {
            return min;
        }

        std::istringstream flux{ligne};
        int valeur{};
        char reste{};

        if (!(flux >> valeur) || (flux >> reste)) {
            std::cout << " Saisie invalide : entrez un nombre entier.\n";
        } else if (valeur < min || valeur > max) {
            std::cout << " La valeur doit être comprise entre "
                      << min << " et " << max << ".\n";
        } else {
            return valeur;
        }
    }
}

double lireNote(std::string_view invite)
{
    while (true) {
        std::cout << invite;

        std::string ligne;
        if (!std::getline(std::cin, ligne)) {
            return noteMin;
        }

        for (char& caractere : ligne) {
            if (caractere == ',') {
                caractere = '.';
            }
        }

        std::istringstream flux{ligne};
        double note{};
        char reste{};

        if (!(flux >> note) || (flux >> reste)) {
            std::cout << " Saisie invalide : entrez une note.\n";
        } else if (!std::isfinite(note) || note < noteMin || note > noteMax) {
            std::cout << " La note doit être comprise entre 0 et 20.\n";
        } else {
            return note;
        }
    }
}

int main()
{
    std::cout << "Nom de l'UE : ";

    std::string ue;
    if (!std::getline(std::cin, ue)) {
        return 0;
    }

    const int nb = lireEntier("Nombre d'étudiants (1 à 200) : ", 1, 200);

    std::vector<double> notes;
    notes.reserve(static_cast<std::size_t>(nb));

    for (int i{1}; i <= nb; ++i) {
        notes.push_back(
            lireNote(std::format("Note de l'étudiant {} : ", i))
        );
    }

    double minimum{noteMax};
    double maximum{noteMin};
    double somme{0.0};
    int admis{0};
    std::array<int, nbMentions> repartition{};

    for (double note : notes) {
        minimum = std::min(minimum, note);
        maximum = std::max(maximum, note);
        somme += note;

        if (note >= seuilValidation) {
            ++admis;
        }

        const auto indice = static_cast<std::size_t>(mentionPour(note));
        ++repartition[indice];
    }

    const double taille = static_cast<double>(notes.size());
    const double moyenne = somme / taille;

    double sommeEcarts{0.0};
    for (double note : notes) {
        const double ecart = note - moyenne;
        sommeEcarts += ecart * ecart;
    }

    const double ecartType = std::sqrt(sommeEcarts / taille);
    const double pourcentageAdmis = 100.0 * static_cast<double>(admis) / taille;

    std::println("\nStatistiques — {} ({} étudiants)", ue, nb);
    std::println("{:-<58}", "");
    std::println("{:<18}: {:6.2f}", "Note minimale", minimum);
    std::println("{:<18}: {:6.2f}", "Note maximale", maximum);
    std::println("{:<18}: {:6.2f}", "Moyenne", moyenne);
    std::println("{:<18}: {:6.2f}", "Écart-type", ecartType);
    std::println("{:<18}: {:6} ({:.1f} %)", "Admis", admis, pourcentageAdmis);

    std::println("\nRépartition par mention");
    for (std::size_t i{0}; i < nbMentions; ++i) {
        const auto mention = static_cast<Mention>(i);
        const auto nombre = static_cast<std::size_t>(repartition[i]);

        std::println(
            "{:<12} {} ({})",
            libelle(mention),
            std::string(nombre, '*'),
            repartition[i]
        );
    }

    return 0;
}
