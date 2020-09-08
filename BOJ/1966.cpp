#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		priority_queue<int, vector<int>, less<int>>pq;
		queue<pair<int, int>>q;
		int N, M;
		int importance;
		int cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> importance;
			pq.push(importance);
			q.push(make_pair(i, importance));
		}

		while (1)
		{
			if (q.front().first == M && pq.top() == q.front().second)
			{
				cout << cnt + 1 << endl;
				break;
			}
			if (q.front().second != pq.top())
			{
				int tmp_x = q.front().first;
				int tmp_y = q.front().second;
				q.pop();
				q.push(make_pair(tmp_x, tmp_y));
			}
			else if (q.front().second == pq.top()) {
				q.pop();
				pq.pop();
				cnt++;
			}
		}

	}
	
	return 0;
}