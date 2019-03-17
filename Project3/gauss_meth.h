#pragma once
#include "DMatrix.h"
#define EPS 0.01

template<typename T, typename vec1, typename vec2>
void gauss_step(int i, int j, DMatrix<T> &A, vec1 &b, vec2 &c) {
	b[i+1] *= 1 / A[i][j];
	A.mult_line(i, 1 / A[i][j]);
	for (int k = 0; k < A.get_height(); k++) {
		if (k != i) {
			b[k+1] += b[i+1] * (-A[k][j]);
			A.add_lines(i, k, -A[k][j]);
		}
	}

	double param = c[j];
	for (int k = 0; k < A.get_width(); k++) {
		c[k] -= param * A[i][k];
	}
	b[0] -= b[i+1] * param;
}

template<typename T>
void gaussStep(int i, int j, DMatrix<T> &A, DMatrix<T> &B)
{
	for()
}

template<typename T>
void gauss(int i, int j, DMatrix<T> &A, DMatrix<T> &B)
{
	int max_length = (A.get_height() < A.get_width()) ? A.get_height() : A.get_width();
	int min_row = 0;
	int suit_col = 0;
	for (int i = 0; i < max_length - 1; ++i)
	{
		suit_col = i;
		if (!FindSuitColumn<T>(suit_col, A))
		{
			return -1;
		}
		if (suit_col != i)
		{
			A.swapColumns<T>(i, suit_col);
			B.swapColumns<T>(i, suit_col);
		}
		gaussStep<T>();
	}
}

template <typename T>
int FindSuitColumn(int& sui_col, DMatrix<T> &A)
{
	int row = sui_col;
	for (sui_col; sui_col < A.get_height; ++sui_col)
	{
		if (fabs(A.mat[sui_col][row]) > EPS)
		{
			return 0;
		}
	}
	return -1;
}

