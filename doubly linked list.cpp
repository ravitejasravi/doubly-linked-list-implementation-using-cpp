#include<iostream>
using namespace std;

class Node
{
	public:
			int data;
			Node* prev;
			Node* next;
			
			Node(int data)
			{
				this -> data = data;
				this -> prev = NULL;
				this -> next = NULL;
			}
};

void print(Node* &head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp -> data<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

void insertAtHead(Node* &head, int data)
{
	Node* temp = new Node(data);
	temp -> next = head;
	head -> prev = temp;
	head = temp;
}

void insertAtTail(Node* &tail, int data)
{
	Node* temp = new Node(data);
	tail -> next = temp;
	temp -> prev = tail;
	tail = temp; 
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data)
{
	if(position == 1)
	{
		insertAtHead(head,data);
	}
	else
	{
		
		Node* temp = head;
		
		for(int i = 1; i < position - 1; i++)
		{
			temp = temp -> next;
		}
		
		if(temp -> next == NULL)
		{
			insertAtTail(tail,data);
		}
		else
		{
			Node* node = new Node(data);
			node -> next = temp -> next;
			temp -> next -> prev = node;
			node -> prev = temp;
			temp -> next = node;
		}

	}
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	head = head -> next;
	temp -> next -> prev = NULL;
	temp -> next = NULL;
	delete temp;
}

void deleteAtTail(Node* &tail)
{
	Node* temp = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	temp -> prev = NULL;
	delete temp;
	
}

void deleteAtPosition(Node* &tail, Node* &head, int position)
{
	if(position == 1)
	{
		deleteAtHead(head);
		return;
	}
	
	Node* current_node = head;
	Node* previous_node = head;	
	
	for(int i = 1; i < position; i++)
	{
		previous_node = current_node;
		current_node = current_node -> next; 
	}
	
	if(current_node -> next == NULL)
	{
		deleteAtTail(tail);
		return;
	}
	
	previous_node -> next = current_node -> next;
	current_node -> next -> prev = current_node -> prev;
	current_node -> next = NULL;
	current_node -> prev = NULL;
	delete current_node;
	
}

int main()
{
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	insertAtTail(tail,20);
	insertAtTail(tail,30);
	insertAtTail(tail,40);
	insertAtPosition(tail,head,2,50);
	
	cout << "Head " << head -> data<<endl;
	cout << "Tail " << tail -> data<<endl;
	print(head);
	
//	deleteAtHead(head);
//	deleteAtTail(tail);
	deleteAtPosition(tail,head,5);
	cout << "Head " << head -> data<<endl;
	cout << "Tail " << tail -> data<<endl;
	
	
	print(head);
	
	return 0;
}
