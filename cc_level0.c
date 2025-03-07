#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

DoublyLinkedList* create_list() {
    DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    dll->head = NULL;
    return dll;
}

void insert_at_head(DoublyLinkedList* dll, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = dll->head;
    new_node->prev = NULL;
    if (dll->head)
        dll->head->prev = new_node;
    dll->head = new_node;
}

void insert_at_tail(DoublyLinkedList* dll, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!dll->head) {
        new_node->prev = NULL;
        dll->head = new_node;
        return;
    }
    Node* temp = dll->head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void traverse_forward(DoublyLinkedList* dll) {
    Node* temp = dll->head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverse_backward(DoublyLinkedList* dll) {
    Node* temp = dll->head;
    if (!temp)
        return;
    while (temp->next)
        temp = temp->next;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList* dll = create_list();
    int choice, data;
    while (1) {
        printf("\n1. Insert at Head\n2. Insert at Tail\n3. Traverse Forward\n4. Traverse Backward\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &data);
                insert_at_head(dll, data);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &data);
                insert_at_tail(dll, data);
                break;
            case 3:
                printf("Forward Traversal: ");
                traverse_forward(dll);
                break;
            case 4:
                printf("Backward Traversal: ");
                traverse_backward(dll);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}