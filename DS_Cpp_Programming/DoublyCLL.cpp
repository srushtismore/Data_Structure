#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCLL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
                newn->next = newn;
                newn->prev = newn;
            }
            else
            {
                newn->next = first;
                newn->prev = last;
                first->prev = newn;
                first = newn;
                last->next = first;
                
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
                newn->next = newn;
                newn->prev = newn;
            }
            else
            {
                temp = first;

                while(temp->next != first)
                {
                    temp = temp->next;
                }

                last->next = newn;
                newn->prev = temp;
                last = newn;
                newn->next = first;
                first->prev = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last  = NULL;
            }
            else
            {
                first = first->next;
                delete last->next;
                first->prev = last;
                last->next = first;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last  = NULL;
            }
            else 
            {
                temp = first;

                while(temp->next->next != first)
                {
                    temp = temp->next;
                }

                delete last;

                last = temp;
                last->next = first;
                first->prev = last;
            }
            iCount--;
        }

        void Display()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }

            PNODE temp = first;

            do 
            {
                cout<<" | "<<temp->data<<" | <=> ";
                temp = temp->next;
            }while(temp != first);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int i = 0;

            if(pos < 1 || pos > iCount)
            {
                printf("Invalid position");
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp  = first;

                for(i = 1; i<pos-1; i++)
                {
                    temp = temp->next;
                }

                target = temp-> next;

                temp->next = target->next;
                temp->next->prev = temp;
                delete target;

                iCount--;
            }
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int i = 0;

            if(pos < 1 || pos > iCount+1)
            {
                cout<<"Invalid position";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(i = 1; i < pos-1 ; i++)
                {
                    temp = temp -> next;
                }

                newn->next = temp->next;
                newn->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                iCount++;
            }
        }
};

int main()
{
    DoublyCLL dobj;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;
    
    cout<<"----------------------------------------------------------------------------------\n";
    cout<<"-------------------------Doubly Circular Linked List--------------------------------\n";
    cout<<"----------------------------------------------------------------------------------\n\n";

    while(1)
    {
        cout<<"----------------------------------------------------------------------------------\n";
        cout<<"------------------------- Please select your option -------------------------------\n";
        cout<<"----------------------------------------------------------------------------------\n";
        cout<<"1 : Insert new node at first position\n";
        cout<<"2 : Insert new node at last position\n";
        cout<<"3 : Insert new node at given position\n";
        cout<<"4 : Delete the node from first position\n";
        cout<<"5 : Delete the node from Last position\n";
        cout<<"6 : Delete the node from given position\n";
        cout<<"7 : Display all elements of Linked list\n";
        cout<<"8 : Count number of nodes of Linked list\n";
        cout<<"0 : Terminate the application\n";
        cout<<"----------------------------------------------------------------------------------\n";

        cin>>iChoice;
         
        if(iChoice == 1)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;

            dobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;

            dobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;

            cout<<"Enter the position at which you want to insert the node : \n";
            cin>>iPos;

            dobj.InsertAtPos(iValue,iPos);
        }
        else if(iChoice == 4)
        {
            cout<<"Deleting the first element from linked list";

            dobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            cout<<"Deleting the last element from linked list";

            dobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            cout<<"Deleting the element from given position from linked list\n";

            cout<<"Enter the position at which you want to delete the node : \n";
            cin>>iPos;

            dobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Elememts of the linked list are : \n";

            dobj.Display();
        }
        else if(iChoice == 8)
        {
            iRet = dobj.Count();
            cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
        }
        else if(iChoice == 0)
        {
            cout<<"Thank you for Using our Application\n";
            break;
        }
        else
        {
            cout<<"Invalid choice";
        }
        cout<<"----------------------------------------------------------------------------------\n";
    }

    return 0;
}