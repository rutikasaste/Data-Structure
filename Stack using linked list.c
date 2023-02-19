#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
int countNode =0;

struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data : \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
}

void addNode(){
    struct Node *newNode = createNode();
    if(head == NULL){
        head =newNode ;
    }
    else{
        newNode ->next =head ;
        head =newNode ;
    }
}
int eleCount (){
    struct Node *temp =head;
    int count = 0;
    while(temp !=NULL){
        count ++ ;
        temp =temp ->next ;
    }
    return count ;
}

bool isFull(){
    if(eleCount() == countNode){
        return true ;
    }
    else{
        return false ;
    }
}

int push (){
    if(isFull()){
        return -1 ;
    }
    else{
        addNode();
        return 0;
    }
}

bool isEmpty(){
    if(head == NULL){
        return true ;
    }
    else{
        return false ;
    }
}

int pop(){
    if(isEmpty()){
        return -1 ;
    }
    else{
        int val;
        val =head ->data ;
        struct Node *temp =head ;
        head =head->next ;
        free(temp);
        return val;
    }
}
int peek(){
    if(isEmpty()){
        return -1 ;
    }
    else{
        return head->data ;
    }
}
int display (){
    if(isEmpty()){
     printf("Stack is Empty \n");
    }
    else{
        struct Node *temp =head ;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp= temp->next ;
        }
    }
}

void main()
{
    printf("Enter Size\n");
    scanf("%d", &countNode);
    char choice;
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.isEmpty\n");
        printf("5.isFull\n");
        printf("6.display\n");

        int ch;
        printf("Enter Choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int ret ;
            ret  =push();
            if(ret == -1){
                printf("Stack overflow \n");
            }
        }
            break;
        case 2:
        { int ret ;
        ret = pop();
        if(ret == -1){
            printf("Stack is Underflow \n");
        }
        else{
            printf("%d popped \n",ret);
        }
        }
        break;
        case 3:
       {
        int ret = peek();
        if(ret == -1){
            printf("Stack UnderFlow\n");
        }
        else{
            printf("%d\n",ret);
        }
       }
        break;
        case 4:
            {
                bool ret =isEmpty();
                if(ret == true){
                    printf("Stack is Empty\n");
                }
                else{
                    printf("Stack is not Empty\n");
                }
            }
            break;
        case 5:
            {
                bool ret =isFull();
                if(ret ==true){
                    printf("Stack is Full\n");
                }
                else{
                    printf("Stack is not full\n");
                }
            }
            break;
        case 6:
            display();
            break;
        default:
            printf("Wrong input\n");
        }
        getchar();
        printf("Do you want to continue ? \n");
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
}
