#include "SparseMatrix.hpp"

SparseMatrix::SparseMatrix(ui m, ui n) :
	m_m(m), m_n(n),
	m_compressedMatrix((m / 2) * n)
{

}

int SparseMatrix::get(ui i, ui j) {
	_checkIndexes(i, j);

	if (_isZiroItem(i, j)) return 0;

	return m_compressedMatrix[_getInternalIndex(i, j)];
}

void SparseMatrix::set(ui i, ui j, int val) {
	_checkIndexes(i, j);

	if (_isZiroItem(i, j)) return;

	m_compressedMatrix[_getInternalIndex(i, j)] = val;
}

inline int SparseMatrix::_getInternalIndex(ui i, ui j) {
	return i * m_n + j;
}

inline bool SparseMatrix::_isZiroItem(ui i, ui j) {
	return i >= m_m / 2;
}

inline void SparseMatrix::_checkIndexes(ui i, ui j) {
	if (i >= 0 && j >= 0 && i < m_m && j < m_n) {
		return;
	}

	throw std::runtime_error("SparseMatrix subscript out of range");
}

std::vector<int> SparseMatrix::__getCompressedMatrix() {
	return m_compressedMatrix;
}

int SparseMatrix::getM() {
	return m_m;
}

int SparseMatrix::getN() {
	return m_n;
}

SparseMatrix::~SparseMatrix() {

}
