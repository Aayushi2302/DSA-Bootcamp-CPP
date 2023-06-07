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

void swapNodes(struct Node** head_ref, int x, int y){

	if(x == y){
		return;
	}

	struct Node *currX = (*head_ref), *prevX = NULL;
	while(currX && currX->data != x){
		prevX = currX;
		currX = currX->next;
	}

	struct Node *currY = (*head_ref), *prevY = NULL;
	while(currY && currY->data != y){
		prevY = currY;
		currY = currY->next;
	}

	if(prevX == NULL){
		(*head_ref) = currY;
		struct Node* nextY = currY->next;
		currY->next = currX->next;
		prevY->next = currX;
		currX->next = nextY;
		return;
	}
	if(prevY == NULL){
		(*head_ref) = currX;
		struct Node* nextX = currX->next;
		currX->next = currY->next;
		prevX->next = currY;
		currY->next = nextX;
		return;
	}

	struct Node* next = currX->next;
	prevX->next = currY;
	prevY->next = currX;
	currX->next = currY->next;
	currY->next = next;
	return;
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
	printf("\n");
	swapNodes(&head, 2, 4);
	display(head);
	
	
	return 0;
}
