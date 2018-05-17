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
        nList[num] = {0,}

        for (uint k = 1;; k *= 2) 
        {
            for (uint l = k;; l *= 3) 
            {
                for (uint m = l;; m *= 5) 
                {
                    arr.push_back(m);
                    if (m>umax/5) break;
                }
                if (l>umax/3) break;
            }
            if (k>umax/2) break;
        }

    }
}


