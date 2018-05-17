#include <iostream>

using namespace std;

int main()
{
    float score, sum = 0.0, avg;
    int stack = 0;
    while (1){
        cout << "학생성적을 입력하시오: ";
        cin >> score;
        if (score < 0){
            break;
        }
        sum += score;
        stack += 1;
    }
    avg = sum / stack;
    cout << "학생들 성적의 평균은" << avg << "입니다." <<endl;
    return 0;
}