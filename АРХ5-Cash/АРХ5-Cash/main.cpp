#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>

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

void printArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;
}

int main() {
	srand((int)time(0));
	int len = 20;	

	auto arr1 = getTargArr(len, "preorder");
	auto arr2 = getTargArr(len, "postorder");
	auto arr3 = getTargArr(len, "randorder");

	printArr(arr1, len);
	printArr(arr2, len);
	printArr(arr3, len);

	cout << endl;

	for (int t = 0; t < len; t++) {
		
		for (int k = 0, i = 0; i < len; i++, k = arr3[k]) {
			cout << arr3[k] << " ";
		}

		cout << endl;
	}
	

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

#include <intrin.h>
#include <algorithm>
#include <iostream>
#include <thread>

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