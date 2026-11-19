#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end
void insert() {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted successfully!\n");
}

// Delete a node from the beginning
void delete() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted successfully!\n");
    }
}

// Display the linked list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        printf("Linked List: ");

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2: 
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}