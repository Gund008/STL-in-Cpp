#include<iostream>
using namespace std;

//Structure Declaration
template<class T>
struct node
{
    T data;
    struct node *next;
};

//Class Declaration
template<class T>
class SinglyLL
{
    //Characteristics
    public:
    struct node<T> *First;

    SinglyLL();
    //Behaviour
    void InsertFirst(T iNo);   
    void Display();
    int Count();
    void InsertLast(T iNo); 
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,T iNo);
    void DeleteAtPos(int iPos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    First=NULL;
}

template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;
    
    newn->data=iNo;
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
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Linked list Elements are:\n";
    struct node<T> *temp=First; 

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T>::Count()
{
    int iCnt=0;
    struct node<T> *temp=First; 

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>:: InsertLast(T iNo)
{
    struct node<T> *temp=First;

    struct node<T> *newn=NULL;
    newn=new struct node<T>;   

    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
       int iCnt=0;
       while(temp->next!=NULL)
       {
          temp=temp->next;
       }
       temp->next=newn;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>:: DeleteFirst()
{
    struct node<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
        First=First->next;
        delete(temp);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>:: DeleteLast()
{
    struct node<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
       while(temp->next->next!=NULL)
       {
          temp=temp->next;
       }
       delete(temp->next);
       temp->next=NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertAtPos(int iPos,T iNo)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct node<T> *temp=First;
    
    if((iPos<1)||(iPos>iNodeCnt+1))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T> *newn=new struct node<T>;
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct node<T> *temp=First;
    struct node<T> *temp1=NULL;
    
    if((iPos<1)||(iPos>iNodeCnt))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        delete(temp1);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet=0;
    SinglyLL<char> cobj;
    cobj.InsertFirst('d');
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');

    cobj.InsertLast('e');

    cobj.DeleteFirst();

    cobj.DeleteLast();

    cobj.InsertAtPos(2,'f');

    cobj.DeleteAtPos(2);

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<endl;

   
    SinglyLL<int> iobj;
    iobj.InsertFirst(101);
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.InsertLast(121);

    iobj.DeleteFirst();

    iobj.DeleteLast();

    iobj.InsertAtPos(2,111);

    iobj.DeleteAtPos(2);
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<endl;


    SinglyLL<float> fobj;
    fobj.InsertFirst(101.4);
    fobj.InsertFirst(51.3);
    fobj.InsertFirst(21.2);
    fobj.InsertFirst(11.1);

    fobj.InsertLast(121.2);

    fobj.DeleteFirst();

    fobj.DeleteLast();

    fobj.InsertAtPos(2,14.6);

    fobj.DeleteAtPos(2);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<endl;


    SinglyLL<double> dobj;
    dobj.InsertFirst(101.4);
    dobj.InsertFirst(511.3);
    dobj.InsertFirst(21.2);
    dobj.InsertFirst(11.1);

    dobj.InsertLast(1.1234);

    dobj.DeleteFirst();

    dobj.DeleteLast();

    dobj.InsertAtPos(2,66.5);

    dobj.DeleteAtPos(2);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<endl;
    
    return 0;

}