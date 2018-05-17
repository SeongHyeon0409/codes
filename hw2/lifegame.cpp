#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Print(char** a, int row, int col)
{
    for(int j = 0; j < row; j++){
        for(int k = 0; k < col; k++)
            cout << a[j][k] << " ";
        cout << endl;
    }
}

int Crush(char** a, int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return 0;
    else
        return 1;
}

int Neignbor(char** a, int row, int col, int r, int c)
{
    int count = 0;
    if (Crush(a, row, col, r-1 ,c-1) == 1 && a[r-1][c-1] == 'O')
        count++;
}
int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int row, col, decade;
    char** board;
	for (int q = 0; q < lineCount; q++)
	{
        fin >> row >> col >> decade;

        board = new char*[row];

        for (int i = 0; i<row; i++)
        {
            board[i] = new char[col];
        }
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
                fin >> board[i][j];
        }

        Print(board, row, col);

        
    }//end lineCount
}

