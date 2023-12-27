#include "adjList.h"
#include <random>
#include <algorithm>

// 定义边
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
};

// 定义并查集
class UnionFind
{
private:
    std::vector<int> parent;

public:
    UnionFind(int n) : parent(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};

int adjList::kruskal()
{
    std::vector<Edge> edges;
    for (int i = 0; i < list.size(); i++)
        for (int j = 0; j < list[i].size(); j++)
            edges.push_back({i, list[i][j].first, list[i][j].second});
    std::sort(edges.begin(), edges.end());
    UnionFind uf(list.size());
    int weightSum = 0;
    for (auto e : edges)
    {
        if (uf.find(e.u) != uf.find(e.v))
        {
            weightSum += e.w;
            uf.unite(e.u, e.v);
        }
    }
    for (int i = 1; i < list.size(); i++)
    {
        if (uf.find(i) != uf.find(0))
        {
            throw "impossible";
        }
    }
    return weightSum;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    adjList list(n);

    std::random_device rd;                               // 用于获取随机数的种子
    std::mt19937 gen(rd());                              // 使用Mersenne Twister算法生成随机数
    std::uniform_int_distribution<> dis(0, n - 1);       // 生成在[0, n-1]范围内的随机数
    std::uniform_int_distribution<> dis_weight(-10, 10); // 生成在[-10, 10]范围内的随机数作为权值

    for (int i = 0; i < m; i++)
    {
        int x = dis(gen);
        int y = dis(gen);
        int w = dis_weight(gen);
        list.addEdge(x, y, w);
        list.addEdge(y, x, w);
    }

    list.printGraph();
    try
    {
        int r = list.kruskal();
        std::cout << "最小生成树的总路径长度为" << r << std::endl;
    }
    catch (char const *s)
    {
        std::cout << "抛出异常：" << s << std::endl;
    }
    return 0;
}