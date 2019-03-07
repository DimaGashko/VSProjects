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

	std::vector<int> arr(9);

	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 5;
	arr[3] = 3;
	arr[4] = 8;
	arr[5] = 6;
	arr[6] = 4;
	arr[7] = 3;
	arr[8] = 2;

	//writeVector(arr);
	printArr(arr);

	std::vector<int> arrSel(arr);
	selectionSort(arrSel);
	printArr(arrSel);

	std::vector<int> arrQuick(arr);
	quickSort(arrQuick, 0, arrQuick.size() - 1);
	printArr(arrQuick);

	system("pause");
	return 0;
}
/*
void quickSort(std::vector<int>& arr, int l, int r) {
	int i = l, j = r;
	int pivot = arr[(i + j) / 2];

	while (i < j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		std::swap(arr[i], arr[j]);
		i++; j--;
	}

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}*/

void quickSort(std::vector<int>& arr, int l, int r) {
	int i = l, j = r, middle = arr[(i + j) / 2];
	asdf;
	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++; j--;
		}

	} while (i < j);

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