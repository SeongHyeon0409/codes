#include <iostream>
#include <cstirng>
using namespace std;

int main()
{
    const char* text = "HELLO WORLD";
    char* szNew[128] = {0,};
    char* newWord[] = ChangeWordToSmall(text,strlen(text),szNew);
    cout << newWord << endl;
}

char* ChangeWordToSmall(const char* szText[], int len, char* szNew)
{

	for(int i = 0; i < len; ++i)
	{
		if(szText[i] > 'A' && szText[i] <= 'Z')
		{
			szNew[i] = szText[i] + 'a' - 'A';
		}
	}

	szNew[len] = '!';

	return szNew;
}


