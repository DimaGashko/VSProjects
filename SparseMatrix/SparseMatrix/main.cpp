#pragma once

#include <iostream>
#include "SparseMatrix.hpp"

int main() {
	SparseMatrix matrix(5, 10);

	matrix.set(1, 2, 10);

	std::cout << matrix.get(1, 2) << std::endl;
	
	system("pause");
	return 0;
}