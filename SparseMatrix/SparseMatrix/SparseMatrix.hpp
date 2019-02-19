#pragma once

class SparseMatrix {

public:
	SparseMatrix(int m, int n);

	int get(int m, int n);
	void set(int m, int n, int val);

	int getM();
	int getN();

	~SparseMatrix();

private:
	int _m;
	int _n;



};

