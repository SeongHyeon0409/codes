#include <iostream>
#include <fstream>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int y, m;

	for (int q = 0; q < lineCount; q++)
	{
        int today;
        int c = 0;
        int sstack = 0;
        fin >> y >> m;
        int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            monthArray[1] = 29;

        for (int i = 0; i<m-1; i++)
            c += monthArray[i];

        for (int i = 1; i<y; i++)
        {
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                c += 366;
            else
                c += 365;
        }

        today = (c+1)%7;
        sstack += today;

        cout << y << " " << m << endl;
        for (int i = 0; i<today; i++)
            cout << "0" << " ";
        
        for (int i = 1; i <= monthArray[m-1]; i++)
        {
            cout << i;
            sstack++;
            if ((sstack%7==0)&&(monthArray[m-1]==i))
                continue;
            else if(sstack%7 == 0)
                cout << "\n";
            else
                cout << " ";
        }

            for (; sstack % 7 > 0; sstack++){
                cout << "0" << " ";
            }
        
        cout << endl;

    }

}


