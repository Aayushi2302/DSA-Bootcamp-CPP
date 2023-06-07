#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *Next;

    Node(int data){
        this -> data = data;
        this -> Next = nullptr;
    }
};

void Printlist(Node *h1){
    Node *temp = h1;
    while (temp != nullptr )
    {
        cout<<temp->data<<" ";
        temp = temp->Next;
    }
    cout<<endl;
}

Node *takeinput(){
    int data;
    cin>>data;
    Node *head = nullptr;
    Node* temp = head;
    //1, 2, 3
    //temp -> n3
    while (data != -1)
    {
        if (head == nullptr) //for the first node we'll change the head pointer 
        {                    // after that we will not change head

            temp = new Node(data);
            head = temp;
        }//this upper block executes only once
        
        else{
            temp ->Next = new Node(data);
            temp = temp -> Next;
        }
        cin>>data;
    }
   // Printlist(head);
    return head;
}

int listLength(Node *head){
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count ++;
        temp = temp -> Next;
    }
    return count;
}

int printNode(Node* head, int n){
    // n++;
    Node * temp = head;

    while(temp && n){
        temp = temp -> Next;
        n--;
    }
    if (!n)
    {
        cout<<temp->data<<endl;
    }
    return (temp -> data);
    
}

void Push(Node** head, int data)
{
    Node *newNode = new Node(data);

    newNode ->Next = (*head);

    (*head) = newNode;
}

void Pushati(Node** head, int data, int i){
    Node* temp = *head;
    i--;
    while (i-- > 0)
    {
        temp = temp ->Next;
    }
    Node* temp2 = temp ->Next;
    if(i == -2){
        Push(head, data);
    }
    else{
        Node *newNode = new Node(data);
        newNode ->Next = temp ->Next;
        temp ->Next = newNode;
    }
    
}

void Append(Node** head, int data){
    Node * temp = *head;
    while (temp->Next)
    {
        temp = temp ->Next;
    }
    Node *newNode = new Node(data);
    temp ->Next = newNode;
    
}

void Deletenode(Node * &head, int i){
        Node* temp = head;
    if (i == 0)
    {
        head = head ->Next;
        delete temp;
    }
    else{
        i--;
        while (i--)
        {
            temp = temp -> Next;
        }
        Node * temp2 = temp -> Next;
        temp -> Next = temp2 -> Next;
        delete [] temp2;
        
    }
    
}

int FindNode(Node * head, int x){
    Node * temp = head;
    for (int i = 0; temp ; i++)
    {
        if (temp ->data == x)
        {
            return i;
        }
        temp = temp->Next;
    }
    return -1;
    
}

void deleteDuplicates(Node *head){
    int i = 0;
    Node* temp = head;
    while (temp)
    {
        if ((temp -> data) == (temp ->Next ->data))
        {
            Deletenode(head,i+1);
        }
        temp = temp ->Next;
        i++;
        
    }
    
}

void printReverseList(Node * head){
    Node * temp = head;
    if(!temp){
        return;
    }
    printReverseList(temp -> Next);
    cout<<temp->data<<" ";
}

void merge2SortedList(Node * &head1, Node* &head2){
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

}

void ReverseLL(Node **head){
    Node* prevNode = nullptr;
    Node * currentNode = *head;
    Node* nextNode = nullptr;
    
    while (currentNode)
    {
        nextNode = currentNode ->Next; //stores next address
        currentNode -> Next = prevNode;//reverses the current node
        prevNode = currentNode;//sets new previous node
        currentNode = nextNode;//move the current forward
    }
    *head = prevNode;

}

