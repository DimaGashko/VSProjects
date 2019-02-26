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

	system("pause");
	return 0;
}

void selectionSort(std::vector<int>& arr) {

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