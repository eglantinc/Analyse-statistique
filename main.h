#ifndef MAIN_H
#define MAIN_H

/*
 * Module pour: main.c
 *
 * Description: Definie un module pour le main
 * d'un programme de tri et de statistiques.
 *
 *
 * Auteure: Églantine Clervil
 * Date: 11 aout 2024
 */


#define MAX_CHAR 80

#define USAGE "NAME\n" \
               "    %s - Trie une liste de mots provenant d’un fichier d’entrée.\n" \
               "    Une fois les mots triés, le programme affichera la liste ordonnée\n" \
               "    sans doublons sur stdout.\n" \
               "\n" \
               "SYNOPSIS\n" \
               "    ./%s entree.txt [-S sortie.txt]\n" \
               "\n" \
               "DESCRIPTION\n" \
               "    entree.txt\n" \
               "        Fichier contenant la liste des mots à trier.\n" \
               "    -S sortie.txt\n" \
               "        (Optionnel) Génère des statistiques et les enregistre\n" \
               "        dans le fichier de sortie spécifié.\n"




/**
 * Point d'entrée du programme.
 *
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments de la ligne de commande.
 */
int main (int argc, char **argv);

#endif
