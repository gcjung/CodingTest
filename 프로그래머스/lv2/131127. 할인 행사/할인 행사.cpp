#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	unordered_map<string, int> wantMap;
	unordered_map<string, int> discountMap;

	int totalCount = 0;
	for (size_t i = 0; i < want.size(); i++)
	{
		wantMap[want[i]] = number[i];
		totalCount += number[i];
	}

	int idx = 0;
	while (idx <= discount.size() - totalCount)
	{
		for (size_t i = 0; i < totalCount; i++)
		{
			discountMap[discount[i+idx]]++;
		}

		bool isOK = true;
		for (auto i : wantMap)
		{
			if (i.second > discountMap[i.first])
			{
				isOK = false;
				break;
			}
		}
		idx++;
		discountMap.clear();

		if (isOK) answer++;
	}

	return answer;
}