# TP 3 — Statistiques d'une série de notes

Ce programme est un exercice autonome du chapitre 3. Il est indépendant du projet fil rouge **UIN-Campus**.

## Fonctionnalités

- Saisie du nom de l'UE.
- Saisie du nombre d'étudiants (de 1 à 200).
- Saisie des notes dans l'intervalle [0 ; 20], avec virgule ou point décimal.
- Calcul du minimum, du maximum, de la moyenne et de l'écart-type.
- Calcul du nombre et du pourcentage d'étudiants admis (note supérieure ou égale à 10).
- Répartition des étudiants par mention sous forme d'histogramme horizontal.

## Compilation

Depuis la racine du dépôt `uin-campus` :

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion \
    TP3/main.cpp -o build/tp3-statistiques
```

Le dossier `build/` doit exister. Il est normalement créé par la configuration CMake du projet principal.

## Exécution

```bash
./build/tp3-statistiques
```

Le TP3 se compile directement et séparément. Il n'est pas ajouté à la cible CMake de UIN-Campus.
