#include<iostream>
using namespace std;

//Node Class --
class node{
	public:
		int data;
		node *next;
		
		//Parametrixe Constructor to create node
		node(int num){
			data = num;
			next = NULL;
		}	
};

//Function 1 :  To create node at end of head node
void insertAtTail(node *&head,int newValue){
	
	node *ptr = head;
	node *newNode = new node(newValue);
	
	if(head->next == NULL)
	head->next = newNode;
	
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
	
}

//Function 2 :  To create node at starting of head node
void insertAtHead(node *&head,int newValue){
	
	node *newNode = new node(newValue);
	newNode->next = head;
	head = newNode;
}

//Function 3 :  To create node at particular position(position is judged by data value of node)
void insertAtPosition(node *&head,int position,int newValue){
	
	node *ptr = head;
	node *newNode = new node(newValue);
	int flag = 0;
	
	while(ptr!=NULL){
		if(ptr->data == position){
			flag++;
			newNode->next = ptr->next;
			ptr->next = newNode;
			break;
		}
		ptr = ptr->next;
	}
	
	if(flag  == 0)	
		cout<<endl<<"Value entered by you does not exist in the linked list!!"<<endl;
}

//Function 4 : To delte a node from the end of Linked List
void deleteAtTail(node *&head){
	
	node *ptr = head;
	node *prev = head;
	
	//ptr = ptr->next;
	while(ptr->next != NULL){
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	delete ptr;
}

//Function 5 : To delete a node from the starting of linked list
void deleteAtHead(node *&head){
	node *prev = head;
	head = head->next;
	delete prev;
}

//Function 6 : To delete a node at particular postion(position is judges by data value of node)
void deleteAtPosition(node *&head,int position){
	
	node *ptr = head;
	node *prev = head;
	int flag = 0;
	
	while(ptr != NULL){
		if(ptr->data == position){
			flag++;
			prev->next = ptr->next;
			delete ptr;
			break;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	
	if(flag == 0)
		cout<<endl<<"Value entered by you does not exist in the linked list!!"<<endl;
}

//Function 7 : To display the linked list
void display(node *&head){
	node *ptr = head;
	while(ptr != NULL){
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	if(ptr == NULL)
		cout<<"NULL"<<endl;
}


int main(){
	
	int input;
	cout<<endl<<"Enter a value to create a node : ";
	cin>>input;
	node *n1 = new node(input);
	
	char ch;
	do{
		cout<<endl<<"You can do the following tasks with Linked List :"<<endl;
		cout<<"1.Insertion at Tail"<<endl;
		cout<<"2.Insertion at Head"<<endl;
		cout<<"3.Insertion at Particular Position"<<endl;
		cout<<"4.Deletion at Tail"<<endl;
		cout<<"5.Deletion at Head"<<endl;
		cout<<"6.Deletion at Particular Position"<<endl;
		cout<<"7.Display"<<endl;
		
		int choice;
		cout<<endl<<"Enter your choice : ";
		cin>>choice;
		
		cout<<endl;
		
		switch(choice){
			
			case 1 :	int value1;
						cout<<"Enter a value to insert in the Linked List : ";
						cin>>value1;
						insertAtTail(n1,value1);
						break;
			
			case 2 :	int value2;
						cout<<"Enter a value to insert in the Linked List : ";
						cin>>value2;
						insertAtHead(n1,value2);
						break;	
						
			case 3 :	int value3,position;
						cout<<"Enter the value of node after which you want to insert new node : ";
						cin>>position;
						cout<<endl<<"Enter a value to insert in the Linked List : ";
						cin>>value3;
						insertAtPosition(n1,position,value3);
						break;	
			
			case 4 :	deleteAtTail(n1);
						break;	
						
			case 5 :	deleteAtHead(n1);
						break;
			
			case 6 :	int value4;
						cout<<"Enter the value of node which you want to delete : ";
						cin>>value4;
						deleteAtPosition(n1,value4);
						break;
							
			case 7 :	display(n1);
						break;
		}
		
		cout<<endl<<"Do you want to perform more tasks(Y/N) : ";
		cin>>ch;
			
	}while(ch == 'Y' || ch == 'y');
	
	
	return 0;
}