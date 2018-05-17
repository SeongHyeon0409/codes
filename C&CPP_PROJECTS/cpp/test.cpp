#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	ifstream fin;
	fin.open("input.txt");
	int lineCount = 0;
	fin >> lineCount; // 첫줄의 원소의 개수를 읽는다.

	for (int i = 0; i < lineCount; i++)
	{
		int count,num,a;
        int stack = 0;
        fin >> count;
        fin >> num;
		for (int j = 0; j< count; j++)
        {
            fin >> a;
            if (num == a)
            {
                stack++
            }

        }
        cout << stack << endl;

	}

	return 0;
}

