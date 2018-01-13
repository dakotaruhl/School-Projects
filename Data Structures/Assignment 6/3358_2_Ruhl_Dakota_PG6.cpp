// Roster Number : Dakota Ruhl (43) - Kennth Omo (31)
//
// Author: Dakota Ruhl and Kenneth Omo
// Due Date: such as 04/12/2017
// Assignment Number: 6
// Spring - 2017 - CS 3358 - 2
// Instructor: Husain Gholoom
//
// This program will use recursion in a series of functions.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void tableOfSquares(int[], int, int i);  //table of squares
int raiseToPower(int, int);              //raises first element to second power
int sumOfSquares(int[], int, int, int);  //sums all squares (0-given value)
void minF(int [], int , int &, int);     //find minimum
void maxF(int [], int , int &, int);     //find maximum
void bubbleSort(int [], int, int );      //bubble sort with recursion
bool isMember(int [], int, int, int);    //linear search with recursion
bool notMember(int [], int, int, int);   //binary search with recursion
void isPrime(int [], int, int);          //list if each member is prime


int main()
{
    int i = 1,  //iterator value
        num,    //iterator value
        sum;    //sum of squares total

    cout << "Thinking Recursively" << endl << endl
         << "The function of this program is to" << endl
         << "use recursion to :-" << endl << endl
         << "    1.   Display squares of integers in ascending" << endl
         << "         order from 1 to the last element in the array" << endl
         << "    2.   Raise the first number to a power of 2" << endl
         << "    3.   Return the sums of squares of the numbers" << endl
         << "         from 0 to the fifth element in the array" << endl
         << "    4.   Search the array for the array's min and max values"
         << endl
         << "    5.   Sort the array in ascending order" << endl
         << "    6.   Search the array for the first value in the array"
         << endl
         << "    7.   Search the array for the number 600" << endl
         << "    8.   Determine if a number is prime (process all array values)"
         << endl << endl;

         char userInput;    //user entered character
do
{
         cout << endl << "Select from the following menu" << endl
              << "A.   Enter array size that is > 4" << endl
              << "X.   Terminate the program    " << endl;
         cin >> userInput;

         while (isdigit(userInput) || (userInput != 'A' && userInput != 'a')
                                   &&  userInput != 'X' && userInput != 'x')
         {
             cout << endl << "***Must be a character, A or X" << endl
                  << "Select from the following menu" << endl
                  << "A.   Enter array size that is < 4" << endl
                  << "X.   Terminate the program    " << endl;
             cin.clear();
             cin.ignore();
             cin >> userInput;
        }

         int arraySize;     //user entered size for array
         if (userInput == 'A' || userInput == 'a')
         {
             cout << "Enter array size: ";
             cin >> arraySize;

             while (!cin)
             {
                 cout << endl << "***Must be an integer greater than 4" << endl
                      << "Enter array size: " << endl;
                 cin.clear();
                 cin.ignore();
                 cin >> arraySize;
             }
             while (arraySize < 4)
             {
                 cout << endl << "***Must be an integer greater than 4" << endl
                      << "Enter array size: " << endl;
                 cin >> arraySize;
             }
         }
         else if (userInput == 'X' || userInput == 'x')
         {
             cout<< endl << endl << "Implemented by Dakota Ruhl and Kenneth Omo"
                 << endl
                 << "April 2017";
             return 0;
         }
         //Create and populate an array given the user's size.
         int myArray[arraySize];        //array to be populated with random #s
         srand(0);
         for (int i = 0; i < arraySize; i++)
         {
             myArray[i] = (rand() % 476) + 25;
         }
         //Display generated array
         cout << endl << "The generated array is: ";
         for (int j = 0; j < arraySize; j++)
         {
             cout << myArray[j] << "  ";
         }

        //table of squares
        cout << endl << endl << "Table of squares 1 - " << myArray[arraySize-1]
             << endl << endl << "N" <<"    " << " N Squared " << endl;
        tableOfSquares(myArray, arraySize,  i);

        //raise to power
        num = raiseToPower(myArray[0], 2);
        cout << endl << "Power Function:" << endl;
        cout << myArray[0] << " raised to the second power is: " << num;

        //sum of squares
        i = 0;
        num = 0;
        sum = sumOfSquares(myArray, arraySize, i, num);
        cout << endl << endl << "Sum of squares between 0 and "
             << myArray[arraySize-2] << " is: " << sum << endl;

        //min and max
        int min = 501;
        int max = -1;
        i = 0;
        minF(myArray, arraySize, min, i);
        maxF(myArray, arraySize, max, i);

        cout << endl << "Min number of ( ";
        for (i = 0; i<(arraySize-1); i++)
        {
            cout << myArray[i] << " , ";
        }
        cout << myArray[arraySize-1] << " )" << endl
             << "is  : " << min << endl;

        cout << "Max number of ( ";
        for (i = 0; i<(arraySize-1); i++)
        {
            cout << myArray[i] << " , ";
        }
        cout << myArray[arraySize-1] << " )" << endl
             << "is  : " << max << endl << endl;

        //bubble sort
        bubbleSort(myArray, arraySize, arraySize);

        cout << "Sorted Array" << endl;
        for (int j =0; j<arraySize; j++)
        {
            cout << myArray[j] << "  ";
        }
        cout << endl << endl;

        //bool isMember
        i = 0;          //reset iterator
        bool flag = isMember(myArray, arraySize, myArray[3], i);
        cout << "Does the array: ";
        for (i = 0; i<arraySize; i++)
        {
            cout << myArray[i] << "  ";
        }
        cout << "have the number " << endl << myArray[3] << "?  ";
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        //bool notMember (will work for any value)
        flag = notMember(myArray, 0, arraySize, 600);
        cout << "Does the array: ";
        for (i = 0; i<arraySize; i++)
        {
            cout << myArray[i] << "  ";
        }
        cout << "have the number " << endl << 600 << "?  ";
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        //prime
        int index = 0;
        cout << endl;
        isPrime(myArray, arraySize, index);


}while (userInput!= 'x' && userInput != 'X');

}
//*****************************************************************
// tableOfSquares, void fucntion that will print all values between
// 1 and the last value in the array.
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int theSize, the size of the array
// returns: none
//*******************************************************************
void tableOfSquares(int theArray[], int theSize, int i)
{
    if (i != theArray[theSize-1])
    {
         cout << i << " " << setw(6) << (i * i) << endl;
         i++;
    }
    else
    {
        //for last value
        cout << i << " " << setw(6) << (i * i) << endl;
        return;
    }
    tableOfSquares(theArray, theSize, i);   //recursion
}

