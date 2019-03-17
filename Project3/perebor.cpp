#include "gauss_meth.h"
#include <iostream>
#include <fstream>
#include "DMatrix.h"
using namespace std;


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
	const char* left_matrix_file = "left_matrix.txt";
	const char* right_matrix_file = "right_matrix.txt";
	DMatrix<double> A1(left_matrix_file);
	DMatrix<double> A2(left_matrix_file);
	DMatrix<double> B1(right_matrix_file);
	A1.print();
	B1.print();
	double b[] = {0, 1, 2, 3};
	double c[] = {0, 0, 0, 0};

	// Ioann method
	for(int i = 0; i < A1.get_height(); ++i)
	{
		if (fabs(A1[i][i]) < EPS)
			break;
		gauss_step(i, i, A1, b, c);
		A1.print();
		cout << b[1] << endl << b[2] << endl << b[3] << endl;
		printf("\n\n");
	}
	A1.print();

	//Pahan method
	cout << "---------------Pahan-----------";
	gauss(A2, B1);
	A2.print();
	//B1.print();

}