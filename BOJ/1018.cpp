#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int check(char *chess[], int x,int y)
{
	//B�� W�� or W�� B�� �ٽ� ĥ�ϴ� ������ �����ϴ� �迭 ����
	char** cnt1, ** cnt2;
	cnt1 = (char**)malloc(sizeof(char*) * (y - 6));
	for (int i = 0; i < y-7; i++)
	{
		cnt1[i] = (char*)malloc(sizeof(char) * (x - 6));
	}
	cnt2 = (char**)malloc(sizeof(char*) * (y - 6));
	for (int i = 0; i < y-7; i++)
	{
		cnt2[i] = (char*)malloc(sizeof(char) * (x - 6));
	}
	//cnt1, cnt2�� 0���� �ʱ�ȭ
	for (int i = 0; i < y - 7; i++)
	{
		for (int j = 0; j < x - 7; j++)
		{
			cnt1[i][j] = 0;
			cnt2[i][j] = 0;
		}
	}
	int tx,ty;
	//ó�������� W�� ��
	for (ty = 0; ty < y - 7; ty++) {
		for (tx = 0; tx < x - 7; tx++) {
			for (int i = 0; i < 8; i++) {

				for (int j = 0; j < 8; j++) {
					
					if (i % 2 == 0) {
						if (j % 2 == 0) {
							if (chess[i+ty][j+tx] == 'B')
							{
								cnt1[ty][tx]++;
							}
						}
						else if (j % 2 == 1) {
							if (chess[i + ty][j + tx] == 'W')
							{
								cnt1[ty][tx]++;
							}
						}
					}
					else if (i % 2 == 1) {
						if (j % 2 == 0) {
							if (chess[i + ty][j + tx] == 'W')
							{
								cnt1[ty][tx]++;
							}
						}
						else if (j % 2 == 1) {
							if (chess[i + ty][j + tx] == 'B')
							{
								cnt1[ty][tx]++;
							}
						}
					}
				}
			}
		}
	}
		//ó�������� B�� ��
	for (ty = 0; ty < y - 7; ty++) {

		for (tx = 0; tx < x - 7; tx++) {

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						if (chess[i+ty][j + tx] == 'W')
						{
							cnt2[ty][tx]++;
						}
					}
					else if (j % 2 == 1) {
						if (chess[i + ty][j + tx] == 'B')
						{
							cnt2[ty][tx]++;
						}
					}
				}
				else if (i % 2 == 1) {
					if (j % 2 == 0) {
						if (chess[i + ty][j + tx] == 'B')
						{
							cnt2[ty][tx]++;
						}
					}
					else if (j % 2 == 1) {
						if (chess[i + ty][j + tx] == 'W')
						{
							cnt2[ty][tx]++;
						}
					}
				}
			}
		}
		}
	}
	////cnt1, cnt2�� ����� ���� ���(������)
	//for (int i = 0; i < y - 7; i++)
	//{
	//	for (int j = 0; j < x - 7; j++) {

	//		printf("%d %d\n", cnt1[i][j], cnt2[i][j]);
	//	}
	//	printf("\n----\n");
	//}

	//8x8�迭��� �ٽ� ��ĥ�� ��� �ִ�� 64
	int maxx = 64;

	//�ּڰ� Ž��
	for (int i = 0; i < y - 7; i++)
	{
		for (int j = 0; j < x - 7; j++) {

			if (maxx > cnt1[i][j])
			{
				maxx = cnt1[i][j];
			}
			if (maxx > cnt2[i][j])
			{
				maxx = cnt2[i][j];
			}
		}
	}
	printf("\n\n\n\n");
	return maxx;
}

int main()
{
	int x, y;
	int cnt = 0;
	scanf("%d %d", &y, &x);
	getchar();
	char** arr;
	arr = (char**)malloc(sizeof(char*) * y);
	for (int i = 0; i < y; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * (x + 1));
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) 
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}

	printf("%d",check(arr, x, y));

	
	for (int i = 0; i < y; i++)
		free(arr[i]);
	free(arr);
}