// Authors: Dakota Ruhl (43) and Kenneth Omo (31)
// Due Date: 3/29/2017
// Programming Assignment Number 5
// Spring 2017 - CS 3358 - 2
//
// Instructor: Husain Gholoom
//
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

template<class T>
class StackQ
{
    private:
            char *stackArray;
            int stackSize,
                size,
                top,
                num;
    public:
           StackQ(int);
           void push (char);
           char pop ();
           bool stackisFull() const,
                stackisEmpty() const;
           void display(int Ssize);
           bool symbolCheck(StackQ<T>);

};

template<class T>
class Queue
{
    private:
        string *queueArray;
         int size,
            queueSize,
            front,
            rear,
            numitems = 0;
    public:
        Queue(int);
        void enqueue(int);
        int dequeue();
        bool queueisFull() const,
             queueisEmpty() const;

};



template<class T>
StackQ<T>::StackQ(int size)
{
    stackArray = new char[size];   //dynamic alloc
    stackSize = size;       //save for reference
    top = -1;               //empty
}

template<class T>            //second constructor to flip stack for Q
Queue<T>::Queue(int size)
{
    queueArray = new string[size];   //dynamic alloc
    queueSize = size;       //save for reference
    front = -1;
    rear = -1;              //empty
}

template<class T>
bool StackQ<T>::stackisFull() const
{
    return (stackSize == top-1);
}


template<class T>
bool StackQ<T>::stackisEmpty() const
{
    return (top == -1);
}


template<class T>
bool Queue<T>::queueisFull() const
{
    return (numitems == queueSize);
}


template<class T>
bool Queue<T>::queueisEmpty() const
{
    return (numitems = 0);
}

template<class T>
void StackQ<T>::push(char num)
{
    assert(!stackisFull());   //need to replace for array
    top++;
    stackArray[top] = num;
}


template<class T>
char StackQ<T>::pop()
{
    assert(!stackisEmpty());  //need to replace for array
    char num = stackArray[top];
    top--;
    return num;
}


template<class T>
void Queue<T>::enqueue(int num)
{
    assert(!queueisFull());   //need to replace for array
    if (rear == (queueSize-1))
        rear = 0;
    else
        {rear = rear+1;}
    queueArray[rear] = num;
    numitems++;

}


template<class T>
int Queue<T>::dequeue()
{
    assert(!queueisEmpty());   //need to replace for array
    front = (front+1) % queueSize;
    numitems--;
    return queueArray[front];
}

template<class T>
void StackQ<T>::display(int Ssize)
{
    for (int i=0; i<Ssize; i++)
    {
        cout << *(stackArray + i) << "  ";
    }
}

template<class T>
bool StackQ<T>::symbolCheck(StackQ<T> stack)
{
    bool groupCheck = true,
         numberCheck = false,
         totalCheck = false;
    T tempChar;
    int openType1 = 0,
        openType2 = 0,
        openType3 = 0,
        openType4 = 0,
        closeType1 = 0,
        closeType2 = 0,
        closeType3 = 0,
        closeType4 = 0;

    while(stack.stackisEmpty() == false)
    {
        tempChar = stack.pop();

        switch(tempChar)
        {
        case '(':
            openType1++;
            break;
        case '{':
            openType2++;
            break;
        case '[':
            openType3++;
            break;
        case '<':
            openType4++;
            break;
        case ')':
            closeType1++;
            break;
        case '}':
            closeType2++;
            break;
        case ']':
            closeType3++;
            break;
        case '>':
            closeType4++;
            break;
        default:
            break;
        }

        if(openType1 < closeType1 || openType2 < closeType2 ||
           openType3 < closeType3 || openType4 < closeType4)
            groupCheck = false;
    }
    if(openType1 == closeType1 && openType2 == closeType2 &&
       openType3 == closeType3 && openType4 == closeType4)
        numberCheck = true;

    if(groupCheck == true && numberCheck == true)
        totalCheck = true;

    return totalCheck;

}


int main()
{
    string expression;
    string expressionSave;
    bool symbols;
    char temp;
    int userInput; //Input from first cin, must be 1 or 9.
    cout << "*** Welcome to My stack / Queue Program ***" << endl << endl
         << "The function of this program is to : " << endl
         << "      1- Validate that a stack and a" << endl
         << "         queue is identical." << endl
         << "         Stacks / Queues are same if" << endl
         << "         they have the same number of elements, symbols," << endl
         << "         and their elements and symbols at the" << endl
         << "         corresponding positions are the same." << endl << endl
         << "      2- The program also outputs whether the elements" << endl
         << "         do have the same matching group symbols." << endl << endl;

         do
         {
             cout << "Select from the following menu" << endl
                  << "1.    Enter Stack / Queue Values." << endl
                  << "9.    Terminate the program.     ";
             cin >> userInput;

             while (!cin)
             {
                 cout << "*********Invalid Input, must be an integer."
                      << endl << "Try again: ";
                 cin.ignore();
                 cin.clear();
                 cin >> userInput;
             }

             while (userInput != 1 && userInput !=9)
             {
                  cout << "*********Invalid Input, must be 1 or a 9."
                      << endl << "Try again: ";
                 cin >> userInput;
             }

             cout << "Enter stack values terminated by ; ";
            cin.ignore(1000, '\n');
            getline(cin, expression,';');

            int size = expression.size();
            typedef StackQ <int> charStack;
            charStack stack(size);
            for (int i=0; i<expression.length(); i++)
            {
                if (expression[i] != ' ')
                {
                    expressionSave += expression[i];
                }
            }
            for (int i = 0; i<size; i++)
            {
                stack.push(expressionSave[i]);
            }


            cout << "Enter Queue values terminated by ; ";
            cin.ignore(1000, '\n');
            getline(cin, expression,';');

            size = expression.size();
            typedef Queue <int> charQueue;
            charQueue queue(size);
            for (int i=0; i<expression.length(); i++)
            {
                if (expression[i] != ' ')
                {
                    expressionSave += expression[i];
                }
            }
            for (int i = 0; i<size; i++)
            {
                queue.enqueue(expressionSave[i]);
            }

            StackQ<char> dupStack(size);
            StackQ<char> flipedStack(size);

            while(dupStack.stackisEmpty() != true)
            {
                temp = dupStack.pop();
                flipedStack.push(temp);
            }

            symbols = dupStack.symbolCheck(dupStack);

            if(symbols)
            {
                cout << "First Expression does have "
                     << "matching group symbols."
                     << endl << endl;
            }
            else
            {
                cout << "First Expression does not have matching "
                     << "group symbols."
                     << endl << endl << endl;
            }


            if(symbols)
            {
               cout << endl
                    << "Stack and Queue are identical" << endl << endl;
            }
         else
            {
                cout << endl << "Stack and Queue are not identical"
                     << endl << endl;
            }


         }while (userInput != 9 && userInput != 1);













}
