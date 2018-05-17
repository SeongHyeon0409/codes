#include <iostream>
using namespace std;

int FuncTwo(int &a);

int main()
{
    int a = 4;

    int b = FuncTwo(a);
    int c = FuncTwo(a);

    cout << a << " " << b << " " << c;
}

int FuncTwo(int &a)

{

   a++;

   return a;

}

