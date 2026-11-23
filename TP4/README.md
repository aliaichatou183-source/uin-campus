# TP 4 — Carnet de notes en mode menu

## Objectif

Créer un programme autonome en C++23 qui gère le carnet de notes d'une UE avec un menu interactif.

Ce TP est indépendant du projet principal UIN-Campus : il n'est pas intégré à sa compilation CMake.

## Fonctionnalités

- Ajouter, afficher, modifier et supprimer des notes.
- Trier les notes par ordre croissant ou décroissant.
- Afficher le minimum, le maximum, la moyenne et le nombre de notes validées.
- Appliquer un bonus en maintenant chaque note dans l'intervalle de 0 à 20.
- Quitter le programme.

Une note est considérée comme validée à partir de 10/20.

## Notions C++ travaillées

- Fonctions et espace de noms `carnet`.
- Passage par référence constante et par référence modifiable.
- Structure `Statistiques` et liaison structurée.
- Lambdas pour le tri décroissant et l'application du bonus.
- `std::ranges::sort`, `std::ranges::for_each`, `std::ranges::minmax`.
- `std::clamp`.
- Attribut `[[nodiscard]]`.

## Compilation

Depuis la racine du dépôt `uin-campus` :

```bash
mkdir -p build
g++ -std=c++23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion TP4/main.cpp -o build/tp4-carnet
```

## Exécution

```bash
./build/tp4-carnet
```

## Organisation

```text
TP4/
├── main.cpp
└── README.md
```

Tout le code, sauf `main`, est placé dans l'espace de noms `carnet`.

## Remarque

La saisie du bonus réutilise `lireNote`, comme dans la correction fournie : le bonus saisi est donc compris entre 0 et 20. La fonction `appliquerBonus` borne ensuite chaque résultat entre 0 et 20.
