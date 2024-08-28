#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        Node *temp = head;
        if (temp->next == NULL) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
        printf("Node deleted from the end.\n");
    }
}

// Function to print the list contents
void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        Node *temp = head;
        printf("List contents: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to search for a node
void searchNode(int data) {
    Node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        printf("Node with data %d found in the list.\n", data);
    } else {
        printf("Node with data %d not found in the list.\n", data);
    }
}

// Function to display the menu and handle user choices
void displayMenu() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a new list\n");
        printf("2. Insert a node at the beginning\n");
        printf("3. Insert a node at the end\n");
        printf("4. Delete a node from the beginning\n");
        printf("5. Delete a node from the end\n");
        printf("6. Print the list contents\n");
        printf("7. Search for a node\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = NULL;
                printf("New list created.\n");
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printList();
                break;
            case 7:
                printf("Enter data to search for: ");
                scanf("%d", &data);
                searchNode(data);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    displayMenu();
    return 0;
}

