#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int l, int r);

void printArr(std::vector<int>& arr);
void writeVector(std::vector<int>& arr);

std::vector<int> getSizesToTest();

void printHello();
bool askIfExit();

template <typename T>
T prompt(const char label[]);

int main() {
	srand((int)time(0));

	printHello();

	while (true) {
		auto sizesToTest = getSizesToTest();
		printArr(sizesToTest);

		if (askIfExit()) break;
		std::cout << "\n\n- - - - - - - -\n\n";
	}

	return 0;
}

std::vector<int> getSizesToTest() {
	std::vector<int> sizes;

	std::cout << "Enter sizes to test (non-positive to complete):\n";

	while (true) {
		int size = prompt<int>("> ");
		if (size <= 0) break;

		sizes.push_back(size);
	}

	return sizes;
}

void printHello() {
	std::cout << "* * * Algorithms: Sorting Methods * * *\n\n";
}

bool askIfExit() {
	return (prompt<std::string>("\nRepeat? (0 if not)") == "0");
}

void quickSort(std::vector<int>& arr, int l, int r) {
	int i = l, j = r;
	int pivot = arr[(i + j) / 2];

	while (i < j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
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

template <typename T>
T prompt(const char label[]) {
	std::cout << label;

	while (true) {
		T val;
		std::cin >> val;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong. Try again: ";
		}
		else {
			std::cin.ignore(32767, '\n');
			return val;
		}

	}

}