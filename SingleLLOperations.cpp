#include<iostream>

using namespace std;

struct Node {
    int value;
    struct Node * next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = tail = NULL;
    }

    Node* createNode(int value)
    {
        Node *node = new Node;
        node->value = value;
        node->next = NULL;

		return node;
    }
    
    void insertFirst(int value)
    {
    	Node *newNode = createNode(value);
    	if(head == NULL)
		{
			head = newNode;
			tail = newNode;		
		}	
		else
		{
			newNode->next = head;
			head = newNode;
		}
		display();
	}
	void insertlast(int value)
	{
	 Node *newNode=createNode(value);
	 if(head==NULL)
	 {
	 	head=newNode;
	 	tail=newNode;
	 }
	 else
	 {
	 	tail->next=newNode;
	 	tail=newNode;
	 }
	 display();
		
	}
	void insertposition(int value,int pos)
	{
		Node *newNode=createNode(value);
		Node *current=head;
		Node *prev=head;
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else if(pos==1)
		{
			insertFirst(value);
		}
		else
		{
		for(int i=1;i<pos&&current!=NULL;i++)
		{
			prev=current;
			current=current->next;
			}
		if(current==NULL)
		{
			cout<<"Position not found."<<endl;
		}
		else{
		
		newNode->next=current;
		prev->next=newNode;
			display();
		}
		}
	
	}
	void deletefirst()
	{
		if(head==NULL)
		{
		cout<<"List is empty! Cannot delete!"<<endl;
		}
		else if (head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else
		{
			head=head->next;
			
		}
		display();
	}
	void deletelast()
	{
	
  	    Node *current=head;
		Node *prev=head;
		if(head==NULL)
		{
			cout<<"List is empty! Cannot delete!"<<endl;
		}
		else if (head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else
		{
		while(current->next!=NULL)
		{
			prev=current;
			current=current->next;
		}
		tail=prev;
		delete current;
		tail->next=NULL;
		
		}
		display();
	 }
    
	void deleteposition(int pos)
	{
	
        Node *current=head;
		Node *prev=head;
		if(head==NULL)
		{
			cout<<"List is empty! Cannot delete!"<<endl;
		}
		else if (head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else if(pos==1)
		{
			deletefirst();
		}
		else
		{
			for(int i=1;i<pos&&current!=NULL;i++)
			{
				prev=current;
				current=current->next;
			}
			if(current==NULL)
			{
				cout<<"Position not found."<<endl;
			}
			else
			{
			
			prev->next=current->next;
			delete current;
			
		    }  
		}display();
	}

    void display() {
        Node *current = head;

        while (current != NULL) 
		{
           	cout << current->value << "->";
        	current = current->next;
        }
        cout << "NULL" << endl;
    }


private:
    Node *head, *tail;
};


int main() 
{
	int choice, data,position;
	LinkedList ll;
	
	while(1)
	{
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" <<endl;
		cout << "3. Insert at Position" <<endl;
		cout << "4. Delete First" << endl;
		cout << "5. Delete Last" <<endl;
		cout << "5. Delete at position" <<endl;
		
		cout << "7. Display" << endl;		
		cout << "8. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1: 
				cout << "Enter the value : ";
				cin >> data;
				ll.insertFirst(data);
				break;
			case 2: 
				cout << "Enter the value : ";
				cin >> data;
				ll.insertlast(data);
				break;
			case 3: 
				cout << "Enter the value : ";
				cin >> data;
				cout<<"Enter The position :";
				cin>>position;
				ll.insertposition(data,position);
				break;
			case 4: 
				ll.deletefirst();
				break;	
			case 5: 
				ll.deletelast();
				break;
			case 6:
			     cout<<"Enter The position :";
				cin>>position;
				ll.deleteposition(position);
			case 7: 
				ll.display();
				break;
			case 8: 
				exit(0);
			default:
				cout<< "Invalid choice" << endl;
				break;
		}
	}
}
