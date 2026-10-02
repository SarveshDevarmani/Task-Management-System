#include<iostream>
#include<string>
using namespace std;

struct node{
    int id;
    string title;
    string priority;
    bool completed;
    node *next;
};

node *head = NULL;

void addTask() {
    node *newnode = new node;
    printf("Enter Task Id: ");
    scanf("%d", &newnode->id);
    cin.ignore();
    printf("Enter Task Title: ");
    getline(cin, newnode->title);
    printf("Enter Task Priority: ");
    getline(cin, newnode->priority);

    newnode->completed = false;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    }
    else {
        struct node *temp;
        temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void displayTask() {
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        cout << "Task ID: " << temp->id << endl;
        cout << "Task Title: " << temp->title << endl;
        cout << "Task Priority: " << temp->priority << endl;

        if(temp->completed) {
            cout << "Staus: Completed" << endl;
        } else {
            cout << "Status: Pending" << endl; 
        }
        cout << endl;
        temp = temp->next;
    }

}

void search() {
    int targetId;
    printf("Enter Target ID to found: ");
    scanf("%d", &targetId);

    struct node *temp;
    temp = head;

    if(temp == NULL) {
        printf("List is Empty!");
        return;
    }
    
    bool found = false;

    while(temp != NULL) {
        if(temp->id == targetId) {
            printf("Task found!");
            found =  true;
            break;
        }
        temp = temp->next;
    }
    if(found == false) {
        printf("Task not found!");
    }
}

void completeTask() {
    int targetId;
    printf("Enter Task ID to complete: ");
    scanf("%d", &targetId);

    struct node *temp = head;

    if(temp == NULL) {
        printf("List is Empty!");
        return;
    }

    while(temp != NULL) {
        if(temp->id == targetId) {
            temp->completed = true;
            printf("Task marked as completed\n");
            return;
        }
        temp = temp->next;
    }
    printf("Task not found!\n");
}

void deleteTask() {
    int targetId;
    printf("Enter Task ID to delete: ");
    scanf("%d", &targetId);

    if(head == NULL) {
        printf("List is Empty!");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    if(temp->id == targetId) {
        head = head->next;
        delete temp;
        printf("Task deleted successfully!");
        return;
    }

    while(temp != NULL && temp->id != targetId) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Task not found!");
        return;
    }

    prev->next = temp->next;
    delete temp;

    printf("Task deleted successfully!");
}

void countTask() {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of tasks: %d", count);
}

int main() {
    int choice;
        printf("\n========= TASK MANAGEMENT SYSTEM =========\n");
    do {
        printf("\n1. Create Task");
        printf("\n2. Display Task");
        printf("\n3. Search Task");
        printf("\n4. Complete Task");
        printf("\n5. Delete Task");
        printf("\n6. Count Task");
        printf("\n7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTask();
                break;
                
            case 2:
                displayTask();
                break;

            case 3:
                search();
                break;

            case 4:
                completeTask();
                break;

            case 5:
                deleteTask();
                break;

            case 6:
                countTask();
                break;

            case 7:
                printf("Thank you!");
                break;

            default:
                printf("Invalid Choice!");
        }

    }while(choice != 7);
    return 0;
}