

#include <iostream>

#include <fstream>

#include <vector>

#include <algorithm>

using namespace std;



int main(void){

	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;


    for(int i = 0; i<lineCount; i++){

        int num;

        const unsigned int max = 0xffffffff;

        vector<unsigned int> numArray;

        fin >> num;

        //numArray에 모든 해밍수를 넣어줌.
        for (unsigned int k = 1;; k *= 2) 
        {

            for (unsigned int l = k;; l *= 3) 
            {

                for (unsigned int m = l;; m *= 5) 
                {

                    numArray.push_back(m);

                    if (m>max/5) break;

                }

                if (l>max/3) break;

            }

            if (k>max/2) break;

        }



        //정렬 후 마지막값 출력
        sort(numArray.begin(), numArray.end());

        /*for (int i = 0; i <max; i++)
            cout<<numArray[i]<<" ";
        cout << endl; */

        cout << numArray[num-1] << endl;

        }


    return 0;

}
