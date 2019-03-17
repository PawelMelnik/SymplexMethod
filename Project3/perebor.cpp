#include "gauss_meth.h"
#include <iostream>
#include <fstream>
#include "DMatrix.h"
using namespace std;

#define EPS 0.01

void SubMatrix();

int main()
{
	SubMatrix();
	return 0;
}

double** ReadMatrix(const char* input)
{
	ifstream in(input);

	int n, m;
	in >> n;
	in >> m;
	double **x;
	x = new double*[n];
	for (int i = 0; i < n; i++) x[i] = new double[m];

	//Считаем матрицу из файла
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			in >> x[i][j];

	//Выведем матрицу
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << x[i][j] << "\t";
		cout << "\n";
	}

	return x;
}

void SubMatrix()
{
	int M = 3, N = 3;
	double** arr = ReadMatrix("input.txt");
	double b[] = { 1, 2, 3, 4, 5 };
	double c[] = {0,0,0,0,0};
	DMatrix<double> A(3, 2, arr);
	DMatrix<double> A1("input.txt");
	/*A.print();
	for(int i = 0; i < M; ++i)
	{
		if (fabs(A[i][i]) < EPS)
			break;
		gauss_step(i, i, A, b, c);
		printf("\n\n");
	}
	A.print();*/
	A.print();
	double** arr1 = ReadMatrix("input1.txt");
	DMatrix<double> B(2, 3, arr1);
	DMatrix<double> C = A * B;
	C.print();
}