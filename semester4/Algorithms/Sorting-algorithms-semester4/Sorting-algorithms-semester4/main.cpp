#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int l, int r);

void heapSort(std::vector<int>& arr);
void heapify(std::vector<int>& arr, int size, int index);

void printArr(std::vector<int>& arr, int maxElementsToPrint = 500);
void writeVector(std::vector<int>& arr);

std::vector<int> getSizesToTest();

void printHello();
bool askIfExit();

void runTests(std::vector<int> &sizesToTest);
void test(int size);

template <typename T>
T prompt(const char label[]);

template<typename F>
long long measure(F&& f);

int main() {
	srand((int)time(0));
	
	printHello();

	while (true) {
		auto sizesToTest = getSizesToTest();
		runTests(sizesToTest);

		if (askIfExit()) break;
		std::cout << "\n- - - - - - - -\n\n";
	}

	return 0;
}

void heapSort(std::vector<int>& arr) {
	for (int i = (int)arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, (int)arr.size(), i);
	}

	for (int i = (int)arr.size() - 1; i >= 0; i--) {
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

void runTests(std::vector<int>& sizesToTest) {
	if (sizesToTest.empty()) {
		std::cout << "No sizes to test\n";
	}

	std::cout << std::endl;

	for (auto& size : sizesToTest) {
		test(size);
	}
}

void test(int size) {
	std::cout << "Testing for " << size << " elements:\n";

	std::vector<int> arr(size);
	writeVector(arr);

	// Quick Sort
	std::cout << "Quick Sort: ";
	std::vector<int> arrToQuickSort(arr);

	auto timeToQuickSort = measure([&arr, &arrToQuickSort] {
		arrToQuickSort = std::vector<int>(arr);
		quickSort(arrToQuickSort, 0, (int)arrToQuickSort.size() - 1);
	});

	std::cout << timeToQuickSort << std::endl;

	// Heap Sort
	std::cout << "Heap Sort: ";
	std::vector<int> arrToHeapSort;

	auto timeToHeapSort = measure([&arr, &arrToHeapSort] {
		arrToHeapSort = std::vector<int>(arr);
		heapSort(arrToHeapSort);
	});

	std::cout << timeToHeapSort << std::endl;

	std::cout << "- - - - -\n";
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
	int size = (int)arr.size();

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

void printArr(std::vector<int>& arr, int maxElementsToPrint) {
	int size = std::min((int)arr.size(), maxElementsToPrint);

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}

	if ((int)arr.size() > size) {
		std::cout << "(...)";
	}

	std::cout << std::endl;
}

void printHello() {
	std::cout << "* * * Algorithms: Sorting Methods * * *\n\n";
}

bool askIfExit() {
	return (prompt<std::string>("\nRepeat? (0 if not): ") == "0");
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

template<typename F>
long long measure(F&& f) {
	auto start = std::clock();

	f();

	auto time = std::clock() - start;

	return (long long)time;
}
