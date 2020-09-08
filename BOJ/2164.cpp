#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	for (int i = 1; i < n; i++)
	{
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	printf("%d", q.front());
	
	return 0;
}