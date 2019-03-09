#include <iostream>
#include <fstream>
#include <vector>
#include <intrin.h>

#include "SparseMatrix.hpp"

typedef std::vector<std::vector<int>> VecMatrix;

template<typename F>
unsigned long long measure(F&& f, const int n = 1000);

VecMatrix getVecMatrix();
SparseMatrix compress(VecMatrix& matrix);
VecMatrix uncompress(SparseMatrix& matrix);
void printMatrix(VecMatrix& matrix);
void printMatrix(SparseMatrix& matrix);
void printCompressedMatrix(SparseMatrix& matrix);

void measureAll(VecMatrix vecMatrix, SparseMatrix sparseMatrix);

int main() {
	auto vecMatrix = getVecMatrix();
	auto compressed = compress(vecMatrix);
	auto uncompressed = uncompress(compressed);

	std::cout << "= = = Matrix = = =" << std::endl;
	printMatrix(compressed);

	std::cout << "= = = Compressed Matrix = = =" << std::endl;
	printCompressedMatrix(compressed);

	measureAll(vecMatrix, compressed);

	system("pause");
	return 0;
}

void measureAll(VecMatrix vecMatrix, SparseMatrix sparseMatrix) {
	int m = vecMatrix.size();
	int n = vecMatrix[0].size();
	int len = m * n;

	auto timeToReadVecMatrix = measure([&vecMatrix, m, n] {
		int val;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) val = vecMatrix[i][j];
		}
	}) / len;

	auto timeToWriteVecMatrix = measure([&vecMatrix, m, n] {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) vecMatrix[i][j] = 1;
		}
	}) / len;

	auto timeToReadSparseMatrix = measure([&sparseMatrix, m, n] {
		int val;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) val = sparseMatrix.get(i, j);
		}
	}) / len;

	auto timeToWriteSparseMatrix = measure([&sparseMatrix, m, n] {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) sparseMatrix.set(i, j, 1);
		}
	}) / len;

	std::cout << "timeToReadVecMatrix: " << timeToReadVecMatrix << std::endl;
	std::cout << "timeToWriteVecMatrix: " << timeToWriteVecMatrix << std::endl;
	std::cout << "timeToReadSparseMatrix: " << timeToReadSparseMatrix << std::endl;
	std::cout << "timeToWriteSparseMatrix: " << timeToWriteSparseMatrix << std::endl;
}

SparseMatrix compress(VecMatrix& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	SparseMatrix compressed(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			compressed.set(i, j, matrix[i][j]);
		}
	}

	return compressed;
}

VecMatrix uncompress(SparseMatrix& matrix) {
	int m = matrix.getM();
	int n = matrix.getN();

	VecMatrix uncompressed(m, std::vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			uncompressed[i][j] = matrix.get(i, j);
		}
	}

	return uncompressed;
}

VecMatrix getVecMatrix() {
	std::ifstream fin("input.txt");

	int m, n;
	fin >> m >> n;

	VecMatrix matrix(m, std::vector<int>(n));

	for (auto& row : matrix) {
		for (auto& item : row) {
			fin >> item;
		}
	}

	fin.close();

	return matrix;
}

void printMatrix(VecMatrix& matrix) {
	for (auto row : matrix) {
		for (auto item : row) {
			std::cout << item << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void printMatrix(SparseMatrix& matrix) {
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {
			std::cout << matrix.get(i, j) << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void printCompressedMatrix(SparseMatrix& matrix) {
	auto compressed = matrix.__getCompressedMatrix();

	for (auto item : compressed) {
		std::cout << item << " ";
	}

	std::cout << std::endl << std::endl;
}

template<typename F>
unsigned long long measure(F&& f, const int n) {
	unsigned long long res = UINT64_MAX;

	for (int i = 0; i < n; i++) {
		auto start = __rdtsc();

		f();

		auto time = __rdtsc() - start;

		if (time < res) res = time;
	}

	return res;
}