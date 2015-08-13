// p.346 Nicholas C++11 Standard
//#include <unordered_set>
//#include <iostream>
//#include <iostream>
// using namespace std;

// int main() {
//  // unordered multiset container for int values
//  std::unordered_multiset<int> coll;
////    map<int> coll;  //map need 2 elements
//  // insert some elements
//  coll.insert({1, 3, 5, 7, 11, 13, 17, 19, 23, 27, 1});
//  // print all elements
//  for (auto elem : coll) {
//    std::cout << elem << ' ';
//  }
//  std::cout << std::endl;
//  // insert one more element
//  coll.insert(25);
//  // print all elements again
//  for (auto elem : coll) {
//    std::cout << elem << ' ';
//  }
//  std::cout << std::endl;
//}
// cont/map1.cpp
//#include <map>
//#include <string>
//#include <iostream>
//#include <algorithm>
// using namespace std;
// int main() {
//  map<string, double> coll{{"tim", 9.9}, {"struppi", 11.77}};
////    map<string, double> coll;
////    coll["tim"] = 9,9;
////    coll["struppi"] = 11.77;

//  // square the value of each element:
//  for_each(coll.begin(), coll.end(), [](pair<const string, double> &elem) {
//    elem.second *= elem.second;
//  });
//  // print each element:
//  for_each(coll.begin(), coll.end(),
//           [](const map<string, double>::value_type &elem) {
//             cout << elem.first << ": " << elem.second << endl;
//           });
//}
// cont/map2.cpp
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  // create map / associative array
  // - keys are strings
  // - values are floats

  typedef map<string, float> StringFloatMap;
  StringFloatMap stocks; // create empty container
//    map<string, float> stocks;
  // insert some elements
  stocks["BASF"] = 369.50;
  stocks["VW"] = 413.50;
  stocks["Daimler"] = 819.00;
  stocks["BMW"] = 834.00;
  stocks["Siemens"] = 842.20;
  // print all elements
  StringFloatMap::iterator pos;

//  stocks::iterator pos;
//  map<string, float>::iterator pos;
  cout << left; // left-adjust values
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
         << endl;
  }
  cout << endl;
  // boom (all prices doubled)
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    pos->second *= 2;
  }
  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
         << endl;
  }
  cout << endl;
  // rename key from "VW" to "Volkswagen"
  // - provided only by exchanging element
  stocks["Volkswagen"] = stocks["VW"];
  stocks.erase("VW");
  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
         << endl;
  }
}
