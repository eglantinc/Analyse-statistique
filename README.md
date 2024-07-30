
# Tri Unique

## Description

**Tri Unique** est un logiciel qui trie une liste de mots provenant d'un fichier donné, les affiche en ordre alphabétique sans doublons, et génère des statistiques optionnelles sur ces mots. Ce logiciel a été réalisé dans le cadre du cours ``INF3135``  sous la supervision de Serge Dogny, chargé de cours à Université du Québec à Montréal.

## Fonctionnalités

1. **Tri et Affichage**: Trie les mots provenant d'un fichier et les affiche sans doublons.
2. **Statistiques**: Lorsque l'option `-S` est spécifiée, génère des statistiques sur les données du fichier d'entrée et les enregistre dans un fichier de sortie.

## Exécution du Logiciel

### Sans Statistiques
```
./tri liste.txt
```
Affiche les mots triés et sans doublons. Où `liste.txt` représente le fichier d'entrée qui contient une liste de mots.
### Avec Statistiques
```bash
./tri liste.txt -S stats.txt
```
Affiche les mots triés et sans doublons, et génère un fichier `stats.txt` contenant les statistiques. 

## Statistiques Produites

Lorsque l'option `-S` est utilisée, les statistiques suivantes sont générées :
- Nombre de mots sans doublons.
- Nombre de mots avec doublons.
- Nombre de lignes dans le fichier d'entrée (sans considérer les lignes vides).
- Nombre de lettres distinctes dans la liste de mots (sans considérer les doublons).
- La lettre la plus fréquente (sans considérer les doublons).

## Exigences de Conception

- La structure de données utilisée pour accumuler les mots et les trier est une liste chaînée allouée dynamiquement.
- Le logiciel est découpé en modules distincts :
  - `main` : Point d'entrée du programme.
  - `listechainee` : Gestion de la liste chaînée.
  - `statistiques` : Gestion des statistiques.
  - `tests` : Tests unitaires et de validation.
  - `helper`: Composée des fonctions extraites du main

## Compilation et Tests

Pour compiler le programme, utilisez `make` :
```
make all
```

Pour exécuter les tests de manière à générer l'exécutable `./test` , utilisez :
```
make test
```

Pour avoir la couverture des tests, utilisez :
```
make coverage
```

Pour avoir le fichier `README.md` sous format html, utilisez :
```
make html
```

Pour nettoyer le répertoire, supprimer les fichiers objets (`.o`), les fichiers de données de couverture (`.gcda`, `.gcno`, `.gcov`), et d'autres fichiers générés lors de la compilation ou des tests.

## Utilisation

### Exemple d'Exécution Sans Statistiques
```
$ ./tri liste.txt
AMERTUME
BAR
CASSEROLE
PATRON
UNIVERS
```

### Exemple d'Exécution Avec Statistiques
```
$ ./tri liste.txt -S stats.txt
AMERTUME
BAR
CASSEROLE
PATRON
UNIVERS
```

Le fichier `stats.txt` contiendra les statistiques spécifiées.

En cas d'erreur, voici le comportement au terminal :

1. Nombre erroné d'argument en ligne de commande
```
$ ./tri
Ce programme prends soit 2 arguments, soit 4 arguments.
NAME
tri - Trie une liste de mots provenant d’un fichier d’entrée.
Une fois les mots triés, le programme affichera la liste ordonnée
sans doublons sur stdout.

SYNOPSIS
./tri entree.txt [-S sortie.txt]
DESCRIPTION
entree.txt
Fichier contenant la liste des mots à trier.
-S sortie.txt
(Optionnel) Génère des statistiques et les enregistre
dans le fichier de sortie spécifié.
```

```
$ ./tri test.txt -S
Ce programme prends soit 2 arguments, soit 4 arguments.
NAME
tri - Trie une liste de mots provenant d’un fichier d’entrée.
Une fois les mots triés, le programme affichera la liste ordonnée
sans doublons sur stdout.

SYNOPSIS
./tri entree.txt [-S sortie.txt]
DESCRIPTION
entree.txt
Fichier contenant la liste des mots à trier.
-S sortie.txt
(Optionnel) Génère des statistiques et les enregistre
dans le fichier de sortie spécifié.
```

2. Fichier d'entrée non existant
```
$ ./tri liste.txt
Erreur lors de l'ouverture du fichier.
: No such file or directory
Erreur: No such file or directory
```

## Tests

Voici le résultat lorsqu'on lance l'exécutable `./test` :
```  
CUnit - A unit testing framework for C - Version 2.1-3
http://cunit.sourceforge.net/

Suite: LinkedList Suite
Test: test of initialize_list ...passed
Test: test of insert_into_empty_list ...passed
Test: test of create_node ...passed
Test: test of insert_in_order ...passed
Test: test of delete_duplicate ...passed
Test: test of free_word_list ...passed
Test: test of insert_word_from_file ...passed

Suite: Statistics Suite
Test: test of distinct_letter_count ...passed
Test: test of find_most_repeated_letter ...passed
Test: test of is_empty_line ...passed
Test: test of count_lines ...passed

Run Summary:  Type  Total  Ran Passed Failed Inactive
suites  2  2  n/a  0  0
tests 11 11 11  0  0
asserts 40 40 40  0  n/a
Elapsed time =  0.000 seconds
```

De même, voici le résultat lorsqu'on lance `make coverage` :

```./test
CUnit - A unit testing framework for C - Version 2.1-3
http://cunit.sourceforge.net/

Suite: LinkedList Suite
Test: test of initialize_list ...passed
Test: test of insert_into_empty_list ...passed
Test: test of create_node ...passed
Test: test of insert_in_order ...passed
Test: test of delete_duplicate ...passed
Test: test of free_word_list ...passed
Test: test of insert_word_from_file ...passed

Suite: Statistics Suite
Test: test of distinct_letter_count ...passed
Test: test of find_most_repeated_letter ...passed
Test: test of is_empty_line ...passed
Test: test of count_lines ...passed

Run Summary:  Type  Total  Ran Passed Failed Inactive
suites  2  2  n/a  0  0
tests 11 11 11  0  0
asserts 40 40 40  0  n/a
Elapsed time =  0.000 seconds

gcov listechainee.c statistiques.c helper.c
File 'listechainee.c'
Lines executed:92.47% of 93
Creating 'listechainee.c.gcov'

File 'statistiques.c'
Lines executed:100.00% of 49
Creating 'statistiques.c.gcov'

File 'helper.c'
Lines executed:80.56% of 36
Creating 'helper.c.gcov'
```
## Auteure

Églantine Clervil - CLEE89530109

