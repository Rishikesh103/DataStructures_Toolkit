#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   QueueX
//  Description       :   This class represents a generic Queue using a Singly Linear Linked List.
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
        struct node<T> *first;  // Pointer to the front of the queue
        int iCount;             // Number of elements in the queue

    public:
        QueueX();
        void Enqueue(T no);
        T Dequeue();
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   QueueX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class QueueX. It initializes the queue.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Enqueue
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//
//      [IN] T no.
//      Holds the element to be added to the queue.
//
//  Description       :
//      This function adds a new element to the rear of the queue (InsertLast).
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Dequeue
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function removes an element from the front of the queue (DeleteFirst).
//
//  Returns           :
//      T
//      Returns the removed element. If the queue is empty, it returns a
//      default-constructed value for the type T.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
T QueueX<T> :: Dequeue()         //deletefirst    
{
    struct node<T> *temp = NULL;
    T value;
    if(first == NULL)
    {
        cout<<"Unable to pop as queue is empty\n";
        return T(); // Return default value for type T for safety
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays all elements in the queue.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void QueueX<T> :: Display()
{
    struct node<T> *temp = NULL;
    temp = first;
    cout << "Elements of Queue are: ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of elements in the queue.
//
//  Returns           :
//      int
//      Number of elements in the queue.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int QueueX<T> :: Count()
{
    return iCount;
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   StackX
//  Description       :   This class represents a generic Stack using a Singly Linear Linked List.
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   StackX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class StackX. It initializes the stack.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Push
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//
//      [IN] T no.
//      Holds the element to be added to the stack.
//
//  Description       :
//      This function adds a new element to the top of the stack (InsertFirst).
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Pop
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function removes an element from the top of the stack (DeleteFirst).
//
//  Returns           :
//      T
//      Returns the removed element. If the stack is empty, it returns a
//      default-constructed value for the type T.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
T StackX<T> :: Pop()
{
    struct node<T> *temp = NULL;
    T value;
    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return T(); // Return default value for type T
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays all elements in the stack from top to bottom.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Display()
{
    struct node<T> *temp = NULL;
    temp = first;
    cout << "Elements of Stack are: \n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of elements in the stack.
//
//  Returns           :
//      int
//      Number of elements in the stack.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T> :: Count()
{
    return iCount;
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   SinglyCLL
//  Description       :   This class represents a generic Singly Circular Linked List.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        int iCount;
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
    
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   SinglyCLL
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class SinglyCLL.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    iCount = 0;
    first = NULL;
    last = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the beginning of the list.
//
//  Description       :
//      This function inserts a new node at the beginning of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    struct SinglyCLLnode<T>* newn = new struct SinglyCLLnode<T>;

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
    last->next = first; // Maintain circular nature
    iCount++;
 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the end of the list.
//
//  Description       :
//      This function inserts a new node at the end of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    struct SinglyCLLnode<T>* newn = new struct SinglyCLLnode<T>;

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
    last->next = first; // Maintain circular nature
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the entire linked list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: Display()
{
    if(first == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }
    struct SinglyCLLnode<T>* temp = first;
    cout << "Elements of the list are: ";
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of nodes in the list.
//
//  Returns           :
//      int
//      The total number of nodes.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the first node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first == last) // Only one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else // More than one node
    {
        struct SinglyCLLnode<T>* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the last node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteLast()
{
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
        struct SinglyCLLnode<T>* temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted.
//      [IN] int pos.
//      The position at which to insert the data.
//
//  Description       :
//      This function inserts a new node at a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
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
        struct SinglyCLLnode<T>* newn = new struct SinglyCLLnode<T>;
        struct SinglyCLLnode<T>* temp = first;

        newn->data = no;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int pos.
//      The position from which to delete the node.
//
//  Description       :
//      This function deletes a node from a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        struct SinglyCLLnode<T>* temp = first;
        struct SinglyCLLnode<T>* target = NULL;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   DoublyCLL
//  Description       :   This class represents a generic Doubly Circular Linked List.
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DoublyCLL
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class DoublyCLL.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the beginning of the list.
//
//  Description       :
//      This function inserts a new node at the beginning of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;

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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the end of the list.
//
//  Description       :
//      This function inserts a new node at the end of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;

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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the entire linked list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: Display()
{
    if(first == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }

    struct DoublyCLLnode<T> * temp = first;

    cout<<"Elements of the linkedlist are : \n";
    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
    } while (temp != first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of nodes in the list.
//
//  Returns           :
//      int
//      The total number of nodes.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the first node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   //LL is empty
    {
        return;
    }
    else if(first == last)         // ll contains one node
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
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the last node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted.
//      [IN] int pos.
//      The position at which to insert the data.
//
//  Description       :
//      This function inserts a new node at a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
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
        struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;
        struct DoublyCLLnode<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int pos.
//      The position from which to delete the node.
//
//  Description       :
//      This function deletes a node from a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        struct DoublyCLLnode<T> * temp = first;
        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   SinglyLL
//  Description       :   This class represents a generic Singly Linear Linked List.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
    private:
        int iCount;
        struct SinglyLLnode<T> * first;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   SinglyLL
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class SinglyLL.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL<T> :: SinglyLL()
{
    iCount = 0;
    first = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of nodes in the list.
//
//  Returns           :
//      int
//      The total number of nodes.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the entire linked list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: Display()
{
    struct SinglyLLnode<T> * temp = first;
    cout << "Elements of the list are: ";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the beginning of the list.
//
//  Description       :
//      This function inserts a new node at the beginning of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SinglyLLnode<T> * newn = new struct SinglyLLnode<T>;
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the end of the list.
//
//  Description       :
//      This function inserts a new node at the end of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct SinglyLLnode<T> * newn = new struct SinglyLLnode<T>;
    struct SinglyLLnode<T> * temp = first;
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the first node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    
    struct SinglyLLnode<T> * target = first;
    first = first->next;
    delete target;
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the last node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: DeleteLast()
{
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
        struct SinglyLLnode<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted.
//      [IN] int pos.
//      The position at which to insert the data.
//
//  Description       :
//      This function inserts a new node at a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
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
        struct SinglyLLnode<T> * temp = first;
        struct SinglyLLnode<T> * newn = new struct SinglyLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int pos.
//      The position from which to delete the node.
//
//  Description       :
//      This function deletes a node from a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        struct SinglyLLnode<T> * temp = first;
        struct SinglyLLnode<T> * target = NULL;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next; 
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   DoublyLL
//  Description       :   This class represents a generic Doubly Linear Linked List.
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DoublyLL
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class DoublyLL.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    first = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function counts the number of nodes in the list.
//
//  Returns           :
//      int
//      The total number of nodes.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the entire linked list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> * temp = first;
    cout << "Elements of the list are: ";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the beginning of the list.
//
//  Description       :
//      This function inserts a new node at the beginning of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to insert at the end of the list.
//
//  Description       :
//      This function inserts a new node at the end of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteFirst
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the first node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL) // List is empty
    {
        return;
    }
    else if(first->next == NULL) // List has one node
    {
        delete first;
        first = NULL;
    }
    else // List has more than one node
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteLast
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function deletes the last node of the list.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(first == NULL) // List is empty
    {
        return;
    }
    else if(first->next == NULL) // List has one node
    {
        delete first;
        first = NULL;
    }
    else // List has more than one node
    {
        struct DoublyLLnode<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted.
//      [IN] int pos.
//      The position at which to insert the data.
//
//  Description       :
//      This function inserts a new node at a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
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
        struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
        struct DoublyLLnode<T> * temp = first;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < pos-1; i++)
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DeleteAtPos
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int pos.
//      The position from which to delete the node.
//
//  Description       :
//      This function deletes a node from a specified position.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        struct DoublyLLnode<T> * temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   BST
//  Description       :   This class represents a generic Binary Search Tree.
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   BST
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the constructor of class BST.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
BST<T> :: BST()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Insert
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted into the tree.
//
//  Description       :
//      This function inserts a new node into the Binary Search Tree.
//      Duplicate elements are not allowed.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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
                cout<<"Duplicate element: unable to insert\n";
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Search
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to search for in the tree.
//
//  Description       :
//      This function searches for a given element in the tree.
//
//  Returns           :
//      bool
//      Returns true if the element is found, otherwise false.
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DisplayInorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function initiates the Inorder traversal of the BST.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: DisplayInorder()
{
    Inorder(first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Inorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] struct BSTnode<T> *temp
//      The current node in the recursive traversal.
//
//  Description       :
//      This is a private helper function that performs a recursive
//      Inorder (Left-Root-Right) traversal.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DisplayPreorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function initiates the Preorder traversal of the BST.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: DisplayPreorder()
{
    Preorder(first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Preorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] struct BSTnode<T> *temp
//      The current node in the recursive traversal.
//
//  Description       :
//      This is a private helper function that performs a recursive
//      Preorder (Root-Left-Right) traversal.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DisplayPostorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function initiates the Postorder traversal of the BST.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: DisplayPostorder()
{
    Postorder(first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Postorder
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] struct BSTnode<T> *temp
//      The current node in the recursive traversal.
//
//  Description       :
//      This is a private helper function that performs a recursive
//      Postorder (Left-Right-Root) traversal.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Count
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function returns the total number of nodes in the BST.
//
//  Returns           :
//      int
//      The total count of nodes.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   CountLeaf
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function initiates the counting of leaf nodes.
//
//  Returns           :
//      int
//      The total number of leaf nodes.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: CountLeaf()
{
    return CountLeafNodes(first);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   CountLeafNodes
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] struct BSTnode<T> *temp
//      The current node in the recursive traversal.
//
//  Description       :
//      This private helper function recursively counts the leaf nodes
//      (nodes with no children) in the tree.
//
//  Returns           :
//      int
//      The count of leaf nodes in the subtree rooted at temp.
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   CountParent
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function initiates the counting of parent nodes.
//
//  Returns           :
//      int
//      The total number of parent nodes.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: CountParent()
{
    return CountParentNodes(first);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   CountParentNodes
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] struct BSTnode<T> *temp
//      The current node in the recursive traversal.
//
//  Description       :
//      This private helper function recursively counts the parent nodes
//      (nodes with at least one child) in the tree.
//
//  Returns           :
//      int
//      The count of parent nodes in the subtree rooted at temp.
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   ArrayX
//  Description       :   This class provides a generic array with various sorting algorithms.
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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   ArrayX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int no.
//      The size of the array to be created.
//
//  Description       :
//      This is the constructor of class ArrayX. It allocates memory for the array.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayX<T>::ArrayX(int no)
{
    this->isize = no;
    this->arr = new T[isize];
    this->sorted = true; // Assume sorted until elements are accepted
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   ~ArrayX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the destructor of class ArrayX. It deallocates the array memory.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayX<T>::~ArrayX()
{
    delete []arr;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   accept
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function accepts elements from the user to fill the array.
//      It also checks if the input array is already sorted.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::accept()
{
    cout<<"Enter "<<isize<<" elements:\n";
    sorted = true; // Reset sorted flag before accepting new values
    for(int i = 0; i < isize; i++)
    {
        cout<<"Enter element number "<<i+1<<": ";
        cin>>arr[i];

        if(i > 0 && arr[i] < arr[i - 1])
        {
            sorted = false;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the elements of the array.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::display()
{
    cout << "Array elements are: ";
    for(int i = 0; i < isize; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   BubbleSort
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function sorts the array using the Bubble Sort algorithm.
//      It compares adjacent elements and swaps them if they are in the wrong order.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::BubbleSort()
{
    if(sorted == true)
    {
        cout<<"Array is already sorted. Skipping BubbleSort.\n";
        return;
    }

    for(int i = 0 ; i < isize; i++)      // Passes
    {
        for(int j = 0; j < isize - 1; j++)    // Comparisons
        {
            if(arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    sorted = true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   BubbleSortEfficient
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function sorts the array using an efficient version of Bubble Sort.
//      It stops if no swaps are made during a pass, indicating the array is sorted.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::BubbleSortEfficient()
{
    if(sorted == true)
    {
        cout<<"Array is already sorted. Skipping efficient BubbleSort.\n";
        return;
    }
    bool bflag = true;
    for(int i = 0 ; i < isize && bflag == true; i++)
    {
        bflag = false;
        for(int j = 0; j < isize - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bflag = true;
            }
        }
    }
    sorted = true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   SelectionSort
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function sorts the array using the Selection Sort algorithm.
//      It repeatedly finds the minimum element and puts it at the beginning.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::SelectionSort()
{
    for(int i = 0; i < isize - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1 ; j < isize ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            T temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    sorted = true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   InsertionSort
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function sorts the array using the Insertion Sort algorithm.
//      It builds the final sorted array one item at a time.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T>::InsertionSort()
{
    for(int i = 1; i < isize; i++)
    {
        T selected = arr[i];
        int j = i - 1;
        while((j >= 0) && (arr[j] > selected))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
    sorted = true;
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   ArrayXX
//  Description       :   This class provides a generic array with searching algorithms.
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
        bool IsSorted();
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   ArrayXX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] int no.
//      The size of the array to be created.
//
//  Description       :
//      This is the constructor of class ArrayXX.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayXX<T>::ArrayXX(int no)
{
    this->isize = no;
    this->arr = new T[isize];
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   ~ArrayXX
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This is the destructor of class ArrayXX.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayXX<T>::~ArrayXX()
{
    delete []arr;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   accept
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function accepts elements from the user to fill the array.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayXX<T>::accept()
{
    cout<<"Enter "<<isize<<" elements:\n";
    for(int i = 0; i < isize; i++)
    {
        cout<<"Enter element number "<<i+1<<": ";
        cin>>arr[i];
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   display
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function displays the elements of the array.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayXX<T>::display()
{
    cout << "Array elements are: ";
    for(int i = 0; i < isize; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   IsSorted
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      This function checks if the array is sorted in ascending order.
//
//  Returns           :
//      bool
//      Returns true if the array is sorted, otherwise false.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T>::IsSorted()
{
    for(int i = 0; i < isize - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   LinearSearch
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The element to search for.
//
//  Description       :
//      This function searches for an element sequentially from beginning to end.
//
//  Returns           :
//      bool
//      Returns true if the element is found, otherwise false.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T>::LinearSearch(T no)
{
    for(int i = 0 ; i < isize ; i++)
    {
        if(arr[i] == no)
        {
            return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   BinarySearch
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The element to search for.
//
//  Description       :
//      This function searches for an element in a sorted array by repeatedly
//      dividing the search interval in half.
//
//  Returns           :
//      bool
//      Returns true if the element is found, otherwise false.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T>::BinarySearch(T no)
{
    if(!IsSorted())
    {
        cout<<"Warning: Array is not sorted. Binary search is not applicable.\n";
        return false;
    }

    int iStart = 0;
    int iEnd = isize - 1;

    while(iStart <= iEnd)
    {
        int iMid = iStart + ((iEnd - iStart) / 2);

        if(arr[iMid] == no)
        {
            return true;
        }
        else if(no < arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else
        {
            iStart = iMid + 1;
        }
    }
    return false;
}



///////////////////////////////////////////////////////////////////////////////
//
//  Class Name        :   DataSequence
//  Description       :   A generic sequential container for basic data analysis.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
class DataSequence
{
    private:
        struct node<T> *first;
        int iCount;

    public:
        DataSequence();
        ~DataSequence();

        void Insert(T no);
        void Display();
        int Count();

        int FindFirst(T no);
        int FindLast(T no);
        T Aggregate();
        T FindMax();
        T FindMin();
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   DataSequence
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      Constructor for DataSequence class.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
DataSequence<T>::DataSequence()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   ~DataSequence
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :   NONE
//  Description       :
//      Destructor for DataSequence class. Frees all nodes.
//
//  Returns           :   NONE
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
DataSequence<T>::~DataSequence()
{
    struct node<T> *temp = first;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name     :   Insert
//  Function Date     :   19/09/2025
//  Function Author   :   Rishikesh Shinde
//  Parameters        :
//      [IN] T no.
//      The data to be inserted at the end of the sequence.
//
//  Description       :
//      Inserts a new element at the end of the data sequence.
//
//  Returns           :   void
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void DataSequence<T>::Insert(T no)
{
    struct node<T> *newn = new struct node<T>;
    struct node<T> *temp = first;
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

// ... Documentation for Display, Count, FindFirst, FindLast, Aggregate, FindMax, FindMin, etc.
// for all remaining classes would continue in this exact format.

///////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	main
//	Function Date		:	19/09/2025
//	Function Author	    :	Rishikesh Shinde
//  Parameters          :   NONE
//	Description         :
//		This is the entry point function. It serves as a test driver
//      for the various data structures implemented in this file.
//  Returns             :
//      int
//      Returns 0 upon successful execution.
//
///////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "/////////////////////////////////////////////////////////////\n";
    cout << "//        Data Structures Comprehensive Test Suite         //\n";
    cout << "/////////////////////////////////////////////////////////////\n\n";

    // Test for SinglyLL
    cout << "--- Testing SinglyLL<int> ---\n";
    SinglyLL<int> sllobj;
    sllobj.InsertFirst(51);
    sllobj.InsertFirst(21);
    sllobj.InsertFirst(11);
    sllobj.Display(); // Expected: |11|->|21|->|51|->NULL
    sllobj.InsertLast(101);
    sllobj.Display(); // Expected: |11|->|21|->|51|->|101|->NULL
    cout << "Count is: " << sllobj.Count() << "\n\n";

    // Test for DoublyLL
    cout << "--- Testing DoublyLL<char> ---\n";
    DoublyLL<char> dllobj;
    dllobj.InsertFirst('B');
    dllobj.InsertFirst('A');
    dllobj.InsertLast('C');
    dllobj.Display(); // Expected: |A|<=>|B|<=>|C|<=>NULL
    cout << "Count is: " << dllobj.Count() << "\n\n";

    // Test for Stack
    cout << "--- Testing StackX<int> ---\n";
    StackX<int> stack_obj;
    stack_obj.Push(10);
    stack_obj.Push(20);
    stack_obj.Push(30);
    stack_obj.Display();
    cout << "Popped: " << stack_obj.Pop() << endl; // Expected: 30
    stack_obj.Display();
    cout << "Count is: " << stack_obj.Count() << "\n\n";

    // Test for Queue
    cout << "--- Testing QueueX<float> ---\n";
    QueueX<float> queue_obj;
    queue_obj.Enqueue(10.5f);
    queue_obj.Enqueue(20.5f);
    queue_obj.Enqueue(30.5f);
    queue_obj.Display();
    cout << "Dequeued: " << queue_obj.Dequeue() << endl; // Expected: 10.5
    queue_obj.Display();
    cout << "Count is: " << queue_obj.Count() << "\n\n";
    
    // Test for ArrayX (Sorting)
    cout << "--- Testing ArrayX<int> (Sorting) ---\n";
    ArrayX<int> sort_obj(5);
    sort_obj.accept(); // User enters 5 elements, e.g., 50 20 40 10 30
    cout << "Original Array: ";
    sort_obj.display();
    sort_obj.BubbleSort();
    cout << "Sorted Array: ";
    sort_obj.display();
    cout << "\n";

    cout << "/////////////////////////////////////////////////////////////\n";
    cout << "//                 End of Test Suite                     //\n";
    cout << "/////////////////////////////////////////////////////////////\n";

    return 0;
}