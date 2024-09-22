// 홍정모 연구소, <자료구조 압축코스>
#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
    terms_ = new MatrixTerm[capacity];
    capacity_ = capacity;
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    num_terms_ = 0;
}

SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
    if (b.capacity_ > 0)
    {
        terms_ = new MatrixTerm[b.capacity_];
        capacity_ = b.capacity_;
        num_rows_ = b.num_rows_;
        num_cols_ = b.num_cols_;
        num_terms_ = b.num_terms_;
        memcpy(terms_, b.terms_, sizeof(MatrixTerm) * num_terms_);
    }
}

SparseMatrix::~SparseMatrix()
{
    if (terms_) delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
    if (value == 0.0f) return;

    int key = col + num_cols_ * row;
    int i = 0;
    for (; i < num_terms_; ++i)
    {
        int key_i = terms_[i].col + num_cols_ * terms_[i].row;
        if (key_i == key)
        {
            terms_[i].row = row;
            terms_[i].col = col;
            terms_[i].value = value;
            return;
        }
        else if (key_i > key)
            break;
    }

    assert(capacity_ > num_terms_);
    num_terms_++;
    for (int j = num_terms_ - 1; j > i; --j)
        terms_[j] = terms_[j - 1];
    terms_[i].row = row;
    terms_[i].col = col;
    terms_[i].value = value;
}

float SparseMatrix::GetValue(int row, int col) const
{
    //for (int i = 0; i < num_terms_; ++i)
    //    if (terms_[i].row == row && terms_[i].col == col)
    //        return terms_[i].value;
    //return 0.0f;

    // terms가 row, col에 대해 정렬되어 있는 경우 검색을 더 빠르게 할 수 있음.
    int key = col + num_cols_ * row;
    for (int i = 0; i < num_terms_; ++i)
    {
        int key_i = terms_[i].col + terms_[i].row * num_cols_;
        if (key_i == key)
            return terms_[i].value;
        else if (key_i > key)
            return 0.0f;
    }
    return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix temp(num_cols_, num_rows_, capacity_);

    // 정렬이 안된 상태
    // O(num_rows_ * num_cols_ * num_terms_)
    //for (int r = 0; r < num_rows_; ++r)
    //    for (int c = 0; c < num_cols_; ++c)
    //        temp.SetValue(c, r, GetValue(r, c));  

    // temp 정렬 유지
    // O(num_rows_ * num_cols_ * num_terms_)
    //for (int r = 0; r < temp.num_rows_; ++r)
    //    for (int c = 0; c < temp.num_cols_; ++c)
    //        temp.SetValue(r, c, GetValue(c, r));

    // O(num_cols * num_terms_)
    for (int r = 0; r < temp.num_rows_; ++r)
        for (int i = 0; i < num_terms_; ++i)
        {
            if (terms_[i].col == r)
            {
                temp.terms_[temp.num_terms_].value = terms_[i].value;
                temp.terms_[temp.num_terms_].col = terms_[i].row;
                temp.terms_[temp.num_terms_].row = terms_[i].col;
                temp.num_terms_++;
            }
        }
    return temp;
}

void SparseMatrix::PrintTerms()
{
    for (int i = 0; i < num_terms_; i++)
        cout << "(" << terms_[i].row
        << ", " << terms_[i].col
        << ", " << terms_[i].value
        << ")" << endl;
}

void SparseMatrix::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}
