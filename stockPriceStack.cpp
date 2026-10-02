#include<iostream>
using namespace std;

class Node{
    public:
        int price;
        Node *next;

    public:
        Node(int p) {
            price = p;
            next = NULL;
        }
};

class StockPriceStack {
    private:
        Node *top;

    public:
        StockPriceStack() {
            top = NULL;
        }

        void record(int price) {
            Node *newnode = new Node(price);

            newnode->next = top;
            top = newnode;

            cout << "Stock Price recorded: " << price << endl;
        }

        int remove() {
            if(isEmpty()) {
                cout << "No stock prices recorded." << endl;
                return -1;
            }

            Node *temp = top;
            int price = top->price;
            top = top->next;
            delete temp;

            return price;
        }

        int latest() {
            if(isEmpty()) {
                cout << "No stock prices recorded." << endl;
                return -1;
            }

            return top->price;
        }

        bool isEmpty() {
            return top == NULL;
        }
};

int main() {
    StockPriceStack stock;

    int choice, price;
    do {
        cout << "\n===== Stock Price Tracker =====" << endl;
        cout << "\n1. Record Stock Price" << endl;
        cout << "\n2. Remove Stock Price" << endl;
        cout << "\n3. View Latest Price" << endl;
        cout << "\n4. Check if Empty" << endl;
        cout << "\n5. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter stock price: ";
                cin >> price;
                stock.record(price);
                break;

            case 2:
                price = stock.remove();
                if(price != -1) {
                    cout << "Removed stock price: " << price << endl;
                }
                break;

            case 3:
                price = stock.latest();
                if(price != -1) {
                    cout << "No prices recorded. Stack is Empty." << endl;
                } else {
                    cout << "Stock prices are recorded. Stack is not empty." << endl;
                }
                break;

            case 4:
                if(stock.isEmpty()) {
                    cout << "No prices are recorded. Stack is empty." << endl;
                } else {
                    cout << "Stock prices are recorded. Stack is not empty." << endl;
                }
                break;

            case 5:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid Choice!";

        }
    }while(choice != 5);

    return 0;
}

