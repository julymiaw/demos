#include<iostream>
#include <windows.h>
using namespace std;

// 打印分界线
void printSeparator(char separator, int length) {
    string line(length, separator);
    cout << line << endl;
}

// 自定义数组类
class nums {
private:
    int* arr; // 数组指针
    int size; // 数组大小

public:
    // 构造函数，初始化数组大小并分配内存
    nums(int n) : size(n) {
        arr = new int[size];
    }

    // 拷贝构造函数，用于初始化一个 nums 对象
    nums(const nums& other) : size(other.size) {
        arr = new int[size];
        copy(other.arr, other.arr + size, arr);
    }

    // 初始化列表的构造函数
    nums(initializer_list<int> list) : size(list.size()) {
        arr = new int[size];
        int i = 0;
        for (int val : list) {
            arr[i++] = val;
        }
    }

    // 析构函数，释放内存
    ~nums() {
        delete[] arr;
    }

    // 获取数组长度(常量成员函数)
    int getSize() const {
        return size;
    }

    // 重载下标访问运算符
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            // 抛出自定义错误
            cerr << "Index out of bounds!" << endl;
            exit(1);
        }
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const nums& n) {
        os << "[";
        for (int i = 0; i < n.size; ++i) {
            os << n.arr[i];
            if (i < n.size - 1) {
                os << ",";
            }
        }
        os << "]";
        return os;
    }

    // 重载赋值运算符
    nums& operator=(initializer_list<int> list) {
        if (size != list.size()) {
            delete[] arr;
            size = list.size();
            arr = new int[size];
        }
        int i = 0;
        for (int val : list) {
            arr[i++] = val;
        }
        return *this;
    }

    // 重载小于运算符，用于比较两个 nums 对象的大小
    bool operator<(nums& other) const {
        int n = size;
        int m = other.getSize();
        cout << "正在比较:";
        for (int j = 0; j < n && j < m; j++){
            cout << "(" << arr[j] << "," << other[j] << ")";
            if(arr[j] > other[j]){
                cout << "status0:";
                return false;
            }
            if(arr[j] < other[j]){
                bool flag = true;
                for (int i = 0; i < j; i++)
                {
                    flag = flag && (arr[i] == other[i]);
                    if(!flag){
                        cout << "status3:";
                        return flag;
                    }
                }
                cout << "status1:";
                return flag;
            }
        }
        if (n < m){
            cout << "status2:";
            return true;
        }
        cout << "status4:";
        return false;
    }

    // 重载大于运算符，用于比较两个 nums 对象的大小
    bool operator>(nums& other) const {
        nums x = *this;
        if (other < x){
            return true;
        }
        return false;
    }

    // 重载==运算符，用于比较两个 nums 对象的大小
    bool operator==(nums& other) const {
        int n = size;
        int m = other.getSize();
        if(n==m){
            bool flag = true;
            cout << "正在比较:";
            for (int i = 0; i < n && i < m; i++){
                cout << "(" << arr[i] << "," << other[i] << ")";
                flag = flag && (arr[i] == other[i]);
                if (!flag){
                    cout << "status2:";
                    return flag;
                }
            }
            cout << "status0:";
            return flag;
        }
        cout << "status1:";
        return false;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    cout << "展示小于的两种情况:" << endl;
    printSeparator('-', 20);
    cout << "第一种情况:" << endl;
    nums x = {1, 2, 3, 4, 4, 7 ,9};
    nums y = {1, 2, 3, 4, 5};
    cout << x << endl;
    cout << y << endl;
    cout << (x < y) << endl;
    printSeparator('-', 20);
    cout << "第二种情况:" << endl;
    x = {1, 2, 3, 4, 5};
    y = {1, 2, 3, 4, 5, 2};
    cout << x << endl;
    cout << y << endl;
    cout << (x < y) << endl;
    printSeparator('-', 20);
    cout << "展示等于的情况:" << endl;
    x = {1, 2, 3, 4, 5};
    y = {1, 2, 3, 4, 5};
    cout << x << endl;
    cout << y << endl;
    cout << (x == y) << endl;
    printSeparator('-', 20);
    cout << "展示不等于的情况1:" << endl;
    x = {1, 2, 3, 4, 5};
    y = {1, 2, 3, 4, 5, 2};
    cout << x << endl;
    cout << y << endl;
    cout << (x == y) << endl;
    printSeparator('-', 20);
    cout << "展示不等于的情况2:" << endl;
    x = {1, 2, 3, 4, 5};
    y = {1, 2, 3, 4, 6};
    cout << x << endl;
    cout << y << endl;
    cout << (x == y) << endl;
    cout << "Press Enter to continue...";
    cin.get(); // Wait for Enter key
    return 0;
}