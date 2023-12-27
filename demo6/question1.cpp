#include "adjList.h"
#include <iostream>
#include <random>
#include <queue>

int adjList::shortestPath(int x, int y)
{
    std::vector<int> dist(list.size(), INT_MAX);                                                                      // 初始化所有结点的距离为无穷大
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // 优先队列，保存结点和到达该结点的距离，其中pair的第一位是距离，第二位是结点序号

    dist[x] = 0;
    pq.push({0, x}); // 到结点0距离为0的点是结点0

    while (!pq.empty())
    {
        int u = pq.top().second; // 取出当前优先队列中到起点距离最近的结点
        pq.pop();

        for (auto v : list[u]) // 对于邻接表中以结点为起点的每一条边
        {
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    return (dist[y] == INT_MAX) ? -1 : dist[y];
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    adjList list(n);

    std::random_device rd;                         // 用于获取随机数的种子
    std::mt19937 gen(rd());                        // 使用Mersenne Twister算法生成随机数
    std::uniform_int_distribution<> dis(0, n - 1); // 生成在[0, n-1]范围内的随机数

    for (int i = 0; i < m; i++)
    {
        int x = dis(gen);
        int y = dis(gen);
        if (list.edgeExists(x, y))
            i--;
        else
            list.addEdge(x, y);
    }

    list.printGraph();

    std::cout << "结点1到n的最短距离是" << list.shortestPath(0, n - 1) << std::endl;

    return 0;
}