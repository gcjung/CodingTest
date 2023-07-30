#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {

    vector<int> answer(2);

	priority_queue<int, vector<int>, less<int>> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;

	int cnt = 0;
	for (string str : operations)
	{
		if (!cnt) {
			while (!maxQ.empty()) maxQ.pop();
			while (!minQ.empty()) minQ.pop();
		}
        
		if (str.substr(0, 1) == "I")
		{
			maxQ.push(stoi(str.substr(2)));
			minQ.push(stoi(str.substr(2)));
			cnt++;
		}
		else
		{
			if (cnt == 0) continue;
			if (str.substr(2) == "1")
			{
				//cout << "max value : " << maxQ.top() << "\n";
				maxQ.pop();
				
			}
			else
			{
				//cout << "min value : " << minQ.top() << "\n";
				minQ.pop();
				
			}
			cnt--;
		}
	}
	//cout << maxQ.top() << ", " << minQ.top() << endl;


	if (cnt)
	{
		answer[0] = maxQ.top();
		answer[1] = minQ.top();
	}


	return answer;
}
