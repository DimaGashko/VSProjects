#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

const int MIN_LEN = 1024/4; //256
const int MAX_LEN = 32*1024*1024/4; //8388608

// ¬озвращает массив дл€ тестировани€ с размером len 
// «аполненный type способом в виде цикличного списка
// type = "preorder" - пр€мой | "postorder" - обратный | "randorder" 
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
		vector<int> links(len - 1);

		// ¬озможные значение ссылок без "0" - последовательность от 1 до "len-1"
		// (ƒл€ исключени€ преждевременного ссылани€ на 0 элемент)
		for (int i = 0; i < len - 1; i++) {
			links[i] = i + 1;
		}

		random_shuffle(links.begin(), links.end());

		int prevLink = 0;

		// Ќепосредственное заполнение массива в виде списка в случайно пор€дке
		// ¬ каждый последующий prevLink записываетс€ последнее значение links
		// Ќе может бысть ситуации, когда элемент ссылаетс€ на себ€ так как extLink 
		// ѕосле определени€ удал€етс€ из links из-за чего prevLink и nextLink всегда разные 
		for (int i = 0; i < len - 1; i++) {
			int nextLink = links.back();
			links.pop_back();

			arr[prevLink] = nextLink;
			prevLink = nextLink;
		}

		arr[prevLink] = 0;
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
	int len = 20;	

	auto arr1 = getTargArr(len, "preorder");
	auto arr2 = getTargArr(len, "postorder");
	auto arr3 = getTargArr(len, "randorder");

	printArr(arr1, len);
	printArr(arr2, len);
	printArr(arr3, len);

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