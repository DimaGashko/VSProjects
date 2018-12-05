#include <iostream>
#include <fstream>
#include <intrin.h>
#include <thread>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Возвращает массив для тестирования с размером len 
// Заполненный type способом в виде цикличного списка
// type = "preorder" - прямой | "postorder" - обратный | "randorder" 
int* getTargArr(int len, string type) {
	int *arr = new int[len];

	if (type == "preorder") {
		for (int i = 0; i < len; i++) {
			arr[i] = (i + 1) % len;
		}

	}
	else if (type == "postorder") {
		for (int i = 0; i < len; i++) {
			arr[i] = (i - 1 + len) % len;
		}
	
	}
	else if (type == "randorder") {
		vector<int> links(len);

		for (int i = 0; i < len; i++) {
			links[i] = i;
		}

		random_shuffle(links.begin() + 1, links.end());

		for (int i = 0; i < len; i++) {
			arr[links[i]] = links[(i + 1) % len];
		}
	}

	return arr;
}

inline void loopTargArr(int *arr, int n) {
	for (int i = 0, link = 0; i < n; i++) {
		link = arr[link];
	}
}

void printArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;
}

template<typename F>
unsigned long long measure(F&& f, const int n = 10) {
	unsigned long long res = UINT64_MAX;

	for (int i = 0; i < n; i++) {
		std::this_thread::yield();
		__asm xor eax, eax
		__asm cpuid
		auto start = __rdtsc();

		f();

		__asm xor eax, eax
		__asm cpuid
		auto time = __rdtsc() - start;

		if (time < res) res = time;
	}
	
	return res;
}

unsigned long long measureTargArr(int *arr, int len) {
	int fullLen = max(len, 1'000'000);
	int repeat = 10;

	auto overhead = measure([fullLen] {
		for (int i = 0; i < fullLen; i++) {};
	});

	// Подготовительный обход
	loopTargArr(arr, len);

	auto time = measure([&arr, fullLen] {
		loopTargArr(arr, fullLen);
	}, repeat);

	return (time - overhead) / fullLen;
}

vector<int> getLens() {
	const int MIN_LEN = 1024 / 4; //256
	const int MAX_LEN = 32 * 1024 * 1024 / 4; //8388608

	vector<int> lens;

	for (int len = MIN_LEN, step = 1; len < MAX_LEN; len += step) {
		step = int(step * 1.03 + 10);
		lens.push_back(len);
	}

	return lens;
}

bool saveInFile(string data, string src) {
	return true;
}

int main() {
	srand((int)time(0));

	string res = "";
	vector<int> lens = getLens();

	for (int i = 0; i < (int)lens.size(); i++) {
		int len = lens[i];

		auto arr1 = getTargArr(len, "preorder");
		auto arr2 = getTargArr(len, "postorder");
		auto arr3 = getTargArr(len, "randorder");

		auto r1 = measureTargArr(arr1, len);
		auto r2 = measureTargArr(arr2, len);
		auto r3 = measureTargArr(arr3, len);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;

		string curRes = to_string(len) + ","
			+ to_string(r1) + ","
			+ to_string(r2) + ","
			+ to_string(r3) + "\n";

		res += curRes;
		cout << curRes; 
	}

	saveInFile(res, "cash.csv");
	
	string close;
	cin >> close;
	return 0;
}