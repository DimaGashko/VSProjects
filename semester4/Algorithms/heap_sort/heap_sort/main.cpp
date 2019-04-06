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

void heapify(std::vector<int>& arr, int index) {
	int l = index * 2 + 1;
	int r = index * 2 + 2;

	int max = (arr[l] > arr[r]) ? l : r;
	if (arr[index] > arr[max]) return;

	std::swap(arr[index], arr[max]);
	heapify(arr, max);
}

void printArr(std::vector<int>& arr) {
	for (auto& item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}