#include <algorithm>
#include <iostream>
#include <cstdio>
int c = 0;
int Sum(int K, int* arr,int i)
{
	int sum = 0;
	*(arr + i) = K % 10;
	i++;
	if(K>=10) K = K / 10;

	else {
		*(arr + i) = K;
		for (int j = 0; j < i; j++)
		{
			sum += *(arr + j);
		}
		return sum;
	}
	return Sum(K, arr, i);
}

int main()
{
	int N, *a,t=0,q=0;
	scanf("%d", &N);
	a = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		if (Sum(i, a, t) + i == N) 
		{
			printf("%d", i);
			q = -1;
			break;
		}
	}
	if (q==0) printf("0");
	return 0;
}