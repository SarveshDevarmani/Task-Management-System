#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL; 
struct node *newnode;

void create() {

    struct node *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) {
        head = temp = newnode;
    } else {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}



void display() {
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        create();
    }

    
    display();

    return 0;
}