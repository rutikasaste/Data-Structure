/*Singular linked List:-
Linked List is a linear data structure . E.g . Treasure Hunt
Every linked list has two parts,
the data section and the address section that holds the address of the next element in the list, which is called a node.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// For creating newNode
struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data: \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

// Add Node at last

void addNode()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Count Nodes in Linked List

int countNode()
{
    int count = 0;
    if (head == NULL)
    {
        printf("Empty Linked List \n");
        return -1;
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

// Add node at First Position

void addFirst()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Add Node at any Position

int addAtPos(int pos)
{
    int count = countNode();
    if (pos <= 0 || pos > count + 1)
    {
        printf("Invalid position \n");
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

// Delete First Node

int delFirst()
{
    if (head == NULL)
    {
        printf("Linked List is Empty \n");
        return -1;
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *temp = head;
            head = temp->next;
            free(temp);
        }
        return 0;
    }
}

// Delete Last node

int delLast()
{
    if (head == NULL)
    {
        printf("Enter Linked List is Empty \n");
        return -1;
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
        return 0;
    }
}

// Delete at Position

int delAtPos(int pos)
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
                pos--;
            }
            struct Node *easy = temp->next;
            temp->next = temp->next->next;
            easy->next = NULL;
            free(easy);
        }
        return 0;
    }
}
void printLL()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("|%d| ->", temp->data);
        temp = temp->next;
    }
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
        printf("5.delLast\n");
        printf("6.delAtPos\n");
        printf("7.printLL\n");

        int ch;
        printf("Enter your choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addNode();
            printLL();
            break;
        case 2:
            addFirst();
            printLL();
            break;
        case 3:
        {
            int pos;
            printf("Enter no :\n");
            scanf("%d", &pos);
            addAtPos(pos);
            printLL();
        }
        break;
        case 4:
            delFirst();
            printLL();
            break;
        case 5:
            delLast();
            printLL();
            break;
        case 6:
        {
            int pos;
            printf("Enter no :\n");
            scanf("%d", &pos);
            delAtPos(pos);
            printLL();
        }
        break;
        case 7:
            printLL();
            break;
        default:
            printf("Wrong Choice \n");
            break;
        }
        getchar();
        printf("Do you want to continue?\n");
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
}
