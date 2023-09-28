#include<iostream>
#include <windows.h>
#include "SparseMatrix.h"
#include <unistd.h>
using namespace std;

// 打印分界线
void printSeparator(char separator, int length) {
    string line(length, separator);
    cout << line << endl;
}

void test(){
    SparseMatrix x = initMatrix(9, 9);
    cout << x << endl;
    printSeparator('-', 20);
    cout << "使用原转置方法:" << endl;
    SparseMatrix y = x.Transpose();
    cout << y << endl;
    cout << "使用修改后的快速转置方法:" << endl;
    SparseMatrix z = x.FastTranspose();
    cout << z << endl;
    printSeparator('-', 20);
}

int main() {
    SetConsoleOutputCP(65001);
    do
    {
        test();
        cout << "Press Enter to continue...";
        cin.get(); // Wait for Enter key
    } while (true);

    return 0;
}