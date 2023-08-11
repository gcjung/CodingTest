using System;
using System.Collections.Generic;


class Solution {
     int[] dx = { -1, 1, 0, 0 };
    int[] dy = { 0, 0, -1, 1 };
    Queue<(int, int)> queue = new Queue<(int, int)>();

    public void bfs(int i, int j, int[,] maps)
    {
        queue.Enqueue((i, j));

        while (queue.Count != 0)
        {
            (int a, int b) = queue.Dequeue();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if ((0 <= x && x < maps.GetLength(0)) && (0 <= y && y < maps.GetLength(1)) && (maps[x, y] == 1))
                {
                    queue.Enqueue((x, y));
                    maps[x, y] = maps[a, b] + 1;
                }
            }
        }
    }
    public int solution(int[,] maps)
    {
        bfs(0, 0, maps);

        int n = maps.GetLength(0);
        int m = maps.GetLength(1);
        if (maps[n - 1, m - 1] == 1)
            return -1;
        else
            return (maps[n - 1, m - 1]);
    }

}
