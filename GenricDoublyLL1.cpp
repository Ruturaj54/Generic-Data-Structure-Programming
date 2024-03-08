

// ==================================================================================
// ********************Genric Doubly Linear Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T>* next;
    struct node<T>* prev;
};

template<class T>
class DoublyLL
{
    private:
        struct node<T>* first;
        int Count;
    public:
        DoublyLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No,int iPos);
        void DeleteAtPos(int iPos);

};

template<class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->prev = NULL;
        newn->next = first;
        first->prev = newn;
        first = newn;

    }
}

template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    struct node<T>* Temp = first;

    if(first == NULL)
    {
        first = newn;
    }
    else if(first->next == NULL)
    {
        first->next = newn;
        newn->prev = first;
        newn->next = NULL;
        first->prev = NULL;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
        newn->next = NULL;
    }
}

template<class T>
void DoublyLL<T>::Display()
{
    struct node<T>* Temp = first;

    cout<<"NULL<==>";
    while (Temp != NULL)
    {
        cout<<"| "<<Temp->data<<" |<==>";
        Temp = Temp->next;
    }cout<<"NULL\n";
    
}

template<class T>
int DoublyLL<T>::CountNode()
{
    struct node<T>* Temp = first;
    Count = 0;
    while(Temp != NULL)
    {
        Count++;
        Temp = Temp->next;
        
    }
    return Count;

}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"The Linked List is already Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);
        first->prev = NULL;
    }
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"The Linked List is already Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        struct node<T>* Temp = first;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete(Temp->next);
        Temp->next = NULL;
    }

}

template<class T>
void DoublyLL<T>::InsertAtPos(T No,int iPos)
{
    int Size = 0;
    Size = CountNode();
    struct node<T>* Temp = first;
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid position..\n";
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
        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    struct node<T>* Temp = NULL;
    Temp = first;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid position..\n";
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
        for(int i = 1;i < iPos -1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;
    }
}

int main()
{
    DoublyLL<int> dobj;
    DoublyLL<char> dobj1;
    DoublyLL<float> dobj2;
    int iRet = 0;
    dobj.InsertFirst(11);
    dobj.InsertFirst(21);
    dobj.InsertFirst(51);
    dobj.InsertFirst(101);
    dobj.InsertLast(2000);

    dobj.Display();

    iRet = dobj.CountNode();
    cout<<"Number of Node are : "<<iRet<<"\n";

    dobj1.InsertFirst('A');
    dobj1.InsertFirst('B');
    dobj1.InsertFirst('C');
    dobj1.InsertFirst('D');
    dobj1.InsertLast('E');

    dobj1.Display();
    iRet = dobj1.CountNode();
    cout<<"Number of Node are : "<<iRet<<"\n";

    dobj2.InsertFirst(11.1083);
    dobj2.InsertFirst(21.279);
    dobj2.InsertFirst(51.1671);
    dobj2.InsertFirst(101.112);
    dobj2.InsertLast(2000.1661);

    dobj2.Display();
    iRet = dobj2.CountNode();
    cout<<"Number of Node are : "<<iRet<<"\n";


    return 0;
}