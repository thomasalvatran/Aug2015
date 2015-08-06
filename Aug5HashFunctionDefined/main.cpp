//http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210?pgno=2
//
// Compile this example with Visual Studio 2010
// or g++ 4.5 using -std=c++0x
//
//#include <iostream>
//#include <unordered_map>
//#include <string>

//using namespace std;

//typedef pair<string,string> Name;

//int main(int argc, char* argv[])
//{
//    unordered_map<Name,int> ids;
//    ids[Name("Mark", "Nelson")] = 40561;
//    ids[Name("Andrew","Binstock")] = 40562;
//    for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
//        cout << ii->first.first
//        << " "
//        << ii->first.second
//        << " : "
//        << ii->second
//        << endl;
//        return 0;
//}
//usr/include/c++/4.6/bits/hashtable_policy.h:753: error: undefined reference to `std::hash<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::operator()(std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >) const'
//And what is the problem? It's actually a simple one: unordered_map doesn't know how to create a hash for the given key type of std::pair. Instead, the user is left to puzzle over things
// This program uses a simple user-defined function
// to provide a hash function for use in unordered_map
//
// Compile this example with Visual Studio 2010
// or g++ 4.5 using -std=c++0x
//
#include <iostream>
#include <unordered_map>
#include <string.h>
#include <functional>  //function wrapper
#include <hash_map>

using namespace std;
//using namespace __gnu_cxx;

typedef pair<string,string> Name;

struct eqstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};
//Method 1
struct hashname {
    size_t operator()(const Name &name ) const
    {
        return hash<string>()(name.first) ^ hash<string>()(name.second);
    }
};
//Method 2
size_t name_hash( const Name & name )
{
    return hash<string>()(name.first) ^ hash<string>()(name.second);
}
//Method 3
namespace std {
    template <>
        class hash<Name>{
        public :
            size_t operator()(const Name &name ) const
            {
                return hash<string>()(name.first) ^ hash<string>()(name.second);
            }
    };
};

int main(int argc, char* argv[])
{
//Method 1
//    unordered_map<Name,int,function<decltype(name_hash)>> ids(100, name_hash );
//    unordered_map<Name,int,function<size_t( const Name & name )>> ids(100, name_hash );
//Method 2
//    unordered_map<Name,int,hashname> ids;
//Method 3
    unordered_map<Name,int> ids;

    ids[Name("Mark", "Nelson")] = 40561;
    ids[Name("Andrew","Binstock")] = 40562;

    for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
        cout << ii->first.first
                     << " "
                     << ii->first.second
                     << " : "
                     << ii->second
                     << endl;

    __gnu_cxx::hash_map<const char*, int, std::hash<const char*>, eqstr> months;

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

    return 0;
}
