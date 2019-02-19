#include "SparseMatrix.hpp"



SparseMatrix::SparseMatrix(int m, int n) :
	m_m(m), m_n(n),
	m_compressedMatrix((m / 2) * n)
{

}

int SparseMatrix::get(int i, int j) {
	_checkIndexes(i, j);

	if (_isZiroItem(i, j)) return 0;

	return m_compressedMatrix[_getInternalIndex(i, j)];
}

void SparseMatrix::set(int i, int j, int val) {
	_checkIndexes(i, j);

	if (_isZiroItem(i, j)) return;

	m_compressedMatrix[_getInternalIndex(i, j)] = val;
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

inline void SparseMatrix::_checkIndexes(int i, int j) {
	if (i > 0 && j > 0 && i < m_m && j < m_n) {
		return;
	}

	throw std::runtime_error("SparseMatrix subscript out of range");
}

int SparseMatrix::getN() {
	return m_n;
}

SparseMatrix::~SparseMatrix() {

}
