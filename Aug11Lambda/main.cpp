#include <functional>
#include <iostream>
using namespace std;

//auto l = [] {
//std::cout << "hello lambda" << std::endl;
//}();

function<int(int, int)> returnLambda() {
  return [](int x, int y) { return x * y; };
}

auto l = [] {
std::cout << "hello lambda" << std::endl;
};

int x = [] {return 24; }();

auto i = [] (int x, int y)
{
return x * y;
};

void llll(const string &s){
    cout << s << endl;
}


int main() {

  auto lf = returnLambda();
  cout << lf(6, 7) << endl;
  l();

  auto a = 1;
  cout << a << endl;

  cout << x << endl;

  [] {
  std::cout << "hello lambda" << std::endl;
  } (); // prints ‘‘hello lambda’’      //l()

  cout << i(2,3) << endl;

  int x = [] {return 23334; }();

  cout << x << endl;
  cout << [] {return 44444;}() << endl;
  cout << [] {return 44444;} << endl;

  auto lll = [] (const std::string& s) {
  std::cout << s << std::endl;
  };

  lll("stupid");

//  void llll(const string &s){   Cannot
//      cout << s << endl;        in
//  }                             main has to be outsite of main() unlike lambda
  llll("very stupid");

  cout << [] () -> double {
  return 42.55;
  }() << endl;

  cout << [] () -> double {  //output 1 need {}()
  return 42.55;
  } << endl;
}
