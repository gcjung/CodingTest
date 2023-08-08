#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	priority_queue<int> pq;
	queue<pair<int,int>> q;
	for (size_t i = 0; i < priorities.size(); i++)
	{
		pq.push(priorities[i]);
		q.push({ priorities[i], i });
	}

	while (true)
	{
		if (q.front().first == pq.top())
		{
			answer++;
			cout << "q.front : " << q.front().first << ", idx : " << q.front().second << endl;
			if (q.front().second == location)
			{
				cout << "나감" << endl;
				break;
			}
			q.pop();
			pq.pop();
			
		}
		else
		{
			cout << "뒤로보내기 q.front  : " << q.front().first << endl;
			q.emplace(q.front());
			q.pop();
		}

	}
	cout << "answer  : " << answer << endl;
	return answer;
}