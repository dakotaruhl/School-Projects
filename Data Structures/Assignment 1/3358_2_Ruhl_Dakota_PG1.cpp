 /*
    Author/s:Kenneth Omo and Dakota Ruhl
    Due Date: January 30, 2017
    Programming Assignment Number 1
    Spring 2017  - CS3358 - Section Number 2

    Instructor: Husain Gholoom.

    The following program will take the value the user has entered and call a
    series of functions. Each function has a description to detail what it
    will do with the user input. After it has completed every function, it will
    ask the user if they want to enter another number, and they can choose n or
    N to exit the program.
    The functions (in order) are:
    1. getDollarAmount, Displays the amount of quarters, dimes, nickels,
    and pennies that are equivalent to the integer entered by the user.
    2. getUserAge, Displays the users integer input in years, months, days,hours
    and seconds.
    3. convertNumberToWord, Displays the user integer as two separate digits,
    followed by the English word form of the number on a separate line.
    4. getArmstrong, displays whether or not the user integer is an Armstrong
    number.
    5. getFactorial, displays the user integer as a factorial.
    6. getPrime, displays the user integer and determine's if it is prime,
    followed by every prime number between 1 and the user integer.
    7. getHailstone, displays the user integer as a Hailstone sequence.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int inputValidation();                   //Ensures input is an integer less than
                                        //200 and greater than 0.
bool doWhileFlag();                     //returns a true or false value to
                                        //end Do..While loop in main.
void getDollarAmount(int userNum);      //Evaluates quarter, dime, nickel,
                                        //and penny amount.
void getUserAge(int userNum);           //Evaluates year, month, day, hour,
                                        //minute, and seconds equivalences.
void convertNumberToWord(int userNum);  //Converts integer into separate digits,
                                        //and displays word notation.
void getArmstong(int userNum);          //Determines if the user integer is an
                                        //Armstrong Number.
void getFactorial(int userNum);         //Converts user int to a factorial.
void getPrime(int userNum);             //Determines if user int is a prime
                                        //number. Then, displays all primes
                                        //between 1 and user int.
void getHailstone(int userNum);         //Displays hailstone sequence for
                                        //user int.

int main()
{
    int userNum; //user input between 0 and 200 to be used for each function.
    bool flag; //true or false flag to determine when to exit the loop.
    do
    {
        userNum = inputValidation();
        getDollarAmount(userNum);
        getUserAge(userNum);
        convertNumberToWord(userNum);
        getArmstong(userNum);
        getFactorial(userNum);
        getPrime(userNum);
        getHailstone(userNum);
        flag = doWhileFlag();
    } while(flag);

    return 0;
}

//*****************************************************************
// This function is a boolean function that will determine when to stop the
// program. The boolean value is calculated as true or false, based on the user
// input of Yes or No, respectively.
// returns: bool value.
//*****************************************************************
bool doWhileFlag()
{
    char userInput; //stores yes or no to terminate program

    cout << "Would you like to try for another number?" << endl
         << "Enter Y || y for yes, or N || n for no ";
    cin >> userInput;
    while(userInput!='Y' && userInput!='y' &&
          userInput!='N' && userInput!='n')
    {
        cout << endl
             << "****Invalid Choice. Must be Y for yes, or N for no."
             << endl << endl
             << "Would you like to try for another number?" << endl
             << "Enter Y || y for yes, or N || n for no ";
        cin >> userInput;
    }
    if (userInput == 'n' || userInput == 'N')
        return false;
    else
        return true;
}

//*****************************************************************
// This function returns an int value. This int value is used as the userNum
// in main, and will be used as the integer value for every function that
// follows. It is determined by two parameters. Must be an integer, and must be
// between 0 and 200.
// returns: integer to be used in each function.
//*****************************************************************
int inputValidation()
{
    int num; //temp variable used for input validation

    cout << "Please enter a positive number between 0 and 200: ";
    cin >> num;
    while(!cin)
    {
        cout << "Error***** Must be a number." << endl;
        cin.clear();    //clear the cin stream to avoid infinite loop
        cin.ignore();   //ignore remaining char in cin stream
                        //this is only because storing char type into int
                        //causes infinite loop
        cout << "Please enter a positive number between 0 and 200: ";
        cin >> num;
    }
    while(num<1 || num>199)
    {
        cout << "Error***** The number must be between 0 and 200." << endl;
        cout << "Please enter a positive number between 0 and 200: ";
        cin >> num;
    }
}

//*****************************************************************
// Displays the user integer equivalences: Quarters, Dimes, Nickels, Pennies.
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getDollarAmount(int userNum)
{
    double quarterAmount, //stores Quarter amount
           dimeAmount,    //stores Dime amount
           nickelAmount,  //stores Nickel amount
           pennyAmount;   //stores Penny amount

    quarterAmount = userNum / .25;
    dimeAmount = userNum / .10;
    nickelAmount = userNum / .05;
    pennyAmount = userNum / .01;

    cout << endl << endl << "Currency Calculation" << endl << endl
         <<"$" << userNum << " " << "is equivalent to:" << endl << endl
         << quarterAmount << " quarters" << endl
         << dimeAmount << " dimes" << endl
         << nickelAmount << " nickels" << endl
         << pennyAmount << " pennies" << endl << endl;

}

//*****************************************************************
// Displays the user integer equivalences: Years, Months, Days, Hours,
//                                         Minutes, Seconds.
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getUserAge(int userNum)
{
    int yr,             //stores year amount
        month,          //stores month amount
        day,            //stores day amount
        hours;          //stores hour amount
    long minutes;       //stores minute amount
    long long seconds;  //stores second amount, largest data type

        yr = userNum;
        month = userNum * 12;
        day = userNum * 365;
        hours = userNum * 365 * 24;
        minutes = userNum * 365 * 24 * 60;
        seconds = userNum * 365 * 24 * 3600;

        cout << "Age Calculation" << endl << endl
             << "Assuming you are " << userNum << " years old, then" << endl
             << "You are " << left << setw(6) << month << "  months old" << endl
             << "You are " << left << setw(6) << day << "  days old" << endl
             << "You are approximately " << left << setw(7) << hours
             << "  hours old" << endl
             << "You are approximately " << left << setw(9) << minutes
             << "  minutes old" << endl
             << "You are approximately " << left << setw(10) << seconds
             << "  seconds old" << endl << endl;
}

//*****************************************************************
// Displays the user integer as two separate digits,
// followed by the English word form of the number on a separate line.
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void convertNumberToWord(int userNum)
{
    //this switch statement is only for integers less than 10.
    cout << "Separating digits for the integer: " << userNum << endl;
    if (userNum < 10)
    {
        switch (userNum)
        {
            case 0: cout << "0" << endl << "Zero";
                    break;
            case 1: cout << "1" << endl << "One";
                    break;
            case 2: cout << "2" << endl << "Two";
                    break;
            case 3: cout << "3" << endl << "Three";
                    break;
            case 4: cout << "4" << endl << "Four";
                    break;
            case 5: cout << "5" << endl << "Five";
                    break;
            case 6: cout << "6" << endl << "Six";
                    break;
            case 7: cout << "7" << endl << "Seven";
                    break;
            case 8: cout << "8" << endl << "Eight";
                    break;
            case 9: cout << "9" << endl << "Nine";
                    break;
        }
    cout << endl << endl;
    }
    //The following two switch statements are for numbers less than 100
    //One is for the first digit, and the other is for the second digit.
    else if (userNum < 100)
    {
        int digitOne = userNum/10;  //evaluates to first digit
        int digitTwo = userNum%10;  //evaluates to second digit
        cout << digitOne << " " << digitTwo << endl;
        switch (digitOne)
        {
            case 0: cout << "Zero";
                    break;
            case 1: cout << "One";
                    break;
            case 2: cout << "Two";
                    break;
            case 3: cout << "Three";
                    break;
            case 4: cout << "Four";
                    break;
            case 5: cout << "Five";
                    break;
            case 6: cout << "Six";
                    break;
            case 7: cout << "Seven";
                    break;
            case 8: cout << "Eight";
                    break;
            case 9: cout << "Nine";
                    break;
        }
        cout << " ";
        switch (digitTwo)
        {
            case 0: cout << "Zero";
                    break;
            case 1: cout << "One";
                    break;
            case 2: cout << "Two";
                    break;
            case 3: cout << "Three";
                    break;
            case 4: cout << "Four";
                    break;
            case 5: cout << "Five";
                    break;
            case 6: cout << "Six";
                    break;
            case 7: cout << "Seven";
                    break;
            case 8: cout << "Eight";
                    break;
            case 9: cout << "Nine";
                    break;
        }
        cout << endl << endl;
    }
    //The last three switch statements are for the first, second,
    //and third digits of the user integer. This is executed when the user
    //enters an integer greater than 100, and therefore containing three digits.
    else
    {
        int digitOne = userNum/100;         //evaluates to first digit
        int digitTwo = (userNum%100)/10;    //evaluates to second digit
        int digitThree = (userNum%100)%10;  //evaluates to third digit
        cout << digitOne << " " << digitTwo << " " << digitThree << endl;
        switch (digitOne)
        {
            case 0: cout << "Zero";
                    break;
            case 1: cout << "One";
                    break;
            case 2: cout << "Two";
                    break;
            case 3: cout << "Three";
                    break;
            case 4: cout << "Four";
                    break;
            case 5: cout << "Five";
                    break;
            case 6: cout << "Six";
                    break;
            case 7: cout << "Seven";
                    break;
            case 8: cout << "Eight";
                    break;
            case 9: cout << "Nine";
                    break;
        }
        cout << " ";
        switch (digitTwo)
        {
            case 0: cout << "Zero";
                    break;
            case 1: cout << "One";
                    break;
            case 2: cout << "Two";
                    break;
            case 3: cout << "Three";
                    break;
            case 4: cout << "Four";
                    break;
            case 5: cout << "Five";
                    break;
            case 6: cout << "Six";
                    break;
            case 7: cout << "Seven";
                    break;
            case 8: cout << "Eight";
                    break;
            case 9: cout << "Nine";
                    break;
        }
        cout << " ";
        switch (digitThree)
        {
            case 0: cout << "Zero";
                    break;
            case 1: cout << "One";
                    break;
            case 2: cout << "Two";
                    break;
            case 3: cout << "Three";
                    break;
            case 4: cout << "Four";
                    break;
            case 5: cout << "Five";
                    break;
            case 6: cout << "Six";
                    break;
            case 7: cout << "Seven";
                    break;
            case 8: cout << "Eight";
                    break;
            case 9: cout << "Nine";
                    break;
        }
    cout << endl << endl;
    }

}

//*****************************************************************
// Determines whether or not the user integer is an Armstrong Number
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getArmstong(int userNum)
{
    if (userNum<10)
        cout << userNum << " is an Armstrong number" << endl;
    else
    {
        if (userNum>9 && userNum<100)
        {
            int digitOne = userNum/10,
                digitTwo = userNum%10;
            int digitOneCubed = digitOne*digitOne*digitOne,
                digitTwoCubed = digitTwo*digitTwo*digitTwo;
            if ((digitOneCubed+digitTwoCubed)==userNum)
                cout << userNum << " is an Armstrong Number" << endl;
            else
                cout << userNum << " is not an Armstrong Number" << endl;
        }
        else if (userNum>99)
        {
            int digitOne = userNum/100,
                digitTwo = (userNum%100)/10,
                digitThree = (userNum%100)%10;
            int digitOneCubed = digitOne*digitOne*digitOne,
                digitTwoCubed = digitTwo*digitTwo*digitTwo,
                digitThreeCubed = digitThree*digitThree*digitThree;
            if ((digitOneCubed+digitTwoCubed+digitThreeCubed)==userNum)
            {
                cout << userNum << " is an Armstrong Number" << endl;
                        cout << "its me down here";
            }
            else
                cout << userNum << " is not an Armstrong Number" << endl;
        }
    }
}

//*****************************************************************
// Displays the user integer as a factorial
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getFactorial(int userNum)
{
    long long fact = userNum;   //large data type to store factorial number
    if (userNum==0)             //cannot hold number bigger than !20
    {
        fact = 1;
    }
    for (int i=1; i<userNum; i++)
    {
        fact = fact*(userNum-i);
    }
    cout << endl << "Factorial of " << userNum <<": " << fact
         << endl << endl;

}

//*****************************************************************
// Displays the users integer and determine's if it's prime,
// followed by every prime number between 1 and the user integer.
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getPrime(int userNum)
{
    bool prime = true;          //boolean flag to determine if number is prime
    for (int i=2; i<userNum; i++)
    {
        if (userNum%i==0)
        {
            prime = false;
            break;
        }
    }
    if (prime)
    {
        cout << userNum << " is prime." << endl << endl
             << "All prime numbers between 1 and " << userNum << " are" << endl;
    }
    else
    {
        cout << userNum << " is not prime." << endl << endl
             << "All prime numbers between 1 and " << userNum << " are" << endl;
    }
    if (userNum==1)
    {
        cout << "There are no prime numbers less than 1." << endl;
    }
    for (int i=1; i<userNum; i++)
    {
        prime = true;
        for (int j=2; j<i; j++)
        {
            if (i%j==0)
                prime = false;
        }
        if (prime)
        {
            cout << left << setw(5) << i << "is a prime number" << endl;
        }
    }
}

//*****************************************************************
// Displays the user integer as a Hailstone sequence.
// param-1-name: int userNum, integer entered by user.
//*******************************************************************
void getHailstone(int userNum)
{
    bool flag = false;         //boolean flag to exit Do..While loop
    cout << endl << endl << "The hailstone sequence starting at " << userNum
         << " is:" << endl << userNum << " ";
    do
    {
        if(userNum%2 == 0)
        {
            userNum = userNum/2;
        }
        else if(userNum%2 <= 1)
        {
            userNum = (3*userNum) + 1;
        }

        if(userNum == 1)
        {
            flag = true;
        }

        cout << userNum << " ";
    }while(!flag);
    cout << endl << endl;
}
