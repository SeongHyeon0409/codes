#include <iostream>
//using namespace std;

int main()
{
    int n;
    int i = 1;

    std::cin >> n;
    while (i < 10){
        std::cout << n << "x" << i << "=" << n * i << std::endl;
        i++;
    }

    return 0;
}