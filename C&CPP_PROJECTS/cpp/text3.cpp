#include <iostream>
#include <fstream>
using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount; // 첫줄의 원소의 개수를 읽는다.

	for (int i = 0; i < lineCount; i++)
	{
		int ascore, bscore;
        int a =0, b =0, result = 0;
        fin >> ascore;
        fin >> bscore;


        a += (ascore/16)*2;
        a += ascore%16;
        
        b += (bscore/16)*2;
        b += bscore%16;

        result = a>b ? a : b;

        cout << result << endl;

	}
}

