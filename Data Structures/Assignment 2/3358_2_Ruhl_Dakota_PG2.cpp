/*
    Author/s:Kenneth Omo and Dakota Ruhl
    Due Date: February 13, 2017
    Programming Assignment Number 2
    Spring 2017  - CS3358 - Section Number 2
    Instructor: Husain Gholoom
    This program will allow the user to enter the size of a matrix such as N.
    It will then create a 2d vector of size NxN, and populate it with distinct
    random numbers. It will display the vector in a matrix form, and begin
    to determine if it is a perfect matrix. This is done by adding the rows,
    columns, and diagonals of the vector to find the perfect number. After
    the perfect number is calculated, it can determine if the matrix is a
    perfect matrix or not.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void matrixCreator(int vSize);  //Function to create, print,
                                //and test for perfect matrix
bool programEndFlag();  //Function to recieve Y or N to continue or end program
int getNextRando(vector<bool> &boolArray, int vSize); //function to generate
                                                      //distinct random numbers
int main()
{
    cout << "Welcome to Dakota's and Kenneth's perfect matrix program." << endl
         << endl << "This program will allow the user to: " << endl
         << "1. Enter the size of the matrix such as N. While N >= 2 " << endl
         << "2. Create a 2 dimensional vector array of the size of N x N"
         << endl << "3. The program will then populate the vector array with "
         << "distinct random numbers." << endl << "4. It will then display the "
         << "sum for each row, column, and diagonals." << endl
         << "   Then determine weather the numbers in N x N vector are perfect "
         << "matrix numbers." << endl << endl;

    srand(time(NULL));  //time seed for random number generator
    int matrixSize; //Temp variable for matrix size
    bool flag = true; //variable to store result of programEndFlag function
    do
    {
        cout << "Enter the size of the matrix: ";
        cin >> matrixSize;
        while (!cin || matrixSize<2)
        {
            cout << "***Invalid choice, must be an integer greater than 2."
                 << endl << "Please try again: ";
            cin.clear();
            cin.ignore();
            cin >> matrixSize;
        }
        matrixCreator(matrixSize);
        flag = programEndFlag();    //this is where the program determines
                                    //wehter or not to continue, based on the
                                    //user input Y, y, N, or n.
                                    //See function definiton.
    }while (!flag);

    cout << endl << "This perfect matrix algorithm was implemented by"
         << "Dakota Ruhl, and Kenneth Omo" << endl << "February 13, 2017"
         << endl;
    return 0;
}

//*****************************************************************
// Creates a matrix, determines the perfect number for that matrix,
// and then determines if the matrix is a Perfect Matrix.
// param-1-name: int Vsize, the user entered matrix size
//*******************************************************************
void matrixCreator(int vSize)
{
    vector<int>aVector(vSize);                   //Row vector
    vector<vector<int> >bVector(vSize, aVector); //2d vector of vector<int> type

    int total = 0,                  //Total of all n^2 numbers in vector.

        perfectNumber = 0,          //initialized to 0, but later = (total/3)

        perfectMatrixCounter = 0,   //if all numbers in row/column/diagonal are
                                    //equal to perfectNumber, we increment this.

        columnDecrement = vSize-1,  //Used to determine right diagonal.
                                    //Used to lower the column value as we raise
                                    //the row value(i) as shown in last for loop
                                    //to determine the diagonal row total

    //populate vector with random numbers
    vector<bool>boolArray((vSize*vSize), false);  //boolean vector,
                                                  //all values set to false.
    for (int r=0;r<vSize;r++)
    {
        for(int c=0;c<vSize;c++)
        {
            bVector[r][c] = getNextRando(boolArray, vSize); //function call,
                                                            //see defenition
        }
    }

    //print the vector matrix
    cout << "The perfect matrix that is created for size " << vSize
         << endl << endl;
    for (int i=0; i<bVector.size(); i++)
    {
        for (int j=0; j< bVector[i].size(); j++)
        {
           cout << setw(3) << bVector[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    //Find the perfect number
    //start by evaluating the total
    for (int i=0; i<bVector.size(); i++)
    {
        for (int j=0; j< bVector[i].size(); j++)
        {
           total += bVector[i][j];
        }
    }

    //divide total by 3 to get perfect number.
    perfectNumber = total/3;
    cout << "The perfect number is " << perfectNumber << endl << endl;

    //Now evaluating the rows and columns, comparing the total to perfectNumber
    //Each time the row/column/diagonal = to the perfect number, increment by 1

    //This nested for loop will determine if any of the rows are equal to
    //the perfect number
    for (int i=0; i<bVector.size(); i++)
    {
        total = 0;
        for (int j=0; j< bVector[i].size(); j++)
        {
           total += bVector[i][j];
        }
        cout << "The sum for row " << i+1 << " is: "
         << setw(4) << total << endl;
         if (total==perfectNumber)
            perfectMatrixCounter++;
    }
    cout << endl;

    //This nested for loop will determine if any of the columns are equal to
    //the perfect number
    for (int i=0; i<bVector.size(); i++)
    {
        total = 0;
        for (int j=0; j< bVector[i].size(); j++)
        {
           total += bVector[j][i];
        }
        cout << "The sum for column " << i+1 << " is: "
             << setw(4) << total << endl;
         if (total==perfectNumber)
            perfectMatrixCounter++;
    }
    cout << endl;

    //This for loop will add the diagonal from left to right and compare that
    //total to the perfectNumber
    total = 0; //Reset total to 0
    for (int i=0; i<bVector.size(); i++)
    {
        total += bVector[i][i];
    }
    if (total==perfectNumber)
            perfectMatrixCounter++;
    cout << "The sum for left diagonal is: "
         << setw(4) << total << endl;

    //This for loop will add the diagonal from right to left and compare that
    //total to the perfectNumber
    total = 0; //Reset total to 0
    for (int i=0; i<bVector.size(); i++)
    {
        total += bVector[i][columnDecrement];
        columnDecrement--; //used to lower the column value as we raise the
                           //row value(i)
    }
    if (total==perfectNumber)
        perfectMatrixCounter++;
    cout << "The sum for right diagonal is: "
         << setw(4) << total << endl << endl;

    //Now we need to determine if the matrix is a perfect matrix.
    //The perfectMatrixCounter should be equal to the (matrix size *2) + 2
    //This accounts for each row(size) + each column(size) + 2 diagonals.

    if (perfectMatrixCounter==(vSize*2)+2)
    {
        cout << "The above matrix is a perfect matrix!" << endl << endl << endl;
    }
    else
    {
        cout << "The above matrix is not a perfect matrix." << endl << endl
             << endl;
    }
}

//*****************************************************************
// This function is used for input validation purposes. Once the program
// has completed at least one matrix, it will ask the user if they would
// like to try again. If the user enters anything besides Y,y,N, or n
// it will make them try again.
// returns: Boolean value, true if they choose Y or y, and false if they
// choose N or n. This value will determine if the program should continue
// for another matrix input.
//*******************************************************************
bool programEndFlag()
{
    char userInput; //Char value to store Y,y,N, or n.

    cout << "Would you like to try for another perfect matrix?" << endl
         << "Enter Y or y for yes, and N or n for no: ";
    cin >>  userInput;

    while (!cin)  //while not a character
    {
        cout << endl << "Must be a character. Try again: ";
        cin.clear();
        cin.ignore();
        cin >> userInput;
    }

    while (userInput!= 'Y' && userInput!= 'N'
        && userInput!= 'y' && userInput!= 'n' )
    {
       cout << endl << "Must be Y or y for yes, and N or n for no. Try again: ";
       cin >> userInput;
    }
    if (userInput=='Y' || userInput=='y')
        return false;
    else
        return true;
}

//*****************************************************************
// This function will generate a DISTINCT random number, from 0-(vSize)^2.
// That means, each number is unique and does not excced the matrix size.
// It does this by changing a value at the index of (random number) to true,
// once the value has been changed to true, that index can not be used, therfore
// it must generate a new random number, and this can be used for any size.
// Param-1: boolArray, is a vector passed by refernce from the main program.
//          It is filled with n^2 values all set to false. These values will
//          change once a distinct number is found.
// Param-2: vSize, is the matrix size taken from the user in main.
// returns: interger value that is the distinct random number.
//*******************************************************************
int getNextRando(vector<bool> &boolArray, int vSize)
{
    int tryRando = rand()%(vSize*vSize); //tryRando is a random number between 0
                                         //and the matrix size squared.

    while (boolArray[tryRando])          //While the value at location tryRando
    {                                    //is true, (meaning there is duplicate)
        tryRando = rand()%(vSize*vSize); //generate a new random number and
    }                                    //check again.

      boolArray[tryRando] = true;        //once you have ensured there are no
                                         //duplicates, set that location to true
      return tryRando;                   //and return the distinct random number
}
