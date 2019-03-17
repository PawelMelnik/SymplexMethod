#pragma once
#include "DMatrix.h"
#define EPS 0.001

template<typename T, typename vec1, typename vec2>
void gauss_step(int i, int j, DMatrix<T> &A, vec1 &b, vec2 &c);

template<typename T>
void gaussStep(int i, int j, DMatrix<T> &A, DMatrix<T> &B);

template<typename T>
int gauss(DMatrix<T> &A, DMatrix<T> &B);

template <typename T>
int FindSuitColumn(int& sui_col, DMatrix<T> &A);

#include "gauss_meth.hpp"