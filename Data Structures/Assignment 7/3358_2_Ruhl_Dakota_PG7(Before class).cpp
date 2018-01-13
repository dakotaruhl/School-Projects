#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void displayArray(int []);
void arraySearch(int [], int);
void arrayInsert(int [], int, int &, int &);
void arrayDelete(int [], int, int &, int &);


int main()
{
    const int SIZE = 30;
    int mArray[SIZE],
        num,
        index,
        collision = 0,
        empt = 0,
        userInput,
        target,
        deleteEmpt = 0,
        deleteColl = 0;

    //fill each value with -1
    for (int i = 0; i < SIZE; i++)
    {
        mArray[i] = -1;
    }

    //populate half the array with random
    srand(0);
    for (int i = 0; i < 15; i++)
    {
        num = rand()%400 + 100;
        index = num % SIZE;
        if (mArray[index] == -1)
        {
            mArray[index] = num;
            empt++;
        }
        else
        {
            while (mArray[index] != -1)
            {
                num++;                  //these 2 lines are equiv to
                index = (num % SIZE);   //(num + 1) % size
                collision++;
            }
            mArray[index] = num;
        }
    }

    //Display introduction and array
    cout << "Welcome to my hashing program." << endl;
    displayArray(mArray);

    //Menu display
    do
    {
        cout << "     1. Display the generated array." << endl
             << "     2. Search for a number (between 1-500) in the array."
        << endl << "     3. Insert a new number (bwetween 1-500) in the array"
             << endl << "     4. Delete a number (between 1-500) in the array."
             << endl << "     9. End the program." << endl;
        cin >> userInput;
        while ( !cin || (userInput > 4 && userInput !=9) )
        {
            cin.clear();
            cin.ignore();
            cout << "     Must be an integer. Try again: ";
            cin >> userInput;
        }


        switch (userInput)
        {
            case 1: displayArray(mArray);
                    break;
            case 2: cout << "Enter value to search: ";
                    cin >> target;
                    while (!cin || target<1 || target >500)
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "     Must be an integer 1-500, try again: ";
                        cin >> target;
                    }
                    arraySearch(mArray, target);
                    break;
            case 3: cout << "Enter value to add to array: ";
                    cin >> target;
                    arrayInsert(mArray, target, empt, collision);
                    break;
            case 4: cout << "Enter value to delete: ";
                    cin >> target;
                    arrayDelete(mArray, target, deleteEmpt, deleteColl);
                    break;

        }
    }while (userInput != 9);

}

void displayArray(int arr[])
{
    cout << "Generated Array: " << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << left << setw(3) << arr[i]<< "  ";
    }
    cout << endl;
    for (int i = 15; i < 30; i++)
    {
        cout << left << setw(3) << arr[i]<< "  ";
    }
    cout << endl << endl;
}

void arraySearch(int arr[], int target)
{
    bool found = false;
    int index;

    for (int i = 0; i < 30; i++)
    {
        if (arr[i] == target)
        {
            found = true;
            index = i + 1;
            break;
        }
    }
    if (found && target != -1)
    {
        cout << "Number has been found at index: " << index << endl;
    }
    else
    {
        cout << "Number was not found" << endl;
    }
}

void arrayInsert(int arr[], int target, int &empt, int &collision)
{
    int index = (target % 30);

    if (arr[index] == -1)
    {
        arr[index] = target;
        empt++;
    }
    else
    {
        while (arr[index] != -1)
        {
            index = (target+1) % 30;
            collision++;
        }
        arr[index] = target;
    }

    cout << target << " has been added to index location " << index+1
         << " using the hashing function." << endl;
}

void arrayDelete(int arr[], int target, int &delEmpt, int &delColl)
{
    int index = (target % 30);
    int counter = 0;

    if (arr[index] == target)
    {
        arr[index] = -1;
        delEmpt++;
        cout << target << " has been deleted from index location " << index+1
         << " using the hashing function." << endl;
    }
    else
    {
        while (arr[index] != target && counter < 30)
        {
            index = (target+1) % 30;
            delColl++;
            counter++;
        }
        if (arr[index] == target)
        {
            arr[index] = -1;
            cout << target << " has been added to index location " << index+1
                 << " using the hashing function." << endl;
        }
        else
        {
            cout << target << " was not found in the array." << endl;
        }
    }

}
