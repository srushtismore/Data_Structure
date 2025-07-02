#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
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

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp -> next;
                }

                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)          
            {
                return;
            }
            else if(first->next == NULL)       
            {
                delete first;
                first = NULL;
            }
            else                                
            {
                temp = first;
                first = first -> next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)          
            {
                return;
            }
            else if(first->next == NULL)       
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }

                free(temp -> next);
                temp -> next = NULL;
            }   
            iCount--;
        }

        void Display()
        {
            PNODE temp = first;

            if(first == NULL)
            {
                return;
            }
            else
            {
                while(temp != NULL)
                {
                    cout<<" | "<<temp->data<<" | -> ";
                    temp = temp->next;
                }
        
                cout<<"NULL\n";
            }
            
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int i = 0;

            if((pos < 1) || (pos > iCount + 1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                temp = first;

                newn = new NODE;

                newn->data = no;
                newn->next = NULL;

                for(i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;
                
                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int i = 0;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid Position\n";
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
                temp = first;

                for(i = 1; i < pos - 1;i++)
                {
                    temp = temp -> next;
                }

                target = temp -> next;

                temp -> next = target -> next;  
                free(target);

                iCount--;
            }
        }

};

int main()
{
    SinglyLLL sobj;
    
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;
    
    cout<<"----------------------------------------------------------------------------------\n";
    cout<<"-------------------------Singly Linear Linked List--------------------------------\n";
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

            sobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;

            sobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;

            cout<<"Enter the position at which you want to insert the node : \n";
            cin>>iPos;

            sobj.InsertAtPos(iValue,iPos);
        }
        else if(iChoice == 4)
        {
            cout<<"Deleting the first element from linked list";

            sobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            cout<<"Deleting the last element from linked list";

            sobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            cout<<"Deleting the element from given position from linked list\n";

            cout<<"Enter the position at which you want to delete the node : \n";
            cin>>iPos;

            sobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Elememts of the linked list are : \n";

            sobj.Display();
        }
        else if(iChoice == 8)
        {
            iRet = sobj.Count();
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

