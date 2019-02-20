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
	auto vecMatrix = getVecMatrix();

	int m = vecMatrix.size() / 2;
	int n = vecMatrix[0].size();
	int len = m * n;

	auto matrix = vecMatrix;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			vecMatrix[i][j];
		}
	}

	auto start = __rdtsc();
	vecMatrix[1][2];
	auto end = __rdtsc() - start;

	std::cout << end << std::endl;

	std::vector<int> a(10);

	for (int i = 0; i < a.size(); i++) {
		a[i] = i;
	}

	start = __rdtsc();
	a[1];
	end = __rdtsc() - start;

	std::cout << end << std::endl;

	int** b = new int*[10];
	for (int i = 0; i < 10; i++) {
		b[i] = new int[10];

		for (int j = 0; j < 10; j++) {
			b[i][j] = i * j;
		}
	}

	start = __rdtsc();
	b[1][2];
	end = __rdtsc() - start;

	std::cout << end << std::endl;

	printMatrix(matrix);
	std::cout << std::endl;

	

	auto matrix1 = compress(matrix);
	printMatrix(matrix1);
	std::cout << std::endl;

	auto matrix2 = uncompress(matrix1);
	printMatrix(matrix2);
	std::cout << std::endl;

	auto sys = measure([&matrix, m, n] {
		int val;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				val = 1;
			}
		}

	}, 100) / len;

	std::cout << sys << std::endl;

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

	auto timeToReadSparseMatrix = measure([&matrix1, m, n] {
		int val;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				val = matrix1.get(i, j);
			}
		}
		
	}, 1000) / len;

	auto timeToWriteSparseMatrix = measure([&matrix1, m, n] {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix1.set(i, j, 1);
			}
		}
	}, 1000) / len;

	std::cout << "timeToReadVecMatrix: " << timeToReadVecMatrix - sys << std::endl;
	std::cout << "timeToWriteVecMatrix: " << timeToWriteVecMatrix - sys << std::endl;
	std::cout << "timeToReadSparseMatrix: " << timeToReadSparseMatrix - sys << std::endl;
	std::cout << "timeToWriteSparseMatrix: " << timeToWriteSparseMatrix - sys << std::endl;

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