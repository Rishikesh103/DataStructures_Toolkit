#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             QueueX
//  Description :       Genric Implementation of Doubly Circular Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node<T> *next;   
};

template<class T>
class QueueX
{
    private:
        struct node<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        int Dequeue();
        void Display();
        int Count();
};

template<class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;


}

template<class T>
void QueueX<T> :: Enqueue(T no)      //insertlast
{
    struct node<T> *newn = new struct node<T>();
    struct node<T> *temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template<class T>
int QueueX<T> :: Dequeue()         //deletefirs    
{
    struct node<T> *temp = NULL;
    T value;
    if(first == NULL)
    {
        cout<<"unable to pop as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;
        first = temp->next;
        delete temp;
        iCount--;
        return value;
    }

    
}

template<class T>
void QueueX<T> :: Display()
{
    struct node<T> *temp = NULL;
    temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int QueueX<T> :: Count()
{
    return iCount;
}



////////////////////////////////////////////////////////////////////////////////
//
//  Class :             StackX
//  Description :       Genric Implementation of Doubly Circular Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
class StackX
{
    private:
        struct node<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: Push(T no)
{
    struct node<T> *newn = new struct node<T>();
    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: Pop()
{
    struct node<T> *temp = NULL;
    T value;
    if(first == NULL)
    {
        cout<<"unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;
        first = temp->next;
        delete temp;
        iCount--;
        return value;
    }

    
}

template<class T>
void StackX<T> :: Display()
{
    struct node<T> *temp = NULL;
    temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |";
        temp = temp->next;
        cout<<"\n";
    }
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             SynglyCLL
//  Description :       Genric Implementation of Doubly Circular Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct SynglyCLLnode
{
    T data;
    struct SynglyCLLnode<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        int iCount;
        struct SynglyCLLnode<T> * first;
        struct SynglyCLLnode<T> * last;
    
    public:
        SinglyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"inside constructer";
    iCount = 0;
    first = NULL;
    last = NULL;
}

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    struct SynglyCLLnode<T>* newn = NULL;
    newn = new struct SynglyCLLnode<T>();

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
 
}

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    struct SynglyCLLnode<T>* newn = NULL;
    newn = new struct SynglyCLLnode<T>();

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
        last = first;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}

template<class T>
void SinglyCLL<T> :: Display()
{
    struct SynglyCLLnode<T>* temp = NULL;
    temp = first;

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != first);
    cout<<"\n";
}

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    struct SynglyCLLnode<T>* temp = first;
    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    struct SynglyCLLnode<T>* temp = first;
    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        while(temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = first;
        delete last;
        last = temp;
    }
    iCount--;
}

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct SynglyCLLnode<T>* newn = new struct SynglyCLLnode<T>();
    struct SynglyCLLnode<T>* temp = NULL;
    int i = 0;

    newn->next = NULL;
    newn->data = no;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"invalid pos\n";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        for(i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    struct SynglyCLLnode<T>* newn = new struct SynglyCLLnode<T>();
    struct SynglyCLLnode<T>* temp = NULL;
    struct SynglyCLLnode<T>* target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"invalid pos\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        delete target;
        last->next = first;
        iCount--;
    }
    
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             DoublyCLL
//  Description :       Genric Implementation of Doubly Circular Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);


};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"inside constructor\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)       //linklist is empty
    {
        first = newn;
        last = newn;
    }
    else                                    //linklist contains atleast one node
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)       //linklist is empty
    {
        first = newn;
        last = newn;
    }
    else                                    //linklist contains atleast one node
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
        
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

