#ifndef MATRIXTERM_H
#define MATRIXTERM_H
#include<iostream>
class SparseMatrix;

class MatrixTerm {
friend class SparseMatrix;
public:
    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }

    int getValue(){
        return value;
    }
    void setRow(int r){
        row = r;
    }
    void setCol(int c){
        col = c;
    }
    void setValue(int v){
        value = v;
    }
private:
    int row, col, value;
};

#endif // !MATRIXTERM_H