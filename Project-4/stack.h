#ifndef STACK_H
#define STACK_H
//-----------------------------------------------------------
//  Purpose:    Header file for the string Stack class.
//  Author:     Dawson Sanders 
//-----------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
class StackNode
{
    public:
        string str;
        StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
class Stack
{
    public:
        // Constructors
        Stack();
        Stack(const Stack & stack);
        ~Stack();

        // Methods
        bool IsFull() const;
        bool IsEmpty() const;
        void Push(string str);
        string Pop();
        string Top();
        void Print() const; //In the real world there is not a print method when using stacks

    private:
        StackNode *Head;
};

#endif