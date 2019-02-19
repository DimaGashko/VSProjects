#pragma once

#include <iostream>
#include <fstream>
#include "SparseMatrix.hpp"

SparseMatrix getMatrix();
void printMatrix(SparseMatrix& matrix);
void printCompressedMatrix(SparseMatrix& matrix);

int main() {
	auto matrix = getMatrix();

	std::cout << "= = = Matrix = = =" << std::endl;
	printMatrix(matrix);

	std::cout << std::endl << "= = = Compressed Matrix = = =" << std::endl;
	printCompressedMatrix(matrix);

	system("pause");
	return 0;
}

SparseMatrix getMatrix() {
	std::ifstream fin("input.txt");

	int m, n, val;
	fin >> m >> n;

	SparseMatrix matrix(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fin >> val;
			matrix.set(i, j, val);
		}
	}

	fin.close();

	return matrix;
}

void printMatrix(SparseMatrix& matrix) {
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {
			std::cout << matrix.get(i, j) << " ";
		}

		std::cout << std::endl;
	}
}

void printCompressedMatrix(SparseMatrix& matrix) {
	auto compressed = matrix.__getCompressedMatrix();

	for (auto item : compressed) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

