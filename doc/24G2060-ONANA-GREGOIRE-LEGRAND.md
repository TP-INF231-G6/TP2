# Cahier de suivi individuel — INF231 (TP)  
**Étudiant :** ONANA GREGOIRE LEGRAND  
**Matricule :** 24G2060  
**Exercice attribué :** Insertion dans une liste simplement chainée triée  

---

## 1) Objectif de l'exercice
Écrire un programme en C qui permet d’insérer un élément dans une **liste simplement chainée déjà triée** tout en respectant l’ordre croissant.

---

## 2) Algorithme (description)
1. Créer la structure d’un nœud avec une valeur et un pointeur vers le suivant.  
2. Lire les éléments de la liste initiale et les insérer dans l’ordre croissant.  
3. Lire la nouvelle valeur `x` à insérer.  
4. Parcourir la liste :  
   - Si la liste est vide ou si `x` est plus petit que la première valeur, insérer `x` en tête.  
   - Sinon, avancer dans la liste jusqu’à trouver la bonne position.  
   - Insérer le nouveau nœud avant le premier élément plus grand que `x`.  
5. Afficher la liste mise à jour.  

---

## 3) Code source (fichier : `insertion_triee.c`)

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insererTrie(Node **head, int val) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL && temp->next->data < val)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void afficherListe(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int n, val;

    printf("Entrez le nombre d’éléments initiaux : ");
    scanf("%d", &n);

    printf("Entrez les éléments (ils seront insérés triés) :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insererTrie(&head, val);
    }

    printf("Liste actuelle : ");
    afficherListe(head);

    printf("Entrez la valeur à insérer : ");
    scanf("%d", &val);
    insererTrie(&head, val);

    printf("Liste après insertion : ");
    afficherListe(head);

    return 0;
}
````

---

## 4) Compilation

```bash
gcc -Wall -Wextra -O2 -o insertion_liste insertion_liste.c
```

## 5) Exécution

```bash
./insertion_liste
```

---

## Exemple d’exécution

```
Entrez le nombre d’éléments initiaux : 4
Entrez les éléments (ils seront insérés triés) :
7 2 5 3
Liste actuelle : 2 -> 3 -> 5 -> 7 -> NULL
Entrez la valeur à insérer : 4
Liste après insertion : 2 -> 3 -> 4 -> 5 -> 7 -> NULL
```

```

 
```
 
