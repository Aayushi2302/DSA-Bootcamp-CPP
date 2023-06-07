#include<bits/stdc++.h>
using namespace std;
#include "LinkedListTemplate.cpp" //this file can be found in this repo's->LinkedList->implementation-> LinkedListTemplate.cpp
void splitMidLL(Node *head, Node *&mid , Node *&last);
Node* merge2SortedListt(Node * &head1, Node* &head2);


void LLmergeSort(Node ** head){
    Node *subList1;
    Node *subList2;

    if ((*head) == nullptr || (*head)-> Next == nullptr)
    {
        return;
    }
    

    splitMidLL(*head,subList1,subList2 );
    
    LLmergeSort(&subList1);
    LLmergeSort(&subList2);
    (*head) = merge2SortedListt(subList1,subList2);
}
Node* merge2SortedListt(Node * &head1, Node* &head2){
    Node *finalHead  = nullptr;
    if (head1 -> data < head2 -> data)
    {
        finalHead = head1;
        head1 = head1 -> Next;
    }
    else{
        finalHead = head2;
        head2 = head2  -> Next;
    }
    Node * finalTail = finalHead;
    while (head1 && head2)
    {
        if (head1 -> data < head2 -> data)
        {
            finalTail -> Next = head1;
            head1 = head1 -> Next;
            finalTail = finalTail -> Next;
        }
        else{
            finalTail -> Next = head2;
            head2 = head2 -> Next;
            finalTail = finalTail -> Next;
        }
    }
    if (!head1)
    {
        finalTail -> Next = head2;
    }
    if (!head2)
    {
        finalTail -> Next = head1;
    }
    head1 = finalHead;
    return head1;
}

void splitMidLL(Node *head, Node *&subar1 , Node *&subar2){
    Node* slow = head;
    Node* fast = head -> Next;

    while (fast)
    {
       fast = fast -> Next;
       if(fast){
           fast = fast -> Next;
           slow = slow -> Next;
        }
    }  
    //now mid points at mid element, but we want it to point at 
    //next element. Also, we need to split it. so mid-> next = null;
    subar1 = head;
    subar2 = slow -> Next;
    slow ->Next = nullptr;
}


int main(){
    Node* head1 = takeinput();
    LLmergeSort(&head1);
    Printlist(head1);
    
return 0;
}
