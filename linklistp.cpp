#include <iostream>
using namespace std;
    struct node {
        int data;
        struct node* next;
    };

    struct node* head = NULL;
    struct node* temp = NULL;

  
void insert(){
int n;  // Number of nodes you want to create
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

  void display(){  // Print the data in all the nodes
    temp = head;
    while (temp != NULL) 
	{
        cout<< temp->data<< "---> ";
        temp = temp->next;
    }
}
int search()
{
	int x;
	cout<<"\n Enter number want to search: "<<endl;
	cin>>x;   
      node* temp = head;
      int found = 0;
      int i = 0;

      if(temp != NULL) {
        while(temp != NULL) {
          i++;
          if(temp->data == x) {
            found++;
            break;
          }
          temp = temp->next;
        }
        if (found == 1) {
          cout<<x<<" is found at index = "<<i<<".\n";
        } else {
          cout<<x<<" is not found in the list.\n";
        }
      } else {
        cout<<"The list is empty.\n";
      }
    } 

void split(struct node*& head, struct node*& second, int a) {
    struct node* current = head;
    struct node* prev = NULL;

    // Traverse the linked list to find the split element
    while (current != NULL && current->data !=a) {
        prev = current;
        current = current->next;
    }

    // If the split element was found
    if (current != NULL) {
        // Set the second list's head to the element after the split element
        second = current;

        // Set the next of the first list to NULL, effectively splitting the lists
        

        // Update the head of the first list if needed
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
//    struct node* head = NULL;
//    struct node* temp = NULL;
    int a;
    
    cout << "Enter the value to split the list at: ";
    cin >> a;

    // Create your linked list here (you should have code for this)

    struct node* second = NULL;
    split(head, second, a);

    cout << "First Linked List: ";
    struct node* temp1 = head;
    while (temp1 != NULL) {
        cout << temp1->data <<" " ;
        temp1 = temp1->next;
    }

    cout << "\nSecond Linked List: ";
    struct node* temp2 = second;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
}



