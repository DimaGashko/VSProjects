#pragma once

#include <vector>

class SparseMatrix {

public:
	typedef unsigned int ui;

	SparseMatrix(ui m, ui n);
	
	int get(ui i, ui j);
	void set(ui i, ui j, int val);

	int getM();
	int getN();

	std::vector<int> __getCompressedMatrix();

	~SparseMatrix();

private:
	int m_m;
	int m_n;

	std::vector<int> m_compressedMatrix;

	int _getInternalIndex(ui i, ui j);
	bool _isZiroItem(ui i, ui j);

	void _checkIndexes(ui i, ui j);

};