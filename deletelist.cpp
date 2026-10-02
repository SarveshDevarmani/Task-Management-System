#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *head, *temp;

node *creationll() {
    node *head = NULL;
    node *temp = NULL;
    node *newNode;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        newNode = new node;

        cout << "Enter data: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void deletefrombeg() {
    if(head == NULL) {
        cout << "List is Empty!";
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

void deletefromend() {
    struct node *prevnode;
    temp = head;
    while (temp->next != NULL) {
        prevnode = temp;
        temp = temp->next;
    }

    if(temp == head) {
        head = NULL;
    } else {
        prevnode->next = NULL;
    }
    free(temp);    
}

void deletefrompos(){
    struct node *nextNode;
    int pos, i = 1;
    temp = head;

    cout << "Enter position: ";
    cin >> pos;

    while(i < pos-1) {
        temp = temp->next;
        i++;
    }
    nextNode = temp->next;
    temp->next = nextNode->next;
    free(temp);
}

void display() {
    temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    int choice;

    do{
        cout << "\n1. Create List";
        cout << "\n2. Delete from Begin";
        cout << "\n3. Delete from End";
        cout << "\n4. Delete from a particular position";
        cout << "\n5. Display";
        cout << "\n6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                head = creationll();
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
                cout << "Exiting program...!";
                break;

            default:
                cout << "Invalid choice...!";
        }
    }while(choice != 6);

    return 0;
}