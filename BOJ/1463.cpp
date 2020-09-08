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
	//X가 3으로 나누어 떨어지면, 3으로 나눈다.
	//X가 2로 나누어 떨어지면, 2로 나눈다.
	//1을 뺀다.
	// 1000000보다 작은 N
	//첫줄에 연산하는 횟수의 최솟값 출력
	int N;
	scanf("%d", &N);
	fill(dp, dp + 1000001, -1);
	printf("%d", div(N));
	return 0;
}