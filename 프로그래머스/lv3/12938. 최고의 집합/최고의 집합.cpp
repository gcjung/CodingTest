#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {	
	vector<int> answer;
	
	if (n > s)
	{
		answer.push_back(-1);
		return answer;
	}

	for (int i = 0; i < n; i++)
	{
		answer.push_back(s / n);
	}

	int t = s % n;
	for (int i = t-1; i >= 0; i--)
	{
		answer[n - (i % n)-1]++;
	}

	return answer;
}