template<class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    temp = first;

    cout<<"Elements of the linkedlist are : \n";


    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
    } while (temp != first);
    cout<<"\n";
}

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   //LL is empty
    {
        return;

    }else if(first == last)         // ll contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else                        //LL contains multiple nodes
    {
        first = first->next;
        delete first->prev;     //delete last -> next;

        last->next = first;
        first->prev = last;
    }
}

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   //LL is empty
    {
        return;
        
    }
    else if(first == last)         // ll contains one node
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else                        //LL contains multiple nodes
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
}

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;
    int iCnt = 0;
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"invalid pos";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;

    }
}

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;
    if(pos < 1 || pos > iCount)
    {
        cout<<"invalid pos";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;

    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             SinglyLL
//  Description :       Genric Implementation of Singly Circular Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct SynglyLLnode
{
    T data;
    struct SynglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
    private:
        int iCount;
        struct SynglyLLnode<T> * first;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    cout<<"inside constructor\n";
    iCount = 0;
    first = NULL;
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct SynglyLLnode<T> * temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
void SinglyLL<T> :: InsertFirst(int no)
{
    struct SynglyLLnode<T> * newn = new struct SynglyLLnode<T>;
    newn->data = no;
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
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertLast(int no)
{
    struct SynglyLLnode<T> * newn = new struct SynglyLLnode<T>;
    struct SynglyLLnode<T> * temp = first;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct SynglyLLnode<T> * target = first;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete target;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct SynglyLLnode<T> * temp = first;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(int no, int pos)
{
    struct SynglyLLnode<T> * temp = NULL;
    struct SynglyLLnode<T> * newn = new struct SynglyLLnode<T>;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"invalid pos";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        newn->data = no;
        newn->next = NULL;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    struct SynglyLLnode<T> * temp = NULL;
    struct SynglyLLnode<T> * target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"invalid pos";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next; 
        delete target;
        iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////////
//
//  Class :             DoublyLL
//  Description :       Genric Implementation of Doubly Linked list 
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> *next;
    struct DoublyLLnode<T> *prev;
};

template <class T>
class DoublyLL
{
    private:
        int iCount;
        struct DoublyLLnode<T> * first;
    public:
        DoublyLL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
      
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    first = NULL;
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> * temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
    struct DoublyLLnode<T> * temp = NULL;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        first = NULL;
        delete first;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DoublyLLnode<T> * temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
    struct DoublyLLnode<T> * temp = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"invlid pos";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        newn->data = no;
        newn->next = NULL;
        newn->next = NULL;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyLLnode<T> * temp = NULL;
    struct DoublyLLnode<T> * target = NULL;
    int i = 0;
    if(pos < 1 || pos > iCount)
    {
        cout<<"invlid pos";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete target;
        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             BST (program571.c)
//  Description :       Genric Implementation of Binary Search Tree
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *lchild;
    struct BSTnode<T> *rchild;
};

template<class T>
class BST
{
    private:
        struct BSTnode<T> *first;
        int iCount;

        // Private helper functions for recursive operations
        void Inorder(struct BSTnode<T> *temp);
        void Preorder(struct BSTnode<T> *temp);
        void Postorder(struct BSTnode<T> *temp);
        int CountLeafNodes(struct BSTnode<T> *temp);
        int CountParentNodes(struct BSTnode<T> *temp);
        
    public:
        BST();

        void Insert(T no);
        bool Search(T no);
        
        void DisplayInorder();
        void DisplayPreorder();
        void DisplayPostorder();

        int Count();
        int CountLeaf();
        int CountParent();
};

template<class T>
BST<T> :: BST()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void BST<T> :: Insert(T no)
{
    struct BSTnode<T> *newn = new struct BSTnode<T>;
    struct BSTnode<T> *temp = NULL;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)          //BST is empty
    {
        first = newn;
        iCount++;
    }
    else                        //BST contains atleast one node
    {
        temp = first;
        
        while(1) // Loop forever until a break condition is met
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : unable to insert\n";
                delete newn; // Must free the unused node
                break;
            }
            else if(no > temp->data)     // Traverse rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)       // Traverse lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template<class T>
bool BST<T> :: Search(T no)
{
    struct BSTnode<T> *temp = first;
    bool bFlag = false;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

template<class T>
void BST<T> :: DisplayInorder()
{
    Inorder(first);
    cout<<"\n";
}

template<class T>
void BST<T> :: Inorder(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
      Inorder(temp->lchild);
      cout<<temp->data<<"\t";
      Inorder(temp->rchild);  
    }
}

template<class T>
void BST<T> :: DisplayPreorder()
{
    Preorder(first);
    cout<<"\n";
}

template<class T>
void BST<T> :: Preorder(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
      cout<<temp->data<<"\t";
      Preorder(temp->lchild);
      Preorder(temp->rchild);  
    }
}

template<class T>
void BST<T> :: DisplayPostorder()
{
    Postorder(first);
    cout<<"\n";
}

template<class T>
void BST<T> :: Postorder(struct BSTnode<T> *temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\t";  
    }
}

template<class T>
int BST<T> :: Count()
{
    return iCount;
}

template<class T>
int BST<T> :: CountLeaf()
{
    return CountLeafNodes(first);
}

template<class T>
int BST<T> :: CountLeafNodes(struct BSTnode<T> *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->lchild == NULL && temp->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return CountLeafNodes(temp->lchild) + CountLeafNodes(temp->rchild);
    }
}

template<class T>
int BST<T> :: CountParent()
{
    return CountParentNodes(first);
}

template<class T>
int BST<T> :: CountParentNodes(struct BSTnode<T> *temp)
{
    if(temp == NULL || (temp->lchild == NULL && temp->rchild == NULL))
    {
        return 0; // Not a parent node
    }
    
    // It is a parent, so count it (1) and add the counts from its subtrees
    return 1 + CountParentNodes(temp->lchild) + CountParentNodes(temp->rchild);
}




////////////////////////////////////////////////////////////////////////////////
//
//  Class :             Sorting
//  Description :       Genric Implementation of Sorting Algorithms
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
    protected:
        T *arr;
        int isize;
        bool sorted;
    
    public:
        ArrayX(int no);
        ~ArrayX();

        void accept();
        void display();
        
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template<class T>
ArrayX<T>::ArrayX(int no)
{
    this->isize = no;
    this->arr = new T[isize];
    this->sorted = true; // Assume sorted until proven otherwise
}

template<class T>
ArrayX<T>::~ArrayX()
{
    delete []arr;
}

template<class T>
void ArrayX<T>::accept()
{
    cout<<"Enter "<<isize<<" elements:\n";

    int i = 0;
    for(i = 0; i < isize; i++)
    {
        cout<<"Enter the element number : "<<i+1<<"\n";
        cin>>arr[i];

        // Corrected logic to check if the array is sorted
        if(i > 0 && sorted == true)
        {
            if(arr[i] < arr[i - 1])
            {
                sorted = false;
            }
        }
    }
}

template<class T>
void ArrayX<T>::display()
{
    int i = 0;
    for(i = 0; i < isize; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

template<class T>
void ArrayX<T>::BubbleSort()
{
    int i = 0, j = 0;
    T temp;

    if(sorted == true)
    {
        cout<<"Array is already sorted. Skipping BubbleSort.\n";
        return;
    }

    for(i = 0 ; i < isize; i++)      //outer loop
    {
        for(j = 0; j < isize - 1; j++)    //inner loop
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout<<"Data after pass: "<<i+1<<"\n";
        display();
    }
}

template<class T>
void ArrayX<T>::BubbleSortEfficient()
{
    int i = 0, j = 0;
    T temp;
    bool bflag = true;

    if(sorted == true)
    {
        cout<<"Array is already sorted. Skipping efficient BubbleSort.\n";
        return;
    }

    for(i = 0 ; (i < isize && bflag == true); i++)      //outer loop
    {
        bflag = false;
        for(j = 0; j < isize - 1 - i; j++)    //inner loop
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bflag = true;
            }
        }
        cout<<"Data after pass: "<<i+1<<"\n";
        display();
    }
}

template<class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < isize - 1; i++)
    {
        min_index = i;
        for(j = i + 1 ; j < isize ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

template<class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < isize; i++)
    {
        selected = arr[i];
        for(j = i - 1; (j >= 0) && (arr[j] > selected); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = selected;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             Searching
//  Description :       Genric Implementation of Searching Algorithms
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayXX
{
    protected:
        T *arr;
        int isize;
    
    public:
        ArrayXX(int no);
        ~ArrayXX();

        void accept();
        void display();

        bool LinearSearch(T no);
        bool BinarySearch(T no);
        bool BinarySearchEfficient(T no);
        bool IsSorted();
};

template<class T>
ArrayXX<T>::ArrayXX(int no)
{
    this->isize = no;
    this->arr = new T[isize];
}

template<class T>
ArrayXX<T>::~ArrayXX()
{
    delete []arr;
}

template<class T>
void ArrayXX<T>::accept()
{
    cout<<"Enter "<<isize<<" elements:\n";
    int i = 0;
    for(i = 0; i < isize; i++)
    {
        cout<<"Enter the element number : "<<i+1<<"\n";
        cin>>arr[i];
    }
}

template<class T>
void ArrayXX<T>::display()
{
    int i = 0;
    for(i = 0; i < isize; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

template<class T>
bool ArrayXX<T>::IsSorted()
{
    bool bFlag = true;
    int i = 0;
    for(i = 0; i < isize - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }
    return bFlag;
}

template<class T>
bool ArrayXX<T>::LinearSearch(T no)
{
    int i = 0;
    bool bflag = false;

    for(i = 0 ; i < isize ; i++)
    {
        if(arr[i] == no)
        {
            bflag = true;
            break;
        }
    }
    return bflag;
}

template<class T>
bool ArrayXX<T>::BinarySearch(T no)
{
    int iStart = 0;
    int iEnd = 0;
    int iMid = 0;
    bool bFlag = false;

    if(!IsSorted())
    {
        cout<<"Warning: Array is not sorted. Binary search may not work correctly.\n";
        // Forcing linear search for unsorted data.
        return LinearSearch(no);
    }

    iStart = 0;
    iEnd = isize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < arr[iMid])     //first half
        {
            iEnd = iMid - 1;
        }
        else if(no > arr[iMid])     //second half
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

template<class T>
bool ArrayXX<T>::BinarySearchEfficient(T no)
{
    int iStart = 0;
    int iEnd = 0;
    int iMid = 0;
    bool bFlag = false;

    if(!IsSorted())
    {
        cout<<"Warning: Array is not sorted. Binary search may not work correctly.\n";
        return LinearSearch(no);
    }
    
    iStart = 0;
    iEnd = isize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        // Your efficient check
        if((arr[iMid] == no) || (arr[iStart] == no) || (arr[iEnd] == no))
        {
            bFlag = true;
            break;
        }
        else if(no < arr[iMid])     //first half
        {
            iEnd = iMid - 1;
            iStart = iStart + 1; // Since start is already checked
        }
        else if(no > arr[iMid])     //second half
        {
            iStart = iMid + 1;
            iEnd = iEnd - 1; // Since end is already checked
        }
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             DataSequence
//  Description :       Advanced Generic Implementation of a Sequential Data Container
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct seq_node
{
    T data;
    struct seq_node<T> *next;
};

template <class T>
class DataSequence
{
    private:
        struct seq_node<T> *first;
        int iCount;

    public:
        DataSequence();
        ~DataSequence();

        void Insert(T no); // Simplified insertion, defaults to end
        
        void Display();
        int Count();

        int FindFirst(T no);
        int FindLast(T no);
        T Aggregate();
        T FindMax();
        T FindMin();
};

template <class T>
DataSequence<T>::DataSequence()
{
    first = NULL;
    iCount = 0;
}

template <class T>
DataSequence<T>::~DataSequence()
{
    struct seq_node<T> *temp = first;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void DataSequence<T>::Insert(T no) // Inserts at the end
{
    struct seq_node<T> *newn = new struct seq_node<T>;
    struct seq_node<T> *temp = first;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DataSequence<T>::Display()
{
    struct seq_node<T> *temp = first;
    cout<<"Sequence: [ ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"]\n";
}

template <class T>
int DataSequence<T>::Count()
{
    return iCount;
}

template <class T>
int DataSequence<T>::FindFirst(T no)
{
    int index = 1;
    struct seq_node<T> *temp = first;
    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1; // Not found
}

template <class T>
int DataSequence<T>::FindLast(T no)
{
    int index = 1;
    int lastFoundIndex = -1; 
    struct seq_node<T> *temp = first;
    while(temp != NULL)
    {
        if(temp->data == no)
        {
            lastFoundIndex = index;
        }
        index++;
        temp = temp->next;
    }
    return lastFoundIndex;
}

template <class T>
T DataSequence<T>::Aggregate() // Summation
{
    T iSum = T(); // Default constructor for the type (e.g., 0 for int/float)
    struct seq_node<T> *temp = first;
    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;
}

template <class T>
T DataSequence<T>::FindMax()
{
    if (first == NULL) { return T(); }

    struct seq_node<T> *temp = first;
    T iMax = temp->data;

    while(temp != NULL)
    {
        if(temp->data > iMax)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
T DataSequence<T>::FindMin()
{
    if (first == NULL) { return T(); }

    struct seq_node<T> *temp = first;
    T iMin = temp->data;

    while(temp != NULL)
    {
        if(temp->data < iMin)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             NumericCollection
//  Description :       A Generic Collection for Numerical Analysis
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct collection_node
{
    T data;
    struct collection_node<T> *next;
};

template <class T>
class NumericCollection
{
    private:
        struct collection_node<T> *first;
        int iCount;

    public:
        NumericCollection();
        ~NumericCollection();

        void Add(T no); // Add element to the collection
        void Display();
        int Count();

        // Mathematical analysis methods
        void DisplayPerfect();
        void DisplayPrime();
        T SumEven();
        T SecondLargest();
        void DisplayDigitSum();
};

template <class T>
NumericCollection<T>::NumericCollection()
{
    first = NULL;
    iCount = 0;
}

template <class T>
NumericCollection<T>::~NumericCollection()
{
    struct collection_node<T> *temp = first;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void NumericCollection<T>::Add(T no)
{
    struct collection_node<T> *newn = new struct collection_node<T>;
    newn->data = no;
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
    iCount++;
}

template <class T>
void NumericCollection<T>::Display()
{
    struct collection_node<T> *temp = first;
    cout << "Collection Elements: ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int NumericCollection<T>::Count()
{
    return iCount;
}

template <class T>
void NumericCollection<T>::DisplayPerfect()
{
    struct collection_node<T> *temp = first;
    T iSum = 0;
    
    cout << "Perfect numbers are: ";
    while(temp != NULL)
    {
        iSum = 0;
        for(int i = 1; i <= (temp->data / 2); i++)
        {
            if((int)temp->data % i == 0)
            {
                iSum = iSum + i;
            }
        }
        if(iSum == temp->data && temp->data != 0)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
void NumericCollection<T>::DisplayPrime()
{
    struct collection_node<T> *temp = first;
    int iFactors = 0;
    
    cout << "Prime numbers are: ";
    while(temp != NULL)
    {
        iFactors = 0;
        for(int i = 1; i <= temp->data; i++)
        {
            if((int)temp->data % i == 0)
            {
                iFactors++;
            }
        }
        if(iFactors == 2)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
T NumericCollection<T>::SumEven()
{
    struct collection_node<T> *temp = first;
    T iSum = 0;

    while(temp != NULL)
    {
        if((int)temp->data % 2 == 0)
        {
            iSum = iSum + temp->data;
        }
        temp = temp->next;
    }
    return iSum;
}

template <class T>
T NumericCollection<T>::SecondLargest()
{
    if(first == NULL || first->next == NULL)
    {
        cout << "Collection needs at least two elements." << endl;
        return T();
    }

    struct collection_node<T> *temp = first;
    T iMax = 0, iMax2 = 0;

    if (first->data > first->next->data)
    {
        iMax = first->data;
        iMax2 = first->next->data;
    }
    else
    {
        iMax = first->next->data;
        iMax2 = first->data;
    }

    temp = first->next->next;

    while(temp != NULL)
    {
        if(temp->data > iMax)
        {
            iMax2 = iMax;
            iMax = temp->data;
        }
        else if(temp->data > iMax2 && temp->data != iMax)
        {
            iMax2 = temp->data;
        }
        temp = temp->next;
    }
    return iMax2;
}

template <class T>
void NumericCollection<T>::DisplayDigitSum()
{
    struct collection_node<T> *temp = first;
    int iSum = 0;
    int iDigit = 0;
    int iNum = 0;
    
    cout << "Sum of digits for each element: ";
    while(temp != NULL)
    {
        iNum = temp->data;
        iSum = 0;
        while(iNum != 0)
        {
            iDigit = iNum % 10;
            iSum = iSum + iDigit;
            iNum = iNum / 10;
        }
        cout << iSum << " ";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class :             DigitAnalyzer
//  Description :       A Generic Class for Digit-Level Analysis of Integers
//  Author :            Rishikesh Venkat Shinde
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct da_node // da for DigitAnalyzer
{
    T data;
    struct da_node<T> *next;
};

template <class T>
class DigitAnalyzer
{
    private:
        struct da_node<T> *first;
        int iCount;

    public:
        DigitAnalyzer();
        ~DigitAnalyzer();

        void Add(T no);
        void Display();
        int Count();

        // Digit manipulation methods
        void DisplayReverse();
        void DisplayPalindrome();
        void DisplaySmallestDigits();
        void DisplayLargestDigits();
};

template <class T>
DigitAnalyzer<T>::DigitAnalyzer()
{
    first = NULL;
    iCount = 0;
}

template <class T>
DigitAnalyzer<T>::~DigitAnalyzer()
{
    struct da_node<T> *temp = first;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void DigitAnalyzer<T>::Add(T no)
{
    struct da_node<T> *newn = new struct da_node<T>;
    newn->data = no;
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
    iCount++;
}

template <class T>
void DigitAnalyzer<T>::Display()
{
    struct da_node<T> *temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int DigitAnalyzer<T>::Count()
{
    return iCount;
}

template <class T>
void DigitAnalyzer<T>::DisplayReverse()
{
    struct da_node<T> *temp = first;
    int iDigit = 0;
    int iNum = 0;
    
    cout << "Reversed elements are: ";
    while(temp != NULL)
    {
        iNum = temp->data;
        cout << "| ";
        if (iNum == 0) { cout << 0; }
        while(iNum != 0)
        {
            iDigit = iNum % 10;
            cout << iDigit;
            iNum = iNum / 10;
        }
        cout << " |->";
        temp = temp->next;
    }
    cout << " NULL\n";
}

template <class T>
void DigitAnalyzer<T>::DisplayPalindrome()
{
    struct da_node<T> *temp = first;
    int iDigit = 0;
    int iRev = 0;
    int iNum = 0;

    cout << "Palindrome numbers are: ";
    while(temp != NULL)
    {
        iNum = temp->data;
        iRev = 0;
        
        int original = iNum;
        while(iNum != 0)
        {
            iDigit = iNum % 10;
            iRev = (iRev * 10) + iDigit;
            iNum = iNum / 10;
        }

        if(original == iRev)
        {
            cout << original << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
void DigitAnalyzer<T>::DisplaySmallestDigits()
{
    struct da_node<T> *temp = first;
    int iDigit = 0;
    int iNum = 0;
    int iSmall = 0;
    
    cout << "Smallest digit of each element: ";
    while(temp != NULL)
    {
        iNum = temp->data;
        iSmall = 9; // Initialize with the largest possible digit

        if (iNum == 0) { iSmall = 0; }
        
        while(iNum != 0)
        {
            iDigit = iNum % 10;
            if(iDigit < iSmall)
            {
                iSmall = iDigit;
            }
            iNum = iNum / 10;
        }
        cout << iSmall << " ";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
void DigitAnalyzer<T>::DisplayLargestDigits()
{
    struct da_node<T> *temp = first;
    int iDigit = 0;
    int iNum = 0;
    int iLarge = 0;

    cout << "Largest digit of each element: ";
    while(temp != NULL)
    {
        iNum = temp->data;
        iLarge = 0; // Initialize with the smallest possible digit

        if (iNum == 0) { iLarge = 0; }

        while(iNum != 0)
        {
            iDigit = iNum % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;
            }
            iNum = iNum / 10;
        }
        cout << iLarge << " ";
        temp = temp->next;
    }
    cout << "\n";
}


int main()
{
    cout << "/////////////////////////////////////////////////////////////\n";
    cout << "//        Data Structures Comprehensive Test Suite         //\n";
    cout << "/////////////////////////////////////////////////////////////\n\n";

    // ----------------------------------------------------------------------
    // 1. Testing Singly Linear Linked List with Integers
    // ----------------------------------------------------------------------
    cout << "------------------- 1. Testing SinglyLL<int> -------------------\n";
    SinglyLL<int> sllobj;
    sllobj.InsertFirst(51);
    sllobj.InsertFirst(21);
    sllobj.InsertFirst(11);
    cout << "After InsertFirst 3 times: ";
    sllobj.Display();
    sllobj.InsertLast(101);
    sllobj.InsertLast(111);
    cout << "After InsertLast 2 times: ";
    sllobj.Display();
    cout << "Count: " << sllobj.Count() << "\n";
    sllobj.InsertAtPos(55, 3);
    cout << "After InsertAtPos(55, 3): ";
    sllobj.Display();
    sllobj.DeleteFirst();
    cout << "After DeleteFirst: ";
    sllobj.Display();
    sllobj.DeleteLast();
    cout << "After DeleteLast: ";
    sllobj.Display();
    sllobj.DeleteAtPos(3);
    cout << "After DeleteAtPos(3): ";
    sllobj.Display();
    cout << "Final count: " << sllobj.Count() << "\n\n";

    // ----------------------------------------------------------------------
    // 2. Testing Doubly Linear Linked List with Characters
    // ----------------------------------------------------------------------
    cout << "------------------- 2. Testing DoublyLL<char> ------------------\n";
    DoublyLL<char> dllobj;
    dllobj.InsertFirst('C');
    dllobj.InsertFirst('B');
    dllobj.InsertFirst('A');
    cout << "After InsertFirst 3 times: ";
    dllobj.Display();
    dllobj.InsertLast('D');
    dllobj.InsertLast('E');
    cout << "After InsertLast 2 times: ";
    dllobj.Display();
    cout << "Count: " << dllobj.Count() << "\n";
    dllobj.InsertAtPos('X', 4);
    cout << "After InsertAtPos('X', 4): ";
    dllobj.Display();
    dllobj.DeleteFirst();
    cout << "After DeleteFirst: ";
    dllobj.Display();
    dllobj.DeleteLast();
    cout << "After DeleteLast: ";
    dllobj.Display();
    dllobj.DeleteAtPos(2);
    cout << "After DeleteAtPos(2): ";
    dllobj.Display();
    cout << "Final count: " << dllobj.Count() << "\n\n";

    // ... Add similar comprehensive tests for other classes ...
    // Example for StackX
    cout << "------------------- 3. Testing StackX<int> ---------------------\n";
    /*
    StackX<int> stack_obj;
    cout << "Pushing 10, 20, 30 onto the stack.\n";
    stack_obj.Push(10);
    stack_obj.Push(20);
    stack_obj.Push(30);
    stack_obj.Display();
    cout << "Count: " << stack_obj.Count() << "\n";
    cout << "Popped value: " << stack_obj.Pop() << "\n";
    cout << "Stack after one pop:\n";
    stack_obj.Display();
    cout << "Popping all elements...\n";
    cout << "Popped: " << stack_obj.Pop() << "\n";
    cout << "Popped: " << stack_obj.Pop() << "\n";
    cout << "Attempting to pop from empty stack:\n";
    stack_obj.Pop(); // This should display an error message
    cout << "Final count: " << stack_obj.Count() << "\n\n";
    */
    
    // Example for QueueX
    cout << "------------------- 4. Testing QueueX<float> -------------------\n";
    /*
    QueueX<float> queue_obj;
    cout << "Enqueuing 1.1, 2.2, 3.3 into the queue.\n";
    queue_obj.Enqueue(1.1f);
    queue_obj.Enqueue(2.2f);
    queue_obj.Enqueue(3.3f);
    queue_obj.Display();
    cout << "Count: " << queue_obj.Count() << "\n";
    cout << "Dequeued value: " << queue_obj.Dequeue() << "\n";
    cout << "Queue after one dequeue: ";
    queue_obj.Display();
    cout << "Final count: " << queue_obj.Count() << "\n\n";
    */

    // Example for BST
    cout << "------------------- 5. Testing BST<int> ------------------------\n";
    /*
    BST<int> bst_obj;
    bst_obj.Insert(50);
    bst_obj.Insert(30);
    bst_obj.Insert(70);
    bst_obj.Insert(20);
    bst_obj.Insert(40);
    bst_obj.Insert(60);
    bst_obj.Insert(80);
    cout << "BST created with 7 nodes.\n";
    cout << "Inorder traversal: "; bst_obj.DisplayInorder();
    cout << "Preorder traversal: "; bst_obj.DisplayPreorder();
    cout << "Postorder traversal: "; bst_obj.DisplayPostorder();
    cout << "Total nodes: " << bst_obj.Count() << "\n";
    cout << "Leaf nodes: " << bst_obj.CountLeaf() << "\n";
    cout << "Parent nodes: " << bst_obj.CountParent() << "\n";
    cout << "Searching for 40: " << (bst_obj.Search(40) ? "Found" : "Not Found") << "\n";
    cout << "Searching for 99: " << (bst_obj.Search(99) ? "Found" : "Not Found") << "\n\n";
    */

    cout << "/////////////////////////////////////////////////////////////\n";
    cout << "//                 End of Test Suite                     //\n";
    cout << "/////////////////////////////////////////////////////////////\n";

    return 0;
}