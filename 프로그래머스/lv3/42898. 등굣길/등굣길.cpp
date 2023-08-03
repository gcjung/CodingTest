#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int arr[101][101] = { 0, };

	for (int i = 0; i < puddles.size(); i++) 
	{ 
		arr[puddles[i][1]][puddles[i][0]] = -1;
	}

	arr[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] != -1 && (i > 1 || j > 1))
			{
				if (arr[i - 1][j] == -1)
					arr[i][j] = arr[i][j - 1] % 1000000007;
				else if (arr[i][j - 1] == -1)
					arr[i][j] = arr[i - 1][j] % 1000000007;
				else
					arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
			}

		}
	}

	answer = arr[n][m];


	return answer;
}