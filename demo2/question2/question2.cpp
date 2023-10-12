#include <iostream>

using namespace std;

void transform(int *x, int size)
{
    int right = size - 1, left = 0;
    while (left < right)
    {
        swap(x[right], x[left]);
        left++;
        right--;
    }
}

int main()
{
    int x[10] = {1, 2, 3, 4, 4, 3, 2, 1, 5, 6};
    cout << "翻转前：" << endl;
    for (int num : x)
    {
        cout << num << ' ';
    }
    cout << endl;
    transform(x, 10);
    cout << "翻转后：" << endl;
    for (int num : x)
    {
        cout << num << ' ';
    }
    cout << endl;

    cout << "按 Enter 键继续" << endl;
    cin.get();
    return 0;
}