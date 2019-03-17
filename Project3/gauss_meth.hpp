#pragma once
#define EPS 0.001

template<typename T, typename vec1, typename vec2>
void gauss_step(int i, int j, DMatrix<T> &A, vec1 &b, vec2 &c) {
	b[i + 1] *= 1 / A[i][j];
	A.mult_line(i, 1 / A[i][j]);
	for (int k = 0; k < A.get_height(); k++) {
		if (k != i) {
			b[k + 1] += b[i + 1] * (-A[k][j]);
			A.add_lines(i, k, -A[k][j]);
		}
	}

	double param = c[j];
	for (int k = 0; k < A.get_width(); k++) {
		c[k] -= param * A[i][k];
	}
	b[0] -= b[i + 1] * param;
}

template<typename T>
void gaussStep(int i, int j, DMatrix<T> &A, DMatrix<T> &B)
{
	T divider = A[i][j];

	for (int cntrColumn = 0; cntrColumn < i; ++cntrColumn)
	{
		B.addLinesDivide(i, cntrColumn, -A[cntrColumn][j], divider);
		A.addLinesDivide(i, cntrColumn, -A[cntrColumn][j], divider);
		//A.print();
		//B.print();
	}
	for (int cntrColumn = i + 1; cntrColumn < A.get_height(); ++cntrColumn)
	{
		B.addLinesDivide(i, cntrColumn, -A[cntrColumn][j], divider);
		A.addLinesDivide(i, cntrColumn, -A[cntrColumn][j], divider);
		//A.print();
		//B.print();
	}
	for (int cntrRow = 0; cntrRow < A.get_width(); ++cntrRow)
	{
		A[i][cntrRow] /= divider;
	}
	for (int cntrRow = 0; cntrRow < B.get_width(); ++cntrRow)
	{
		B[i][cntrRow] /= divider;
	}
	//A.print();
	//B.print();
}

template<typename T>
int gauss(DMatrix<T> &A, DMatrix<T> &B)
{
	int max_length = (A.get_height() < A.get_width()) ? A.get_height() : A.get_width();
	int min_row = 0;
	int suit_col = 0;
	for (int i = 0; i < max_length; ++i)
	{
		suit_col = i;
		if (FindSuitColumn<T>(suit_col, A))
		{
			return -1;
		}
		if (suit_col != i)
		{
			A.swapColumns(i, suit_col);
			B.swapColumns(i, suit_col);
		}
		gaussStep<T>(i, i, A, B);
		A.print();
		B.print();
	}
}

template <typename T>
int FindSuitColumn(int& sui_col, DMatrix<T> &A)
{
	int row = sui_col;
	for (sui_col; sui_col < A.get_height(); ++sui_col)
	{
		if (fabs(A[sui_col][row]) > EPS)
		{
			return 0;
		}
	}
	return -1;
}

