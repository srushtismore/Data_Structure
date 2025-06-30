#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    newn -> next = *first;
    *first = newn ;

}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)          //Empty LL
    {
        return;
    }
    else if((*first) -> next == NULL)       //Single node
    {
        free(*first);
        *first = NULL;
    }
    else                                //more then 1 node
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);
    }
    
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)          //Empty LL
    {
        return;
    }
    else if((*first) -> next == NULL)       //Single node
    {
        free(*first);
        *first = NULL;
    }
    else                                //more then 1 node
    {
        temp = *first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
    
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iCount = 0,i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        for(i = 1; i <= pos - 2;i++)
        {
            temp = temp -> next;
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        newn -> next = temp -> next;
        temp -> next = newn;

    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iCount = 0,i = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i <= pos - 2;i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;  //temp ->next = temp -> next ->next;
        free(target);

    }
}

int main()
{   
    PNODE head = NULL;
     
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;
    
    printf("----------------------------------------------------------------------------------\n");
    printf("-------------------------Singly Linear Linked List--------------------------------\n");
    printf("----------------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("----------------------------------------------------------------------------------\n");
        printf("------------------------- Please select your option -------------------------------\n");
        printf("----------------------------------------------------------------------------------\n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete the node from first position\n");
        printf("5 : Delete the node from Last position\n");
        printf("6 : Delete the node from given position\n");
        printf("7 : Display all elements of Linked list\n");
        printf("8 : Count number of nodes of Linked list\n");
        printf("0 : Terminate the application\n");
        printf("----------------------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            InsertFirst(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            InsertLast(&head,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert the node : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from linked list");

            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from linked list");

            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position from linked list\n");

            printf("Enter the position at which you want to delete the node : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elememts of the linked list are : \n");

            Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head);
            printf("Number of elements in the linked list are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for Using our Application\n");
            break;
        }
        else
        {
            printf("Invalid choice");
        }
        printf("----------------------------------------------------------------------------------\n"); 

    }

    return 0;
}