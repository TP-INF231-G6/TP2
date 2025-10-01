#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud
struct Noeud {
    int valeur;
    struct Noeud* suivant;
};

// Supprimer toutes les occurrences
void supprimerValeur(struct Noeud** tete, int valASupprimer) {
    struct Noeud* actuel;
    struct Noeud* temp;

    // Supprimer au début
    while (*tete != NULL && (*tete)->valeur == valASupprimer) {
        temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
    }

    // Supprimer dans le reste
    actuel = *tete;
    while (actuel != NULL && actuel->suivant != NULL) {
        if (actuel->suivant->valeur == valASupprimer) {
            temp = actuel->suivant;
            actuel->suivant = actuel->suivant->suivant;
            free(temp);
        } else {
            actuel = actuel->suivant;
        }
    }
}

// Ajouter à la fin
void ajouter(struct Noeud** tete, int val) {
    struct Noeud* nouveau = malloc(sizeof(struct Noeud));
    nouveau->valeur = val;
    nouveau->suivant = NULL;

    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        struct Noeud* temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
}

// Afficher
void afficher(struct Noeud* tete) {
    if (tete == NULL) {
        printf("NULL\n");
        return;
    }
    while (tete != NULL) {
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

// Libérer la mémoire
void liberer(struct Noeud** tete) {
    struct Noeud* temp;
    while (*tete != NULL) {
        temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
    }
}

int main() {
    struct Noeud* liste = NULL;
    int n, valeur, valASupprimer;

    printf("Combien d'elements voulez-vous entrer ? ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Entrez les %d valeurs :\n", n);
        for (int i = 0; i < n; i++) {
            printf("Valeur %d : ", i + 1);
            scanf("%d", &valeur);
            ajouter(&liste, valeur);
        }
    }

    printf("\nListe avant : ");
    afficher(liste);

    printf("\nValeur a supprimer : ");
    scanf("%d", &valASupprimer);

    supprimerValeur(&liste, valASupprimer);

    printf("Liste apres : ");
    afficher(liste);

    // Libérer la mémoire
    liberer(&liste);

    return 0;
}
