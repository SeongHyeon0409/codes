#include <iostream>

using namespace std;

int main()
{
    int x, y, r;
    cin >> x;
    cin >> y;

    while(y != 0){
        r = x % y;
        x = y;
        y = r;
    }

    cout << x;
}