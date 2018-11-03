#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	system("pause");

	{
		vector<long double *> arr;

		for (int i = 0; i < 10000000; i++) {
			arr.push_back(new long double(i));
		}

		for (int i = 0; i < arr.size(); i++) {
			delete arr[i];
		}

		arr.clear();		
		system("pause");
	}

	system("pause");
	return 0;
}