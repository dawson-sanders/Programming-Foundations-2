#ifndef PERSON_NODE_H
#define PERSON_NODE_H
//-----------------------------------------------------------
//  Purpose:    Header file for the Machine container class.
//  Author:     Dawson Sanders
//-----------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//-----------------------------------------------------------
// Define the Machine Class  
//-----------------------------------------------------------
class Machine
{
    public:
        //Constructors
        Machine();
        Machine(string gametitle, string manufacturer, int year, string type);
        Machine(const Machine & m);
        ~Machine();
        
        // Get methods
        string getgameTitle();
        string getManufacturer();
        int getYear();
        string getType();

        // Set methods
        void setgameTitle(string gametitle);
        void setManufacturer(string manufacturer);
        void setYear(int year);
        void setType(string type);
        
        // Print method
        void Print();
        
    private:
        //object attributes
        string gameTitle;
        string Manufacturer;
        int Year;
        string Type;
};
#endif

