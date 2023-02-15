/*Doubly Circular Linked List : -
Circular doubly linked list is a more complexed type of data structure in which a node contain pointers to its previous node as well as
 the next node. Circular doubly linked list doesn't contain NULL in any of the node. The last node of the list contains the address of the first 
 node of the list.The first node of the list also contain address of the last node in its previous pointer.
 
Advantages :-
1)List can be traversed from both directions i.e. from head to tail or from tail to head.
2)Efficient insertion and deletion.
3)Ability to handle circular buffers.

DisAdvantages :-
1)Requires additional memory.
2)If not used properly, then the problem of infinite loop can occur.
3)Difficulty in detecting the end.

Application :-
1)Music Player.
2)Can be used in game development to implement a loop of game objects
 */

#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    int data ;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(){
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));
    newNode ->prev = NULL ;
    int data ;
    printf("Enter Data : \n");
    scanf("%d",&newNode->data);
    newNode->next =NULL;
    return newNode ;
}

void addNode(){
    struct Node *newNode = createNode();
    if(head==NULL){
        head = newNode ;
        head ->prev =head ;
        head ->next =head ;
    }
    else{
        struct Node *temp =head;
        while(temp->next != head){
            temp =temp->next ;
        }
        temp ->next =newNode ;
        newNode->prev =temp ;
        newNode->next = head ;
        head ->prev = newNode;

        /*head->prev->next = newNode;
         newNode->prev =head ->prev ;
         newNode ->next =head ;
         head ->prev = newNode;*/
    }
}
void addFirst(){
    struct Node *newNode = createNode();
    if(head ==NULL){
        head = newNode;
        head ->prev =newNode ;
        head->next = newNode;
    }
    else{
        struct Node *temp =head;
        while(temp ->next !=head){
            temp =temp->next ;
        }
        newNode ->next =head;
        newNode->prev = head->prev ;
        head ->prev =newNode->next ;
        head =newNode ;
        newNode->prev ->next =head;

    }
}
int countNode(){
    int count = 0;
    if(head ==NULL){
        printf("Empty Linked List \n");
        return -1;
    }
    else{
        struct Node *temp =head;
        while(temp->next!=head){
            count ++ ;
            temp =temp ->next ;
        }
        return count+1 ;
    }
}

int addAtPos(int pos){
   int count = countNode();
   if(pos<= 0 ||pos > count +1){
    printf("Invalid Position \n");
    return -1 ;
   }
   else{
    if(pos==1){
        addFirst();
    }
    else if(pos==count +1){
        addNode();
    }
    else{
        struct Node *newNode = createNode();
        struct Node *temp =head ;
        while(pos -2){
            temp =temp ->next ;
            pos-- ;
        }
        newNode->next =temp->next ;
        newNode->prev =temp;
        temp->next->prev =newNode;
        temp->next =newNode ;
    }
    return 0;
   }
}
int delFirst(){
    if(head ==NULL){
        printf("Empty Linked List\n");
        return -1 ;
    }
    else{
        if(head->next ==head){
            free(head);
            head =NULL;
        }
        else{
            head = head->next ;
            head->prev =head->prev ->prev ;
            free(head->prev->next);
            head->prev->next =head ;
        }
        return 0;
    }
}
int delLast(){
    if(head ==NULL){
        printf("Empty Linked List \n");
        return -1;
    }
    else{
        if(head->next ==head){
            free(head);
            head =NULL;
        }
        else{
            head ->prev =head ->prev->prev ;
            free(head->prev->next);
            head->prev->next = head ;
        }
        return 0;
    }
}
int delAtPos (int pos)
{
    int count = countNode();
    if (pos <= 0 || pos > count - 1)
    {
        printf("Invalid Position");
        return -1;
    }
    else
    {
        if (pos == 1)
        {
            delFirst();
        }
        else if (pos == count + 1)
        {
            delLast();
        }
        else
        {
            struct Node *temp = head;
            while (pos - 2)
            {
                temp = temp->next;
                pos-- ;
            }
            temp->next = temp->next->next;
            free(temp->next->prev);
            temp->next->prev = temp;
        }
        return 0;
    }
}
void printDCLL(){
struct Node *temp = head ;
while(temp->next !=head){
    printf("|%d|->",temp->data);
    temp =temp->next ;
}
 printf("|%d|\n",temp->data);
}

void main(){
    char choice ;
    do{
        printf("1.addNode\n");
        printf("2.addFirst\n");
        printf("3.addAtPos\n");
        printf("4.delFirst\n");
        printf("5.delLast\n");
        printf("6.delAtPos\n");
        printf("7.printDCLL\n");

        int ch;
        printf("Enter choice :\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            addNode();
            printDCLL();
            break;
            case 2:
            addFirst();
            printDCLL();
            break;
            case 3:
            {
                int pos ;
                printf("Enter the position \n");
                scanf("%d",&pos);
                addAtPos(pos);
                printDCLL();
            }
            break;
            case 4:
            delFirst();
            printDCLL();
            break ;
            case 5:
            delLast();
            printDCLL();
            break ;
            case 6:
            {
                int pos ;
                printf("Enter the position \n");
                scanf("%d",&pos);
                delAtPos(pos);
                printDCLL();
            }
            break;
            case 7:
            printDCLL();
            break;
            default:
            printf("Wrong Choice \n");
            break;
        }
        getchar();
        printf("Do you want to continue \n");
        scanf("%c",&choice);
    }
    while(choice == 'Y'|| choice == 'y');
}
