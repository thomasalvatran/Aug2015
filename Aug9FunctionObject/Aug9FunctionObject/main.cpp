//p. 578 Big C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class RandomInt
{
    int a, b;
public:
    RandomInt(int ia, int ib) {a = ia; b = ib;}
    int operator()();
};

inline int RandomInt::operator()(){
    return a + rand() % (b - a + 1);
}

int main(){
    RandomInt r10(1, 10);
    cout << "one random number " << r10() << endl;
    cout << "and another " << r10() << '\n';
    cout << "and another " << r10() << '\n';

    vector<int> b(10);
    generate(b.begin(), b.end(), RandomInt(1, 20));
    int a;
    for_each(b.begin(), b.end(), [](int &i){ cout << i++ << endl;}); //increase
    for_each(b.begin(), b.end(), [](int i){ cout << i << endl;});
    cout << "===" << endl;

    for (int a: b)
        cout << a << endl;

    cout << "------" << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
}
