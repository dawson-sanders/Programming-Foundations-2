//------------------------------------------------------------------
// Purpose: This program demonstrates the classic binary merge sort algorithm
// as well as the 3-way merge sort algorithm.
// Author:  Dawson Sanders
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdlib.h>

//------------------------------------------------------------------
// Initialize data array with random values
//------------------------------------------------------------------
void create_random_data(int data[], int count, int range)
{
    // Put random data values into array
    for (int index = 0; index < count; index++)
        data[index] = rand() % range;
}

//------------------------------------------------------------------
// Write data array to output file
//------------------------------------------------------------------
void write_data(std::string name, int data[], int count)
{
    // Open output file
    std::ofstream dout;
    dout.open(name.c_str());
    if (dout.fail())
        std::cout << "Error: could not open output file\n";

    // Write the data
    dout << count;
    for (int i = 0; i < count; i++)
    {
        if (i % 20 == 0)
	    dout << std::endl;
        dout << data[i] << " ";
    }

    // Close the file 
    dout.close();
}

//------------------------------------------------------------------
// Classic merge sort implementation with copy array
//------------------------------------------------------------------
void classic_mergeSort(int data[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        
        // Calls classic merge sort function recursively 
        classic_mergeSort(data, low, mid);
        classic_mergeSort(data, mid + 1, high);
 
        // Create temporary array for merged data
        int *copy = new int[range];
        
        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;
        
        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (data[index1] < data[index2])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index2++];
        }
 
        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = data[index1++];
            
        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = data[index2++];
 
        // Copy data back from the temporary array
        for (index = 0; index < range; index++)
            data[low + index] = copy[index];
        
        delete[]copy;
    }
}


//------------------------------------------------------------------
// Function to divide and merge 3 arrays 
//------------------------------------------------------------------
void merge3Arrays(int initalArray[], int low, int mid1, int mid2, int high, int newArray[])
{
    // Declaring local varibles
    int index1 = low;
    int index2 = mid1; 
    int index3 = mid2; 
    int index4 = low;
 
    // Choose smaller of the smallest in the three ranges
    while ((index1 < mid1) && (index2 < mid2) && (index3 < high))
    {
        if(initalArray[index1] < initalArray[index2])
        {
            if(initalArray[index1] < initalArray[index3])
                newArray[index4++] = initalArray[index1++];
            
            else
                newArray[index4++] = initalArray[index3++];
        }
        
        else
        {
            if(initalArray[index2] < initalArray[index3])
                newArray[index4++] = initalArray[index2++];
                
            else
                newArray[index4++] = initalArray[index3++];
        }
    }
 
    // Case where first and second ranges have remaining values
    while ((index1 < mid1) && (index2 < mid2))
    {
        if(initalArray[index1] < initalArray[index2])
            newArray[index4++] = initalArray[index1++];
            
        else
            newArray[index4++] = initalArray[index2++];
    }
 
    // Case where second and third ranges have remaining values
    while ((index2 < mid2) && (index3 < high))
    {
        if(initalArray[index2] < initalArray[index3])
            newArray[index4++] = initalArray[index2++];
            
        else
            newArray[index4++] = initalArray[index3++];
    }
 
    // Case where first and third ranges have remaining values
    while ((index1 < mid1) && (index3 < high))
    {
        if(initalArray[index1] < initalArray[index3])
            newArray[index4++] = initalArray[index1++];
            
        else
            newArray[index4++] = initalArray[index3++];
    }
 
    // Copy remaining values from the first range
    while (index1 < mid1)
        newArray[index4++] = initalArray[index1++];
    
    // Copy remaining values from the second range
    while (index2 < mid2)
        newArray[index4++] = initalArray[index2++];
 
    // Copy remaining values from the third range
    while (index3 < high)
        newArray[index4++] = initalArray[index3++];
}
 
//------------------------------------------------------------------
// Function to do 3-way merge sort recursively
//------------------------------------------------------------------
void Recursive3WayMerge(int initialArray[], int low, int high, int newArray[])
{
    // Termination condition
    if (high - low < 2)
        return;
 
    // Splitting array into 3 arrays
    int mid1 = low + ((high - low) / 3);
    int mid2 = low + 2 * ((high - low) / 3) + 1;
 
    // Sorting 3 arrays recursively
    Recursive3WayMerge(newArray, low, mid1, initialArray);
    Recursive3WayMerge(newArray, mid1, mid2, initialArray);
    Recursive3WayMerge(newArray, mid2, high, initialArray);
 
    // Merging the 3 sorted arrays back together into one
    merge3Arrays(newArray, low, mid1, mid2, high, initialArray);
}
 
 
//------------------------------------------------------------------
// 3-way merge sort implementation 
//------------------------------------------------------------------
void mergeSort3Way(int initialArray[], int count)
{
    // Terminating condition
    if (count == 0)
        return;
 
    // Creating copy of given array
    int copy[count];
 
    // Copying elements of given array into copy array
    for (int i = 0; i < count; i++)
        copy[i] = initialArray[i];
 
    // Calling recursive 3-way merge sort function 
    Recursive3WayMerge(copy, 0, count, initialArray);
 
    // Copy back elements of copy array to given array
    for (int i = 0; i < count; i++)
        initialArray[i] = copy[i];
}

