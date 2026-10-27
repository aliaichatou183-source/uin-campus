# UIN-Campus

Système de gestion académique de l'Université Islamique au Niger.

## Présentation

UIN-Campus est un projet C++ développé dans le cadre du cours de programmation orientée objet.

Le projet utilise CMake pour la configuration et Ninja pour la construction.

## Environnement de développement

- Système d'exploitation : Parrot OS
- Standard C++ : C++23

| Outil | Version |
|---|---|
| g++ | 14.2.0-19|
| clang++ | 19.1.7|
| CMake | 3.31.6 |
| Ninja | 1.12.1|
| GDB | 16.3-1|
| Git | 2.47.3|

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
│       └── version.hpp
├── src/
│   └── version.cpp
├── tests/
├── CMakeLists.txt
├── CMakePresets.json
├── .clang-format
├── .clang-tidy
├── .gitignore
└── README.md
```

## Dépôt GitHub

https://github.com/aliaichatou183-source/uin-campus
