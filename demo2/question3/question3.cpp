#include <windows.h>    // 设置终端编码为UTF8
#include "polynomial.h" // 提供多项式基本操作
#include <ctime>        // clock_t类型和clock()方法
#include <cmath>        // pow函数
#include <fstream>      // 文件的打开，关闭和写入
using namespace std;

// 使用迭代法公式1
double Polynomial::F1a(double x)
{
    double y = 0;
    for (int Pos = 0; Pos < terms; Pos++)
        y += coefArray[Pos] * pow(x, terms - Pos - 1);
    return y;
}

// 使用递归法公式1
double Polynomial::F1b(double x, int index)
{
    return index < terms ? coefArray[index] * pow(x, terms - index - 1) + F1b(x, index + 1) : 0;
}

// 使用迭代法公式2
double Polynomial::F2a(double x)
{
    double y = 0;
    for (int Pos = 0; Pos < terms; Pos++)
        y = y * x + coefArray[Pos];
    return y;
}

// 使用递归法公式2
double Polynomial::F2b(double x, int index)
{
    return index < terms ? F2b(x, index + 1) * x + coefArray[terms - index - 1] : 0;
}

// 公式3
double F3(int n, double x)
{
    double y = 1;
    for (int i = 1; i <= n; i++)
    {
        y += pow(x, i) / i;
    }
    return y;
}

// 根据索引值调用对应算法
double algorithms(Polynomial &f, double x, int index)
{
    switch (index)
    {
    case 0:
        return f.F1a(x);
    case 1:
        return f.F1b(x);
    case 2:
        return f.F2a(x);
    case 3:
        return f.F2b(x);
    default:
        cout << "非法索引" << endl;
        return -1;
    }
}

int main()
{
    SetConsoleOutputCP(65001);
    // 第一题
    cout << "取x=1.1,计算f3(x)的值:\n"
         << "n的取值\t";
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n结果\t";
    for (int i = 0; i < 10; i++)
    {
        cout << F3(i, 1.1) << "\t";
    }
    cout << endl;

    // 第二题
    int n = 6;
    Polynomial f(n);
    cout << "已随机生成多项式f:" << f << endl;

    double x = 3.2;
    cout << "使用迭代法公式1:" << f.F1a(x) << endl;
    cout << "使用递归法公式1:" << f.F1b(x) << endl;
    cout << "使用迭代法公式2:" << f.F2a(x) << endl;
    cout << "使用递归法公式2:" << f.F2b(x) << endl;

    // n的取值数组
    int n_values[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100};

    // 一组x的取值
    double x_values[] = {8.27336, 9.60413, 3.79897, 6.29539, 2.91809}; // 你可以添加更多x值

    const char *algorithm_names[] = {"F1a", "F1b", "F2a", "F2b"};

    Polynomial Polynomials[sizeof(n_values) / sizeof(int)];

    for (int j = 0; j < sizeof(n_values) / sizeof(int); j++)
    {
        int n = n_values[j];
        Polynomial f(n); // 创建一个Polynomial对象
        Polynomials[j] = f;
    }

    // 打开一个文件以写入数据
    ofstream outputFile("output.csv");

    // 检查文件是否成功打开
    if (!outputFile.is_open())
    {
        cerr << "无法打开文件" << std::endl;
        return 1;
    }

    // 创建表格的表头
    outputFile << "n\t";
    for (int n : n_values)
    {
        outputFile << n << "\t";
    }
    outputFile << "\n";

    // 遍历四种算法
    for (int i = 0; i < 4; i++)
    {
        outputFile << algorithm_names[i] << "\t";
        // 遍历每一个n值
        for (int j = 0; j < sizeof(n_values) / sizeof(int); j++)
        {
            double total_time = 0.0;
            int num_iterations = 10000000; // 调整迭代次数
            int times = sizeof(x_values) / sizeof(double);
            cout << "正在计算第" << i + 1 << "行, 第" << j + 1 << "列。请耐心等待……" << endl;
            // 遍历选取的每一个x值
            for (int t = 0; t < times; t++)
                // 迭代10^7次
                for (int k = 0; k < num_iterations; k++)
                {
                    clock_t start_time = clock();

                    // 调用当前算法，通过函数接受成员函数指针的方法
                    algorithms(Polynomials[j], x_values[t], i); // 循环使用x_values

                    clock_t end_time = clock();
                    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // 以秒为单位
                    total_time += elapsed_time;
                }
            // 计算对于不同x的平均时间
            double average_time = total_time / times;
            outputFile << average_time << "\t";
        }

        outputFile << "\n";
    }

    // 关闭文件
    outputFile.close();

    cout << "数据已写入文件" << endl;
    return 0;
}
