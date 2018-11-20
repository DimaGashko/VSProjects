#include <iostream>
#include <vector>
#include <memory>

typedef long double ld;

using namespace std;

void ptrs(), classes();

int main() {
	//ptrs();
	classes();

	return 0;
}

class BasePerson {
public:
	BasePerson() { cout << "___BasePersonConstructor -> "; };
	virtual void a() = 0;
	BasePerson(int a) { cout << "BasePersonConstructor -> "; };
	virtual ~BasePerson() { cout << "~BasePerson -> "; };
};

class Person : public BasePerson {
public:
	Person() { cout << "___PersonConstructor -> "; };
	void a() { cout << "a from Person"; };
	Person(int a) : BasePerson(a) { cout << "PersonConstructor -> "; };
	~Person() { cout << "~Person -> "; };
};

class Student : public Person {
public:
	Student() { cout << "___StudentConstructor -> "; };
	Student(int a) : Person(a) { cout << "StudentConstructor -> "; };
	void a() override { cout << "a from Student"; }
	~Student() { cout << "~Student -> "; };
};

class Nlassleader : public Student {
public:
	Nlassleader() { cout << "___CalssLeaderConstructor -> "; };
	void a() override { cout << "a form CLeader"; };
	Nlassleader(int a) : Student(a) { cout << "ClassleaderConstructor -> "; };
	~Nlassleader() { cout << "~Classleader -> "; };
};

void classes() {
	{
		Person *p1 = new Person(5);

		cout << endl;
		p1->a();

		cout << endl;
		system("pause");

		delete p1;
	}

	cout << endl;
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