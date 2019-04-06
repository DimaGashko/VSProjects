#include <iostream>
#include <vector>
#include <cmath>

void heapify(std::vector<int>& arr);
void printArr(std::vector<int>& arr);

int main() {
	std::vector<int> arr{5,13,54,4,1,3,2};

	while (true) {
		int a;
		std::cin >> a;
		std::cout << floor((a + 1) / 2) - 1 << std::endl;
	}

	system("pause");
	return 0;
}


void bubbleUp(std::vector<int>& arr, int index) {
	int rootIndex = (index + 1) / 2;
}

void heapify(std::vector<int>& arr) {
	
}

void printArr(std::vector<int>& arr) {
	for (auto& item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}