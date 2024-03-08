//===========================================================================================
//++++++++++++++++++++++++++++++++++Generic Queue DataStructure++++++++++++++++++++++++++++++++
//-------------------------------------------------------------------------------------------

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct node
{
    T  data;
    struct node<T> *next;

};


template<class T>
class Queue
{
    private:
       struct node<T>* first;
        int Count;
    public:
        Queue();
        void enqueue(T No);
        T dequeue();
        void Display();
        int CountNode();
};


template<class T>
Queue<T>::Queue()
{
    first = NULL;
    Count = 0;
}


template<class T>
void Queue<T>::enqueue(T No) //Insert Last
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
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->next = NULL;
    }
}



template<class T>
T Queue<T>::dequeue()
{
    T Value;
    struct node<T>* Temp = first;

    if(first == NULL)
    {
        cout<<"Queue is already empty\n";
        return -1;
    }
    else if(first->next == NULL)
    {
        Value = first->data;
        delete(first);
        first = NULL;
    }
    else
    {
        Value = first->data;
        first = first->next;
        delete(Temp);
    }
    return Value;
}



template<class T>
void Queue<T>::Display()
{
    struct node<T>* Temp = first;
    if(first == NULL)
    {
        cout<<" Queue is Empty...\n";
        return;
    }
    else
    {
        cout<<"Exit<---";
        while(Temp != NULL)
        {
            cout<<"| "<<Temp->data<<" |<--";
            Temp = Temp->next;
        }cout<<"Entry\n";
    }
}


int main()
{
    Queue<int> qobj;
    Queue<float> qobj1;
    Queue<char> qobj2;
    int iRet = 0;
    float fRet = 0.0;
    char chRet = '\0';

    qobj.enqueue(10);
    qobj.enqueue(20);
    qobj.enqueue(30);
    qobj.enqueue(40);
    qobj.Display();
    iRet = qobj.dequeue();
    cout<<"Dequeued value is : "<<iRet<<"\n";
    qobj.Display();

    qobj1.enqueue(10.272);
    qobj1.enqueue(20.738);
    qobj1.enqueue(30.738);
    qobj1.enqueue(40.972);
    qobj1.Display();
    fRet = qobj1.dequeue();
    cout<<"Dequeued value is : "<<fRet<<"\n";
    qobj1.Display();

    qobj2.enqueue('A');
    qobj2.enqueue('B');
    qobj2.enqueue('C');
    qobj2.enqueue('D');
    qobj2.Display();
    chRet = qobj2.dequeue();
    cout<<"Dequeued value is : "<<chRet<<"\n";
    qobj2.Display();

    return 0;
}
