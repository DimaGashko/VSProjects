#include "SparseMatrix.hpp"



SparseMatrix::SparseMatrix(int m, int n) :
	_m(m), _n(n)
{

}

int SparseMatrix::get(int i, int j) {
	return 0;
}

void SparseMatrix::set(int i, int j, int val) {

}

int SparseMatrix::getM() {
	return _m;
}

int SparseMatrix::getN() {
	return _n;
}

SparseMatrix::~SparseMatrix() {

}
