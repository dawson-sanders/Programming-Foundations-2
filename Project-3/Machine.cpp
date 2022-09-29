//----------------------------------------------
// Purpose: Implement Machine container class 
// Author:  Dawson Sanders
//----------------------------------------------
#include "Machine.h"

//----------------------------------------------
// Constructor (Default)
//----------------------------------------------
Machine::Machine()
{
    gameTitle = "blank";
    Manufacturer = "blank";
    Year = -1;
    Type = "blank";
}

//----------------------------------------------
// Constructor Method with Parameters (Non-Default)
//----------------------------------------------
Machine::Machine(string gametitle, string manufacturer, int year, string type)
{
    gameTitle = gametitle;
    Manufacturer = manufacturer;
    Year = year;
    Type = type;
    
}

//----------------------------------------------
// Copy Constructor 
//----------------------------------------------
Machine::Machine(const Machine & m)
{
    gameTitle = m.gameTitle;
    Manufacturer = m.Manufacturer;
    Year = m.Year;
    Type = m.Type;
}

//----------------------------------------------
// Deconstructor
//----------------------------------------------
Machine::~Machine()
{
    //Empty
}

//----------------------------------------------
// Get methods
//----------------------------------------------
string Machine::getgameTitle() 
{
    return gameTitle;
}

//----------------------------------------------
string Machine::getManufacturer() 
{
    return Manufacturer;
}

//----------------------------------------------
int Machine::getYear() 
{
    return Year;
}

//----------------------------------------------
string Machine::getType() 
{
    return Type;
}

//----------------------------------------------
// Set methods
//----------------------------------------------
void Machine::setgameTitle(string gametitle)
{
    gameTitle = gametitle;
}

//----------------------------------------------
void Machine::setManufacturer(string manufacturer)
{
    Manufacturer = manufacturer;
}

//----------------------------------------------
void Machine::setYear(int year)
{
   Year = year;
}

//----------------------------------------------
void Machine::setType(string type)
{
   Type = type;
}


//----------------------------------------------
// Print Method 
//----------------------------------------------
void Machine::Print() 
{
    cout << gameTitle << "    " << Manufacturer << "    " << Year << "    "  << Type << endl;
}








