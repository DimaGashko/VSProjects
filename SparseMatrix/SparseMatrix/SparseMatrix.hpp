#pragma once

#include <vector>

class SparseMatrix {

public:
	SparseMatrix(int m, int n);

	int get(int i, int j);
	void set(int i, int j, int val);

	int getM();
	int getN();

	~SparseMatrix();

private:
	int m_m;
	int m_n;

	std::vector<int> m_compressedMatrix;

};

