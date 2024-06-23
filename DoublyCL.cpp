// Doubly Circular
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
class DoublyCL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int iCount;

    public:
        DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((Head == NULL) && (Tail == NULL)) // if(iCount == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
       Tail -> next = newn;
       newn -> prev = Tail;
       Tail = newn;
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iCount++;
}

template <class T>
void DoublyCL<T>::Display()
{
    struct node<T> *temp = Head;
    for (int i = 1; i <= iCount; i++)
    {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }
    cout << "\n";
}

template <class T>
int DoublyCL<T>::CountNode()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
        iCount = 0;
    }
    else
    {
        Head = Head -> next;
        delete (Tail -> next); // delete(Head -> prev);
        Tail -> next = Head;
        Head -> prev = Tail;
        iCount--;
    }
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
        iCount = 0;
    }
    else
    {
        Tail = Tail -> prev;
        delete Tail -> next; // delete(Head -> prev)
        Tail -> next = Head;
        Head -> prev = Tail;
        iCount--;
    }
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
{
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
        struct node<T> *newn = new struct node<T>;
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        struct node<T> *temp = Head;
        for(int i = 1; i < ipos - 1; i++)
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
void DoublyCL<T>::DeleteAtPos(int ipos)
{
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
        struct node<T> *temp = Head;
        for(int i = 1; i < ipos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete(temp->next->prev);
        temp -> next -> prev = temp;
        iCount--;
    }
}

int main()
{
    DoublyCL <int>iobj;
    DoublyCL <float>fobj;
    DoublyCL <double>dobj;
    DoublyCL <char>cobj;

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