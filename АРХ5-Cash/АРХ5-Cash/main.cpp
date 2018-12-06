#include <iostream>
#include <fstream>
#include <intrin.h>
#include <thread>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename F>
unsigned long long measure(F&& f, const int n = 10);

int getSystemTime();

int* getTargArr(int len, string type);
inline void loopTargArr(int *arr, int n);
unsigned long long measureTargArr(int *arr, int len);
int getRepeatVal(int len);
vector<int> getLens(int k = 1.5);
string formatSize(int bytes);
bool saveInFile(string data, string src);

void printArr(int *arr, int len);
void run(), printHello();

template <typename T>
T prompt(const char label[]);

int main() {
	srand((int)time(0));
	printHello();

	while (1) {
		run();
		cout << endl;

		auto repeat = prompt<string>("Repeat? (1 - yes): ");
		if (repeat != "1") break;
	}

	return 0;
}

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

		/*
		links = {0,2,1,3,4};

		arr[0] = 2;
		arr[2] = 1;
		arr[1] = 3;
		arr[3] = 4;
		arr[4] = 0;
		*/
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
unsigned long long measure(F&& f, const int n) {
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
//getCPUTime

int getRepeatVal(int len) {
	if (len < 100'000) return 100;
	else if (len < 1'000'000) return 10;

	return 1;
}

unsigned long long measureTargArr(int *arr, int len) {
	int fullLen = len;
	int repeat = getRepeatVal(len);

	// Подготовительный обход
	//loopTargArr(arr, len);

	auto time = measure([&arr, fullLen] {
		loopTargArr(arr, fullLen);
	}, repeat);

	return time / fullLen;
}

int getSystemTime() {
	const int len = 1'000'000;

	auto overhead = measure([len] {
		for (int i = 0; i < len; i++) {};
	}, 50);

	return int(overhead / len);
}

vector<int> getLens(int k) {
	const int MIN_LEN = 1024 / 4; //256
	const int MAX_LEN = 5 * 1024 * 1024 / 4; //8388608

	vector<int> lens;

	for (int len = MIN_LEN, step = 1; len < MAX_LEN; len += step) {
		lens.push_back(len);
		step = int(step * k + 10);
	}

	lens.push_back(MAX_LEN);

	return lens;
}

bool saveInFile(string data, string src) {
	ofstream fout(src);
	if (!fout) return false;

	fout << data;

	fout.close();
	return true;
}

string formatSize(int bytes) {
	const int KB = 1024;
	const int MB = 1024 * 1024;

	if (bytes < KB) {
		return to_string(bytes) + " bytes";
	}
	
	float size = (float)bytes / (bytes < MB ? KB : MB);
	string strSize = to_string(size);
	strSize = strSize.substr(0, strSize.length() - 4);

	return strSize + " " + (bytes < MB ? "KB" : "MB");
}

void printHello() {
	cout << "- - - Cash diagnostic - - -" << endl << endl;
}

template <typename T>
T prompt(const char label[]) {
	cout << label;

	while (true) {
		T val;
		cin >> val;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Wrong. Try again: ";
		}
		else {
			cin.ignore(32767, '\n');
			return val;
		}

	}

}

void run() {
	int lenK = prompt<float>("Enter the increment step: ");
	int systemTime = getSystemTime();
	vector<int> lens = getLens(lenK);

	string res = "Length,Size,Preorder,Postorder,Randorder\n";
	cout << res;

	for (int i = 0; i < (int)lens.size(); i++) {
		int len = lens[i];

		auto arr1 = getTargArr(len, "preorder");
		auto arr2 = getTargArr(len, "postorder");
		auto arr3 = getTargArr(len, "randorder");

		auto r1 = measureTargArr(arr1, len) - systemTime;
		auto r2 = measureTargArr(arr2, len) - systemTime;
		auto r3 = measureTargArr(arr3, len) - systemTime;

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;

		string curRes = to_string(len) + ","
			+ formatSize(len * 4) + ","
			+ to_string(r1) + ","
			+ to_string(r2) + ","
			+ to_string(r3) + "\n";

		res += curRes;
		cout << to_string(i + 1) << "/" << to_string(lens.size()) << "," << curRes;
	}

	bool saved = saveInFile(res, "cash.csv");
	cout << (saved ? "Saved" : "Cannot save results to file") << endl;
}