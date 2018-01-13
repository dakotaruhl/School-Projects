// shuffle algorithm example
#include <iostream>     // std::cout
//#include <algorithm>    // std::shuffle
#include <vector> // std::array
//#include <random>       // std::default_random_engine
#include <ctime> // std::chrono::system_clock
#include <cstdlib>

using namespace std;
int main ()
{
  vector<int> foo(5, 6);

  // obtain a time-based seed:
  srand(time(NULL));


  cout << "shuffled elements:";
  for (int& x: foo) cout << ' ' << x;
  cout << '\n';

  return 0;
}
