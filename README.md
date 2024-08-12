
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

Pour nettoyer le répertoire, supprimer les fichiers objets (`.o`), les fichiers de données de couverture (`.gcda`, `.gcno`, `.gcov`), et d'autres fichiers générés lors de la compilation ou des tests, utilisez : 
```
make clean
```

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

```
$ cat stats.txt
Nombre de mots avec dupplication: 120
Nombre de mots sans dupplication: 5
Nombre de lignes dans le fichier: 24
Nombre de lettres distinctes dans la liste: 15
La lettre la plus fréquente: E
```

Dans le cas où le fichier d'entrée est vide, donc la liste est vide, voici le comportement :
```
$ ./tri empty_file.txt -S stats.txt

La liste de mots est vide
```

```
$ cat stats.txt

Nombre de mots avec dupplication: 0
Nombre de mots sans dupplication: 0
Nombre de lignes dans le fichier: 0
Nombre de lettres distinctes dans la liste: 0
La lettre la plus fréquente: 
```
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
[...]
Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      3      3    n/a      0        0
               tests     13     13     13      0        0
             asserts     48     48     48      0      n/a

Elapsed time =    0.000 seconds
```
## Auteure

Églantine Clervil - CLEE89530109


