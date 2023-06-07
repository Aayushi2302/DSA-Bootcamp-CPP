#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node* next;
};

void display(struct Node* n){
	while(n!=NULL){
		printf("%d\n", n->data);
		n = n->next;
	}
}

void append(struct Node** head_ref, int value){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = (*head_ref);

	n->data = value;
	n->next = NULL;

	if((*head_ref) == NULL){
		(*head_ref) = n;
		return;
	}

	while(last->next !=NULL){
		last = last->next;
	}

	last->next = n;
}

bool linearsearch(struct Node** head_ref, int key){
	struct Node* curr = (*head_ref);
	while(curr != NULL){
		if(curr->data == key){
			return true;
		}
		curr = curr->next;
	}
	return false;
}




int main(){

	struct Node* head = NULL;

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	display(head);
	
	bool found = linearsearch(&head, 0);
	if(found == true){
		printf("Element found!!!");
	}
	else{
		printf("Element not found!!!");
	}
	return 0;
}
