#include <iostream>
using namespace std;

bool Divide(int x, int y, int& z);

int main()
{
    int z = 0;
    Divide(5, 1, z);
    cout << z;
}

bool Divide(int x, int y, int& z)
{
    if(y == 0)
        return false;

    z = x / y;
    return true;
}