#include <iostream>
#include <fstream>
using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int size;

	for (int i = 0; i < lineCount; i++)
	{
        
        fin >> size;
        int half = size/2;
        //1,2사분면
        for( int u = 0; u <size/2; u++){
            for (int j = 0; j <size/2; j++)
            {
                cout << ".";
            }

            cout << "I";

            for (int l = 1; l <= size/2; l++)
            {
                if (l == half){
                    cout << "*";
                }
                else{
                    cout << ".";
                }
            }
            cout << endl;
            half--;
        }
        //중앙
        for (int q = 0; q < size/2; q++)
        {
            cout << "+";
        }
        cout << "O" ;
        for (int x = 0; x < size/2; x++)
        {
            cout << "+";
        }
        cout << endl;
        //3,4분면
        half = size/2;
        for( int u = 0; u <size/2; u++)
        {
            for (int l = 1; l <= size/2; l++)
            {
                if (l == half){
                    cout << "*";
                }
                else{
                    cout << ".";
                }
            }

            cout << "I";

            for (int j = 0; j <size/2; j++)
            {
                cout << ".";
            }
            cout << endl;
            half--;
        }
	}
}


