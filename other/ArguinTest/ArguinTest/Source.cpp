#include <iostream>
#include <ctime>

using namespace std;

//���������� ��������� ���� � ���� ����� �� 0 �� 0xffffff
//RAND_MAX =  0x7fff
long long getRandNumberColor() {
	return rand() / (double)RAND_MAX * 0xffffff;
}

int main() {
	srand(time(0));
	
	for (int i = 0; i < 100; i++) {
		cout <<  << endl; 
	}

	system("pause");
	return 0;
} 