#include <iostream>
#include <unordered_map>

using namespace std;

// 利用哈希表统计字符出现次数
void count(const char *text)
{
    unordered_map<char, int> charCount;
    // 遍历字符串并统计每个字符的出现次数
    for (int i = 0; text[i] != '\0'; i++)
    {
        char currentChar = text[i];
        if (charCount.find(currentChar) == charCount.end())
        {
            charCount[currentChar] = 1;
        }
        else
        {
            charCount[currentChar]++;
        }
    }
    // 输出字符及其出现次数
    for (const auto &pair : charCount)
    {
        cout << "Character '" << pair.first << "' appears " << pair.second << " times." << endl;
    }
}

// 利用简单遍历获取指定字符出现次数
int count(const char *text, char x)
{
    int count = 0;
    // 遍历字符串并统计每个字符的出现次数
    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] == x ? count++ : count = count;
    }
    // 输出字符及其出现次数
    cout << "Character '" << x << "' appears " << count << " times." << endl;
    return count;
}

int main()
{
    const char *x = "Hello,world!";
    count(x);
    count(x, 'l');

    cout << "按 Enter 键继续" << endl;
    cin.get();
    return 0;
}