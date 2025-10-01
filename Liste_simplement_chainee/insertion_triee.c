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
