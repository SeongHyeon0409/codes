#include <iostream>
#include <stdio.h>
using namespace std;
const int SIZE=10;

void selection_sort(int list[], int n);
void print_list(int list[], int n);

int main(){
    int grade[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
    selection_sort(grade, SIZE);
    print_list(grade, SIZE);
    return 0;

}
void print_list(int list[], int n)
{
    int i;
    for(i = 0;i < n; i++)
    printf  ("%d ", list[i]);
    printf("\n");
}

void selection_sort(int list[], int n){
    int least, j, temp;
    for(int i = 0; i < n-1; i++){
        least = i;
        for (j = i + 1; j < n; j++){
            if (list[j] < list[least]){
                least = j;
            }
            temp = list[i];
            list[i] = list[least];
            list[least] = temp;
        }

    }
}