//*****************************************************************
// raiseToPower, int function that will raise the first element in
// the array to the power of 2.
//
// param-1-name: int base, the first element in the array
// param-2-name: int power, the power the base is to be raised to. (Fixed at 2)
// returns: integer value, (the base squared)
//*******************************************************************
int raiseToPower(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return base * raiseToPower(base, power-1);  //recursion
    }
}

//*****************************************************************
// sumOfSquares, returns the sum all of the squares between 0 and the value
//
// param-1-name: int theArray[], array of random generated values
// param-2-name: theSize is the size of the array
// param-3-name: int i, an iterator to move throughout the array
// param-4-name: int sum, integer to store the total sum.
// returns: integer value (sum of squares)
//*******************************************************************
int sumOfSquares(int theArray[], int theSize, int i, int sum)
{
    if (i != theArray[theSize-2])
    {
         sum += (i * i);
         i++;
    }
    else
    {
        return sum;
    }
    sumOfSquares(theArray, theSize, i, sum);    //recursion
}

//*****************************************************************
// minF, void function to find minimum value recursively
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int theSize, the size of the array
// param-3-name: int &min, varialbe to store minimum value (by reference)
// returns: void
//*******************************************************************
void minF(int theArray[], int theSize, int &min, int i)
{

    //find minimum
    if (min > theArray[i])
    {
        if (theArray[i] != theArray[theSize-1])
        {
            min = theArray[i];
            i++;
            minF(theArray, theSize, min, i);    //recursion
        }
        else
        {
            if (min > theArray[i])
            {
                min = theArray[i];
            }
        }
    }
    else
    {
        if (theArray[i] != theArray[theSize-1])
        {
            i++;
            minF(theArray, theSize, min, i);    //recursion
        }
        else
        {
            if (min > theArray[i])
            {
                min = theArray[i];
            }
        }

    }
}

