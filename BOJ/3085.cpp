#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int Max(int n, char** ary, char ch)
{
	int tmp1=0, max1=0, tmp2 = 0, max2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ary[i][j] == ch) {
				tmp1++;
				if (tmp1 > max1)max1 = tmp1;
			}
			else if (ary[i][j] != ch) {
				tmp1 = 0;
			}

			if (ary[j][i] == ch) {
				tmp2++;
				if (tmp2 > max2)max2 = tmp2;
			}
			else if (ary[j][i] != ch) {	
				tmp2 = 0;
			}
		}
		tmp1 = tmp2 = 0;
	}
	return max(max1,max2);
}
int main()
{
	int a[4];
	int N,MM=0;
	char temp;
	scanf("%d", &N); getchar();
	char** arr;
	arr = (char**)malloc(sizeof(char*)*N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * (N+1));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N-1; j++)
		{
			temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;
			a[0] = Max(N, arr, 'C');
			a[1] = Max(N, arr, 'Y');
			a[2] = Max(N, arr, 'Z');
			a[3] = Max(N, arr, 'P');
			sort(a, a + 4);
			if (MM < a[3]) { MM = a[3]; }
			temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			temp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = temp;
			a[0] = Max(N, arr, 'C');
			a[1] = Max(N, arr, 'Y');
			a[2] = Max(N, arr, 'Z');
			a[3] = Max(N, arr, 'P');
			sort(a, a + 4);
			if (MM < a[3]) { MM = a[3]; }
			temp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = temp;
		}
	}
		

	printf("%d", MM);

	for (int i = 0; i < N; i++)
		free(arr[i]);
	free(arr);
	return 0;
}