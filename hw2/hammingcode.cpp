#include <iostream>
#include <fstream>
#include <vector>
#define EVEN(a) (a%2==0 ? 1 : 0)
using namespace std;

void displayV(vector<int> &v);
int by2degit(vector<int> &v);

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int hcase;
    unsigned int num;


	for (int i = 0; i < lineCount; i++)
	{
        int p1=0, p2=0, p4=0, p8=0, p16=0;
        int c1=0, c2=0, c4=0, c8=0, c16=0;
        fin >> hcase >> num;
        vector<int> b;
        b.clear();

        if (hcase == 0)
        {
            for (int i = 25; i >=0 ; i--){
                b.push_back(num >> i & 1 ? 1 : 0); 
            }
 
            b.insert(b.end()-0,0);
            b.insert(b.end()-1,0);
            b.insert(b.end()-3,0);
            b.insert(b.end()-7,0);
            b.insert(b.end()-15,0);

            int stack = 0;
            //p1
            for(int i = 0; i<31; i+=2)
            {
                if(b[i] == 1)
                    p1++;
            }
            //p2
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 4)
                    stack = 0;
                if(stack < 2)
                    if(b[i] == 1)
                        p2++;
                stack++;
            }  
            //p4
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 8)
                    stack = 0;
                if(stack < 4)
                    if(b[i] == 1)
                        p4++;
                stack++;
            }
            //p8
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 16)
                    stack = 0;
                if(stack < 8)
                    if(b[i] == 1)
                        p8++;
                stack++;
            }
            //p16
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 32)
                    stack = 0;
                if(stack < 16)
                    if(b[i] == 1)
                        p16++;
                stack++;
            }                   
            b[30] = (EVEN(p1)) ? 0 : 1;
            b[29] = (EVEN(p2)) ? 0 : 1;
            b[27] = (EVEN(p4)) ? 0 : 1;
            b[23] = (EVEN(p8)) ? 0 : 1;
            b[15] = (EVEN(p16)) ? 0 : 1;


        }//end case 0

        if ( hcase == 1)
        {
            for (int i = 30; i >=0 ; i--){
                b.push_back(num >> i & 1 ? 1 : 0); 
            }

            c1 = b[30];
            c2 = b[29];
            c4 = b[27];
            c8 = b[23];
            c16 = b[15];

            b[30] = 0;
            b[29] = 0;
            b[27] = 0;
            b[23] = 0;
            b[15] = 0;
            int stack = 0;
            //p1
            for(int i = 0; i<31; i+=2)
            {
                if(b[i] == 1)
                    p1++;
            }
            
            //p2
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 4)
                    stack = 0;
                if(stack < 2)
                    if(b[i] == 1)
                        p2++;
                stack++;
            }  

            //p4
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 8)
                    stack = 0;
                if(stack < 4)
                    if(b[i] == 1)
                        p4++;
                stack++;
            }

            //p8
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 16)
                    stack = 0;
                if(stack < 8)
                    if(b[i] == 1)
                        p8++;
                stack++;
            }
            //p16
            stack = 0;
            for(int i = 0; i<31; i++)
            {
                if(stack == 32)
                    stack = 0;
                if(stack < 16)
                    if(b[i] == 1)
                        p16++;
                stack++;
            }       

            int wrong = 0;

            p1 = (EVEN(p1)) ? 0 : 1;
            p2 = (EVEN(p2)) ? 0 : 1;
            p4 = (EVEN(p4)) ? 0 : 1;
            p8 = (EVEN(p8)) ? 0 : 1;
            p16 = (EVEN(p16)) ? 0 : 1;  

            if (p1 != c1)
                wrong += 1;
            if (p2 != c2)
                wrong += 2;
            if (p4 != c4)
                wrong += 4;
            if (p8 != c8)
                wrong += 8;
            if (p16 != c16)
                wrong += 16;

            
            if (wrong != 1 && wrong != 2 && wrong != 4 && wrong != 8 && wrong != 16 ){
                if (b[31 - wrong] == 1)
                    b[31 - wrong] = 0;
                if (b[31 - wrong] == 0)
                    b[31 - wrong] = 1;
            }
            b.erase(b.begin()+30);
            b.erase(b.begin()+29);
            b.erase(b.begin()+27);
            b.erase(b.begin()+23);
            b.erase(b.begin()+15);

        }//end case 1
        // if (num == 0)
        //     cout << 0 << endl;
        // else if (num == 1)
        //     cout << 1 << endl;
        // else
        cout <<  by2degit(b)<< endl;

    }
        
    
}

void displayV(vector<int> &v)
{
    for (int i = 0; i<v.size(); ++i)
            cout << v[i] << " ";
    cout << "\n";
}

int by2degit(vector<int> &v)
{
    unsigned int sum = 0;
    int a = 1;
    for (int i = v.size() -1 ; i>= 0; --i)
    {
         if(v[i] == 1)
            sum += a;
        a *= 2;
    } 
    return sum;
}

