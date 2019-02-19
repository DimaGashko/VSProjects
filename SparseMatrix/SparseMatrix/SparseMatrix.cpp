#include "SparseMatrix.hpp"



SparseMatrix::SparseMatrix(int m, int n) :
	m_m(m), m_n(n),
	m_compressedMatrix((m / 2) * n)
{

}

int SparseMatrix::get(int i, int j) {
	if (_isZiroItem(i, j)) return 0;

}

void SparseMatrix::set(int i, int j, int val) {

}

int SparseMatrix::getM() {
	return m_m;
}

inline int SparseMatrix::_getInternalIndex(int i, int j) {
	return i * m_n + i;
}

inline bool SparseMatrix::_isZiroItem(int i, int j) {
	return i >= m_m / 2;
}

int SparseMatrix::getN() {
	return m_n;
}

SparseMatrix::~SparseMatrix() {

}
