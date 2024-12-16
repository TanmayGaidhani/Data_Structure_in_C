
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;                   
    struct Node* prev;      
    struct Node* next;   
};

struct Node* head = NULL;

void insertAtBeginning(int element) {
    printf("Enter element: ");
    scanf("%d", &element);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = element;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL) 
        head->prev = temp;
    head = temp;
}

void insertAtEnd(int element) {
    printf("Enter element: ");
    scanf("%d", &element);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;
    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    } struct Node* temp1 = head;
    while (temp1->next != NULL) 
        temp1 = temp1->next;
    temp1->next = temp;
    temp->prev = temp1;
}

void insertAt_nth_position(int element, int position) {
    printf("Enter element and position: ");
    scanf("%d %d", &element, &position);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = element;
    if (position == 1) {
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL) 
            head->prev = temp;
        head = temp;
        return;
    } struct Node* temp1 = head;
    for (int i = 1; i < position - 1 && temp1 != NULL; i++)
        temp1 = temp1->next;
    if (temp1 == NULL) {
        printf("Position out of range\n");
        free(temp);
    } else {
        temp->next = temp1->next;
        temp->prev = temp1;
        if (temp1->next != NULL)
            temp1->next->prev = temp;
        temp1->next = temp;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("The List is empty, cannot delete from an empty list\n");
    } else {
        struct Node* temp1 = head;
        head = head->next;
        if (head != NULL) 
            head->prev = NULL;
        printf("Deleted: %d\n", temp1->data);
        free(temp1);
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("The List is empty, cannot delete from an empty list\n");
    } else if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        printf("Deleted: %d\n", temp1->data);
        temp1->prev->next = NULL;
        free(temp1);
    }
}

void deleteFrom_nth_position(int position) {
    printf("Enter position: ");
    scanf("%d", &position);
    if (head == NULL) {
        printf("The List is empty, cannot delete from an empty list\n");
        return;
    } if (position == 1) {
        struct Node* temp1 = head;
        head = temp1->next;
        if (head != NULL) 
            head->prev = NULL;
        printf("Deleted: %d\n", temp1->data);
        free(temp1);
        return;
    } struct Node* temp1 = head;
    for (int i = 1; i < position && temp1 != NULL; i++) 
        temp1 = temp1->next;
    if (temp1 == NULL) {
        printf("Position out of range\n");
    } else {
        printf("Deleted: %d\n", temp1->data);
        if (temp1->prev != NULL) 
            temp1->prev->next = temp1->next;
        if (temp1->next != NULL)
            temp1->next->prev = temp1->prev;
        free(temp1);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp1 = head;
        printf("Doubly Linked List: \n");
        while (temp1 != NULL) {
            printf("[ %p |  %d  | %p ] <=> ", 
                    temp1->prev, temp1->data, temp1->next);
            temp1 = temp1->next;
        }
        printf("NULL\n");
    }
}
void main() {
    int choice, element, position;
    do {
        printf("\nChoice:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Nth Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Nth Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertAtBeginning(element);
                break;
            case 2:
                insertAtEnd(element);
                break;
            case 3:
                insertAt_nth_position(element, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                deleteFrom_nth_position(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please enter the choice again\n");
        }
    } while (choice != 8);
}
