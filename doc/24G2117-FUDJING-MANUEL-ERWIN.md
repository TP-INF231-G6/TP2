# Cahier de Suivi Individuel — INF231 (TP)

## Informations Personnelles
- **Nom :** FUDJING Manuel Erwin
- **Matricule :** 24G2117  
- **Groupe :** INF231_EC2

---

## Exercices Attribués
1. **Insertion en tête** dans une liste doublement chaînée circulaire
2. **Insertion en queue** dans une liste doublement chaînée circulaire

---

## Objectifs des Exercices

### Insertion en Tête
Développer une fonction en C permettant d'ajouter un élément au début d'une liste doublement chaînée circulaire.

### Insertion en Queue  
Développer une fonction en C permettant d'ajouter un élément à la fin d'une liste doublement chaînée circulaire.

---

## Analyse Algorithmique

### Structure de Données
```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Algorithme d'Insertion en Tête
text
FONCTION insertAtHead(valeur):
    nouveauNoeud <- créerNoeud(valeur)
    
    SI head est NULL:
        head <- nouveauNoeud
    SINON:
        tail <- head->prev
        nouveauNoeud->next <- head
        nouveauNoeud->prev <- tail
        tail->next <- nouveauNoeud
        head->prev <- nouveauNoeud
        head <- nouveauNoeud
    FIN SI
FIN FONCTION
Complexité :

Temporelle : O(1)

Spatiale : O(1)

Algorithme d'Insertion en Queue
text
FONCTION insertAtTail(valeur):
    nouveauNoeud <- créerNoeud(valeur)
    
    SI head est NULL:
        head <- nouveauNoeud
    SINON:
        tail <- head->prev
        nouveauNoeud->next <- head
        nouveauNoeud->prev <- tail
        tail->next <- nouveauNoeud
        head->prev <- nouveauNoeud
    FIN SI
FIN FONCTION
Complexité :

Temporelle : O(1)

Spatiale : O(1)

Implémentation en C
Code Complet
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

/**
 * Crée un nouveau nœud avec la valeur spécifiée
 */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

/**
 * Insère un élément au début de la liste
 */
void insertAtHead(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Insertion en tête : %d\n", value);
}

/**
 * Insère un élément à la fin de la liste
 */
void insertAtTail(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
    printf("Insertion en queue : %d\n", value);
}

/**
 * Affiche le contenu de la liste
 */
void displayList() {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* temp = head;
    printf("Liste : ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("[retour début]\n");
}

/**
 * Libère la mémoire allouée pour la liste
 */
void freeList() {
    if (head == NULL) return;
    
    Node* current = head;
    Node* nextNode;
    
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
    
    head = NULL;
    printf("Memoire liberee\n");
}

/**
 * Fonction principale avec menu interactif
 */
int main() {
    int choix, val;
    
    printf("Programme de Gestion de Liste Doublement Chainee Circulaire\n");
    
    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n"); 
        printf("3. Affichage de la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &val);
                insertAtHead(val);
                break;
                
            case 2:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &val);
                insertAtTail(val);
                break;
                
            case 3:
                displayList();
                break;
                
            case 0:
                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
    
    freeList();
    return 0;
}
Compilation et Exécution
Compilation
bash
gcc -o liste_circulaire liste_circulaire.c
Exécution
bash
./liste_circulaire
Tests et Validation
Scénario de Test Complet
text
MENU PRINCIPAL
1. Insertion en tête
2. Insertion en queue
3. Affichage de la liste
0. Quitter
Votre choix : 1
Entrez la valeur à insérer : 10
Insertion en tête : 10

Votre choix : 2  
Entrez la valeur à insérer : 20
Insertion en queue : 20

Votre choix : 1
Entrez la valeur à insérer : 5
Insertion en tête : 5

Votre choix : 3
Liste : 5 -> 10 -> 20 -> [retour début]

Votre choix : 0
Au revoir !
Memoire liberee
