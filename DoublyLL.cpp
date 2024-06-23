// Doubly Linear
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> *Head;
        int iCount;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    newn = new struct node<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(Temp -> next != NULL)
        {
            Temp = Temp -> next;
        }
        Temp -> next = newn;
        newn -> prev = Temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout <<"|"<< temp -> data<<"|->";
        temp = temp -> next; 
    }
    cout << "NULL";
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
     if(Head == NULL)
        {
            return;
        }

        else if(Head -> next == NULL)
        {
            delete Head;
            Head = NULL;
        }

        else
        {
            Head = Head -> next;
            delete(Head -> prev);
            Head -> prev = NULL;
            iCount--; 
        } 
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(Head == NULL) // ll is empty
        {
            return;
        }
        else if(Head -> next == NULL) // ll contain 1 node
        {
            delete Head;
            Head = NULL;
        }
        else // ll contain more than 1 node
        {
            struct node<T> *temp = Head;
            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            delete (temp -> next);
            temp -> next = NULL;
            iCount--;
        }
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;
    struct node<T> *temp = Head;
    
    if((ipos < 1) || (ipos > iCount + 1))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    struct node<T> *temp = Head;

    if((ipos < 1) || (ipos > iCount))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }

    else if(ipos == iCount)
    {
        DeleteLast();
    }

    else
    {
        for(int i = 1; i < ipos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete (temp -> next -> prev);
        temp -> next -> prev = temp;
        iCount--;
    }
}

int main()
{
    DoublyLL <int>iobj;
    DoublyLL <float>fobj;
    DoublyLL <double>dobj;
    DoublyLL <char>cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);

    cout<<"LinkedList of Integers : "<<"\n";
    iobj.Display();

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"LinkedList of Floats : "<<"\n";
    fobj.Display();

    dobj.InsertLast(11.999999);
    dobj.InsertLast(21.999999);
    dobj.InsertLast(51.999999);
    dobj.InsertLast(101.99999);

    cout<<"LinkedList of Doubles : "<<"\n";    
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"LinkedList of Characters : "<<"\n";
    cobj.Display();
    return 0;
}