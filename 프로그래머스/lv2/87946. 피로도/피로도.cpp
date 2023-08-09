#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool isVisited[8] = { false, };
void dfs(int k, vector<vector<int>>& dungeons, int cnt)
{
	if (cnt > answer) answer = cnt;

	for (size_t i = 0; i < dungeons.size(); i++)
	{
		if (!isVisited[i] && k >= dungeons[i][0])
		{
			isVisited[i] = true;
			dfs(k - dungeons[i][1], dungeons, cnt + 1);
			isVisited[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	
	dfs(k, dungeons, 0);
	
	return answer;
}