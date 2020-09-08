#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000001];
int div(int N)
{
	if (N == 1)return 0;
	if (dp[N] != -1)return dp[N];

	int result = div(N - 1) + 1;
	if (N % 3 == 0)result = min(result, div(N / 3) + 1);
	if (N % 2 == 0)result = min(result, div(N / 2) + 1);
	dp[N] = result;
	return result;

}

int main()
{
	//X�� 3���� ������ ��������, 3���� ������.
	//X�� 2�� ������ ��������, 2�� ������.
	//1�� ����.
	// 1000000���� ���� N
	//ù�ٿ� �����ϴ� Ƚ���� �ּڰ� ���
	int N;
	scanf("%d", &N);
	fill(dp, dp + 1000001, -1);
	printf("%d", div(N));
	return 0;
}