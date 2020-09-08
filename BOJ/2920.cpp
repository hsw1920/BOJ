#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> N[i];
	}
	if (N[0] == 1) {
		for (int i = 0; i < 7; i++) {
			if (N[i] + 1 != N[i + 1]) {
				printf("mixed");
				return 0;
			}
		}
		printf("ascending");
	}
	else if (N[0] == 8) {
		for (int i = 0; i < 7; i++) {
			if (N[i] - 1 != N[i + 1]) {
				printf("mixed");
				return 0;
			}
		}
		printf("descending");
	}
	else
	{
		printf("mixed");
	}
	return 0;
}