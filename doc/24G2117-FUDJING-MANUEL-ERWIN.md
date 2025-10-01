# Cahier de suivi individuel — INF231 (TP)

## Identification
**Étudiant :** FUDJING Manuel Erwin  
**Matricule :** 24G2117  
**Groupe :** INF231_EC2  

## Exercices attribués
- Insertion en tête dans une liste doublement chaînée circulaire
- Insertion en queue dans une liste doublement chaînée circulaire

---

## 1) Objectif des exercices

### 🔹 Insertion en tête
Écrire un programme en C qui insère un élément au début d'une liste doublement chaînée circulaire.

### 🔹 Insertion en queue  
Écrire un programme en C qui insère un élément à la fin d'une liste doublement chaînée circulaire.

---

## 2) Algorithmes (description)

### 🔹 Insertion en tête
```pseudocode
FONCTION insertAtHead(valeur)
    nouveauNoeud ← créerNoeud(valeur)
    SI listeVide ALORS
        head ← nouveauNoeud
    SINON
        tail ← head->prev
        nouveauNoeud->next ← head
        nouveauNoeud->prev ← tail
        tail->next ← nouveauNoeud
        head->prev ← nouveauNoeud
        head ← nouveauNoeud
    FIN SI
FIN FONCTION
Complexité temporelle : O(1)
Complexité mémoire : O(1)

🔹 Insertion en queue
pseudocode
FONCTION insertAtTail(valeur)
    nouveauNoeud ← créerNoeud(valeur)
    SI listeVide ALORS
        head ← nouveauNoeud
    SINON
        tail ← head->prev
        nouveauNoeud->next ← head
        nouveauNoeud->prev ← tail
        tail->next ← nouveauNoeud
        head->prev ← nouveauNoeud
    FIN SI
FIN FONCTION
Complexité temporelle : O(1)
Complexité mémoire : O(1)

3) Code source
🔹 insertion_en_tete_et_en_queue.c
c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

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

void displayList() {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choix, val;
    do {
        printf("\n1. Insertion en tête\n2. Insertion en queue\n3. Affichage\n0. Quitter\nChoix: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1: printf("Valeur: "); scanf("%d", &val); insertAtHead(val); break;
            case 2: printf("Valeur: "); scanf("%d", &val); insertAtTail(val); break;
            case 3: displayList(); break;
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);
    return 0;
}
4) Compilation
bash
gcc -o insertion_en_tete_et_en_queue insertion_en_tete_et_en_queue.c
5) Exécution
bash
./insertion_en_tete_et_en_queue
Exemple d'exécution :
text
1. Insertion en tête
2. Insertion en queue
3. Affichage
0. Quitter
Choix: 1
Valeur: 10
Insertion en tête : 10

Choix: 2
Valeur: 20
Insertion en queue : 20

Choix: 3
Liste: 10 20

Choix: 0
Fin du programme.
