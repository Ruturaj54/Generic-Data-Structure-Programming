

// ================================================================================
//
// ********************Generic SINGLY Linear Linked List***************************
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    private:
        struct node <T>* first;
        int Count;
    public:
        SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node <T>* newn = NULL;
    newn = new struct node<T>;
    newn->data = No;
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
    
}

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T>* newn = NULL;
    struct node<T>* Temp = first;
    newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else if(first->next == NULL)
    {
        first->next = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node <T>* Temp = first;

    cout<<"Contents of Linked List are : \n";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|-->";
        Temp = Temp->next;
    }cout<<"NULL\n";
}

template<class T>
int SinglyLL<T>::CountNode()
{
    struct node <T>* Temp = first;
    Count = 0;

    while(Temp != NULL)
    {
        Temp = Temp->next;
        Count++;
    }
    return Count;
    
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"The Linked List is Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        struct node <T>* Temp = first;
        first = first->next;
        delete(Temp);
    }
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"The Linked List is Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        struct node <T>* Temp = first;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete(Temp->next);
        Temp->next = NULL;
    }
}

template<class T>
void SinglyLL<T>::InsertAtPos(T No,int iPos)
{
    int Size = 0;
    Size = CountNode();
    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid Position...\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size)
    {
        InsertLast(No);
    }
    else
    {
        struct node <T>* newn = NULL;
       struct node <T>* Tempx = NULL;
        newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;
       struct node <T>* Temp = first;

        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next;
        Temp->next = newn;
        newn->next = Tempx;

    }
}

template<class T>
void SinglyLL<T>:: DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    struct node <T>* Temp = first;
   struct node <T>* Tempx = NULL;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid Position ...\n";
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
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next->next;
        delete(Temp->next);
        Temp->next = Tempx;
    }
}


int main()
{
    SinglyLL<int> obj;
    SinglyLL<char> obj1;
    SinglyLL<float> obj2;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    // obj.DeleteAtPos(8);
    // obj.DeleteAtPos(1);
    // obj.DeleteAtPos(3);
    

    obj1.InsertFirst('A');
    obj1.InsertFirst('B');
    obj1.InsertFirst('C');
    obj1.InsertFirst('D');

    obj1.Display();

    obj2.InsertFirst(111.111);
    obj2.InsertFirst(51.123);
    obj2.InsertFirst(21.123);
    obj2.InsertFirst(11.1342);

    obj2.Display();
   
    
    return 0;
}