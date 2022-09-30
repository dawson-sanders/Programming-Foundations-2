//-----------------------------------------------------------
//  Purpose:    Main file for the string stack project
//  Author:     Dawson Sanders
//-----------------------------------------------------------
#include "stack.h"

bool check_braces(string filename) 
{
    // Declaring stack object
    Stack stack;
    
    // Declaring a character variable called temp to read in the file one character at a time 
    char temp;
    
    // Reading input json file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        cout << "Could not open JSON file\n";    
    
    while (din >> temp)
    {
        string tempString;
        tempString.append(1, temp);
        
        // Push brace onto stack
        if (tempString == "{")
        {
            if (stack.IsFull())   
                return false; 

            stack.Push(tempString);
        }
        
        // Pop brace from stack
        else if (tempString == "}")
        {
            if (stack.IsEmpty())
                return false;
            if (stack.Top() != "{")
                return false;
                
            stack.Pop();
        }
        
        // Push Bracket onto stack
        if (tempString == "[")
        {
            if (stack.IsFull())
                return false;
            
            stack.Push(tempString);
        }
        
        // Pop Bracket from stack
        else if (tempString == "]")
        {
            if (stack.IsEmpty())
                return false;
            if (stack.Top() != "[")
                return false;
                
            stack.Pop();
        }
    }  
    
    // Check if stack is empty at the end
    return stack.IsEmpty();
    // If stack is empty after reading in the JSON file then syntax is valid
    // If stack is NOT empty after reading in the JSON file then syntax is invalid
    
    // Close file
    din.close();    

    return 0;
}

//-----------------------------------------------------------
// JSON file formatter function
//-----------------------------------------------------------
void format_json(string filename)
{
    // Declaring variables 
    char temp;
    int tab = 0;
    int symbols = 0;
    
     // Reading input json file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        cout << "Could not open JSON file\n";    
        
    ofstream dout;
    dout.open("output.json");
    while (din >> temp)
	{
	    string tempString;
        tempString.append(1, temp);
	    
        if (tempString == "{")
		{
			symbols++;

			if(tempString == "{")   
			{
			    tab = symbols;
			    tab--;
			}
			
			if (symbols > 0)
				dout << endl;;
			while (tab)
			{
				dout << "  ";
				tab--;
			}
			dout << tempString << endl;
			
			tab = symbols;
			while (tab)
			{
				dout << "  ";
				tab--;
			}
		}
		
		else if (tempString == ":")
		{
			dout << ": ";
		}
			
		else if (tempString == ",")
		{
		    dout << "\n";     //if we did ",\n" the commas would print in the correct lines but with more spaces than needed
		 
 			tab = symbols + 1;
 			while (tab)
 			{
 				dout << " ";
 				tab--;
 			}
		}
			
		else if (tempString == "}")
		{
			tab = symbols;
			dout << "\n";   
			while (tab)
			{
				dout << " ";
				tab--;
			}
			dout << tempString << ",";
			symbols--;
			tab = symbols + 1;

			while (tab)
			{
				dout << "\t";
				tab--;
			}
		}
		
		else if (tempString == "[")
		{
		    tab = symbols;
		    dout << "\n";
		    while (tab)
			{
				dout << " ";
				tab--;
			}
			dout << tempString << "";
		}
		
		else if (tempString == "]")
		{
		    tab = symbols;
			dout << "\n";
			while (tab)
			{
				dout << " ";
				tab--;
			}
			dout << tempString << ",";
			symbols--;
			tab = symbols + 1;

			while (tab)
			{
				dout << "";
				tab--;
			}
		}
			
 		else
 		{
			if (tempString == "\n" || tempString == "\t")
				break;
			else
				dout << tempString;
		}
	}
	
	// Close output file
	dout.close();
	
	//Close input file
	din.close();
    
}



//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
//-----------------------------------------------------------
// Testing stack class methods
//-----------------------------------------------------------   
/*    Stack s;
    s.Push("}");
    s.Push("{");
    s.Print();     */

//-----------------------------------------------------------
// User Interface
//----------------------------------------------------------- 
    // Declaring variables
    string filename;
    int choice;

    do
    {
        // Menu Statements
        cout << "Welcome to the JSON file syntax and format checker!" << endl;
        cout << "Please enter the name of the JSON file you would like to check: ";
        cin >> filename;
    
        cout << "-----------------------------------------------------------" << endl;
        cout << "                        MENU                               " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "  " << 1 << ") Check to see if JSON file has correct syntax" << endl;
        cout << "  " << 2 << ") Format the JSON file properly meaning indentations and brackets are aligned" << endl;
        cout << "  " << 3 << ") Exit" << endl << endl; 
        cout << "Please enter your choice (1,2,3): ";
        cin >> choice;
        cout << " " << endl;
        
        // Error checking for if user inputs an invalid choice
        while (choice < 1 || choice > 3)
		{
			cout << "Error! Invalid choice! Try Again" << endl;
			cout << "Please enter your choice (1,2,3): ";
			cin >> choice;
			cout << " " << endl;
		}
    
        switch(choice)
        {
            case 1:
            if (check_braces(filename))
            {
                cout << "Braces are balenced!" << endl;
                cout << endl;
            }
            else 
            {
                cout << "Braces are NOT balanced!" << endl;
                cout << endl;
            }
            break;
            
            case 2:
            format_json(filename);
            cout << "Formatting is finished! Please check the file called output.json for the result!" << endl;
            if (check_braces(filename))
                cout << "JSON file has correct syntax" << endl;
            else
                cout << "JSON file does NOT have the correct syntax" << endl;
            cout << endl;
            exit(1);
            break;
            
            case 3:
            exit(1);
            break;
    
        }
    
    }while(choice <= 2 && choice >= 1);        
    
    
    return 0;

}