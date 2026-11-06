# UIN-Campus

Système de gestion académique de l'Université Islamique au Niger.

## Présentation

UIN-Campus est un projet C++ développé dans le cadre du cours de programmation orientée objet.

Il a pour objectif de mettre en place un système de gestion académique permettant notamment de calculer la moyenne d'un étudiant, de déterminer sa mention et de vérifier la validation de ses résultats.

Le projet utilise CMake pour la configuration et Ninja pour la construction.

## Fonctionnalités actuelles

- Saisie du nom d'un étudiant.
- Saisie du nombre de notes (entre 1 et 30).
- Saisie sécurisée des notes comprises entre 0 et 20.
- Acceptation de la virgule ou du point comme séparateur décimal.
- Vérification des saisies incorrectes.
- Calcul automatique de la moyenne.
- Attribution automatique d'une mention.
- Détermination de la validation ou non de la moyenne.

### Barème des mentions

| Moyenne | Mention |
|---|---|
| Inférieure à 10 | Ajourné |
| De 10 à moins de 12 | Passable |
| De 12 à moins de 14 | Assez bien |
| De 14 à moins de 16 | Bien |
| De 16 à 20 | Très bien |

Le seuil de validation est fixé à 10/20.

## Environnement de développement

- Système d'exploitation : Parrot OS
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

## Configuration et compilation

Depuis la racine du projet :

### Mode Debug

```bash
cmake --preset debug
cmake --build --preset debug
./build/debug/uin-campus
```

Le mode Debug active les outils de détection de certaines erreurs mémoire et comportements indéfinis grâce à AddressSanitizer et UndefinedBehaviorSanitizer.

### Mode Release

```bash
cmake --preset release
cmake --build --preset release
./build/release/uin-campus
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
│       └── saisie.hpp
├── src/
│   ├── version.cpp
│   ├── regles.cpp
│   └── saisie.cpp
├── tests/
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
- `main.cpp` : programme principal, calcul de la moyenne et affichage des résultats.

## Dépôt GitHub

[https://github.com/aliaichatou183-source/uin-campus](https://github.com/aliaichatou183-source/uin-campus)