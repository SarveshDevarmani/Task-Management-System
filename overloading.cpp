#include<iostream>
using namespace std;

class Vector {
    int size;
    int *arr;

    public:
        Vector() {
            size = 0;
            arr = NULL;
        }

        Vector(const Vector& v) {
            size = v.size;
            arr = new int[size];

            for(int i=0; i<size; i++) {
                arr[i] = v.arr[i];
            }
        }

        ~Vector()  {
            delete[] arr;
        }

        friend istream& operator>>(istream& in, Vector& v) {
            cout << "Enter size: ";
            in >> v.size;

            v.arr = new int[v.size];

            cout << "Enter elements: ";
            for(int i=0; i<v.size; i++) {
                in >> v.arr[i];
            }
            return in;
        }

        friend ostream& operator<<(ostream& out, const Vector& v) {
            out << "[";

            for(int i=0; i<v.size; i++) {
                out << v.arr[i] << " ";
            }
            out << "]";
            return out;
        }

        Vector operator++(int) {
            Vector temp(*this);

            for(int i=0; i<size; i++) {
                arr[i]++;
            }
            return temp;
        }

        friend Vector operator*(int n, const Vector& v) {
            Vector temp;

            temp.size = v.size;
            temp.arr = new int[temp.size];

            for(int i=0; i<temp.size; i++) {
                temp.arr[i] = n * v.arr[i];
            } 
            return temp;
        }
};

int main() {
    Vector v;

    cin >> v;
    cout << "Original vector = " << v << endl;

    v++; 
    cout << "After v++ = " << v << endl;

    cout << "2 * v = " << 2 * v << endl;

    cout << "Final Vector =  " << v << endl;

    return 0;
}

