#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    } else {
        struct node *temp;
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAtBeg() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

void insertAtMiddle() {
    struct node *newnode, *temp;
    int pos, i;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }
    temp = head;

    for(int i=1; i<pos-1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insertAtEnd() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void display() {
    struct node *temp;
    temp = head;

    if(head == NULL) {
        printf("List is Empty!");
    } else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
    
}

int main() {
    int choice;
    do {
        printf("\n1. Create");
        printf("\n2. Insert At Beginning");
        printf("\n3. Insert At Middle");
        printf("\n4. Insert At End");
        printf("\n5. Display");
        printf("\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                insertAtBeg();
                break;

            case 3:
                insertAtMiddle();
                break;

            case 4:
                insertAtEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid Choice!");
        }
    }while(choice != 6);
    return 0;
}