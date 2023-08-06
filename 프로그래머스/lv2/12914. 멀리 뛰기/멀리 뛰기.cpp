#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	long long answer = 0;
	
	vector<long long> vec(n,0);
	vec[0] = 1;
	vec[1] = 2;
	for (int i = 2; i < n; i++)
	{
		vec[i] = (vec[i - 2] + vec[i - 1]) % 1234567;
	}

	return vec[n-1];
}