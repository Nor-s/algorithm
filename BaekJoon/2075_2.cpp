#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main()
{
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;

			if (i == 0)
			{
				pq.push(-tmp);
			}
			else if (-pq.top() < tmp)
			{
				pq.pop();
				pq.push(-tmp);
			}
		}
	}
	cout << -pq.top();
}