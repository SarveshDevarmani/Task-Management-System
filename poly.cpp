#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int exp;
    node* next;
};


node* insert(node* head, int coeff, int exp)
{
    node* newnode = new node;

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    if (head == NULL)
    {
        return newnode;
    }

    node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    return head;
}


void display(node* head)
{
    node* temp = head;

    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->exp;

        if (temp->next != NULL)
        {
            cout << " + ";
        }

        temp = temp->next;
    }

    cout << endl;
}


node* add(node* p1, node* p2)
{
    node* result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            result = insert(result,
                            p1->coeff + p2->coeff,
                            p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            result = insert(result,
                            p1->coeff,
                            p1->exp);

            p1 = p1->next;
        }
        else
        {
            result = insert(result,
                            p2->coeff,
                            p2->exp);

            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    node* p1 = NULL;
    node* p2 = NULL;
    node* result = NULL;


    p1 = insert(p1, 5, 3);
    p1 = insert(p1, 4, 2);
    p1 = insert(p1, 2, 0);


    p2 = insert(p2, 3, 3);
    p2 = insert(p2, -4, 2);
    p2 = insert(p2, 7, 1);
    p2 = insert(p2, 6, 0);

    cout << "Polynomial 1: ";
    display(p1);

    cout << "Polynomial 2: ";
    display(p2);

    result = add(p1, p2);

    cout << "Addition: ";
    display(result);

    return 0;
}
