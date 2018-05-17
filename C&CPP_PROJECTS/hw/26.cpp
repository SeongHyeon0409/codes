/**************************************
���δ��б� ��ǻ�Ͱ��к� 20103324 ������
���� 26 : ���� ���߱� ����
***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#define NOT_USED 0
#define BALL 1
#define STRIKE 2
#define NO_ANSWER 3

using namespace std;

void playBaseballGame(ifstream&, int);

int main()
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr << "Input file opening failed\n";
		exit(1);
	}

	inStream >> numTestCases;

	for(int i=0; i<numTestCases; i++)
	{
		int count;

		inStream >> count; // �� ������ ������ 
		playBaseballGame(inStream, count);

		
	}
	inStream.close();
}

void playBaseballGame(ifstream& inStream, int size)
{
	/*Ư�� ������ ��� ������ �� ������ ���ϴ� �˰����� ������ �����ǹǷ� �ٸ� �˰����� ����.
	�� ���� 0~9�� �ڸ��� 1~4�� ���� �迭�� ���� �� ���ڿ� ��Ʈ����ũ, ���� �о�´�. �� ������ �ڸ���
	���� ���Ͽ� ��Ʈ����ũ�� ��ġ�ϴ��� �����ְ� (Ȥ�� ��) �̰��� ���õ� ������ �´��� Ȯ���غ���.*/

	const int nums=10, place=4;
	int preAnswer[nums][place]={NOT_USED}; // 10 : 0~9�� ���� 4 : �� ������ ��ġ ���� ���ɼ� ����
	int answer[place]={NOT_USED}; // ������ ���� ������ �͸� ����

	for(int i=0; i<size; i++)
	{
		int number, countOfStrike, countOfBall;

		inStream >> number >> countOfStrike, countOfBall; // ���ڿ� ��Ʈ����ũ, ���� ������ �о�´�.
		if(countOfStrike == 4) // ó���� ���õ� ���� 4��Ʈ����ũ���
		{
			cout << number << "\n";
		}
		else if(countOfStrike) // ��Ʈ����ũ�� ���� �ִٸ�
		{
			/*��Ʈ����ũ�� ����� ���� �ٸ� ���ڰ� �� �ְ�, �ٸ� ���ǿ� �ɸ��� �ʰ� ���� ������ ���ٸ� ������ �ƴϴ�.*/
			for(int j=3; j>=0; j--)
			{
				int temp=number%10; // ������ �ڸ��� ����.
				number/=10;

				if(preAnswer[number][j]==STRIKE) // �̹� ��Ʈ����ũ��
				break;
			}

		}
		else // ��Ʈ����ũ�� ���� ���ٸ� �ش� ���� ��� ���ɼ��� ���� �����̴�.
		{
			for(int j=3; j>=0; j--)
			{
				preAnswer[number%10][j] = NO_ANSWER;
				number/=10;
			}
		}
	}

}
