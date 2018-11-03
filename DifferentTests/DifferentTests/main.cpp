#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
	
	system("pause");

	{
		vector<unique_ptr<long double>> arr;

		for (int i = 0; i < 10000000; i++) {
			arr.push_back(unique_ptr<long double>(new long double(i)));
		}
		
		system("pause");
	}

	system("pause");
	return 0;
}