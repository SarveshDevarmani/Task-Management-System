#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *newnode = NULL;
struct node *temp = NULL;
struct node *tail = NULL;

void createList() {
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void deletefrombeg(){
    if(head == NULL) {
        printf("List is empty!");
    } else {
        temp = head;

        if(head->next == NULL) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;  
        }
        free(temp);
    }
}

void deletefromend() {
    if(tail == NULL) {
        printf("List is Empty!");
    } else {
        temp =tail;
        tail->prev->next =  NULL;
        tail = tail->prev;
        free(temp);
    }
}

void deletefrompos() {
    int pos, i=1;

    if(head == NULL) {
        printf("List is empty!");
        return;
    }

    printf("Enter  position:  ");
    scanf("%d", &pos);

    temp = head;

    while(i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        printf("Invalid position!");
        return;
    }

    if(temp == tail) {
        deletefromend();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    if(head == NULL) {
        printf("List is empty!");
        return;
    }

    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() { 
    int choice;

    do{
        cout << "\n1. Create List";
        cout << "\n2. Delete from Beginning";
        cout << "\n3. Delete from End";
        cout << "\n4. Delete from Specific Position";
        cout << "\n5. Display";
        cout << "\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createList();
                break;

            case 2:
                deletefrombeg();
                break;

            case 3:
                deletefromend();
                break;

            case 4:
                deletefrompos();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting Programm...!";
                break;

            default:
                cout << "\nInvalid Choice!";
    
        }
    }while(choice != 6);

    return 0;
}