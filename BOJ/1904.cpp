#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int fib(int n)
{
	long long int* a, sum = 0;
	a = (long long int*)malloc(sizeof(long long int) * n);
	a[0] = 1;
	a[1] = 2;
	if (n == 1)return 1;
	if (n == 2)return 2;
	for (int i = 0; i < n - 2; i++)
	{
		a[i + 2] = a[i] + a[i + 1];
		if (a[i+2] >= 15746)
		{
			a[i + 2] %= 15746;
			a[i + 1] %= 15746;
			a[i] %= 15746;
		}
	}
	return (a[n-1]);
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", fib(N));
	return 0;
}