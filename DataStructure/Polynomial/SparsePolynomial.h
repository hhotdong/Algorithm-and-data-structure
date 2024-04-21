// 홍정모 연구소, <자료구조 압축코스>
#pragma once

struct Term
{
	float coef;
	int exp;
};

class SparsePolynomial
{
public:
	SparsePolynomial() { }

	~SparsePolynomial()
	{
		if (terms_) delete[] terms_;
	}

	void NewTerm(float coef, int exp);

	float Eval(float x);

	SparsePolynomial Add(const SparsePolynomial& poly);

	void Print();
private:
	Term* terms_ = nullptr;
	int capacity_ = 0;
	int num_terms_ = 0;
};
