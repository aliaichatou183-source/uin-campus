#pragma once

#include "uincampus/regles.hpp"

#include <vector>

namespace uin {

/// Indicateurs statistiques d'une série de notes.
struct Statistiques {
    double minimum{};
    double maximum{};
    double moyenne{};
    double ecartType{};
};

/// Somme des valeurs.
[[nodiscard]] double somme(const std::vector<double> &valeurs);

/// Moyenne arithmétique. Précondition : notes n'est pas vide.
[[nodiscard]] double moyenne(const std::vector<double> &notes);

/// Moyenne pondérée. Préconditions : notes non vide, mêmes tailles,
/// somme des coefficients strictement positive.
[[nodiscard]] double moyenne(const std::vector<double> &notes,
                             const std::vector<double> &coefficients);

/// Minimum, maximum, moyenne et écart-type. Précondition : notes non vide.
[[nodiscard]] Statistiques calculerStatistiques(const std::vector<double> &notes);

/// Nombre de notes supérieures ou égales au seuil.
[[nodiscard]] int compterValidees(const std::vector<double> &notes, double seuil = seuilValidation);

/// Arrondi au nombre de décimales demandé.
[[nodiscard]] double arrondir(double valeur, int decimales = 2);

} // namespace uin
