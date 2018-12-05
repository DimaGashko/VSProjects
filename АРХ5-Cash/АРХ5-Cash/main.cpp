#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <intrin.h>

using namespace std;

const int MIN_LEN = 1024/4; //256
const int MAX_LEN = 32*1024*1024/4; //8388608

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
		auto start = __rdtsc();
		f();
		auto time = __rdtsc() - start;

		if (time < res) res = time;
	}
	
	return res;
}

unsigned long long measureTargArr(int *arr, int len) {
	const int MIN_FULL_LEN = 1'000'000 / len * len;
	int fullLen = max(len, MIN_FULL_LEN);
	int repeat = 2;

	// Подготовительный обход
	loopTargArr(arr, fullLen); 

	auto overhead = measure([] {});

	auto time = measure([&arr, fullLen] {
		loopTargArr(arr, fullLen);
	}, repeat);

	return (time - overhead) / fullLen;
}

int main() {
	srand((int)time(0));

	int step = 1;
	int i = 0;
	for (int len = MIN_LEN; len < MAX_LEN; i++, len += step) {
		
		auto arr1 = getTargArr(len, "preorder");
		auto arr2 = getTargArr(len, "postorder");
		auto arr3 = getTargArr(len, "randorder");

		auto r1 = measureTargArr(arr1, len);
		auto r2 = measureTargArr(arr2, len);
		auto r3 = measureTargArr(arr3, len);

		cout << r1 << "," << r2 << "," << r3 << endl;

		cout << len << "\t\t\t" << step << endl;

		/*delete[] arr1;
		delete[] arr2;
		delete[] arr3;

		step = step * 1.05 + 1;
	}
	
	cout << "IT: " << i << endl;
	cout << "STEP: " << step << endl;
	/*int m;
	len = 8000000;
	int *a = new int[len];
	for (int i = 0; i < len; i++) {
		a[i] = i;
	};

	auto overhead = measure([] {});

	auto loopOnly = measure([&m, &a, len] {
		for (int i = 0; i < len; i++) {

		}
	}) - overhead;

	auto all = measure([&m, &a, len] {
		for (int i = 0; i < len; i++) {
			m = a[i];
		}
	}) - loopOnly;

	auto ticksPerEl = all / len;

	cout << all << endl << ticksPerEl << endl;
	*/
	
	system("pause");
	return 0;
}

/*



template<typename F>
long long measure(F&& f) {
	const auto N = 10;
	long long results[N];

	for (auto& r : results) {
		std::this_thread::yield();
		__asm xor eax, eax
		__asm cpuid // есть интринсик, но мы хотим проигнорировать результат cpuid
		auto start_time = __rdtsc();

		f();

		__asm xor eax, eax
		__asm cpuid
		r = __rdtsc() - start_time;
	}

	auto median = results + N / 2;
	std::nth_element(results, median, results + N);
	return *median;
}


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