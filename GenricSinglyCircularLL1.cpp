

// ==================================================================================
// ********************Genric SINGLY Circular Linear Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class SinglyCircular
{
    private:
        struct node<T>* first;
        struct node<T>* Tail;
        int Count;
    public:
        SinglyCircular();
        void InsertFirst(T No);
        void InsertLast(T No);
        int CountNode();
        void Display();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No,int iPos);
        void DeleteAtPos(int iPos);
};

template<class T>
SinglyCircular<T>::SinglyCircular()
{
    first = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCircular<T>::InsertFirst(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        Tail->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        Tail->next = first;
        
    }
}

template<class T>
void SinglyCircular<T>::InsertLast(T No)
{
    struct node<T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        Tail->next = first;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
        newn->next = first;
    }
}

template<class T>
void SinglyCircular<T>::DeleteFirst()
{
    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first->next == first)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        first = first->next;
        delete(Tail->next);
        Tail->next = first;
    }

}

template<class T>
void SinglyCircular<T>::DeleteLast()
{
    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first->next == first)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T>* Temp = first;
        while(Temp->next != Tail)
        {
            Temp = Temp->next;
        }
        delete(Tail);
        Tail = Temp;
        Tail->next = first;

    }

}

template<class T>
void SinglyCircular<T>::Display()
{
    if(first != NULL && Tail != NULL)
    {
        do
        {
            cout<<"| "<<first->data<<" |-->";
            first = first->next;
        } while(first != Tail->next);
        
        cout<<"Address of First Node\n";
    }
    else
    {
        cout<<"Linked List is Empty \n";
        return;
    }
}

template<class T>
int SinglyCircular<T>::CountNode()
{
    struct node<T>* Temp = first;
    Count = 0;
    do
    {
        Temp=Temp->next;
        Count++;
    }while(Temp != first);
    return Count;
}

template<class T>
void SinglyCircular<T>::InsertAtPos(T No ,int iPos)
{
    int Size = 0;
    Size = CountNode();

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
        struct node<T>* Temp = first;
        struct node<T>* Tempx = NULL;
        struct node<T>* newn = NULL;
        newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next;
        Temp->next = newn;
        newn->next = Tempx;
        
    }
}

template<class T>
void SinglyCircular<T>::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();

    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid Position..\n";
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
        struct node<T>* Temp = first;
        struct node<T>* Tempx = NULL;
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next->next;
        delete(Temp->next);
        Temp->next = Tempx;
        Tail->next = first;

    }
}


int main()
{
    SinglyCircular<int> sobj;
    SinglyCircular<char> sobj1;
    SinglyCircular<float> sobj2;
    int iRet = 0;

    sobj.InsertFirst(11);
    sobj.InsertFirst(21);
    sobj.InsertLast(51);
    sobj.InsertLast(101);
    sobj.InsertAtPos(111,3);
    sobj.Display();
    sobj.DeleteAtPos(3);
    //sobj.Display();
    //sobj.DeleteFirst();
    //sobj.DeleteLast();
    sobj.Display();

    iRet = sobj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    sobj1.InsertFirst('A');
    sobj1.InsertFirst('B');
    sobj1.InsertLast('C');
    sobj1.InsertLast('D');
    sobj1.InsertAtPos('E',3);
    sobj1.Display();
    sobj1.DeleteAtPos(3);
    //sobj.Display();
    //sobj.DeleteFirst();
    //sobj.DeleteLast();
    sobj1.Display();

    iRet = sobj1.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    sobj2.InsertFirst(11.12);
    sobj2.InsertFirst(21.233);
    sobj2.InsertLast(51.131);
    sobj2.InsertLast(101.144);
    sobj2.InsertAtPos(111.1233,3);
    sobj2.Display();
    sobj2.DeleteAtPos(3);
    //sobj.Display();
    //sobj.DeleteFirst();
    //sobj.DeleteLast();
    sobj2.Display();

    iRet = sobj2.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    return 0;
}