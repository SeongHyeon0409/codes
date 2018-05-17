#include <iostream>

using namespace std;

int main()
{
    char letter;

    while (1){
        cout << "소문자를 입력하시오: ";
        cin >> letter;

        if (letter == 'Q')
            break;
        else if ( letter < 'a' || letter > 'z')
            continue;
        
        letter -= 32;
        cout << "변환된 대문자는" << letter << "입니다." <<endl;
        
    }
    
}