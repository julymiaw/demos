#include "adjList.h"
#include <random>
#include <queue>

void adjList::topSort()
{
    std::queue<int> q;
    for (int i = 0; i < list.size(); i++)
        if (count[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for (auto v : list[u])
        {
            count[v.first]--;
            if (count[v.first] == 0)
                q.push(v.first);
        }
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    adjList list(n);

    std::random_device rd;                         // 用于获取随机数的种子
    std::mt19937 gen(rd());                        // 使用Mersenne Twister算法生成随机数
    std::uniform_int_distribution<> dis(0, n - 1); // 生成在[0, n-1]范围内的随机数

    for (int i = 1; i < n; i++)
    {
        int j = dis(gen) % i;
        list.addEdge(j, i); // 因为j必然小于i，所以关系对生成的有向图必然是无环的
    }

    list.printGraph(0);

    list.topSort();
}