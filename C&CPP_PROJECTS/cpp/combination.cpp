#include <iostream>
using namespace std;

int Get_integer(void);
int Combination(int n, int r);
int Factorial(int n);

int main()
{
    int a, b;

    a = Get_integer();
    b = Get_integer();

    cout << "C(" << a << "," << b << ") = " << Combination(a, b) << endl;
    return 0;
}

int Get_integer(void)
{
    int n;
    cout << "정수를 입력하세요:";
    cin >> n;
    return n;
}


int Combination(int n, int r)
{
    int a;
    a = (Factorial(n) / (Factorial(n - r) * Factorial(r)));
    return a;
}

int Factorial(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
