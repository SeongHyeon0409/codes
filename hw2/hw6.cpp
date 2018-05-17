#include <iostream>
#include <fstream>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    unsigned int year, month, day;

    int monthArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	unsigned int sum = 0;
    int c;

	for (int q = 0; q < lineCount; q++)
	{
        fin >> year >> month >> day;

        if (month < 3) {  
            year--;  
            month += 10;  
        }  
        else {  
            month -= 2;  
        }  
        c = year / 100;  
        year = year % 100;  
    
        sum = (day + (26*month-2)/10 - 2*c + year + year/4 + c/4) % 7;  

        cout << sum << endl;

    }
}

