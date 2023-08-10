#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	unordered_map<string, int> map;
	unordered_map<string, int> checkMap;

	int totalCount = 0;
	for (size_t i = 0; i < want.size(); i++)
	{
		map[want[i]] = number[i];
		totalCount += number[i];
	}

	int idx = 0;
	while (idx <= discount.size() - totalCount)
	{
		for (size_t i = idx; i < totalCount + idx; i++)
		{
			checkMap[discount[i]]++;
		}
        idx++;
		bool isOK = true;
		for (auto i : map)
		{
			if (i.second > checkMap[i.first])
			{
				isOK = false;
				break;
			}
		}
		checkMap.clear();
		if (isOK) answer++;
	}



	return answer;
}