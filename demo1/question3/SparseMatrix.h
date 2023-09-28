#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <iostream>
#include <cmath>        // 提供sqrt()函数
#include <ctime>        // 提供time()函数
#include <cstdlib>      // 提供rand()和srand()函数
#include <set>          // 提供set类
#include "MatrixTerm.h" // 提供MatrixTerm类
using namespace std;

// 稀疏矩阵类声明
class SparseMatrix
{
// 重载输出符号
friend ostream& operator<<(std::ostream& os, const SparseMatrix& matrix);

// 用0-9随机数初始化数组
friend SparseMatrix initMatrix(int r, int c);

public:
	// 最基本构造函数
	SparseMatrix(int r = 0, int c = 0, int t = 0);//r行、c列，容纳t个非零项

    // 拷贝构造函数
    SparseMatrix(const SparseMatrix &x); // r行、c列，容纳t个非零项

    // 析构函数
	~SparseMatrix();

    // 愚蠢的冒泡排序，初始化用。
    void sort();

    //返回*this中所有行列均被交换的SparseMatrix（转置操作）
    SparseMatrix Transpose();

    //消耗更多存储空间，但大幅减少运算时间
	SparseMatrix FastTranspose();
private:
    //分别为行数，列数，非零项的数量
	int rows, cols, terms;

    //三元组内按行排列，同一行内按列排列
	MatrixTerm* smArray;
};

// 基本构造函数
SparseMatrix::SparseMatrix(int r, int c, int t):rows(r),cols(c),terms(t)
{
    smArray = new MatrixTerm[t];
}

// 冒泡排序，初始化用。
void SparseMatrix::sort()
{
    int n = terms;

    // 使用冒泡排序进行稳定排序(最复杂的数据结构往往采用最简单的排序方法...)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // 比较两个元素的行号和列号
            if (smArray[j].row > smArray[j + 1].row ||
                (smArray[j].row == smArray[j + 1].row && smArray[j].col > smArray[j + 1].col))
            {
                // 交换两个元素
                MatrixTerm temp = smArray[j];
                smArray[j] = smArray[j + 1];
                smArray[j + 1] = temp;
            }
        }
    }
}

// 重载输出运算符
ostream& operator<<(std::ostream& os, const SparseMatrix& matrix)
{
    // 遍历稀疏矩阵的所有元素
    int currentIndex = 0;
    for (int i = 0; i < matrix.rows; ++i)
    {
        for (int j = 0; j < matrix.cols; ++j)
        {
            if (currentIndex < matrix.terms && matrix.smArray[currentIndex].getRow() == i && matrix.smArray[currentIndex].getCol() == j)
            {
                // 当前位置有非零元素
                os << matrix.smArray[currentIndex].getValue();
                currentIndex++;
            }
            else
            {
                // 当前位置无非零元素，用0占位
                os << "-";
            }

            if (j < matrix.cols - 1)
            {
                os << " "; // 添加空格分隔列
            }
        }

        os << endl; // 换行到下一行
    }

    return os;
}

// 析构函数，释放动态数组smArray
SparseMatrix::~SparseMatrix()
{
    delete[] smArray;
}

// 初始化稀疏矩阵，提供测试数据
SparseMatrix initMatrix(int r, int c){
	// 非零元素个数
	int numValues = sqrt(r * c);
	// 创建一个空的稀疏矩阵
    SparseMatrix randomMatrix(r, c, numValues);

    // 初始化随机种子
    srand(static_cast<unsigned int>(time(0)));

    // 跟踪已生成的位置
    set<pair<int, int>> generatedPositions;

    // 随机生成1到9之间的整数，并放入(不重复)随机位置
    for (int i = 0; i < numValues; i++){
        // 存放随机位置
        int randomRow, randomCol;

        // 循环直到生成新的位置
        do
        {
            randomRow = rand() % r;
            randomCol = rand() % c;
        } while (generatedPositions.count(make_pair(randomRow, randomCol)) > 0);

        // 生成1到9之间的随机数
        int randomValue = rand() % 9 + 1;

        // 放置随机数
        randomMatrix.smArray[i].setRow(randomRow);
        randomMatrix.smArray[i].setCol(randomCol);
        randomMatrix.smArray[i].setValue(randomValue);

        // 记录已生成的位置
        generatedPositions.insert(make_pair(randomRow, randomCol));
    }
    randomMatrix.sort();
    return randomMatrix;
}

// 拷贝构造函数
SparseMatrix::SparseMatrix(const SparseMatrix &_x) : rows(_x.rows), cols(_x.cols), terms(_x.terms){
    smArray = new MatrixTerm[_x.terms];
    for (int i = 0; i < terms; i++){
        smArray[i] = _x.smArray[i];
    }
}

//返回*this中所有行列均被交换的SparseMatrix（转置操作）
SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix b(cols, rows, terms);//b的smArray容量为terms
	if (terms > 0)
	{
		int currentB = 0;//b中smArray的序号
		for (int c = 0; c < cols; c++)//先按列查找
			for (int i = 0; i < terms; i++)//再逐个查找每一列中的元素，顺序按行顺序排列
				if (smArray[i].col == c)
				{
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = smArray[i].row;
					b.smArray[currentB++].value = smArray[i].value;//x++先返回再+1
				}
	}
	return b;
}//该算法的时间复杂度为O(terms*cols)，而当稀疏矩阵中非零元素接近rows*cols时，时间复杂度为rows*cols^2

// 修改前的快速转置方法
// SparseMatrix SparseMatrix::FastTranspose()
// {
// 	SparseMatrix b(cols, rows, terms);
// 	if (terms > 0)
// 	{
// 		int* rowSize = new int[cols];//储存数组A每一列的大小
// 		int* rowStart = new int[cols];//储存数组B每一行的起始编号（smArray）
// 		fill(rowSize, rowSize + cols, 0);//先将数组rowSize填0
// 		for (int i = 0; i < terms; i++)rowSize[smArray[i].col]++;//对于a中的smArray储存的每一组数据，对应列计数，获取每一列的size
// 		rowStart[0] = 0;
// 		for (int i = 1; i < cols; i++)rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
// 		//复制部分
// 		for (int i = 0; i < terms; i++)
// 		{
// 			int j = rowStart[smArray[i].col];
// 			b.smArray[j].row = smArray[i].col;
// 			b.smArray[j].col = smArray[i].row;
// 			b.smArray[j].value = smArray[i].value;
// 			rowStart[smArray[i].col]++;
// 		}//将每一行中各列放入数组b中各行的起始位置，并将位置后移
// 		delete[]rowSize;
// 		delete[]rowStart;
// 	}
// 	return b;
// }

// 修改后的快速转置方法
SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int* rowStart = new int[cols];//储存数组B每一行的起始编号（smArray）
		fill(rowStart, rowStart + cols, 0);//先将数组rowSize填0
		for (int i = 0; i < terms; i++)rowStart[smArray[i].col]++;//对于a中的smArray储存的每一组数据，对应列计数，获取每一列的size
        // 储存矩阵A上一列的大小，默认为0
        int row = 0;
        for (int i = 1; i < cols; i++){
            int temp = row;
            row = rowStart[i];
            rowStart[i] = rowStart[i - 1] + temp;
        }
        rowStart[0] = 0;
        //复制部分
		for (int i = 0; i < terms; i++)
		{
			int j = rowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}//将每一行中各列放入数组b中各行的起始位置，并将位置后移
		delete[]rowStart;
	}
	return b;
}

#endif // !SPARSEMATRIX_H