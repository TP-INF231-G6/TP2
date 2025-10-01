#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction d'insertion en tête

Node* insertAtHead(Node* last, int data) {
    Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Fonction d'insertion en queue
Node* insertAtTail(Node* last, int data) {
    Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

// Fonction pour afficher la liste

void displayList(Node* last) {
    if (last == NULL) {
        printf("La liste est vide\n");
        return;
    }
    
    Node* temp = last->next;
    Node* first = last->next;
    printf("Liste circulaire : ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != first) {
            printf(" -> ");
        }
    } while (temp != first);
    printf(" -> (boucle)\n");
}

// Fonction pour compter les éléments

int countElements(Node* last) {
    if (last == NULL) return 0;
    int count = 0;
    Node* temp = last->next;
    Node* first = last->next;
    
    do {
        count++;
        temp = temp->next;
    } while (temp != first);
    
    return count;
}

// Fonction pour libérer la mémoire

void freeList(Node* last) {
    if (last == NULL) return;
    Node* current = last->next;
    Node* first = last->next;
    Node* nextNode
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != first);
}

// Fonction pour afficher le menu

void displayMenu() {
    printf("\n=== MENU LISTE CIRCULAIRE ===\n");
    printf("1. Insertion en tête\n");
    printf("2. Insertion en queue\n");
    printf("3. Afficher la liste\n");
    printf("4. Nombre d'éléments\n");
    printf("5. Quitter\n");
    printf("Choix : ");
}
int main() {
    Node* last = NULL;
    int choice, value;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &value);
                last = insertAtHead(last, value);
                printf("Valeur %d insérée en tête.\n", value);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &value);
                last = insertAtTail(last, value);
                printf("Valeur %d insérée en queue.\n", value);
                break;
            case 3:
                displayList(last);
                break;           
            case 4:
                printf("La liste contient %d élément(s)\n", countElements(last));
                break;                
            case 5:
                printf("Au revoir !\n");
                break;                
            default:
                printf("Choix invalide ! Veuillez choisir entre 1 et 5.\n");
                break;
        }      
    } while (choice != 5);
  
    // Libération de la mémoire
  
    freeList(last);
    return 0;
}
