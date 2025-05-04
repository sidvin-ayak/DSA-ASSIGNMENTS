//Program to implement ListADT using a singly linked list, involving operations such as push(), peek(), display(), pop()
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class SinglyLinkedList{
    private:
        
        int n;
        struct node{
            int data;
            struct  node *next;
            }; 
    
        struct node *head;
    
    public:
           
        
        SinglyLinkedList(){
            head=NULL;
        }
        int peek();
        int display();
        int pop();
        int push(char);

    
};

// A menu is function is implemented to eliminate the need for using printf statement multiple times and long printed statements

void menu(){

    cout<<"1. Push a user-given value to the top of the list "<<endl;
    cout<<"2. Display the data within the list"<<endl;
    cout<<"3. Pop the value at the top of the list"<<endl;
    cout<<"4. Preview the value on top of the list"<<endl;
    cout<<"5. EXIT"<<endl;
    cout<<"\n   Enter your choice:\t";

}

//Main body of the program begins here

int main(){
    SinglyLinkedList obj;
    int choice=0;
    int data;

    while(1){
        do{
        menu();
        scanf("%d",&choice);
        switch(choice){

            //When the input received is 1, push() function is implemented
            case 1:

            char data;
            printf("Enter the data to be entered into the singlylinkedlist:\t");
            cin>>data;
            obj.push(data);
            break;
            
            
            //When the input received is 2, display() function is implemented
            case 2:
            
            obj.display();
            break;

            //When the input received is 3, pop() is implemented
            case 3:

            obj.pop();
            break;

            //When the input received is 4, peek() is implemented
            case 4:

            obj.peek();
            break;

            //When the input received is 5, the loop is terminated
            case 5:

            break;

        }
    } while (choice==5); 
    }
          
     
}

/* The push() function works by receiving a character argument from the user and pushes it to the top of the list. The following entries are appended to 
   the list in the same manner. When the overflow condition is reached, no input is accepted into the list and corresponding logical error statement is
   printed for the user to view what the specified issue is. */

int SinglyLinkedList::push(char data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return 0;
}

/* The pop() function works by deleting the character at the top of the list at any given time. Only the element at the top of the list is popped and
   removed from the list. When underflow condition is reached, no input is accepted into the list and corresponding logical error statement is
   printed for the user to view what the specified issue is. */

int SinglyLinkedList::pop(){
    if(head==NULL){
        cout<<"Empty list(Underflow)\n"<<endl;
        return 0;
    }
    else{
        node *del = head;
        head=head->next;
        del->next = NULL;
        char value = del->data;
        free(del);
        return value;
    }
    return 0;
}


/* The display() functions allows the user to perform a display operation on the given stack and thereby, 
   viewing the entire stack at once unlike the peek() function, where only one element at the top can be viewed.
   When empty, the stack displays a logical error statement concerning the absence of any data within the stack at the said moment. */

int SinglyLinkedList::display(){
    if(head==NULL){
        cout<<"LIST IS EMPTY!!!"<<endl;
    }
    else{
        node *temp = head;
        cout<<"List:"<<endl;
        while(temp->next!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    return 0;
}

/* The peek() function enables the user to view the element at the top of the list at any given time post compiling the program. When the list is empty, 
   no value is there to be displayed and hence, a statement specifying the logical nuance of the porgram is displayed. */

int SinglyLinkedList::peek(){
    if(head==NULL){
        cout<<"EMPTY list"<<endl;
        return -1;
    }
    else{
        char peek = head->data;
        cout<<"PEEK:\t"<<peek<<endl;
        return peek;
    }
    
}

