#include <vector>
#include <iostream>

class adjList
{
private:
    std::vector<std::vector<std::pair<int, int>>> list; // 储存邻接表
    std::vector<int> count;                             // 储存结点的入度

public:
    adjList(int size)
    {
        list = std::vector<std::vector<std::pair<int, int>>>(size);
        count = std::vector<int>(size);
    }

    // 添加从x到y的有向边
    void addEdge(int x, int y, int length = 1)
    {
        if (x >= count.size() || y >= count.size())
            throw "边的端点必须在图的范围内";
        list[x].push_back({y, length});
        count[y]++;
    }

    // 检查从x到y的边是否存在
    bool edgeExists(int x, int y)
    {
        if (x >= count.size() || y >= count.size())
            throw "边的端点必须在图的范围内";
        if (x == y)
            return true;
        for (int i = 0; i < list[x].size(); i++)
        {
            if (list[x][i].first == y)
                return true;
        }
        return false;
    }

    // 输出图的信息
    void printGraph(int x = 1)
    {
        for (int i = 0; i < list.size(); i++)
        {
            std::cout << "结点 " << i + x << " 的邻居: ";
            for (int j = 0; j < list[i].size(); j++)
            {
                std::cout << list[i][j].first + x << "[" << list[i][j].second << "] ";
            }
            std::cout << std::endl;
        }
    }

    int shortestPath(int, int);
    int kruskal();
    void topSort();
};
