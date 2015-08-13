//p.350 Nicholas C++11
// cont/mapfind1.cpp
//#include <map>
//#include <iostream>
//#include <algorithm>
//#include <utility>
//using namespace std;
//int main() {
//  // map with floats as key and value
//  // - initializing keys and values are automatically converted to float
//  map<float, float> coll = {
//      {1, 7}, {2, 4}, {3, 2}, {4, 3}, {5, 6}, {6, 1}, {7, 3}};
//  // search an element with key 3.0 (logarithmic complexity)
//  auto posKey = coll.find(3.0);
//  if (posKey != coll.end()) {
//    cout << "key 3.0 found (" << posKey->first << ":" << posKey->second << ")"
//         << endl;
//  }
//  // search an element with value 3.0 (linear complexity)
//  auto posVal =
//      find_if(coll.begin(), coll.end(), [](const pair<float, float> &elem) {
//        return elem.second == 3.0;
//      });
//  if (posVal != coll.end()) {
//    cout << "value 3.0 found (" << posVal->first << ":" << posVal->second << ")"
//         << endl;
//  }
//}
//https://www.sgi.com/tech/stl/hash_map.html
#include <map>
#include <hash_map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>
#include <unordered_map>

//using google::dense_hash_map;      // namespace where class lives by default
using std::cout;
using std::endl;
//using ext::hash;  // or __gnu_cxx::hash, or maybe tr1::hash, depending on your OS


using namespace std;
using namespace __gnu_cxx;


struct eqstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};

int main()
{
//    unordered_map<Name,int,function<size_t( const Name & name )>> ids(100, name_hash );
//    unordered_map<Name,int,function<decltype(name_hash)>> ids(100, name_hash );
  hash_map<const char*, int, std::hash<const char*>, eqstr> months;
//  dense_hash_map<const char*, int, hash<const char*>, eqstr> months;
//    unordered_map<const char*, int, hash<const char*>, eqstr> months;
//    hash_map<string, int> telephoneNumbers;
  months["january"] = 31;
  months["february"] = 28;
  months["march"] = 31;
  months["april"] = 30;
  months["may"] = 31;
  months["june"] = 30;
  months["july"] = 31;
  months["august"] = 31;
  months["september"] = 30;
  months["october"] = 31;
  months["november"] = 30;
  months["december"] = 31;

  cout << "september -> " << months["september"] << endl;
  cout << "april     -> " << months["april"] << endl;
  cout << "june      -> " << months["june"] << endl;
  cout << "november  -> " << months["november"] << endl;
}
