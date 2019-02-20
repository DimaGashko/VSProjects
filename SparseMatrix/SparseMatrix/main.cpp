#include <iostream>
#include <fstream>
#include <vector>
#include <intrin.h>

#include "SparseMatrix.hpp"

typedef std::vector<std::vector<int>> VecMatrix;

template<typename F>
unsigned long long measure(F&& f, const int n = 10);

VecMatrix getVecMatrix();
SparseMatrix compress(VecMatrix &matrix);
VecMatrix uncompress(SparseMatrix &matrix);
void printMatrix(VecMatrix &matrix);
void printMatrix(SparseMatrix &matrix);
void printCompressedMatrix(SparseMatrix &matrix);

int main() {
	SparseMatrix m(10, 10);
	
	m.set(1, 5, 10);
	std::cout << m.get(1, 5) << std::endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m.get(i, j);
		}
	}

	auto time = measure([&m] {
		int val;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				val = m.get(i, j);
			}
		}

		}, 1000) / 100;

	std::cout << time << std::endl;

	system("pause");
	return 0;
	/*auto vecMatrix = getVecMatrix();
	
	int m = vecMatrix.size();
	int n = vecMatrix[0].size();
	int len = m * n;

	auto matrix = vecMatrix;
	auto compressed = compress(matrix);
	auto uncompressed = uncompress(compressed);

	printMatrix(matrix);
	printMatrix(compressed);
	printMatrix(uncompressed);

	auto sys = measure([&matrix, m, n] {
		int val;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				val = 1;
			}
		}

	}, 100) / len;

	auto timeToReadVecMatrix = measure([&matrix, m, n] {
		int val;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				val = matrix[i][j];
			}
		}

	}, 1000) / len;

	auto timeToWriteVecMatrix = measure([&matrix, m, n] {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 1;
			}
		}
	}, 1000) / len;

	auto timeToReadSparseMatrix = measure([&compressed, m, n] {
		int val;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				val = compressed.get(i, j);
			}
		}
		
	}, 1000) / len;

	auto timeToWriteSparseMatrix = measure([&compressed, m, n] {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				compressed.set(i, j, 1);
			}
		}
	}, 1000) / len;

	std::cout << "timeToReadVecMatrix: " << timeToReadVecMatrix - sys << std::endl;
	std::cout << "timeToWriteVecMatrix: " << timeToWriteVecMatrix - sys << std::endl;
	std::cout << "timeToReadSparseMatrix: " << timeToReadSparseMatrix - sys << std::endl;
	std::cout << "timeToWriteSparseMatrix: " << timeToWriteSparseMatrix - sys << std::endl;
	*/
	/*std::cout << "= = = Matrix = = =" << std::endl;
	printMatrix(matrix);

	std::cout << std::endl << "= = = Compressed Matrix = = =" << std::endl;
	printCompressedMatrix(matrix);*/

	system("pause");
	return 0;
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

	/*for (auto item : compressed) {
		std::cout << item << " ";
	}*/

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