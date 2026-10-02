#include<iostream>
using namespace std;

struct node{
    int value;
    int exp;
    struct node *next;
};

void insertTerm(struct node *head, int value, int exp) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->exp = exp;
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

