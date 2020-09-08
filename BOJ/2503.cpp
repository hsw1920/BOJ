#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1000] = { 0, };

int check(int guess, int clue, int strike, int ball) {
	int g1 = guess / 100, g2 = (guess % 100) / 10, g3 = (guess % 100) % 10;
	int c1 = clue / 100, c2 = (clue % 100) / 10, c3 = (clue % 100) % 10;

	int strikeCount = 0;
	int ballCount = 0;

	//�����ϴ� ���ڿ� 0�� ���ְų�, ���� ��ġ�� ����
	//������ 0�� ����
	if (g1 == 0 || g2 == 0 || g3 == 0 || g1 == g2 || g1 == g3 || g2 == g3)
		return 0;
	if (g1 == c1)strikeCount++;
	if (g2 == c2)strikeCount++;
	if (g3 == c3)strikeCount++;

	if (g1 == c2 || g1 == c3)ballCount++;
	if (g2 == c1 || g2 == c3)ballCount++;
	if (g3 == c2 || g3 == c1)ballCount++;

	//���� ���ǿ� �����ϴ� ���ڴ� 1����
	if (strike == strikeCount && ball == ballCount)
		return 1;
	//���ǿ� �������� ������ 0����
	return 0;
}
int main()
{
	int N;
	cin >> N;

	int clue, strike, ball;
	for (int i = 0; i < N; i++) {
		cin >> clue >> strike >> ball;
		for (int j = 123; j <= 987; j++) {
			if(num[j]==0)
			//0�ΰ͵��� �ٽ� üũ
			num[j] = !check(j, clue, strike, ball);
		}
	}
	int guessNum = 0;

	for (int i = 123; i <= 987; i++)
	{
		if (num[i] == 0) guessNum++;
	}

	cout << guessNum << endl;

	return 0;
}
