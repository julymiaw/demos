#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        unionFind u(26);
        vector<pair<char, char>> n;
        for (auto e : equations)
        {
            if (e[1] == '!')
            {
                n.push_back({e[0], e[3]});
            }
            else
            {
                u.unite(change(e[0]), change(e[3]));
            }
        }
        for (auto l : n)
        {
            if (u.find(change(l.first)) == u.find(change(l.second)))
                return false;
        }
        return true;
    }
    class unionFind
    {
    private:
        std::vector<int> parent;

    public:
        unionFind(int n) : parent(n)
        {
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }
        int find(int x)
        {
            while (x != parent[x])
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void unite(int x, int y)
        {
            parent[find(x)] = find(y);
        }
    };
    int change(char x)
    {
        int r = x - 'a';
        return r;
    }
};

int main()
{
    Solution solution;
    vector<string> equations = {"a==b", "b!=c", "c==a"};
    bool result = solution.equationsPossible(equations);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
