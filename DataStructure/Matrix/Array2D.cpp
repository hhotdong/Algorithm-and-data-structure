// 홍정모 연구소, <자료구조 압축코스>
#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols)
{
    arrays_ = new float*[num_rows];
    for (int r = 0; r < num_rows; ++r)
        arrays_[r] = new float[num_cols];
    num_rows_ = num_rows;
    num_cols_ = num_cols;

    for (int r = 0; r < num_rows_; ++r)
    {
        float* row = arrays_[r];
        for (int c = 0; c < num_cols_; ++c)
            row[c] = 0.0f;
    }

    for (int r = 0; r < num_rows_; ++r)
        for (int c = 0; c < num_cols_; ++c)
            arrays_[r][c] = 0.0f;

    // 참고: C++ 언어의 정적 2차원 배열(동적할당 아님)
    //int arr[3][2] = {1, 2, 3, 4, 5, 6}; // 2차원 (정적) 배열
    //for(int j = 0; j < 3; j ++)
    //    for(int i = 0; i < 2; i ++)
    //        cout << arr[j][i] << " "; // <- 정적 2차원 배열도 2차원 인덱싱 가능
}

Array2D::Array2D(const Array2D& b)
{
    arrays_ = new float*[b.num_rows_];
    for (int r = 0; r < b.num_rows_; ++r)
        arrays_[r] = new float[b.num_cols_];

    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;

    for (int r = 0; r < num_rows_; ++r)
        memcpy(arrays_[r], b.arrays_[r], sizeof(float) * num_cols_);
}

Array2D::~Array2D()
{
    if (arrays_)
    {
        for (int r = 0; r < num_rows_; ++r)
            delete[] arrays_[r];
        delete[] arrays_;
    }
}

void Array2D::SetValue(int row, int col, float value)
{
    arrays_[row][col] = value;
}

float Array2D::GetValue(int row, int col) const
{
    return arrays_[row][col];
}

Array2D Array2D::Transpose()
{
    Array2D temp(num_cols_, num_rows_);

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Array2D Array2D::Add(const Array2D& b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Array2D temp(num_rows_, num_cols_);

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Array2D::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";

        cout << endl;
    }
}
