# TP5 — Réinventer std::vector : comprendre la gestion dynamique de la mémoire

## 1. Objectif du TP

Ce TP a pour objectif de comprendre le fonctionnement interne d'un tableau dynamique en C++ et de découvrir les mécanismes de gestion de la mémoire.

Il permet notamment de comprendre :
- L'allocation dynamique de mémoire avec `new[]`.
- La libération de mémoire avec `delete[]`.
- La gestion de la taille et de la capacité d'un tableau.
- Le redimensionnement automatique d'un tableau dynamique.
- Les erreurs liées à la gestion manuelle de la mémoire.
- L'intérêt de `std::vector` pour simplifier et sécuriser la gestion des tableaux.

## 2. Partie A — Création d'un tableau dynamique

La première partie consiste à créer manuellement une structure de tableau dynamique.

Les principales opérations étudiées sont :
- L'allocation d'un tableau avec `new[]`.
- L'ajout d'éléments.
- Le doublement de la capacité lorsque le tableau est plein.
- La copie des éléments vers un nouveau tableau.
- La libération de la mémoire avec `delete[]`.

Cette partie permet également d'étudier les erreurs de gestion mémoire à l'aide des sanitizers.

## 3. Partie B — Problème de copie superficielle

Cette partie permet de comprendre les risques liés à la copie d'un objet qui possède directement un pointeur vers une zone mémoire dynamique.

Une copie superficielle peut entraîner plusieurs problèmes :
- Deux objets qui pointent vers la même zone mémoire.
- Une libération multiple de la même mémoire.
- Des erreurs de gestion de la mémoire.

## 4. Partie C — Utilisation de std::vector

La dernière partie consiste à remplacer la gestion manuelle de la mémoire par `std::vector`.

Les fonctionnalités utilisées sont :
- `push_back()` : ajouter un élément.
- `size()` : connaître le nombre d'éléments.
- `capacity()` : connaître la capacité du tableau.
- `at()` : accéder à un élément avec vérification des limites.
- La copie d'un vector : obtenir une copie indépendante des éléments.

## 5. Compilation et exécution

Depuis la racine du projet UIN-Campus :

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -g -O1 \
-fsanitize=address,undefined -fno-omit-frame-pointer \
TP5/main.cpp -o build/tp5
```

Exécution :

```bash
./build/tp5
```

## 6. Technologies utilisées

- Langage : C++23
- Compilateur : G++
- Système : Parrot OS
- Outils de vérification : AddressSanitizer et UndefinedBehaviorSanitizer

## 7. Conclusion

Ce TP montre pourquoi `std::vector` est préférable à la gestion manuelle d'un tableau dynamique dans la plupart des programmes C++.

Il permet de comprendre les mécanismes de gestion mémoire tout en apprenant à utiliser une solution standard plus simple, plus sûre et plus facile à maintenir.
