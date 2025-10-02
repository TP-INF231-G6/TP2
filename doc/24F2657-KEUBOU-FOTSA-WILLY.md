 # Cahier de suivi individuel — INF231 (TP)

**Étudiant :** Keubou Fotsa Willy  
**Matricule :** 24F2657  
**Groupe :** INF231_EC2  

## Exercices attribués :
Suppression de toutes les occurrences d'un élément dans une liste chaînée (suppression_liste.c)

---

## 1) Objectif de l'exercice

🔹 **Suppression d'occurrences dans une liste chaînée**

Écrire un programme en C qui manipule une liste chaînée et supprime toutes les occurrences d'une valeur donnée.

- **Permettre à l'utilisateur de créer sa propre liste chaînée.**
- Saisir le nombre d'éléments et les valeurs à insérer.
- Saisir la valeur à supprimer.
- Supprimer toutes les occurrences de cette valeur dans la liste.
- Afficher la liste avant et après suppression.
- Libérer correctement la mémoire allouée.

---

## 2) Algorithmes (description)

🔹 **Suppression d'occurrences dans une liste chaînée**

**Structure de données :**
- Définir une structure `Noeud` contenant :
  - `int valeur` : la donnée stockée
  - `struct Noeud* suivant` : pointeur vers le nœud suivant

**Étapes de l'algorithme :**

1. **Saisir le nombre d'éléments** que l'utilisateur souhaite entrer dans la liste.

2. **Créer la liste chaînée dynamiquement :**
   - Pour chaque élément (de 1 à n) :
     - Demander à l'utilisateur d'entrer une valeur
     - Ajouter cette valeur à la fin de la liste

3. **Afficher la liste initiale** en parcourant tous les nœuds.

4. **Saisir la valeur à supprimer** depuis l'entrée utilisateur.

5. **Supprimer les occurrences en tête de liste :**
   - Tant que la tête contient la valeur à supprimer :
     - Sauvegarder le nœud à supprimer dans `temp`
     - Déplacer la tête vers le nœud suivant
     - Libérer la mémoire de `temp`

6. **Supprimer les occurrences dans le reste de la liste :**
   - Parcourir la liste avec un pointeur `actuel`
   - Pour chaque nœud, vérifier si le nœud suivant contient la valeur
   - Si oui :
     - Sauvegarder `actuel->suivant` dans `temp`
     - Faire le lien : `actuel->suivant = actuel->suivant->suivant`
     - Libérer la mémoire de `temp`
   - Sinon : avancer au nœud suivant

7. **Afficher la liste finale** après suppression.

8. **Libérer toute la mémoire** restante de la liste.

**Complexité temporelle :** O(n) — on parcourt la liste une seule fois.  
**Complexité mémoire :** O(1) — pas d'espace supplémentaire proportionnel à n.

---

## 3) Code source

🔹 **Suppression d'occurrences (suppression_liste.c)**

```c
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
```

---

## 4) Compilation et Exécution

### Compilation
```bash
gcc -o suppression_liste ./listes/suppression_liste.c
```

### Exécution
```bash
./suppression_liste
```

**Exemple d'exécution 1 :**

```
Combien d'elements voulez-vous entrer ? 5
Entrez les 5 valeurs :
Valeur 1 : 3
Valeur 2 : 5
Valeur 3 : 3
Valeur 4 : 7
Valeur 5 : 3

Liste avant : 3 -> 5 -> 3 -> 7 -> 3 -> NULL

Valeur a supprimer : 3
Liste apres : 5 -> 7 -> NULL
```

**Exemple d'exécution 2 :**

```
Combien d'elements voulez-vous entrer ? 6
Entrez les 6 valeurs :
Valeur 1 : 10
Valeur 2 : 20
Valeur 3 : 10
Valeur 4 : 30
Valeur 5 : 10
Valeur 6 : 40

Liste avant : 10 -> 20 -> 10 -> 30 -> 10 -> 40 -> NULL

Valeur a supprimer : 10
Liste apres : 20 -> 30 -> 40 -> NULL
```

**Exemple d'exécution 3 (valeur inexistante) :**

```
Combien d'elements voulez-vous entrer ? 4
Entrez les 4 valeurs :
Valeur 1 : 1
Valeur 2 : 2
Valeur 3 : 3
Valeur 4 : 4

Liste avant : 1 -> 2 -> 3 -> 4 -> NULL

Valeur a supprimer : 9
Liste apres : 1 -> 2 -> 3 -> 4 -> NULL
```

**Exemple d'exécution 4 (liste vide) :**

```
Combien d'elements voulez-vous entrer ? 0

Liste avant : NULL

Valeur a supprimer : 5
Liste apres : NULL
```

---

## 5) Notes importantes

⚠️ **Gestion de la mémoire :** 
- Toujours utiliser `free()` pour libérer les nœuds supprimés afin d'éviter les fuites mémoire.
- La fonction `liberer()` a été ajoutée pour nettoyer toute la mémoire à la fin du programme.

✅ **Double pointeur :** La fonction `supprimerValeur` utilise `struct Noeud**` pour pouvoir modifier la tête de liste.

🔄 **Saisie dynamique :** L'utilisateur peut créer une liste de n'importe quelle taille avec les valeurs de son choix.

📌 **Cas particuliers gérés :**
- Suppression en tête de liste (plusieurs occurrences consécutives)
- Suppression au milieu de la liste
- Suppression en fin de liste
- Valeur inexistante dans la liste
- Liste vide (n = 0)
- Affichage correct d'une liste vide ("NULL")

✨ **Améliorations apportées :**
- Saisie interactive du nombre d'éléments
- Saisie interactive des valeurs
- Fonction `liberer()` pour une gestion complète de la mémoire
- Gestion du cas d'une liste vide dans la fonction `afficher()`
