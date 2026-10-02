#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* next;
};


void addSong(Node* &head, string song) {

    Node* newNode = new Node;

    newNode->song = song;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        return;
    }


    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void display(Node* head) {

    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Playlist: ";

    while (temp != NULL) {
        cout << temp->song << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}


void skipSong(Node* &head, string song) {


    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    if (head->song == song) {

        Node* deleteNode = head;

        head = head->next;

        delete deleteNode;

        cout << song << " skipped successfully!" << endl;

        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {

        if (temp->next->song == song) {

            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << song << " skipped successfully!" << endl;

            return;
        }

        temp = temp->next;
    }

    cout << song << " not found in playlist!" << endl;
}

int main() {

    Node* head = NULL;


    addSong(head, "Believer");
    addSong(head, "Perfect");
    addSong(head, "Shape of You");
    addSong(head, "Faded");

    cout << "Before skipping:" << endl;
    display(head);

    skipSong(head, "Perfect");

    cout << "\nAfter skipping:" << endl;
    display(head);

    return 0;
}