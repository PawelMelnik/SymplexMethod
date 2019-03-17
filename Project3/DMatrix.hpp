#pragma once
#include <vector>
#include <fstream>


template<typename T>
DMatrix<T>::DMatrix(int rows, int columns, T** arr) :_rows(rows), _columns(columns) {
	for (int i = 0; i < rows; i++)
	{
		mat.push_back(std::vector<T>());
		for (int j = 0; j < columns; j++)
			mat[i].push_back(arr[i][j]);
	}
};

template<typename T>
DMatrix<T>::DMatrix(const char* fileName) 
{
	std::ifstream in(fileName);
	in >> _rows;
	in >> _columns;

	T var;
	for (int i = 0; i < _rows; i++)
	{
		mat.push_back(std::vector<T>());
		for (int j = 0; j < _columns; j++)
		{
			in >> var;
			mat[i].push_back(var);
		}	
	}
};

	
template<typename T>
DMatrix<T>::DMatrix(const std::vector<T> vec) : _rows(vec.size()), _columns(1) {
	mat.push_back(vec);
};
	
template<typename T>
DMatrix<T>::DMatrix(DMatrix&& other) {};

template<typename T>
int 
	DMatrix<T>::get_width() {
	return _columns;
}
template<typename T>
int
	DMatrix<T>::get_height() {
	return _rows;
}

template<typename T>
DMatrix<T> DMatrix<T>::operator*(const DMatrix& other)
{
	int i = 0, j = 0;
	int rows = _rows, columns = other._columns;
	T ** x = new T*[rows];
	for (int i = 0; i < rows; i++) x[i] = new T[columns];

	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			//x[i][j] = LineOnBold(this, other, i, j);
			int a = 0;
			T b = 0;
			while (a < _columns)
			{
				b += mat[i][a] * other.mat[a][j];
				a++;
			}
			x[i][j] = b;
			j++;
		}
		i++;

	}
	return DMatrix(rows, columns, x);
}

template<typename T>
void DMatrix<T>::mult_line(int line, T val) {
	for (int i = 0; i < _columns; i++)
		mat[line][i] *= val;
}

template<typename T>
void DMatrix<T>::add_lines(int i_from, int i_to, T val) {
	for (int i = 0; i < _columns; i++) {
		mat[i_to][i] += val * mat[i_from][i];
	}
}

template<typename T>
void DMatrix<T>::addLinesDivide(int i_from, int i_to, T mult, T div) {
	for (int i = 0; i < _columns; i++) {
		mat[i_to][i] += mat[i_from][i] * mult / div;
	}
}

template<typename T>
void  DMatrix<T>::swapColumns(int i, int j)
{
	mat[i].swap(mat[j]);
}

template<typename T>
DMatrix<T> DMatrix<T>::operator+(const DMatrix& other) {
	T ** x = new T*[_rows];
	for (int i = 0; i < _rows; i++) x[i] = new T[_columns];

	for (size_t i = 0; i < _rows; ++i)
		for (size_t j = 0; j < _columns; j++)
		{
			x[i][j] = mat[i][j] + other.mat[i][j];
		}
	return DMatrix(_rows, _columns, x);
}

template<typename T>
DMatrix<T> DMatrix<T>::operator-(const DMatrix& other) {
	T ** x = new T*[_rows];
	for (int i = 0; i < _rows; i++) x[i] = new T[_columns];

	for (size_t i = 0; i < _rows; ++i)
		for (size_t j = 0; j < _columns; j++)
		{
			x[i][j] = mat[i][j] - other.mat[i][j];
		}
	return DMatrix<T>(_rows, _columns, x);
}

template<typename T>
std::vector<T>& DMatrix<T>::operator[](int i) {
	return mat[i];
}; //returns i'th row

template<typename T>
void DMatrix<T>::print() {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++)
			printf("%lf ", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
