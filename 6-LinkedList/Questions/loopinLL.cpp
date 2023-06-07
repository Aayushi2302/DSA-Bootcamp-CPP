#include<iostream>
using namespace std;
class Node{
public:
	int data;
	int flag;
	Node* next;
};
void append(Node** head_ref, int value){
	Node* n = new Node();
	Node* curr = (*head_ref);
	n->data = value;
	n->next = NULL;

	if((*head_ref) == NULL){
		(*head_ref) = n;
		return;
	}

	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = n;

}

void display(Node* head){
	Node* n = head;
	while(n != NULL){
		cout<<n->data<<endl;
		n = n->next;
	}
}
bool detectloop(Node** head_ref){
	Node* curr = (*head_ref);
	while(curr != NULL){

		if(curr->flag == 1){
			return true;
		}

		curr->flag = 1;
		curr = curr->next;
	}
	return false;
}

int distance(Node* first, Node* last){
	int counter = 0;
	Node* curr = first;
	while(curr != last){
		counter++;
		curr = curr->next;
	}
}

bool detectloopstorelength(Node** head_ref){
	Node* first = (*head_ref);
	Node* last = (*head_ref);
	int curr_length = 0;
	int prev_length = -1;
	while(last != NULL && curr_length > prev_length){
		prev_length = curr_length;
		curr_length = distance(first, last);
		last = last->next;
	}
	if(last == NULL){
		return false;
	}
	else
		return true;
}
int main(){
	Node* head = NULL;
	//Node* obj = new Node();

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	display(head);
	cout<<"Before looping: "<<detectloop(&head)<<endl;
	cout<<"Before looping: "<<detectloopstorelength(&head)<<endl;
	Node* ref = head;
	int i = 1;
	while(i < 3){
		ref = ref->next;
		i++;
	}
	ref->next = head;
	cout<<"After looping: "<<detectloop(&head);
	cout<<"After looping: "<<detectloopstorelength(&head);

}