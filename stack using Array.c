/*A stack is a linear data structure, a collection of items of the same type.

In a stack, the insertion and deletion of elements happen only at one endpoint.
The behavior of a stack is described as “Last In, First Out” (LIFO).
Here Top = -1 ;
here 3 operations are there - push (); pop();peek()

Types Of Stack :-
1)Register Stack: This type of stack is also a memory element present in the memory unit and can handle a small amount of data only.
The height of the register stack is always limited as the size of the register stack is very small compared to the memory.
2)Memory Stack: This type of stack can handle a large amount of memory data.
The height of the memory stack is flexible as it occupies a large amount of memory data.

Advantages:-
Stack helps in managing data that follows the LIFO technique.
Stacks are be used for systematic Memory Management.
It is used in many virtual machines like JVM.

DisAdvantages:-
Stack memory is of limited size.
The total of size of the stack must be defined before.
If too many objects are created then it can lead to stack overflow.

Application:-
Infix to Postfix conversion.
Undo function in any text editor.

real time Applications:
CD/DVD stand.
Stack of books in a book shop.
Undo and Redo mechanism in text editors.
The history of a web browser is stored in the form of a stack.
Call logs, E-mails, and Google photos in any gallery are also stored in form of a stack.
*/

#include <stdio.h>
#include <stdbool.h>
int top = -1;
int size = 0;
int flag = 0;

bool isFull(){
    if (top == size -1){
        return true ;
    }
    else{
        return false ;
    }
}
int push(int stack[]){
    if(isFull()){
        return -1 ;
    }
    else{
        top ++ ;
        printf("Enter data \n");
        scanf("%d",&stack[top]);
        return 0;
    }
}
bool isEmpty(){
    if(top == -1){
        return true ;
    }
    else{
        return false ;
    }
}
int pop (int stack[]){
    if(isEmpty()){
        flag =0 ;
        return -1 ;
    }
    else{
        int val = stack[top];
        top -- ;
        flag = -1 ;
        return val ;
    }
}
int peek (int stack[]){
    if(isEmpty()){
        flag =0 ;
        return -1 ;
    }
    else{
        /*for(int i=top;i>=0;i--){
            printf("|%d|->",stack[i]);
        }
        */
       int val = stack[top];
        flag = -1;
        return val ;
    }
}
void main()
{
    printf("Enter size for stack \n");
    scanf("%d", &size);
    int stack[size];
    char choice;
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek \n");
        printf("4.isEmpty\n");
        printf("5.isFull \n");

        int ch;
        printf("Enter Choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int ret;
            ret = push(stack);
            if (ret == -1)
            {
                printf("stack overflow \n");
            }
        }
        break;
        case 2:
        {
            int ret;
            ret = pop(stack);
            if (ret == -1)
            {
                printf("Stack Underflow \n");
            }
            else{
                printf("%d popped \n",ret);
            }
        }
        break;
        case 3:
        {
            int ret;
            ret = peek(stack);
            if (flag == 0)
            {
                printf("Stack is empty \n");
            }
            else
            {
                printf("%d\n", ret);
            }
        }
        break;
        case 4:
        {
            bool ret = isEmpty();
            if (ret)
            {
                printf("Stack is empty \n");
            }
            else
            {
                printf("stack is not empty \n");
            }
        }
        break;
        case 5:
        {
            bool ret = isFull();
            if (ret)
            {
                printf("stack is full \n");
            }
            else
            {
                printf("stack is not full \n");
            }
        }
        break;
        default:
            printf("Wrong input \n");
        }
        getchar();
        printf("Do you want to continue ? \n");
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
}
