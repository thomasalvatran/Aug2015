// p.1052 Annotation_ubuntu
#include <iostream>
#include <unordered_map>
#include <string.h>
#include <functional> //function wrapper
#include <hash_map>

using namespace std;

class HashString {
public:
  size_t operator()(std::string const &str) const {
    return __gnu_cxx::hash<char const *>()(str.c_str());
  }
};
int main() {
  __gnu_cxx::hash_map<string, int, HashString> months;
  // Alternatively, using the classes defined in hashclasses.h,
  // the following definitions could have been used:
  // CharPtrHash<int> months;
  // or:
  // StringHash<int> months;
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
  cout << "september -> " << months["september"] << endl
       << "april -> " << months["april"] << endl
       << "june -> " << months["june"] << endl
       << "november -> " << months["november"] << endl;
  HashString t;
  cout << t.operator ()("january") << endl;
}
