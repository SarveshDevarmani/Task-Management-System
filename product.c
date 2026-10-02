#include<iostream>
#include<cstring>
using namespace std;


class Product {
    int prod_id;
    char prod_name[50];
    double price;

    public:
        Product(int id, char nm[], double pr) {
            prod_id = id;
            strcpy(prod_name, nm);
            price = pr;
        }

        void display(){
            cout << "\nProduct ID: " << prod_id << endl;
            cout << "\nProduct Name: " << prod_name << endl;
            cout << "\nProduct Price: " << price << endl;
        }

        friend void compare(Product p1, Product p2);
};

void compare(Product p1, Product p2) {
    if(p1.price < p2.price) {
        cout << "\n\nProduct with lower price: ";
        p1.display();
    } else iF(p2.price < p1.price) {
        cout << "\n\nProduct with lower price: ";
        p2.display();
    } else {
        cout << "\n\nBoth products have equal prices.";
    }
}

int main() {
    clrscr();
    Product p1(101, "Laptop", 55000);
    Product p2(102, "Mobile", 32000);

    cout << "\n------- Product 1 -------";
    p1.display();

    cout << "\n------- Product 2 -------";
    p2.display();

    compare(p1, p2);
    return 0;
}



