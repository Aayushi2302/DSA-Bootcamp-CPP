#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	int flag;
};

void removeLoop(Node*, Node*);

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

void detectandremoveloop(Node** head_ref){
	Node* curr = (*head_ref);
	Node* prev = (*head_ref);
	while(curr != NULL){

		if(curr->flag == 1){
			prev->next = NULL;
			cout<<"Loop removed successfully";
			return;
		}

		curr->flag = 1;

		prev = curr;
		curr = curr->next;
	}

	cout<<"No loop detected"<<endl;

}

void detectloopandremove(Node* head){
	Node* slow_ptr = head;
	Node* fast_ptr = head;
	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if(slow_ptr == fast_ptr){
			removeLoop(slow_ptr, head);
			cout<<"Loop removed successfully"<<endl;
			return;
		}
	}
	cout<<"No loop found"<<endl;
}
void removeLoop(Node* loop_node, Node* head){
	int k = 1;
	Node* ptr1 = loop_node;
	Node* ptr2 = loop_node;

	while(ptr1->next != ptr2){
		ptr1 = ptr1->next;
		k++;
	}

	ptr1 = head;
	ptr2 = head;

	for(int i = 0; i < k; i++){
		ptr2 = ptr2->next;
	}

	while(ptr1 != ptr2){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	while(ptr1->next != ptr2){
		ptr1 = ptr1->next;
	}

	ptr1->next = NULL;
	return;
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
	detectloopandremove(head);
	Node* ref = head;
	int i = 1;
	while(i < 6){
		ref = ref->next;
		i++;
	}
	ref->next = head;
	detectloopandremove(head);
	display(head);
}