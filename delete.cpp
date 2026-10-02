#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        struct node *temp;
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deleteAtBeg() {
    struct node *temp;
    temp = head;

    if(head == NULL) {
        printf("List is Empty!");
    } else {
        head = head->next;
    }
    free(temp);
}

void deleteAtMiddle() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *temp = head;
    struct node *prev = NULL;

    for(int i=1; i<pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAtEnd() {
    struct node *temp = head;
    struct node *prev = NULL;

    if(head == NULL) {
        printf("List is Empty!");
    } else if(head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is Empty!");
    } else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL");
}

int main() {
    int choice;

    do {
        printf("\n1. Create");
        printf("\n2. Delete from Beginning");
        printf("\n3. Delete from Middle");
        printf("\n4. Delete from End");
        printf("\n5. Display");
        printf("\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                deleteAtBeg();
                break;

            case 3:
                deleteAtMiddle();
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting Program...");
                break;

            default:
                printf("Invalid Choice!");
        }

    }while(choice != 6);

    return 0;
}