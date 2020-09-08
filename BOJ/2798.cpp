#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int bj(int* a,int M,int k)
{
	int max = 0;
	
	for (int i = 0; i < k-2; i++)
	{
		for (int j = i+1; j < k-1; j++)
		{
			for (int s = j+1; s < k; s++)
			{
				if (max < (a[i] + a[j] + a[s]) && (a[i] + a[j] + a[s]) <= M)
					max = (a[i] + a[j] + a[s]);
				if (max == M)
				{
					printf("%d", M);
					return 0;
				}
			}
		}
	}
	printf("%d", max);
	return 0;

}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int* card = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", (card + i));
	}
	bj(card, M, N);
	return 0;
}