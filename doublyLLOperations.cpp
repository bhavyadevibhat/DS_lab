#include<iostream>
using namespace std;

struct Node {
    int value;
    struct Node *rlink;
	struct Node *llink;
};

class doublylinkedlist
{
public:
    doublylinkedlist()
    {
        head = tail = NULL;
    }

    Node*createnode(int value)
    {
        Node *node = new Node;
        node->value = value;
        node -> llink=NULL;
		node -> rlink=NULL;
			
		return node;
    }
    
    void insertFirst(int value)
    {
    	Node *newnode = createnode(value);
    	if(head == NULL)
		{
			head = newnode;
			tail = newnode;		
		}	
		else
		{
			newnode->rlink=head;
			head->llink=newnode;
			head=newnode;
		}
		display();
	}
	void insertlast(int value)
	{
	 Node *newNode=createnode(value);
	 if(head==NULL)
	 {
	 	head=newNode;
	 	tail=newNode;
	 }
	 else
	 {
	 	newNode->llink=tail;
	 	tail->rlink=newNode;
	 	tail=newNode;
	 }
	 display();
		
	}
	void insertposition(int value,int pos)
	{
		Node *newNode=createnode(value);
		Node *current=head;
		Node *prev=NULL;
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
			current=current->rlink;
			}
		if(current==NULL)
		{
			cout<<"Position not found."<<endl;
		}
		else{
		newNode->llink=prev;
		newNode->rlink=current;
		prev->rlink=newNode;
		current->llink=newNode;
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
			head->rlink->llink==NULL;
			head=head->rlink;
			
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
		while(current->rlink!=NULL)
		{
			prev=current;
			current=current->rlink;
		}
		tail=prev;
		delete current;
		tail->rlink=NULL;
		
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
				current=current->rlink;
			}
			if(current==NULL)
			{
				cout<<"Position not found."<<endl;
			}
			else
			{
				
			current->rlink->llink=prev;
			prev->rlink=current->rlink;
			delete current;
		    }
			display();  
		}
	}

    void display() {
        Node *current = head;

        while (current != NULL) 
		{
           	cout << current->value << "->";
        	current = current->rlink;
        }
        cout << "NULL" << endl;
    }


private:
    Node *head, *tail;
};


int main() 
{
	int choice, data,position;
	doublylinkedlist ll;
	
	while(1)
	{
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" <<endl;
		cout << "3. Insert at Position" <<endl;
		cout << "4. Delete First" << endl;
		cout << "5. Delete Last" <<endl;
		cout << "6. Delete at position" <<endl;
		
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
