#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Définition de la liste
typedef struct {
    Node* head;
} DoublyLinkedList;

// Fonction pour initialiser la liste
void initList(DoublyLinkedList* list) {
    list->head = NULL;
}

// Créer un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur : mémoire insuffisante.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insérer un élément dans la liste triée
void insertSorted(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);

    // Cas 1 : liste vide
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;

    // Cas 2 : insérer avant la tête
    if (value < current->data) {
        newNode->next = current;
        current->prev = newNode;
        list->head = newNode;
        return;
    }

    // Parcourir jusqu'à la bonne position
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // Insérer après current
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

// Afficher la liste dans le sens normal
void displayList(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Node* current = list->head;
    printf("Liste triée : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Programme principal
int main() {
    DoublyLinkedList myList;
    initList(&myList);

    int n, value;
    printf("\n__________________________________Initialisation de la liste__________________________________\n");
    printf("\nEntrez le nombre d'éléments dans la liste : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &value);
        insertSorted(&myList, value);
    }

    displayList(&myList);

    printf("\nInsertion d'un nouvel élément dans la liste triée.\n");
    printf("Entrez la valeur à insérer : ");
    scanf("%d", &value);
    insertSorted(&myList, value);
    displayList(&myList);
    printf("\n");
    // Libération de la mémoire
    Node* current = myList.head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;     
    }
    myList.head = NULL;
    printf("Mémoire libérée.\n");
    printf("Fin du programme.\n");
    printf("__________________________________Fin de la liste__________________________________\n");
    
    return 0;
}
