#include <iostream>

using namespace std;

int main(void){
    int month, day;

    cin >> month;

    switch(month){
        case 2:
            day = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day = 30;
            break;
        default:
            day = 31;
            break;
    }
    cout << day << "일입니다.";
}