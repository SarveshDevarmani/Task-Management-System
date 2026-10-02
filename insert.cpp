#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};  

struct node *head =  NULL;

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

void insertAtBeg() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertAtMiddle() {
    int pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    temp = head;    
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAtEnd() {
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

void search() {
    int key, pos = 1;
    printf("Enter key: ");
    scanf("%d", &key);
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        if(temp->data ==  key) {
            printf("Element found at %d", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found!");
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
    }
    printf("NULL");  
}

int main() {
    int choice;
    do {
        printf("\n1. Create");
        printf("\n2. Insert At Beginning");
        printf("\n3. Insert At Middle");
        printf("\n4. Insert At End");
        printf("\n5. Search");
        printf("\n6. Display");
        printf("\n7. Exit\n");
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
                search();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting Program...");
                break;

            default:
                printf("Invalid Choice!");
        }


    }while(choice != 7);

    return 0;
}