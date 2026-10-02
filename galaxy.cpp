#include<iostream>
using namespace std;

struct node {
    char row;
    int seatNo;
    bool booked;

    struct node *next, *prev;
};

class Galaxy {
    private:
        node *head;
    public:
        Galaxy() {
            head = NULL;
        }

        void createSeats();
        void displaySeats();
        void bookTicket();
        void cancelTicket();
        void searchSeat();
};

node *createNode(char row, int seatNo) {
    node *newnode = new node;

    newnode->row = row;
    newnode->seatNo = seatNo;
    newnode->booked = false;

    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void Galaxy::createSeats() {
    node *last = NULL;

    for(char r='A'; r<='H'; r++) {
        for(int s=1; s<=8; s++) {
            node *newnode = createNode(r, s);

            if(head == NULL) {
                head = last = newnode;
                head->next = head;
                head->prev = head;
            } else {
                newnode->prev = last;
                newnode->next = head;
                last->next = newnode;
                head->prev = newnode;
                last = newnode;
            }
        }
    }
}

void Galaxy::displaySeats() {
    node *temp = head;

    cout << "\n===== Galaxy Multiplex =====\n";
    cout << "0 = Available X = Booked\n\n";

    cout << "    1 2 3 4 5 6 7 8\n";

    for(char r = 'A'; r <= 'H'; r++) {
        cout << r << "   ";

        for(int s = 1; s <= 8; s++) {

            if(temp->booked == false) {
                cout << "0 ";
            }
            else {
                cout << "X ";
            }


            temp = temp->next;
        }

        cout << endl;
    }
}


void Galaxy::bookTicket() {
    char row;
    int seatNo;

    cout << "Enter row (A-H): ";
    cin >> row;

    cout << "Enter seat number (1-8): ";
    cin >> seatNo;

    node *temp = head;

    do {
        if(temp->row == row && temp->seatNo == seatNo) {

            if(temp->booked == true) {
                cout << "Seat is already booked!\n";
            }
            else {
                temp->booked = true;   // IMPORTANT
                cout << "Ticket booked successfully!\n";
            }

            return;
        }

        temp = temp->next;

    } while(temp != head);

    cout << "Invalid seat!\n";
}


void Galaxy::cancelTicket() {
    char row;
    int seatNo;

    cout << "Enter row (A-H): ";
    cin >> row;

    cout << "Enter seat number (1-8): ";
    cin >> seatNo;

    node *temp = head;

    do {
        if(temp->row == row && temp->seatNo == seatNo) {

            if(temp->booked == true) {
                temp->booked = false;
                cout << "Ticket cancelled successfully!\n";
            }
            else {
                cout << "Seat is not booked!\n";
            }

            return;
        }

        temp = temp->next;

    } while(temp != head);

    cout << "Invalid seat!\n";
}



void Galaxy::searchSeat() {
    char row;
    int seatNo;

    cout << "Enter row (A-H): ";
    cin >> row;

    cout << "Enter seat number (1-8): ";
    cin >> seatNo;

    node *temp = head;

    do {
        if(temp->row == row && temp->seatNo == seatNo) {
            cout << "Seat found!\n";

            if(temp->booked) {
                cout << "Status: Booked\n";
            } else {
                cout << "Status: Available\n";
            }
            return;
        }
        temp = temp->next;

    }while(temp != head);
    cout << "Seat not found!\n";
}

int main() {
    Galaxy g;
    g.createSeats();

    int choice;

    do {
            cout << "\n===== GALAXY MULTIPLEX =====\n";
            cout << "1. Display Seats\n";
            cout << "2. Book Ticket\n";
            cout << "3. Cancel Ticket\n";
            cout << "4. Search Seat\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    g.displaySeats();
                    break;

                case 2:
                    g.bookTicket();
                    break;

                case 3:
                    g.cancelTicket();
                    break;

                case 4:
                    g.searchSeat();
                    break;

                case 5:
                    cout << "Thank you!\n";
                    break;

                default:
                    cout << "Ivalid Choice!\n";
            }
    }while(choice != 5);

    return 0;
}