#include <iostream>
#include <vector>
#include <memory>

typedef long double ld;

using namespace std;

class Big {
private:
	unique_ptr<ld> arr;

public:
	Big(): arr(unique_ptr<ld>(new ld[10000000])) { }
};

void ptrs();

int main() {
	ptrs();
	
	return 0;
}

void ptrs() {
	{
		shared_ptr<Big> b1(new Big);
		{
			shared_ptr<Big> b2 = b1;
			system("pause");
		}
		system("pause");
	}

	/*{
		system("pause");
		unique_ptr<Big> ptrB(new Big);
		system("pause");
	};*/

	/*
	system("pause");

	{
		vector<unique_ptr<long double>> arr;

		for (int i = 0; i < 10000000; i++) {
			arr.push_back(unique_ptr<long double>(new long double(i)));
		}

		system("pause");
	}*/

	system("pause");
}