//------------------------------------------------------------------
// Check to see if data is sorted correctly
//------------------------------------------------------------------
bool data_sorted(int data[], int count)
{
    // Put specified count of random numbers into data array
    for (int index = 1; index < count; index++)
        if (data[index-1] > data[index])
            return false;
    
    return true;
}

//------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------
int main()
{
    // Declaring constant variables
    const int MAX_COUNT = 1000000;
    const int MAX_RANGE = 1000000;
    
    // Initializing data array
    int data[MAX_COUNT];
    
    // Declaring local variables
    int count;
    char choice;
  
    do
    {
        // Welcome Statement 
        std::cout << "------------------------------------------------------------------\n" 
            << "Welcome to Dawson's Merge Sort Program!\n"
            << "Please follow the all of the instruction prompts\n"
            << "in the program for best results! Have fun!\n"
            << "-------------------------------------------------------------------\n\n";
            
        std::cout << "Press any key to start program" << std::endl;
        std::cout << "If you would like to exit the program press 0" << std::endl;
        std::cout << "Selection: ";
        std::cin >> choice;
        if(choice == '0')
            exit(1);
        else 
        {

            // Prompt user for sort parameters
            std::cout << "Enter number of data values [1.." << MAX_COUNT << "]: ";
            std::cin >> count;
            if (count > MAX_COUNT)
                count = MAX_COUNT;

            std::cout << "Enter range of data values [1.." << MAX_RANGE << "]: ";
            int range;
            std::cin >> range;
            if (range > MAX_RANGE)
                range = MAX_RANGE;
        
            // Print sorting method menu
            std::cout << "Select sorting method:\n"
                << "  1) - use classic binary merge sort\n" 
                << "  2) - use 3-way merge sort\n"
                << "  3) - Perform run time on classic merge sort\n"
                << "  4) - Perform run time on 3-Way sort\n"
                << "  5) - exit the program\n"
                << "Selection: ";
        
            // Creates Random Data Array
            create_random_data(data, count, range);
    
            // Write output file for the original unsorted data array
            write_data("input.txt", data, count);    
    
            // Perform requested merge sort choice
            std::cin >> choice;
            std::cout << std::endl;
            
            switch (choice)
            {
                case '1':
                classic_mergeSort(data, 0, count - 1);
                std::cout << "Success!" << std::endl;
                std::cout << "Random values have been added to the input.txt file." << std::endl;
                std::cout << "The output.txt file has the values in sorted order from low to high." << std::endl << std::endl;
                break;
        
                case '2':
                mergeSort3Way(data,count);
                std::cout << "Success!" << std::endl;
                std::cout << "Random values have been added to the input.txt file." << std::endl;
                std::cout << "The output.txt file has the values in sorted order from low to high." << std::endl << std::endl;
                break;
            } 
    
            if(choice == '3')
            {
                std::cout << "Success!" << std::endl;
                std::cout << "Random values have been added to the input.txt file." << std::endl;
                std::cout << "The output.txt file has the values in sorted order from low to high." << std::endl << std::endl;
                
                // Starts clock for run time experiment
                clock_t time1=clock();
        
                // Calls classic merge sort function
                classic_mergeSort(data, 0, count - 1);
        
                // Stops clock for run time experiment
                clock_t time2=clock();
    
                // Prints run time calculation to screen
                double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
                std::cout << "Run time: " << run_time << " seconds\n\n";
            }
            else if(choice == '4')
            {
                std::cout << "Success!" << std::endl;
                std::cout << "Random values have been added to the input.txt file." << std::endl;
                std::cout << "The output.txt file has the values in sorted order from low to high." << std::endl << std::endl;
                
                // Starts clock for run time experiment
                clock_t time1=clock();
        
                // Calls 3-Way merge sort function
                mergeSort3Way(data,count);
        
                // Stops clock for run time experiment
                clock_t time2=clock();
    
                // Prints run time calculation to screen
                double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
                std::cout << "Run time: " << run_time << " seconds\n\n";
            }
            else if(choice == '5')
                exit(1);
    
            // Write output file for the sorted data array
            write_data("output.txt", data, count);
    
            // Check to see if data sorted correctly
            if (!data_sorted(data, count))
                std::cerr << "ERROR: Data not sorted correctly!\n";
        }
    }while(choice <= '5' && choice >= '1');
    
    return 0;
}


