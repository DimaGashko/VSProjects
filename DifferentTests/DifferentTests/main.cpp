#include <iostream>
#include <vector>
#include <memory>

typedef long double ld;

using namespace std;

void ptrs(), classes(), шкафонер();

int main() {
	//ptrs();
	//шкафонер();
	classes();
	
	return 0;
}

class BasePerson {
public:
	BasePerson() { cout << "___BasePersonConstructor -> "; };
	virtual void a() {};
	BasePerson(int a) { cout << "BasePersonConstructor -> "; };
	virtual ~BasePerson() { cout << "~BasePerson -> "; };
};

class Person: public BasePerson {
public:
	Person() { cout << "___PersonConstructor -> "; };
	Person(int a): BasePerson(a) { cout << "PersonConstructor -> "; };
	~Person() { cout << "~Person -> "; };
};

class Student: public Person {
public:
	Student() { cout << "___StudentConstructor -> "; };
	Student(int a): Person(a) { cout << "StudentConstructor -> "; };
	~Student() { cout << "~Student -> "; };
};

class Сlassleader: public Student {
public:
	Сlassleader() { cout << "___CalssLeaderConstructor -> "; };
	void a() {}
	Сlassleader(int a): Student(a) { cout << "ClassleaderConstructor -> "; };
	~Сlassleader() { cout << "~Classleader -> "; };
}; 

void classes() {
	{
		Student * p1 = new Сlassleader(5);

		cout << endl;
		system("pause");

		delete p1;
	}

	cout << endl;
	system("pause");
}

class Шкаф {
public:
	double width;
	double height;
	double deep;
};

class Шифонер {
public:
	double height;
	double deep;
};

class Шкафонер : public Шкаф, public Шифонер {
public:
	Шкафонер() {
		cout << "Шкафонер" << endl;
	}

};

void шкафонер() {
	setlocale(0, "Russian");

	Шкафонер шкафонер1;
	шкафонер1.width = 50;

	cout << шкафонер1.width << endl;
	system("pause");
}

class Big {
private:
	unique_ptr<ld[]> arr;

public:
	Big() : arr(unique_ptr<ld[]>(new ld[10000000])) {

		for (int i = 0; i < 100; i++) {
			cout << arr[100000 + i] << " ";
		}

		cout << endl;

	}
};

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