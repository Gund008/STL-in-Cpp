#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyCL
{
    public:
    struct node<T> *First;
    struct node<T> *Last;

    SinglyCL();
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
SinglyCL<T>::SinglyCL()
{
    First=NULL;
    Last=NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;

    newn->data=iNo;
    newn->next=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
        (Last)->next=First;
    }
    else
    {
        newn->next=First;
        First=newn;
        (Last)->next=First;
    }  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of circular Linked list:\n";
    struct node<T> *temp=First;

    do 
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }while(temp!=(Last->next));
    cout<<"\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T>::Count()
{
    struct node<T> *temp=First;
    int iCnt=0;
    do 
    {
        iCnt++;
        temp=temp->next;
    }while(temp!=(Last->next));
    return iCnt;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;

    newn->data=iNo;
    newn->next=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        Last->next=newn;
        Last=newn;
        Last->next=First;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    struct node<T> *temp=First;

    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
       First=First->next;
       delete temp;
       (Last)->next=First;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct node<T> *temp=First;
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        while(temp->next!=(Last))
        {
            temp=temp->next;
        }
        delete temp->next;
        Last=temp;
        Last->next=First;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::InsertAtPos(int iPos,T iNo)
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet=0;

    SinglyCL<char> cobj;
    cobj.InsertFirst('d');
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');

    cobj.InsertLast('e');

    cobj.DeleteFirst();

    cobj.DeleteLast();

    cobj.InsertAtPos(2,111);

    cobj.DeleteAtPos(2);
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<endl;


    SinglyCL<int> iobj;
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


    SinglyCL<float> fobj;
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


    SinglyCL<double> dobj;
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