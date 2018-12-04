#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

const int MIN_LEN = 1024/4; //256
const int MAX_LEN = 32*1024*1024/4; //8388608

//���������� ������ ��� ������������ � �������� len ����������� type ��������
//type = "preorder" - ������ | "postorder" - �������� | "randorder" 
int* getTargArr(int len, string type) {
	int *arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = i;
	}

	if (type == "postorder") {
		reverse(arr, arr + len);
	}
	else if (type == "randorder") {
		std::random_shuffle(arr, arr + len);
	}

	return arr;
}

void printArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;
}

int main() {
	srand(time(0));
	const int len = 20;

	auto arr1 = getTargArr(len, "preorder");
	auto arr2 = getTargArr(len, "postorder");
	auto arr3 = getTargArr(len, "randorder");
	
	printArr(arr1, len);
	printArr(arr2, len);
	printArr(arr3, len);

	system("pause");
	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <ctime>

int main() {
	srand(time(0));
	const int n = 6;
	int arr[n] = { 0, 1, 2, 3, 4, 5 };

	std::random_shuffle(arr, arr + 5);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i];
	}

	std::cout << std::endl;
	system("pause");
}*/