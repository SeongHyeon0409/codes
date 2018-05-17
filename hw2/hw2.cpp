#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int num,n;
    int x = 0;

	for (int i = 0; i < lineCount; i++)
	{
        int aLength, bLength;
        fin >> aLength;
        vector<int> aArray;
        vector<int> bArray;
        vector<int> cArray;

        for (int i = 0; i < aLength; i++)
        {
            fin >> num;
            aArray.push_back(num);
        }

        fin >> bLength;
        for (int i = 0; i < bLength; i++)
        {
            fin >> num;
            bArray.push_back(num);
        }

        sort(aArray.begin(),aArray.end());
        sort(bArray.begin(),bArray.end());


        for(int i = 0; i<aLength; i++)
        {
            for(int j = 0; j<bLength; j++)
            {
                if(aArray[i] == bArray[j])
                    cArray.push_back(aArray[i]);
            }
        }

        cout << cArray.size() << " ";
        for(int i = 0; i<cArray.size(); i++)
        {
            cout << cArray[i] << " ";
        }
        cout << "\n";

        cArray.clear();

        for(int i = 0; i<aLength; i++)
        {
            cArray.push_back(aArray[i]);
        }

        for(int i = 0; i < bLength; i++)
        {
            x = 0;
            for(int j = 0; j<cArray.size(); j++)
            {
                if(bArray[i] == cArray[j])
                    x = 1;
                    continue;
            }
            if (x == 1)
                continue;
            
            cArray.push_back(bArray[i]);
        }

        sort(cArray.begin(),cArray.end());
        cout << cArray.size() << " ";
        for(int i = 0; i<cArray.size(); i++)
        {
            cout << cArray[i] << " ";
        }
        cout << "\n";

        cArray.clear();

        for(int i = 0; i<aLength; i++)
        {
            x = 0;
            for(int j = 0; j<bLength; j++)
            {
                if(aArray[i] == bArray[j])
                    x = 1;
                    continue;
            }

            if(x == 1)
                continue;

            cArray.push_back(aArray[i]);
        }

        cout << cArray.size() << " ";
        for(int i = 0; i<cArray.size(); i++)
        {
            cout << cArray[i] << " ";
        }
        cout << "\n";

    }
}


