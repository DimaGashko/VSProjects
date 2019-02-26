#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

void selectionSort(std::vector<int>& arr);

void printArr(std::vector<int>& arr);
void writeVector(std::vector<int>& arr);

int main() {
	srand((int)time(0));

	std::vector<int> arr(20);

	writeVector(arr);
	printArr(arr);

	selectionSort(arr);
	printArr(arr);

	system("pause");
	return 0;
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