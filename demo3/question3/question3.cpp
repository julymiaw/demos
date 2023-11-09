#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    stack<int> s;
    unordered_map<int, int> nextGreater;

    for (int num : nums2)
    {
        while (!s.empty() && num > s.top())
        {
            nextGreater[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    for (int num : nums1)
    {
        if (nextGreater.find(num) != nextGreater.end())
        {
            result.push_back(nextGreater[num]);
        }
        else
        {
            result.push_back(-1);
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {3, 4, 2, 5, 7, 1, 8};
    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;

    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
