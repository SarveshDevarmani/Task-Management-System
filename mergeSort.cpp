#include<iostream>
using namespace std;

struct Employee {
    float height, weight, average;
};

void merge(Employee e[], int low, int mid, int high) {
    Employee temp[50];

    int i=low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high) {
        if(e[i].average <= e[j].average) {
            temp[k] = e[i];
            i++;
        } else {
            temp[k] = e[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = e[i];
        i++;
        k++;
    }
    while(j <= high) {
        temp[k] = e[j];
        j++;
        k++;
    }
    
    for(int i=low; i<=high; i++) {
        e[i] = temp[i];
    }
}

void mergeSort(Employee e[], int low, int high) {
    if(low < high) {
        int mid = low + (high-low) / 2;

        mergeSort(e, low, mid);
        mergeSort(e, mid+1, high);
        merge(e, low, mid, high);
    }

}

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;
    
    Employee emp[50];

    for(int i=0; i<n; i++) {
        cout << "Enter height: ";
        cin >> emp[i].height;

        cout << "Enter weight: ";
        cin >> emp[i].weight;

        emp[i].average = (emp[i].height + emp[i].weight) / 2;
    }

    mergeSort(emp, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << emp[i].height << "\t" << emp[i].weight << "\t" << emp[i].average << endl;
    }

    return 0;
}