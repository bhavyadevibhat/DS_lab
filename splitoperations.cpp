#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;

void insert() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        struct node* newnode = new struct node;

        cout << "Enter data for node " << i + 1 << ": ";
        cin >> newnode->data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display() {
    temp = head;
    while (temp != NULL) {
        cout << temp->data << "---> ";
        temp = temp->next;
    }
}

int search() {
    int x;
    cout << "\nEnter the number you want to search: " << endl;
    cin >> x;
    node* temp = head;
    int found = 0;
    int i = 0;

    if (temp != NULL) {
        while (temp != NULL) {
            i++;
            if (temp->data == x) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1) {
            cout << x << " is found at index = " << i << ".\n";
        } else {
            cout << x << " is not found in the list.\n";
        }
    } else {
        cout << "The list is empty.\n";
    }
}

void splitLastFirst(struct node*& head, struct node*& second, int a) {
    struct node* current = head;
    struct node* prev = NULL;

  
    while (current != NULL && current->data !=a) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        
        second = current->next;
        current->next=NULL;
    }
}

void splitFirstLast(struct node*& head, struct node*& second, int a) {
    struct node* current = head;
    struct node* prev = NULL;

   while (current != NULL && current->data !=a) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        
        second = current;
        if (prev != NULL) {
        	prev->next = NULL;
        } else {
            head = NULL;
        }
    }
}

int main() {
    insert();
    display();
    search();

    int a;
    cout << "Enter the value to split the list at: ";
    cin >> a;

    struct node* secondLastFirst = NULL;
    splitLastFirst(head, secondLastFirst, a);

    cout << "\nFirst Linked List (Desired element as the last element): ";
    struct node* temp1 = head;
    while (temp1 != NULL) {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    cout << "\nSecond Linked List: ";
    struct node* temp2 = secondLastFirst;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }

    struct node* secondFirstLast = NULL;
    splitFirstLast(head, secondFirstLast, a);

    cout << "\n\nFirst Linked List (Desired element as the first element): ";
    struct node* temp3 = head;
    while (temp3 != NULL) {
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }

    cout << "\nSecond Linked List: ";
    struct node* temp4 = secondFirstLast;
    while (temp4 != NULL) {
        cout << temp4->data << " ";
        temp4 = temp4->next;
    }

    return 0;
}

