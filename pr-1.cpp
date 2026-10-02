#include<iostream>
using namespace std;

struct node{
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
        return;
    }
    else {
        struct node *temp;
        temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void Count() {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of Nodes: %d", count);
}

void display() {
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    int choice;

    do {
        cout << "\n1. Create List";
        cout << "\n2. Display";
        cout << "\n3. Count Nodes";
        cout << "\n4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                Count();
                break;
            

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice!";

        }
    }while(choice != 4);
    return 0;
}