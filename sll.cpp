#include<iostream>
#include<cstdlib>
using namespace std;


int pos, i, count = 0;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg() {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    count++;

}

void insertEnd() {
    struct node *temp, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter your data: ");
    scanf("%d", &newNode->data);
    
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    }
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    count++;
}

void insertPos() {
    struct node *temp, *newNode;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > count + 1) {
        printf("Invalid Position...");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data: ");
    scanf("%d", &newNode->data);


    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    count++;
}

void display() {
    struct node *temp;

    temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert At Begin";
        cout << "\n2. Insert At End";
        cout << "\n3. Insert At Give Position";
        cout << "\n4. Display";
        cout << "\n5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                insertBeg();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertPos();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    }while(choice != 5);

    return 0;
}





