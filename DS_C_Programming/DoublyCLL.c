#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        newn->next = *last;
        newn->prev = *first;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        newn->prev = *last;
        *first = newn;
        (*last)->next = (*first);
        
    }
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        newn->next = *last;
        newn->prev = *first;
    }
    else
    {
        temp = *first;

        while(temp->next != *first)
        {
            temp = temp->next;
        }

        (*last)->next = newn;
        newn->prev = temp;
        *last = newn;
        newn->next = *first;
        (*first)->prev = newn;
    }
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last  = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);
        (*first)->prev = *last;
        (*last)->next = (*first);
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last  = NULL;
    }
    else 
    {
        temp = *first;

        while(temp->next->next != *first)
        {
            temp = temp->next;
        }

            free(*last);

            *last = temp;
            (*last)->next = (*first);
            (*first)->prev = (*last);
    }
    
}

void Display(PNODE first,PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        printf("| %d | <=>",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);

    return iCount;
   
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int iCount = 0,i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp  = *first;

        for(i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }

            target = temp-> next;

            temp->next = target->next;
            temp->next->prev = temp;
            free(target);
    }
}

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0,i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
        
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;
    
    printf("----------------------------------------------------------------------------------\n");
    printf("-------------------------Doubly Circular Linked List--------------------------------\n");
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

            InsertFirst(&head,&tail,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            InsertLast(&head,&tail,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert the node : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head,&tail,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from linked list");

            DeleteFirst(&head,&tail);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from linked list");

            DeleteLast(&head,&tail);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position from linked list\n");

            printf("Enter the position at which you want to delete the node : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,&tail,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elememts of the linked list are : \n");

            Display(head,tail);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head,tail);
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
