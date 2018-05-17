#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

    if (fin.fail())
    {
        cerr << "Input file opening failed. \n";
        exit(1);
    }

	int lineCount = 0;
	fin >> lineCount; // 첫줄의 원소의 개수를 읽는다.

	for (int i = 0; i < lineCount; i++)
	{
		int max_num;
        int second_max_num;
        int count,num;
        fin >> count;
        if (count == 1){
            fin >> num;
            cout << num << endl;
        }

        else if(count == 2){
            int a,b,answer;
            fin >> a;
            fin >> b;
            answer = a>b ? b: a;
            cout << answer << endl;
        }

        else{

            fin >> max_num;
            second_max_num = max_num;

            for (int j = 0; j< count-1 ; j++)
            {        
                fin >> num;
                if (num > max_num)
                {
                    second_max_num = max_num;
                    max_num = num;
                }
            }
            cout << second_max_num << endl;
        }
        
	}
    return 0;
}

