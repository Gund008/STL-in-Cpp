#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
    struct node<T> *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void push(T);   
    T Pop();
    void Display();
};

template<class T>
Stack<T>::Stack()
{
    First=NULL;
    iCount=0;
}

template<class T>
bool Stack<T>::IsStackEmpty()
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
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::push(T no)
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
        newn->next=First;
        First=newn;
    }
    iCount++;

    cout<<"gets pushed in the stack succesfully"<<"\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::Pop()
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
////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>:: Display()
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

/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack<int>obj1;
    Stack<float>obj2;

    int iRet=0;
    obj1.push(11);
    obj1.push(21);
    obj1.push(51);
    obj1.push(101);
    obj1.Display();

    iRet=obj1.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    iRet=obj1.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    obj1.Display();

    obj2.push(11.2);
    obj2.push(12.3);
    obj2.push(44.3);
    obj2.push(44.6);

    iRet=obj2.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    iRet=obj2.Pop();
    cout<<"Poped Elements is:"<<iRet<<"\n";

    obj2.Display();

     return 0;

}