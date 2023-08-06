#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	queue<int> q;
	for (int i = 0; i < progresses.size(); i++)
	{
		int temp = (100 - progresses[i]) / speeds[i];
		int t = (100 - progresses[i]) % speeds[i] == 0 ? temp : temp + 1;
		
		q.push(t);
	}
	
		int front = q.front();
	
	int count = 0;
	while (!q.empty())
	{
		if (front >= q.front())
		{
			cout << "front : " << front << ", qfront : " << q.front() << endl;
			count++;
			
			q.pop();
		}
		else
		{
		
			cout << "count : " << count << endl;
			answer.emplace_back(count);
			front = q.front();
			count = 0;
		}
	}
	answer.emplace_back(count);

	for (auto& i : answer)
	{
		cout << i << endl;
	}
	return answer;
}