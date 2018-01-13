#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;


int getNextRando(vector<bool> &boolArray)
{
    int tryRando = rand()%100;
    while (boolArray[tryRando])
    {
        tryRando = (rand()%100);
    }
      boolArray[tryRando] = true;
      return tryRando;
}


int main()
{
    int vSize;
    cin >> vSize;
    vector<int>aVector(vSize);                   //Row vector
    vector<vector<int> >bVector(vSize, aVector); //2d vector of vector<int> type
    bool flag = true;               //Flag will change to false if duplicate

    vector<bool>boolArray(100, false);
    //populate vector with random numbers
        for (int r=0;r<vSize;r++)
        {
            for(int c=0;c<vSize;c++)
            {
                bVector[r][c] = getNextRando(boolArray);
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

}
