
//********************************************************************************
//+++++++++++++++++++++++Genric Based Stack DataStructure++++++++++++++++++++++++++++
//================================================================================

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
class Stack
{
    private:
        struct node<T> * first;
        int Count;
    public:
        Stack();
        void Push(T No);
        int Pop();
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    first = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T No)
{
    struct node<T>* newn = NULL;
    struct node<T>* Temp = NULL;
    newn = new struct node<T> ;
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
int Stack<T>::Pop()
{
    int Val = 0;
    struct node<T> * Temp = first;
    if(first == NULL)
    {
        cout<<"Stack is Empty..\n";
        return -1;
    }
    else
    {
        Val = first->data;
        first = first->next;
        delete(Temp);

    }
    return Val;
}


template<class T>
void Stack<T>::Display()
{
    struct node<T>* Temp = first;

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->data<<" |\n";
        Temp = Temp->next;
    }cout<<"  NULL\n";
}

int main()
{
    Stack<int> sobj;
    int iRet = 0;
    sobj.Push(100);
    sobj.Push(200);
    sobj.Push(300);
    sobj.Push(400);
    sobj.Display();


    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    sobj.Display();




    return 0;
}