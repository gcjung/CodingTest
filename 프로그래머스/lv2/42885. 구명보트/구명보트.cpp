#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());


	int index = 0;
	int kg = 0;
	while (people.size() > index)
	{
		int back = people.back();
		people.pop_back();
		
		if (people[index] + back <= limit)
		{
			answer++;
			index++;
		}
		else
		{
			answer++;
		}
		


	}

	

	return answer;
}