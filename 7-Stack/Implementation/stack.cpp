#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top = -1;
    public:
        Stack(int n){
            size = n;
            arr = new int[n];
        }
        void push(int a){
            if(top!=size-1)
                arr[++top] = a;
            else cout<<endl<<"Stack Overflowed!!"<<endl;
        }
        void pop(){
            if(!isEmpty()){
                top--;
                cout<<"Element Popped Successfully!!"<<endl;
            }  
            else cout<<endl<<"Stack is already Empty!!"<<endl;
        }
        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
        void print(){
            for(int i=0;i<=top;i++)  cout<<arr[i]<<" ";
            cout<<endl;
        }

};

int main(){

    int size,num,choice_1;
    char choice_2;

    cout<<"Enter the size of stack : ";
    cin>>size;
    Stack S(size);

    do{
        cout<<endl<<"Things to do : "<<endl;
        cout<<"1.Push an element"<<endl;
        cout<<"2.Pop an element"<<endl;
        cout<<"3.Check if the stack is empty"<<endl;
        cout<<"4.Print the stack"<<endl;
        cout<<"5.Exit"<<endl;

        cout<<"Enter your choice : "<<endl;
        cin>>choice_1;

        switch(choice_1){

            case 1  :   cout<<"Enter value to push : ";
                        cin>>num;
                        S.push(num); 
                        break;
            case 2  :   S.pop();
                        break;
            case 3  :   {
                            int check = S.isEmpty();
                            if(check == 1) cout<<"Stack is Empty!!"<<endl;
                            else    cout<<"Stack is not Empty"<<endl;
                            break;
                        }
            case 4  :   S.print();
                        break;
            case 5  :   break;
            default :   cout<<"Wrong Choice !!"<<endl;
        }
    
        cout<<"Do you want to perform more task on stack(Y/N) : ";
        cin>>choice_2;

    }while(choice_2 == 'Y' || choice_2 == 'y');
    
    return 0;
}
