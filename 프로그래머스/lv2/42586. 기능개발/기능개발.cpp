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
	
	int front = 101;
	int count = 0;
	while (!q.empty())
	{
		if (front >= q.front())
		{
			count++;
			front = q.front();
			q.pop();
		}
		else
		{
		
			answer.emplace_back(count);
			front = 101;
			count = 0;
		}
	}
    
	answer.emplace_back(count);
	
	return answer;
}