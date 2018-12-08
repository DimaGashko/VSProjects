#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	
	for (int i = 0; i < 100; i++) {
		cout << rand() / (double)RAND_MAX * 0xffffff << endl; 
	}

	system("pause");
	return 0;
} 