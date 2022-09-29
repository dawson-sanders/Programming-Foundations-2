//-----------------------------------------------------------
// Purpose: Main file for Recursion Project.
// Author:  Dawson Sanders
//-----------------------------------------------------------
#include "Machine.h"

//-----------------------------------------------------------
// Reading file method for machine.txt file
//-----------------------------------------------------------
void readMachine(vector<Machine> &machine, string filename)
{
    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        cout << "Could not open machine.txt\n";
    
    // Checks to see if vector is empty before reading 
    //cout << "Size: " << machine.size() << endl;
    
    string line;
    string Type;
    
    do
    {
        Machine input;
        
        getline(din,line,',');
        input.setgameTitle(line);
        
        getline(din,line,',');
        input.setManufacturer(line);
        
        getline(din,line,',');
        input.setYear(stoi(line));
        
        din >> Type;
        input.setType(Type);  
        
        //input.Print();
        machine.push_back(input);  
        
    }while(getline(din,line) && !din.fail()); 
    
    // Checks and sees if vector is filled with objects
    //cout << "Size: " << machine.size() << endl;
    
    // Close input file
    din.close();               
}

//-----------------------------------------------------------
// Reading file method for machineyear.txt file
//-----------------------------------------------------------
void readMachineYear(vector<Machine> &year, string filename)
{
    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        cout << "Could not open machineyear.txt\n";
    
    // Checks to see if vector is empty before reading 
    //cout << "Size: " << year.size() << endl;
    
    string line;
    string Type;
    
    while(!din.eof())
    {
        Machine input;
        
        getline(din,line,',');
        input.setgameTitle(line);
        
        getline(din,line,',');
        input.setManufacturer(line);
        
        getline(din,line,',');
        input.setYear(stoi(line));
        
        din >> Type;
        input.setType(Type);  
        
        //input.Print();
        year.push_back(input);   
    }    
    
    // Checks and sees if vector is filled with objects
    //cout << "Size: " << year.size() << endl;
    
    // Close input file
    din.close(); 
}


//-----------------------------------------------------------
// Recursive Search Function for a game title
//-----------------------------------------------------------
void recursiveSearch(vector<Machine> machine, string gameTitle, int low, int high)
{
    int mid = (low + high)/2;
    
    //cout << "low: " << low << " mid: "<< mid << " high: " << high << endl;
    
    // Checking termination condition
    if(low > high)
        cout << "Game Title Not Found! Please Try Again.";
    else if(machine[mid].getgameTitle() == gameTitle)
    {
        cout << machine[mid].getgameTitle() << " " << machine[mid].getManufacturer() << " " 
        << machine[mid].getYear() << " " << machine[mid].getType() << endl;
    }
    
    // handle recursive case
    else if(machine[mid].getgameTitle() < gameTitle)
        return recursiveSearch(machine, gameTitle, mid + 1, high);
    
    else if(machine[mid].getgameTitle() > gameTitle)
        return recursiveSearch(machine, gameTitle, low, mid - 1);
}   

//-----------------------------------------------------------
// Iterative Search Function for a specific year
//-----------------------------------------------------------
void iterativeSearch(vector<Machine> year, int Year, int low, int high)
{   
    // Search vector using divide and conquer approach
    int mid = (low + high) / 2;

    while((year[mid].getYear() != Year) && (high >= low))
    {
        // Change low to search right half
        if(year[mid].getYear() < Year)
            low = mid + 1;
        
        // Change max to search left half 
        else if(year[mid].getYear() > Year) 
            high = mid - 1;
            
        // Update mid location
        mid = (low + high) / 2; 
        
        //cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
    }    
    
    // Return results of search
    if(year[mid].getYear() == Year)
    {
        while(year[mid - 1].getYear() == Year)
            mid = mid - 1;
        
        while(year[mid].getYear() == Year)
        {
            cout << year[mid].getgameTitle() << " " << year[mid].getManufacturer() << " " << year[mid].getYear() << " " << year[mid].getType() << endl;
            mid = mid + 1;
        }
    }
    else
        cout << "Year Not Found! Please Try Again.";

}    


int main()
{
//-----------------------------------------------------------
// Testing Machine Class 
//-----------------------------------------------------------
/*    // Initializing machine object
    Machine test;

    // Testting set methods
    test.setgameTitle("Swords of Stone");
    test.setManufacturer("Rawlings Company");
    test.setYear(1950);
    test.setType("Pinball");
    test.Print();
*/

//-----------------------------------------------------------
// Reading in machine.txt and machineyear.txt files testing
//-----------------------------------------------------------
/*  
    // Testing reading files
    readMachine("machine.txt");
    readMachineYear("machineyear.txt");
*/  


//-----------------------------------------------------------
// Testing search functions
//-----------------------------------------------------------
    //vector<Machine> machines;
    //readMachine(machines,"machine.txt");
    //for(int i = 0; i < machines.size(); ++i)
    //{
       // machines[i].Print();
    //}
    //cout << recursiveSearch(machines,"Ace Attacker", 0, 100);
    //cout << " " << endl;
    
    //vector<Machine> years;
    //readMachineYear(years,"machineyear.txt");
    //for(int i = 0; i < years.size(); ++i)
    //{
        //years[i].Print();
    //}
    //iterativeSearch(years,1950,0,100);


//-----------------------------------------------------------
// User Interface 
//-----------------------------------------------------------
    // Initializing choice 
    int choice;
    
    // do while loop for user interface 
    do
    {
        // Menu statements 
        cout << " " << endl;
        cout << "Welcome to the pinball and arcade machine checker. Please choose from the following: " << endl;
        cout << "  " << 1 << ") Use a recursive search for game title" << endl;
        cout << "  " << 2 << ") Use an iterative search for all machines manufactured in a specific year" << endl;
        cout << "  " << 3 << ") Exit" << endl << endl;
        cout << "Please enter your choice (1,2,3): ";
        cin >> choice;
        cout << endl;
        
        // Error checking for if user inputs an invalid integer choice
        while (choice < 1 || choice > 3)
		{
			cout << "Error! Invalid choice! Try Again" << endl;
			cout << "Please enter your choice (1,2,3): ";
			cin >> choice;
			cout << endl;
		} 
		
		// Initializing vectors
		vector<Machine> machines;
		vector<Machine> years;
		string title;
		
		// Switch statement for user choices
		switch(choice)
		{
		    case 1:
		    cout << "Please input game title you would like to search for: ";
		    getline(cin,title);
		    getline(cin,title);
		    readMachine(machines,"machine.txt");
		    cout << endl << endl;
		    recursiveSearch(machines, title, 0, 5288);  //5288 in big file, 102 in small file
		    cout << endl;  
		    
		    break;
		    
		    case 2:
		    int Y;
		    cout << "Please input year you would like to search for: ";
		    cin >> Y;
            readMachineYear(years,"machineyear.txt");
            cout << endl << endl;
            iterativeSearch(years, Y, 0, 5288);    //5288 in big file, 101 in small file
            cout << endl;
		    break;
		    
		    case 3:
		    exit(1);
		    break;
		}

    }while(choice <= 3 && choice >= 1);

    return 0;
}













