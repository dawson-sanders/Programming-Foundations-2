//-----------------------------------------------------------
//  Purpose:    Implementation of integer Stack class.
//  Author:     Dawson Sanders
//-----------------------------------------------------------
#include "stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
    Head = NULL;
}

//----------------------------------------------
// Copy constructor function.
//----------------------------------------------
Stack::Stack(const Stack & stack)
{
    // Create first node
    StackNode *copy = new StackNode();
    Head = copy;

    // Walk list to copy nodes
    StackNode *ptr = stack.Head;
    while (ptr != NULL)
    {
        copy->Next = new StackNode();
        copy = copy->Next;
        copy->str = ptr->str;
        copy->Next = NULL;
        ptr = ptr->Next;
    }

    // Tidy first node
    copy = Head;
    Head = copy->Next;
    delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
    // Walk stack deleting data
    while (Head != NULL)
    {
        StackNode *Temp = Head;
        Head = Head->Next;
        delete Temp;
    }

    // Reset head
    Head = NULL;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull() const
{
    return false;
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty() const
{
    return (Head == NULL);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(string str)
{
    // Allocate space for data
    StackNode *Temp = new StackNode();
    if (Temp == NULL)
        return;

    // Insert data at head of list
    Temp->str = str;
    Temp->Next = Head;
    Head = Temp;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
string Stack::Pop()
{
    // Check for empty stack
    if (IsEmpty())
        return 0;

    // Pop item from linked list
    StackNode *Temp = Head;
    Head = Temp->Next;
    string ret = Temp->str;
    delete Temp;
    return ret;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
string Stack::Top() 
{
    // Check for empty stack
    if (IsEmpty())
        return 0;

    // Return information from node
    return Head->str;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print() const
{
    // Walk the stack printing data
    StackNode *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->str << " ";
        Temp = Temp->Next;
    }
    cout << endl;   
}   




