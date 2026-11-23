# UIN-Campus

**Système de gestion académique de l'Université Islamique au Niger.**

## Présentation

UIN-Campus est un projet développé en C++ dans le cadre du cours de programmation orientée objet.

Il a pour objectif de mettre progressivement en place un système de gestion académique permettant notamment de saisir les notes des étudiants, calculer leurs moyennes, déterminer leurs mentions et analyser leurs résultats.

Le projet utilise CMake pour la configuration et Ninja pour la construction.

## Fonctionnalités actuelles

- Saisie du nom d'un étudiant.
- Saisie du nombre d'unités d'enseignement (entre 1 et 30).
- Saisie des notes comprises entre 0 et 20.
- Acceptation de la virgule ou du point comme séparateur décimal.
- Vérification des saisies incorrectes.
- Saisie des coefficients des unités d'enseignement.
- Calcul de la moyenne arithmétique.
- Calcul de la moyenne pondérée par les coefficients.
- Calcul de la note minimale et maximale.
- Calcul de l'écart-type des notes.
- Comptage des unités d'enseignement validées.
- Attribution automatique d'une mention.
- Affichage d'un relevé récapitulatif des résultats.
- Affichage de la version du programme avec l'option `--version`.

### Barème des mentions

| Moyenne | Mention |
|---|---|
| Inférieure à 10 | Ajourné |
| De 10 à moins de 12 | Passable |
| De 12 à moins de 14 | Assez bien |
| De 14 à moins de 16 | Bien |
| De 16 à 20 | Très bien |

Le seuil de validation est fixé à **10/20**.

## Environnement de développement

- Système d'exploitation : Parrot Security OS
- Standard C++ : C++23

| Outil | Version |
|---|---|
| g++ | 14.2.0-19 |
| clang++ | 19.1.7 |
| CMake | 3.31.6 |
| Ninja | 1.12.1 |
| GDB | 16.3-1 |
| Git | 2.47.3 |

## Prérequis

- Un compilateur C++ compatible avec les fonctionnalités C++23 utilisées.
- CMake 3.25 ou supérieur.
- Ninja.
- Git.

## Récupération du projet

```bash
git clone https://github.com/aliaichatou183-source/uin-campus.git
cd uin-campus
```

## Configuration et compilation

Depuis la racine du projet :

### Mode Debug

```bash
cmake --preset debug
cmake --build --preset debug
./build/debug/uin-campus
```

Le mode Debug active AddressSanitizer et UndefinedBehaviorSanitizer afin de détecter certaines erreurs mémoire et certains comportements indéfinis.

### Mode Release

```bash
cmake --preset release
cmake --build --preset release
./build/release/uin-campus
```

### Afficher la version

```bash
./build/debug/uin-campus --version
```

## Structure du projet

```text
uin-campus/
├── app/
│   └── main.cpp
├── include/
│   └── uincampus/
│       ├── version.hpp
│       ├── regles.hpp
│       ├── saisie.hpp
│       └── calculs.hpp
├── src/
│   ├── version.cpp
│   ├── regles.cpp
│   ├── saisie.cpp
│   └── calculs.cpp
├── tests/
├── TP3/
│   ├── main.cpp
│   └── README.md
├── CMakeLists.txt
├── CMakePresets.json
├── compile_commands.json
├── .clang-format
├── .clang-tidy
├── .gitignore
└── README.md
```

## Organisation du code

- `version.hpp` et `version.cpp` : gestion de la version du projet.
- `regles.hpp` et `regles.cpp` : constantes académiques, validation des notes et attribution des mentions.
- `saisie.hpp` et `saisie.cpp` : gestion des saisies utilisateur et vérification des données.
- `calculs.hpp` et `calculs.cpp` : fonctions de calcul des sommes, moyennes, statistiques, notes validées et arrondis.
- `main.cpp` : programme principal, saisie des informations et affichage des résultats.

## TP3 — Statistiques sur une série de notes

Le dossier `TP3/` contient un travail pratique indépendant du projet principal UIN-Campus.

Il propose notamment :

- Le calcul de la somme et de la moyenne des notes.
- La recherche de la note minimale et maximale.
- Le calcul de l'écart-type.
- Le comptage des notes validées.
- Le calcul du pourcentage de réussite.
- La répartition des étudiants selon les mentions.

### Compilation du TP3

Depuis la racine du dépôt :

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion TP3/main.cpp -o build/tp3-statistiques
```

### Exécution

```bash
./build/tp3-statistiques
```

Le TP3 reste indépendant de la compilation CMake du projet principal.

## Dépôt GitHub

Le code source du projet est disponible sur GitHub :

https://github.com/aliaichatou183-source/uin-campus

---

*Projet réalisé dans le cadre de la formation en informatique à l'Université Islamique au Niger.*