// Singly Circular
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> *first;
        struct node<T> *last;
        int iCount;

    public:
        SinglyCL();
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
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T> *newn = new struct node<T>;

            newn->data = no;
            newn->next = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }

            last->next = first;
            iCount++;
    }

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
        struct node<T> *newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;

        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }

        last->next = first;
        iCount++;
}

template <class T>
void SinglyCL<T>::Display()
{
if((first == NULL) && (last == NULL))
        {
            return;
        }

        struct node<T> *temp = first;

        do
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        } while (temp != (last->next));

        cout<<"NULL"<<endl;
}

template <class T>
int SinglyCL<T>::CountNode()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
if((first==NULL) && (last==NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;    
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }

        iCount--;
}
template <class T>
void SinglyCL<T>::DeleteLast()
{
if((first==NULL) && (last==NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            struct node<T> *temp = first;

            while((temp->next) != last)
            {
                temp = temp->next;
            }

            delete last;
            last = temp;
            last->next = first;
        }

        iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int ipos)
{
if((ipos < 1) || (ipos > (iCount+1)))
        {
            cout<<"Invalid position"<<endl;
            return;
        }

        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == (iCount+1))
        {
            InsertLast(no);
        }
        else
        {
            struct node<T> *newn = new struct node<T>;

            newn->data = no;
            newn->next = NULL;

            struct node<T> *temp = first;

            for(int iCnt = 1; iCnt < ipos-1 ; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
        {
            cout<<"Invalid position"<<endl;
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
            struct node<T> *temp = first;
            struct node<T> *targeted = NULL;

            for(int iCnt = 1; iCnt < ipos-1 ; iCnt++)
            {
                temp = temp->next;
            }

            targeted = temp->next;
            temp->next = targeted->next;

            delete targeted;

            iCount--;
        }
}

int main()
{
    SinglyCL <int>iobj;
    SinglyCL <float>fobj;
    SinglyCL <double>dobj;
    SinglyCL <char>cobj;

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