#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail;

void creation() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:  ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

}

void insertionatbeg() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) {
        head = tail = newnode;
    } else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertatend() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    } 
}

int getLength() {
    int count = 0;
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertPos() {
    struct node *newnode, *temp;
    int pos, i = 1;

    int length = getLength();

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > length + 1) {
        printf("Invalid Position!");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(pos == 1) {
        newnode->next = head;

        if(head != NULL) {
            head->prev = newnode;
        }
        else {
            tail = newnode;
        }

        head = newnode;
        return;
    }

    temp = head;

    while(i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    else {
        tail = newnode;
    }
    temp->next = newnode;
}

void display() {
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Create";
        cout << "\n2. Insert At Begin";
        cout << "\n3. Insert At End";
        cout << "\n4. Insert At Specific Position";
        cout << "\n5. Display";
        cout << "\n6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                creation();
                break;

            case 2:
                insertionatbeg();
                break;

            case 3:
                insertatend();
                break;

            case 4:
                insertPos();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting Programmm...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    }while(choice != 6);

    return 0;
}