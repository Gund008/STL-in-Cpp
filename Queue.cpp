#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class Queue
{
    public:
    struct node<T> *First;
    int iCount;

    Queue();

    bool IsQueueEmpty();
    void EnQueue(T);   
    T Dequeue();
    void Display();
};

template<class T>
Queue<T>::Queue()
{
    First=NULL;
    iCount=0;
}

template<class T>
bool Queue<T>::IsQueueEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::EnQueue(T no)
{
    struct node<T>  *newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node<T> *temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

    cout<<"gets pushed in the stack succesfully"<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T>::Dequeue()
{
  if(First==NULL)
  {
    cout<<"Unable to pop the elements as stack is empty:"<<"\n";
    return -1;
  }
  else
  {
    T value=First->data;
    struct node<T> *temp=First;

    First=First->next;
    delete temp;

    iCount--;

    return value;
  }

}

//////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>:: Display()
{
    if(First==NULL)
    {
        cout<<"Stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of stack are:"<<"\n";

        struct node<T> *temp=First;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue<int>obj1;
    int iRet=0;
    obj1.EnQueue(11);
    obj1.EnQueue(21);
    obj1.EnQueue(51);
    obj1.EnQueue(101);
    obj1.Display();

    iRet=obj1.Dequeue();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    iRet=obj1.Dequeue();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    obj1.Display();

     return 0;

}