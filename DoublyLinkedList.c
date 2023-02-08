/*Doubly Linked List :-
Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence.
Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to
the previous node (previous pointer).

Adv:-
1.Reversing the doubly linked list is very easy.
2.It can allocate or reallocate memory easily during its execution.
3.easiest data structure to implement.
4.Deletion of nodes is easy as compared to a Singly Linked List

DisAdvantages:-
1.It uses extra memory when compared to the array and singly linked list.
2.Since elements in memory are stored randomly, therefore the elements are accessed sequentially no direct access is allowed.
3.Traversing a doubly linked list can be slower than traversing a singly linked list.

Application :-
1.It is used in the navigation systems where front and back navigation is required.
2.It is used by the browser to implement backward and forward navigation of visited web pages that is a back and forward button.
3.It is also used to represent a classic game deck of cards.
4.Also in many operating systems, the thread scheduler maintains a doubly-linked list of all processes running at that time.
5.Implementing LRU Cache.
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL ;

// create new Node

struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    printf("Enter the Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

// AddNode or Add element at last position

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
        newNode->prev = temp;
    }
}

// Add Node at First position

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
        head->prev = newNode;
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
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
// Add Node at Position

int addAtPos(int pos)
{
    int count = countNode();
    if (pos <= 0 || pos > count + 1)
    {
        printf("Invalid Position\n");
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
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        return 0;
    }
}

// Delete First Node in DLL

int delFirst()
{
    if (head == NULL)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
            free(head);
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            free(head->prev);
        }
        return 0;
    }
}

// Delete Last Node in DLL

int delLast()
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

// Delete node at Position

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
// Print Doubly Linked List
void printDLL()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("|%d| ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
        printf("7.printDLL\n");

        int ch;
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addNode();
            printDLL();
            break;
        case 2:
            addFirst();
            printDLL();
            break;
        case 3:
        {
            int pos;
            printf("Enter the position of Node:\n");
            scanf("%d", &pos);
            addAtPos(pos);
            printDLL();
        }
        break;
        case 4:
            delFirst();
            printDLL();
            break;
        case 5:
            delLast();
            printDLL();
            break;
        case 6:
        {
            int pos;
            printf("Enter the Position:\n");
            scanf("%d", &pos);
            delAtPos(pos);
            printDLL();
        }
        break;
        case 7:
            printDLL();
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