//*****************************************************************
// maxF will find the maximum value and change the maximum in main
//  (by reference)
//
// param-1-name int theArray[], the array passed from main
// param-2-name int theSize, the size of the array
// param-3-name int &max, variable to store maximum value
// param-4-name int i, iterator to move through the array
// returns: void
//*******************************************************************
void maxF(int theArray[], int theSize, int &max, int i)
{
    //find Maximum
    if (max < theArray[i])
    {
        if (theArray[i] != theArray[theSize-1])
        {
            max = theArray[i];
            i++;
            maxF(theArray, theSize, max, i);    //recursion
        }
        else
        {
            if (max < theArray[i])
            {
                max = theArray[i];
            }
        }
    }
    else
    {
        if (theArray[i] != theArray[theSize-1])
        {
            i++;
            maxF(theArray, theSize, max, i);    //recursion
        }
        else
        {
            if (max < theArray[i])
            {
                max = theArray[i];
            }
        }

    }
}

//*****************************************************************
// bubbleSort, a bubble sort function that uses recursion. Will swap
// values each pass and use recursion to iterate passes.
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int theSize, size of the array
// param-3-name: int n, iterator variable to make passes
// returns: void
//*******************************************************************
void bubbleSort(int theArray[], int theSize, int n)
{
    int temp = 0;
    //base case
    if (n==1)
    {
        return;
    }

    //swap untill reaches end
    for (int i=0; i<(theSize); i++)
    {
        if (theArray[i] != theArray[theSize-1])  //if we are not looking at last
        {
            if (theArray[i] < theArray[i+1]) //sorting in descending order
            {
                temp = theArray[i];             //swap
                theArray[i] = theArray[i+1];    //swap
                theArray[i+1] = temp;           //swap
            }
        }
        else
        {
            //to exit and not compare values off array
            break;
        }
    }

    n--;
    //call again
    bubbleSort(theArray, theSize, n);       //recursion

}

//*****************************************************************
// isMember, boolean function will determine true if the value is found
// in the array, or false if not.
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int theSize, the size of the array
// param-3-name: int value, the value passed in from main
// param-4-name: int i, the iterator to pass through the array
// returns: bool ean value, true or false
//*******************************************************************
bool isMember(int theArray[], int theSize, int value, int i)
{
    if (theArray[i] != theArray[theSize-1])
    {
        if (theArray[i] == value)
        {
            return true;
        }
        else
        {
            i++;
            isMember(theArray, theSize, value, i);  //recursion
        }
    }
    else
    {
        if (theArray[i] == value)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}

//*****************************************************************
// notMember, boolean function to determine if the value given is
// located in the array, or not.
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int first, variable stores front index of list
// param-3-name: int last, variable stores end index of list
// param-4-name: int value, variable stores value to be searched
// returns: boolean value true or false.
//*******************************************************************
bool notMember(int theArray[], int first, int last, int value)
{
    if (first <= last)
    {
       int mid = (first + last) / 2;  // compute mid point.
       if (value == theArray[mid])
       {
           return true;   // found it.
       }
       else if (value < theArray[mid])
       {
           // Call ourself for the lower part of the array
           return notMember(theArray, first, mid-1, value); //recursion
       }
       else
       {
           // Call ourself for the upper part of the array
           return notMember(theArray, mid+1, last, value);  //recursion
       }
    }
    else
    {
        return false;    // failed to find value
    }
}

//*****************************************************************
// isPrime, void function to determine wether or not each value in
// the array is prime
//
// param-1-name: int theArray[], integer array passed from main
// param-2-name: int theSize, the size of the array
// param-3-name: int index, index iterator to move throughout the array
// returns: none
//*******************************************************************
void isPrime(int theArray[], int theSize, int index)
{
    if (theArray[index] == theArray[theSize-1])
    {
        return;
    }
    bool prime = true;
    for (int i=2; i<theArray[index]; i++)
    {
        if (theArray[index] % i == 0)
        {
            prime = false;
        }
    }
    if (prime)
    {
        cout << "The number " << left << setw(3) << theArray[index]
             << " is prime" << endl;
    }
    else
    {
        cout << "The number " << left << setw(3) << theArray[index]
             << " is not prime" << endl;
    }
    index++;
    isPrime(theArray, theSize, index);      //recursion
}
