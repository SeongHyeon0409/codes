#include <iostream>

using namespace std;

int main()
{
    int answer = 45;
    int guess;
    int tries = 0;

    do{
        cout << endl << "정답을 추측하여 보시오:";
        cin >> guess;

        if (answer > guess)
        {
            cout << "제시한 정수가 낮습니다.";
        }
        if (guess > answer)
        {
            cout << "제시한 정수가 높습니다.";
        }
        tries++;
    }while ( answer != guess );

    cout << "축하합니다. 시도횟수 = " << tries << endl;

    return 0;
}