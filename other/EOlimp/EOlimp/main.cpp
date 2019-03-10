#include <iostream>
#include <vector>
#include <string>

using namespace std;

int swapCount = 0;
string swaps = "";

void counting_sort(vector<int>& elems, int min, int max) {
	vector<unsigned> counts(max - min + 1);

	for (int elem : elems)	{
		++counts[elem - min];
	}

	auto elemsIt = elems.begin(); //current position to write result
	for (int i = min; i <= max; ++i) {
		// write counts[i - min] copies of i into elems
		fill_n(elemsIt, counts[i - min], i);
		elemsIt += counts[i - min];
	}
}

void quick_sort(vector<int> &arr, int l, int r) {
	int i = l, j = r;
	int pivot = arr[(i + j) / 2];

	while (i < j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i > j) break;

		if (arr[i] != arr[j]) {
			swapCount++;
			//swaps += to_string(i) + " " + to_string(j) + "\n";

			int arrI = arr[i];
			arr[i] = arr[j];
			arr[j] = arrI;
		}

		i++; j--;
	}

	if (i < r) quick_sort(arr, i, r);
	if (j > l) quick_sort(arr, l, j);
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(1000000);

	for (auto& item : arr) {
		//cin >> item;
		item = rand() % 1000;
	}

	counting_sort(arr, 0, arr.size());

	/*for (auto& item : arr) {
		cout << item << " ";
	}*/

	//cout << swapCount << endl << swaps << endl;

	system("pause");
	return 0;
}