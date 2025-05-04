/* Program to implement StackADT, using a character array of size 5, which involves the usage of the functions 
   to append values, delete values, preview the value on top of the stack, to display it etc. */
   #include<cstdio>
   #include<iostream>
   
   using namespace std;
   
   class stack{
   
       private:
   
           char arr[5];
           int top;
   
       public:
   
           stack(){
               top=-1;
           };
           int peek();
           int display();
           int pop();
           int push(char);
   };
   
   // A menu is function is implemented to eliminate the need for using printf statement multiple times and long printed statements
   
   void menu(){
   
       cout<<"1. Push a user-given value to the top of the stack "<<endl;
       cout<<"2. Display the data within the stack"<<endl;
       cout<<"3. Pop the value at the top of the stack"<<endl;
       cout<<"4. Preview the value on top of the stack"<<endl;
       cout<<"5. EXIT"<<endl;
       cout<<"\n   Enter you choice:\t";
   
   }
   
   //Main body of the program begins here
   
   int main(){
       stack obj;
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
               printf("Enter the data to be entered into the stack:\t");
               cin>>data;
               obj.push(data);
               break;
               
               
               //When the input received is 2, display() function is implemented
               case 2:
               
               cout<<"\n"<<endl;
               obj.display();
               break;
   
               //When the input received is 3, pop() is implemented
               case 3:
   
               cout<<"\n"<<endl;
               obj.pop();
               break;
   
               //When the input received is 4, peek() is implemented
               case 4:
                 
               cout<<"\n"<<endl;
               obj.peek();
               break;
   
               //When the input received is 5, the loop is terminated
               case 5:
   
               break;
   
           }
       } while (choice==5); 
       }
             
        
   }
   
   /* The display() functions allows the user to perform a display operation on the given stack and thereby, 
      viewing the entire stack at once unlike the peek() function, where only one element at the top can be viewed.
      When empty, the stack displays a logical error statement concerning the absence of any data within the stack at the said moment. */
      
   int stack::display(){
   
       if(top==-1){
           cout<<"EMPTY STACK!!!"<<endl;
           return -1;
       }
       else{
           printf("\n");
           for (int i = top;i>=0 ; i--){
               cout<<arr[i]<<endl;
           }
           return 0;
       }
   }
   
   
   /* The push() function works by receiving a character argument from the user and pushes it to the top of the stack. The following entries are appended to 
      the stack in the same manner. When the overflow condition is reached, no input is accepted into the stack and corresponding logical error statement is
      printed for the user to view what the specified issue is. */
   
   int stack::push(char data){
       if(top==4){
           cout<<"STACK OVERFLOW"<<endl;
       }
       else{
           arr[top++]=data;
       }
       return 0;
   }
   
   /* The pop() function works by deleting the character at the top of the stack at any given time. Only the element at the top of the stack is popped and
      removed from the stack. When underflow condition is reached, no input is accepted into the stack and corresponding logical error statement is
      printed for the user to view what the specified issue is. */
   
   int stack::pop(){
       if(top==-1){
           cout<<"STACK UNDERFLOW"<<endl;
       }
       else{
           return arr[--top];
       }
       return 0;
   }
   
   /* The peek() function enables the user to view the element at the top of the stack at any given time post compiling the program. When the stack is empty, 
      no value is there to be displayed and hence, a statement specifying the logical nuance of the porgram is displayed. */
   
   int stack::peek(){
       if(top==-1){
           cout<<"Empty STACK"<<endl; 
       }
       else{
           printf("%d", arr[top]);
       }
       return 0;
   }
   