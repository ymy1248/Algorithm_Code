#include <iostream>
#include <map>

using namespace std;
int main ()
{
  std::map<int,int> mymap;
  std::map<int,int>::iterator itlow,itup;

  mymap[10] = 0;
  mymap[15] = 0;
  mymap[20] = 0;
  mymap[4] = 0;
  mymap[6] = 0;

  itlow=mymap.lower_bound (13);  // itlow points to b
  itup=mymap.upper_bound (5);   // itup points to e (not d!)

  cout << itlow->first << endl;
  cout << itup->first << endl;

  // print content:

  return 0;
}
