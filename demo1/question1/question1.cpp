#include <windows.h>
#include <iostream>
#include <cstdlib>      // 提供rand和srand函数
#include <ctime>        // 提供time函数
#include <algorithm>    // 提供sort函数
#include <cmath>        // 提供log10函数

using namespace std;

// 取数组长度为10
const int array_size = 10;
// 内容范围到20
const int range = 20;

// 用1到range的不重复随机数初始化数组
void initNums(int nums[]){
    // 初始化随机种子
    srand(static_cast<unsigned int>(time(0)));

    // 创建一个存储1-20的所有可能数字的数组
    int possibleNumbers[range];
    for (int i = 1; i <= range; ++i) {
        possibleNumbers[i - 1] = i;
    }

    // 随机选择不重复的数字并存入数组
    for (int i = 0; i < array_size; ++i) {
        // 与下一段的替换代码结合，保证生成的随机数组无重复数字
        int randomIndex = rand() % (range - i);
        // 存储随机选择的数字
        nums[i] = possibleNumbers[randomIndex];
        // 将已选择的位置替换为最后一个数字，以确保不重复
        possibleNumbers[randomIndex] = possibleNumbers[range - i - 1];
    }

    // 对结果数组进行排序
    sort(nums, nums + array_size);
}

// 为直观显示查找结果，在数组指定位置下方打印上箭头
void printArrayWithArrow(int num[], int targetIndex, bool status) {
    // 打印数组
    for (int i = 0; i < array_size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    // 打印箭头
    for (int i = 0; i < targetIndex; i++) {
        // 通过计算位数判断空格
        int padding = (num[i] == 0) ? 1 : static_cast<int>(log10(num[i])) + 1;
        for (int j = 0; j < padding; j++){
            cout << ' ';
        }
        cout << ' ';
    }
    if(status)
        cout << "^" << endl;
    else{
        int padding = (num[targetIndex] == 0) ? 1 : static_cast<int>(log10(num[targetIndex])) + 1;
        for (int j = 0; j < padding; j++){
            cout << ' ';
        }
        cout << "^" << endl;
    }
}

// 打印分界线
void printSeparator(char separator, int length) {
    string line(length, separator);
    cout << line << endl;
}

// 折半查找添加位置
int binarySearch(int nums[],int t){
    // 初始化左端点和右端点
    int left = 0;
    int right = array_size - 1;
    int mid = -1;

    while (left < right) {
        // 初始化折半查找位置
        mid = left + (right - left) / 2;

        if(nums[mid] == t){
            cout << "找到目标值，返回索引" << endl;
            printArrayWithArrow(nums, mid, true);
            return mid;
        } else if (nums[mid] < t && nums[mid+1] > t) {
            cout << "未找到目标值，返回插入位置" << endl;
            printArrayWithArrow(nums, mid, false);
            return (mid + 1);
        }
        else if (nums[mid + 1] == t){
            cout << "找到目标值，返回索引" << endl;
            printArrayWithArrow(nums, mid + 1, true);
            return mid + 1;
        }
        else if (nums[mid + 1] < t)
        {
            left = mid + 1;
            mid = array_size;
        }
        else
        {
            right = mid;
            mid = -1;
        }
    }
    cout << "未找到目标值，返回插入位置" << endl;
    printArrayWithArrow(nums, mid, true);
    return mid;
}

// 循环测试功能
void test(){
    int nums[array_size];
    initNums(nums);
    
    cout << "初始化结果:" << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int t;
    cout << "请输入查找目标:";
    cin >> t;

    // 进行折半查找
    int index = binarySearch(nums, t);
    cout << "查找结果为" << index << endl;

    printSeparator('-', 20);
}

int main(){
    SetConsoleOutputCP(65001);
    do{
        test();
    } while (true);
    return 0;
}