#include <iostream>
#include <fstream>
using namespace std;

int print(int a){
    for (int i = 0; i < a; i++)
    {
        if (i%2 == 0)
            cout << "*";
        else
            cout << "+";
    }
}
int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int num;


	for (int i = 0; i < lineCount; i++)
	{
        fin >> num;
        int a = num;
        for(int i = 0; i < num/2+1; i++)
        {
            for(int j = 0; j < (num - a)/2; j++)
                cout << "-";

            print(a);

            for(int j = 0; j < (num - a)/2; j++)
                cout << "-";
            a -= 2;
            cout << endl;
        }
        
        a = 3 ;
        for(int k =0; k <num/2; k++)
        {
            for(int j = 0; j < (num - a)/2; j++)
                cout << "-";

            print(a);

            for(int j = 0; j < (num - a)/2; j++)
                cout << "-";

            a += 2;
            cout << endl;
        }
	}
}


