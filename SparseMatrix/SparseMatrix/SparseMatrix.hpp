#pragma once

class SparseMatrix {

public:
	SparseMatrix(int m, int n);

	int get(int i, int j);
	void set(int i, int j, int val);

	int getM();
	int getN();

	~SparseMatrix();

private:
	int _m;
	int _n;



};

