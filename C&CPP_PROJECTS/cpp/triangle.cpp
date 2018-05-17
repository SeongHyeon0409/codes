#include <iostream>
#include <fstream>
using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int i = 0; i < lineCount; i++)
	{
        int a, b, c;
        fin >> a >> b >> c;
        if ((a + b) <= c)
            cout << 0 <<endl;
        else if ((a == b) && (b ==c))
            cout << "1" << endl;
        else if ((c*c) == (b*b + a*a))
            cout << "2" << endl;
        else if ((b == a) or (a == c) or (b == c))
            cout << "3" << endl;
        else
            cout << "4" << endl;  
	}
}


