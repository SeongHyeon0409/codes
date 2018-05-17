#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int num,n;

	for (int i = 0; i < lineCount; i++)
	{

        fin >> num;
        int numList[num];
        int currentFrequency = 0;

        for (int j = 0; j < num; j++)
        {
            fin >> n;
            numList[j] = n;
        }

        sort(numList , numList + num);
        
        for (int k = 0; k < num; k++)
        {   
            currentFrequency++;
            if((k+1 == num) || (numList[k] != numList[k + 1]))
            {
                cout << numList[k] << " " << currentFrequency << " ";
                currentFrequency = 0;
            }
        }
        cout << endl;

    }
}


