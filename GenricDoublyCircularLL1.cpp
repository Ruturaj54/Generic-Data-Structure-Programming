

// ==================================================================================
// ********************Generic Doubly Circular Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
    struct node<T>  *prev;
};


template<class T>
class DoublyCircular
{
    private:
        struct node<T>* first;
        struct node<T>* Tail;
        int Count;
    public:
        DoublyCircular();
        void InsertFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int CountNode();
        void InsertAtPos(T No,int iPos);
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyCircular<T>::DoublyCircular()
{
    first = NULL;
    Tail = NULL;
    Count = 0;

}

template<class T>
void DoublyCircular<T>::InsertFirst(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        newn->next = Tail;
        Tail->prev = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Tail->next = first;
    first->prev = Tail;
}

template<class T>
void DoublyCircular<T>::InsertLast(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

     if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Tail->next = first;
    first->prev = Tail;
}

template<class T>
void DoublyCircular<T>::DeleteFirst()
{
    struct node<T>* Temp = first;

    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first == Tail)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);
         first->prev = Tail;
         Tail->next = first;
    }
    
}

template<class T>
void DoublyCircular<T>::DeleteLast()
{
     if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first == Tail)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete(Tail->next);
        Tail->next = first;
        first->prev = Tail;
    }

}

template<class T>
void DoublyCircular<T>::Display()
{
    if(first != NULL && Tail != NULL)
    {
    struct node<T>* Temp = first;
    cout<<"Address of Tail<==>";
    do
    {
        cout<<"| "<<Temp->data<<" |<==>";
        Temp = Temp->next;

    }while(Temp != Tail->next);
    cout<<"Address of First\n";
    }
}

template<class T>
int DoublyCircular<T>::CountNode()
{
    struct node<T>* Temp = first;
    Count = 0;
    do
    {
        Count++;
        Temp = Temp->next;

    }while(Temp != Tail->next);
    return Count;
}

template<class T>
void DoublyCircular<T>::InsertAtPos(T No,int iPos)
{
    struct node<T>* Temp = first;
    int Size = 0;
    Size = CountNode();
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid Position..\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size)
    {
        InsertLast(No);
    }
    else
    {
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next->prev = newn;
        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next = newn;
        
    }
    Tail->next = first;
    first->prev = Tail;
}

template<class T>
void DoublyCircular<T>::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    struct node<T>* Temp = first;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid position...\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;
    }
    Tail->next = first;
    first->prev = Tail;
}

int main()
{
    DoublyCircular<int> dobj;
    DoublyCircular<char> dobj1;
    DoublyCircular<float> dobj2;
    int iRet = 0;

    dobj.InsertFirst(11);
    dobj.InsertFirst(21);
    dobj.InsertFirst(51);
    dobj.InsertFirst(101);
    dobj.InsertLast(11);
    dobj.InsertLast(21);
    dobj.InsertLast(51);
    dobj.InsertLast(101);

    dobj.Display();

    dobj1.InsertLast('D');
    dobj1.InsertLast('C');
    dobj1.InsertLast('B');
    dobj1.InsertLast('A');

    dobj1.Display();

    dobj2.InsertFirst(11.112);
    dobj2.InsertFirst(21.354);
    dobj2.InsertFirst(51.442);
    dobj2.InsertFirst(101.9162);

    dobj2.Display();


    return 0;
}