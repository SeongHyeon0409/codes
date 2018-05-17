#include <iostream>

using namespace std;

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void)
{
    int month;
    cin >> month;
    cout << days[month] << endl;

    return 0;
}