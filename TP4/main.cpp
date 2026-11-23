#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace carnet {

enum class Ordre { Croissant, Decroissant };

struct Statistiques {
    double minimum{};
    double maximum{};
    double moyenne{};
    int nbValidees{};
};

namespace {
std::string lireLigne(std::string_view invite)
{
    std::cout << invite;
    std::string ligne;
    std::getline(std::cin, ligne);
    return ligne;
}

bool convertirEntier(const std::string& texte, int& valeur)
{
    std::istringstream flux{texte};
    char reste{};
    return static_cast<bool>(flux >> valeur) && !(flux >> reste);
}

bool convertirReel(std::string texte, double& valeur)
{
    for (char& c : texte) {
        if (c == ',') c = '.';
    }
    std::istringstream flux{texte};
    char reste{};
    return static_cast<bool>(flux >> valeur) && !(flux >> reste);
}
} // namespace

[[nodiscard]] int lireEntier(std::string_view invite, int minimum, int maximum)
{
    while (std::cin) {
        int valeur{};
        if (!convertirEntier(lireLigne(invite), valeur)) {
            std::cout << "Saisie invalide : entrez un nombre entier.\n";
        } else if (valeur < minimum || valeur > maximum) {
            std::cout << "La valeur doit être comprise entre "
                      << minimum << " et " << maximum << ".\n";
        } else {
            return valeur;
        }
    }
    return minimum;
}

[[nodiscard]] double lireNote(std::string_view invite)
{
    while (std::cin) {
        double note{};
        if (!convertirReel(lireLigne(invite), note)) {
            std::cout << "Saisie invalide : entrez un nombre (ex. 12.5 ou 12,5).\n";
        } else if (note < 0.0 || note > 20.0) {
            std::cout << "La note doit être comprise entre 0 et 20.\n";
        } else {
            return note;
        }
    }
    return 0.0;
}

// ---------- Calculs : aucune entrée-sortie ----------

/// @pre notes n'est pas vide.
[[nodiscard]] Statistiques calculerStatistiques(const std::vector<double>& notes)
{
    const auto [mini, maxi] = std::ranges::minmax(notes);
    double somme{0.0};
    int validees{0};

    for (double note : notes) {
        somme += note;
        if (note >= 10.0) ++validees;
    }

    return {mini, maxi, somme / static_cast<double>(notes.size()), validees};
}

void appliquerBonus(std::vector<double>& notes, double bonus)
{
    std::ranges::for_each(notes, [bonus](double& note) {
        note = std::clamp(note + bonus, 0.0, 20.0);
    });
}

void trier(std::vector<double>& notes, Ordre ordre)
{
    if (ordre == Ordre::Croissant) {
        std::ranges::sort(notes);
    } else {
        std::ranges::sort(notes, [](double a, double b) { return a > b; });
    }
}

// ---------- Interface utilisateur ----------

void afficherNotes(const std::vector<double>& notes)
{
    if (notes.empty()) {
        std::cout << "Aucune note.\n";
        return;
    }
    for (std::size_t i{0}; i < notes.size(); ++i) {
        std::cout << i + 1 << ". " << notes[i] << '\n';
    }
}

void ajouter(std::vector<double>& notes)
{
    notes.push_back(lireNote("Note à ajouter : "));
    std::cout << "Note ajoutée.\n";
}

void modifier(std::vector<double>& notes)
{
    if (notes.empty()) {
        std::cout << "Aucune note à modifier.\n";
        return;
    }
    afficherNotes(notes);
    const int rang = lireEntier("Numéro de la note : ", 1, static_cast<int>(notes.size()));
    notes[static_cast<std::size_t>(rang - 1)] = lireNote("Nouvelle valeur : ");
    std::cout << "Note modifiée.\n";
}

void supprimer(std::vector<double>& notes)
{
    if (notes.empty()) {
        std::cout << "Aucune note à supprimer.\n";
        return;
    }
    afficherNotes(notes);
    const int rang = lireEntier("Numéro de la note : ", 1, static_cast<int>(notes.size()));
    notes.erase(notes.begin() + (rang - 1));
    std::cout << "Note supprimée.\n";
}

void afficherStatistiques(const std::vector<double>& notes)
{
    if (notes.empty()) {
        std::cout << "Aucune note.\n";
        return;
    }
    const auto [mini, maxi, moyenne, validees] = calculerStatistiques(notes);
    std::cout << "Min : " << mini << " | Max : " << maxi
              << " | Moyenne : " << moyenne
              << " | Validées : " << validees << '/' << notes.size() << '\n';
}

[[nodiscard]] int afficherMenu()
{
    std::cout << "\n=== Carnet de notes ===\n"
              << "1. Ajouter une note\n"
              << "2. Afficher les notes\n"
              << "3. Modifier une note\n"
              << "4. Supprimer une note\n"
              << "5. Trier les notes (croissant / décroissant)\n"
              << "6. Statistiques\n"
              << "7. Appliquer un bonus\n"
              << "0. Quitter\n";
    return lireEntier("Votre choix : ", 0, 7);
}

} // namespace carnet

int main()
{
    std::vector<double> notes;
    int choix{};

    do {
        choix = carnet::afficherMenu();
        switch (choix) {
        case 1: carnet::ajouter(notes); break;
        case 2: carnet::afficherNotes(notes); break;
        case 3: carnet::modifier(notes); break;
        case 4: carnet::supprimer(notes); break;
        case 5: {
            const int sens = carnet::lireEntier("1. Croissant  2. Décroissant : ", 1, 2);
            carnet::trier(notes, sens == 1 ? carnet::Ordre::Croissant
                                           : carnet::Ordre::Decroissant);
            std::cout << "Notes triées.\n";
            break;
        }
        case 6: carnet::afficherStatistiques(notes); break;
        case 7: {
            const double bonus = carnet::lireNote("Bonus à appliquer : ");
            carnet::appliquerBonus(notes, bonus);
            std::cout << "Bonus appliqué.\n";
            break;
        }
        default: break;
        }
    } while (choix != 0 && std::cin);

    std::cout << "Fin du programme.\n";
    return 0;
}
