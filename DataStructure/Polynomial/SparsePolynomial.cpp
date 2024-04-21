// 홍정모 연구소, <자료구조 압축코스>
#include "SparsePolynomial.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f) return;

	if (num_terms_ >= capacity_)
	{
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1;
		Term* new_term = new Term[capacity_];

		memcpy(new_term, terms_, sizeof(Term) * num_terms_);

		if (terms_) delete[] terms_;
		terms_ = new_term;
	}
	terms_[num_terms_].coef = coef;
	terms_[num_terms_].exp = exp;
	num_terms_++;
}

float SparsePolynomial::Eval(float x)
{
	float temp = 0.0f;
    for (int i = 0; i < num_terms_; ++i)
        temp += terms_[i].coef * std::powf(x, float(terms_[i].exp));
	return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	// this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
	// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)
	SparsePolynomial temp;
    
    int i = 0, j = 0;

    while ((i < this->num_terms_) && (j < poly.num_terms_))
    {
        if (terms_[i].exp == poly.terms_[j].exp)
        {
            float sum = terms_[i].coef + poly.terms_[j].coef;
            if (sum != 0.0f)
                temp.NewTerm(sum, terms_[i].exp);
            i++;
            j++;
        }
        else if ((terms_[i].exp > poly.terms_[j].exp))
        {
            temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
            j++;
        }
        else
        {
            temp.NewTerm(terms_[i].coef, terms_[i].exp);
            i++;
        }
    }

    for (; i < num_terms_; ++i)
        temp.NewTerm(terms_[i].coef, terms_[i].exp);

    for (; j < poly.num_terms_; ++j)
        temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);

	return temp;
}

void SparsePolynomial::Print()
{
	bool is_first = true; // 더하기 출력시 확인용

	for (int i = 0; i < num_terms_; i++)
	{
		// 0이 아닌 항들만 골라서 출력할 필요가 없음

		if (!is_first)
			cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

		cout << terms_[i].coef;

		if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

		is_first = false;
	}

	cout << endl;
}
