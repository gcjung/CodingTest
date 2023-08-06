#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int solution(int k, vector<int> tangerine) {

	int answer = 0;
	map<int, int> map;
	
	for (auto& i : tangerine)
	{
		if (map.find(i) != map.end()) 
		{
			map[i]++;
		}
		else 
		{
			map.emplace(i, 1);
		}
	}

	vector<int> vec;
	for (auto& i : map)
		vec.push_back(i.second);

	sort(vec.rbegin(), vec.rend());

	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (sum >= k) break;
		answer++;
		sum += vec[i];
	}

	return answer;
}