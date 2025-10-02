
# Cahier de suivi individuel — INF231 (TP)

### Étudiant : TIETCHAK TIAGO ESTHERA JOANNA
### Matricule : 24F2810
### Groupe : INF231_EC2

---

## **Exercice attribué :**

Insertion dans une liste doublement chaînée triée



---

## **1) Objectif de l’exercice**

Écrire un programme en C qui permet d’insérer un élément dans une liste doublement chaînée triée, de façon à ce que la liste reste toujours ordonnée en ordre croissant après chaque insertion.


---

## **2) Algorithme (description)**

🔹 Insertion triée dans une liste doublement chaînée

1. Créer un nouveau nœud avec la valeur donnée.


2. Si la liste est vide → le nouveau nœud devient la tête.


3. Sinon :

Si la valeur est plus petite que la tête → insérer avant la tête et mettre à jour head.

Sinon, parcourir la liste jusqu’à trouver la bonne position (le premier élément plus grand que la valeur).

Insérer le nœud entre deux éléments ou en fin de liste si nécessaire.



4. Mettre à jour les pointeurs prev et next correctement.



**Complexité temporelle :** O(n) (parcours de la liste)
**Complexité mémoire :** O(1) (aucun espace supplémentaire, hors allocation du nœud)


---

## 3) Code source

🔹 insertion_liste_doublement_chainee_triee.c

```c
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

// Initialiser la liste
void initList(DoublyLinkedList* list) {
    list->head = NULL;
}

// Créer un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur allocation mémoire.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée
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

    // Parcourir pour trouver la position
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

// Affichage de la liste
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
    printf("Combien d'éléments voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &value);
        insertSorted(&myList, value);
    }

    displayList(&myList);

    return 0;
}

```

---

## 4) Compilation

>     gcc -o insertion_liste_doublement_chainee_triee.c


---

## 5) Exécution

>      ./insertion_liste_doublement_chainee_triee

Exemple d’exécution :

Combien d'éléments voulez-vous insérer ? 5
Entrez l'élément 1 : 8
Entrez l'élément 2 : 3
Entrez l'élément 3 : 10
Entrez l'élément 4 : 1
Entrez l'élément 5 : 5
Liste triée : 1 3 5 8 10


---

