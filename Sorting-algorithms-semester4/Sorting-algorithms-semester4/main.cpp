#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int l, int r);

void printArr(std::vector<int>& arr);
void writeVector(std::vector<int>& arr);

int main() {
	srand((int)time(0));

	std::vector<int> arr(100000000);

	writeVector(arr);
	//printArr(arr);

	//selectionSort(arr);
	//printArr(arr);

	quickSort(arr, 0, arr.size() - 1);
	//printArr(arr);

	system("pause");
	return 0;
}

void quickSort(std::vector<int>& arr, int l, int r) {
	int i = l, j = r;
	int middle = arr[(i + j) / 2];

	while (i < j) {
		while (arr[i] < middle) i++;
		while (arr[j] > middle) j--;
		if (i > j) break;

		std::swap(arr[i], arr[j]);
		i++; j--;
	}

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}

void selectionSort(std::vector<int>& arr) {
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		int min = arr[i];
		int minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] >= min) continue;

			min = arr[j];
			minIndex = j;
		}

		std::swap(arr[i], arr[minIndex]);
	}
}

void writeVector(std::vector<int>& arr) {
	for (auto &item : arr) {
		item = (rand() % 89) + 10;
	}
}

void printArr(std::vector<int>& arr) {
	for (auto item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}