#include <unordered_map>
#include <hash_map>
#include <iostream>
#include <string.h>
#include <functional>
#include <cstring>
using namespace std;

struct EqualCp {
  bool operator()(char const *l, char const *r) const {
    return strcmp(l, r) == 0;    // no hash function
  }
};
struct HashCp {
  size_t operator()(char const *str) const {
    return hash<std::string const &>()(str); // no equal compare to ==
                                             // hash string
  }
};

//struct HashString { //operator() and hash
//  size_t operator()(string const &str) const {
//    return hash<char const *>()(str.c_str());
//  }
//};
//struct HashString { //operator() and hash
//  size_t operator()(string const &str) const {
//    return hash<string const &>()(str.c_str());
//  }
//};
struct HashString { //operator() and hash
  size_t operator()(string const &str) const {
    return __gnu_cxx::hash<char const *>()(str.c_str());  //hash char
  }
};

int main() {
//  unordered_map<char const *, int, HashCp, EqualCp> months;
//  un//ordered_map<const char*, int, hash<string const &>, EqualCp> months;
//  unordered_map<const char*, int, std::hash<const char*>, eqstr> months;

  unordered_map<string, int, HashString> months;

  months["april"] = 30;
  months["november"] = 31;
  string apr("april"); // different pointers, same string
  cout << "april -> " << months["april"] << '\n' << "april -> "
       << months[apr.c_str()] << '\n';
}
