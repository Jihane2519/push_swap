*This project has been created as part of the 1337_42 curriculum by jbounou.*

# Push_swap

## Description

**push_swap** est un projet algorithmique dont l’objectif est de trier une pile d’entiers en utilisant un ensemble limité d’instructions, tout en produisant le **minimum possible d’opérations**.

Le projet se compose de deux parties :

- **push_swap (mandatory)** : génère une suite d’instructions permettant de trier la pile.
- **checker_bonus (bonus)** : vérifie si une suite d’instructions donnée trie correctement la pile.

Les données sont stockées dans deux piles :
- **Pile A** : contient les nombres à trier
- **Pile B** : pile auxiliaire

---

## Objectifs

- Comprendre et manipuler des structures de données (listes chaînées)
- Implémenter des algorithmes de tri optimisés
- Gérer correctement la mémoire (malloc/free)
- Respecter des contraintes strictes (norme, performances, erreurs)

---

## Instructions autorisées

| Instruction | Description |
|-------------|------------|
| `sa` | swap des deux premiers éléments de A |
| `sb` | swap des deux premiers éléments de B |
| `ss` | `sa` et `sb` |
| `pa` | push le premier élément de B vers A |
| `pb` | push le premier élément de A vers B |
| `ra` | rotation vers le haut de A |
| `rb` | rotation vers le haut de B |
| `rr` | `ra` et `rb` |
| `rra` | rotation inverse de A |
| `rrb` | rotation inverse de B |
| `rrr` | `rra` et `rrb` |

---

## Compilation

### Compiler la partie mandatory

```bash
make

Génère l’exécutable :

./push_swap

Compiler la partie bonus (checker)
make bonus


Génère l’exécutable :

./checker_bonus

Nettoyage
make clean
make fclean
make re

Utilisation
push_swap
./push_swap 3 2 1


Sortie exemple :

sa
rra

checker_bonus
./push_swap 3 2 1 | ./checker_bonus 3 2 1


Résultat :

OK


Si les instructions sont incorrectes :

KO


Si une instruction est invalide :

Error

Gestion des erreurs

Le programme affiche Error dans les cas suivants :

Argument non numérique

Dépassement de INT_MIN / INT_MAX

Doublons

Instruction invalide (bonus)

Algorithme utilisé

Tri spécifique pour :

2 nombres

3 nombres

5 nombres

Algorithme par chunks pour les grandes piles :

Division de la pile en blocs

Push intelligent vers B

Remontée optimisée vers A

Partie Bonus – Checker

Le checker_bonus :

Lit les instructions depuis l’entrée standard (stdin)

Utilise get_next_line

Applique chaque instruction sur les piles

Vérifie à la fin :

pile A triée

pile B vide

Structure du projet
push_swap/
├── algo/
├── parsing/
├── operation/
├── bonus/
│   ├── checker.c
│   └── checker_apply.c
├── gnl/
│   ├── get_next_line.c
│   └── get_next_line_utils.c
├── push_swap.h
├── Makefile
└── README.md

Ressources

Sujet officiel push_swap (1337 / 42)

Documentation C (man pages)

Articles sur les algorithmes de tri

Stack overflow & cppreference

Utilisation de l’IA

L’IA a été utilisée pour :

Comprendre certains concepts algorithmiques

Déboguer des erreurs de compilation et de logique

jbounou

1337 /42 Network


