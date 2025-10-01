#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL; // pointeur global vers la tête

// Création d'un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode->prev = newNode; // circulaire
    return newNode;
}

// Insertion en tête
void insertAtHead(int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode; // mise à jour de la tête
    }
    printf("Élément %d inséré en tête.\n", value);
}

// Insertion en queue
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
    printf("Élément %d inséré en queue.\n", value);
}

// Affichage de la liste
void displayList() {
    if (head == NULL) {
        printf("La liste est vide.\n");
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

// Menu d'interaction
int main() {
    int choix, valeur;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Insérer en tête\n");
        printf("2. Insérer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                insertAtHead(valeur);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &valeur);
                insertAtTail(valeur);
                break;
            case 3:
                displayList();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
        }
    } while (choix != 0);

    return 0;
}
