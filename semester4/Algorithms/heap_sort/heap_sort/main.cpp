#include <iostream>
#include <vector>
#include <cmath>

void heapSort(std::vector<int>& arr);
void heapify(std::vector<int>& arr, int size, int index);
void printArr(std::vector<int>& arr);

int main() {
	std::vector<int> arr{5,13,54,4,1,3,60};

	heapSort(arr);

	printArr(arr);

	system("pause");
	return 0;
}

void heapSort(std::vector<int>& arr) {
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, arr.size(), i);
	}

	for (int i = arr.size() - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void heapify(std::vector<int>& arr, int size, int index) {
	int l = index * 2 + 1;
	int r = index * 2 + 2;
	int max = index;

	if (l < size && arr[l] > arr[max]) max = l;
	if (r < size && arr[r] > arr[max]) max = r;
	if (max == index) return;

	std::swap(arr[index], arr[max]);
	heapify(arr, size, max);
}

void printArr(std::vector<int>& arr) {
	for (auto& item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}