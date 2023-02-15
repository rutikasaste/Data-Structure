/*Singly Circular Linked List :-
Circular singly linked list is a type of data structure that is made up of nodes that are created using self referential structures.
linked list whose nodes are connected in such a way that it forms a circle.
In the circular linked list, the next pointer of the last node is not set to null but it contains the address of the first node
 thus forming a circle.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node* createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data : \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}
void addNode()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void addFirst()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
int countNode()
{
    int count = 0;
    if (head == NULL)
    {
        return -1;
    }
    else
    {   
        struct Node *temp = head;
        while (temp ->next != head)
        {
            count++;
            temp = temp->next;
        }
        return count +1;
    }
}
int addAtPos(int pos)
{
    int count = countNode();
    if (pos <= 0 || pos > count + 1)
    {
        printf("Invalid Position \n");
        return -1;
    }
    else
    {
        if (pos == 1)
        {
            addFirst();
        }
        else if (pos == count + 1)
        {
            addNode();
        }
        else
        {
            struct Node *newNode = createNode();
            struct Node *temp = head;
            while (pos - 2)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return 0;
    }
}

int delFirst()
{
    if (head == NULL)
    {
        printf("Linked List is empty \n");
        return -1;
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head->next = NULL;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            free(temp->next);
            temp->next = head;
        }
        return 0;
    }
}
int delLast(){
    if (head == NULL)
    {
        printf("Linked List is empty \n");
        return -1;
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head->next = NULL;
        }
        else{
            struct Node *temp =head ;
            while (temp ->next ->next  != head){
                temp= temp->next ;
            }
            free(temp ->next);
            temp ->next = head ;
        }
}
}
int delAtPos(int pos){
    int count = countNode();
    if(pos <= 0 || pos > count +1){
        printf("Invalid Position \n");
        return 0 ;
    }
    else{
        if(pos == 1){
            delFirst();
        }
        else if(pos == count +1){
            delLast();
        }
        else{
            struct Node *temp = head ;
            while(pos-2){
                temp = temp ->next ;
                pos -- ;
            }
            struct Node *easy = temp->next ;
            temp ->next = temp ->next ->next ;
            easy ->next =NULL;
            free(easy);
        }
        return 0;
    }
}
void printSCLL(){
        struct Node *temp = head;
        while(temp ->next != head){
            printf("|%d| ->", temp->data);
            temp = temp -> next ;
        }
        printf("|%d| ->", temp->data);
}
void main()
{
    char choice;
    do
    {
        printf("1.addNode\n");
        printf("2.addFirst\n");
        printf("3.addAtPos\n");
        printf("4.delFirst\n");
        printf("5.delAtPos\n");
        printf("6.delLast\n");
        printf("7.printSCLL\n");

        int ch;
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addNode();
            printSCLL();
            break;
        case 2:
            addFirst();
            printSCLL();
            break;
        case 3:
        {
            int pos;
            printf("Enter the position \n");
            scanf("%d", &pos);
            addAtPos(pos);
            printSCLL();
        }
        break;
        case 4:
            delFirst();
            printSCLL();
            break;
        case 5:
        {
            int pos;
            printf("Enter the Position \n");
            scanf("%d", &pos);
            delAtPos(pos);
            printSCLL();
        }
        break;
        case 6:
            delLast();
            printSCLL();
            break;
        case 7:
            printSCLL();
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
        getchar();
        printf("Do You Want to Continue ? \n");
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
}
