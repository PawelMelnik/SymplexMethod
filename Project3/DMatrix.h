#pragma once
#include <vector>
#include <fstream>

template<typename T>
class DMatrix
{
public:
	DMatrix() {};
	DMatrix(int rows, int columns, T** arr);
	DMatrix(const char* fileName);
	DMatrix(const std::vector<T> vec);
	DMatrix(const DMatrix& other) = delete;
	DMatrix(DMatrix&& other);

	int get_width();
	int get_height();

	DMatrix operator+(const DMatrix& other);
	DMatrix operator-(const DMatrix& other);
	DMatrix operator*(const DMatrix& other);
	DMatrix & operator=(const DMatrix& other) = delete;
	DMatrix& operator=(DMatrix&& obj) = delete;
	DMatrix& operator+=(const DMatrix& other) = delete;
	DMatrix& operator-=(const DMatrix& other) = delete;
	DMatrix& operator*=(const DMatrix& other) = delete;
	DMatrix& inverseThis() = delete;
	DMatrix& transposeThis() = delete;

	DMatrix& gauss(const DMatrix& b) = delete; //Ax = b
	DMatrix& gauss(const std::vector<T>& b) = delete; //Ax = b
	DMatrix& generalizedGauss(const DMatrix& B) = delete; //AB = 1 (поясните кто-нить шо это такое вообще??)

	void mult_line(int line, T val);
	void add_lines(int i_from, int i_to, T val = 1);
	void addLinesDivide(int i_from, int i_to, T mult, T div);
	void swapColumns(int i, int j);

	DMatrix inverse() = delete;
	DMatrix transpose() = delete;
	DMatrix subMatrix() = delete; //TO DO: продумать чё эта ваще такое

	DMatrix merge(const DMatrix& other, int side) = delete; //типа A|B, где side -- типа присоединями снизу, сверху, сбоку
	DMatrix& mergeWithMe(const DMatrix& other, int side) = delete;

	std::vector<T>& operator[](int i); //returns i'th row

	unsigned int rank() = delete; //находим ранг матрицы

	T determinant() = delete; //определитель

	bool isSquare() = delete; //квадратная ли матрица

	void Clear() = delete;

	void print();

protected:

private:
	unsigned int _rows, _columns; //размерность матрицы
	std::vector<std::vector<T>> mat; //матрица
};

#include "DMatrix.hpp"