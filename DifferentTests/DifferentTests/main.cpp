#include <iostream>
#include <vector>
#include <string>
#include <memory>

typedef long double ld;

using namespace std;

void ptrs(), classes(), classes2(), singleton();

int main() {
	//ptrs();
	//classes();
	//classes2();
	singleton();
	return 0;
}

//-------------------------

class Logger {

public:

	static Logger* getInstance() {
		if (s_logger == nullptr) {
			s_logger = new Logger();
		}

		return s_logger;
	}

	void log(string mess) {
		cout << mess << endl;
	}

private:

	Logger() { }

	static Logger* s_logger;
};

Logger* Logger::s_logger = nullptr;

void singleton() {
	Logger* console = Logger::getInstance();

	console->log("Hello, world!");

	delete console;

	system("pause");
}

//-------------------------

class GameObject
{
	bool obstacle;
public:
	GameObject(bool obs) : obstacle{ obs } {}
	virtual ~GameObject() {}
	virtual void f() = 0;
	bool isObstacle() { return obstacle; }
};

class Obstacle : public GameObject
{
public:
	Obstacle(bool obs = true) : GameObject(obs) {}
	~Obstacle() {}
	void f() {}
};

class SimpleGameObject : public GameObject
{
public:
	SimpleGameObject(bool obs = false) : GameObject(obs) {}
	void f() {}
};

void classes2() {
	GameObject* oobs = new Obstacle();
	GameObject* sobs = new SimpleGameObject();

	std::cout << "Obstacle is Obstacle? " << oobs->isObstacle() << "\n";
	std::cout << "SimpleGameObject is Obstacle? " << sobs->isObstacle() << "\n";

	delete oobs; delete sobs;

	system("pause");
}

// -------------------------

class BasePerson {
public:
	BasePerson() { cout << "___BasePersonConstructor -> "; };
	virtual void a() = 0;
	BasePerson(int a) { cout << "BasePersonConstructor -> "; };
	bool isFoo() { return foo; }

	bool foo = true;
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
	void a() override { 
		cout << "a from Student"; 
		foo = false;
	}

	//bool foo = false;
	~Student() { cout << "~Student -> "; };
};

void classes() {
	Student *p1 = new Student(5);
	cout << endl;
	
	cout << p1->isFoo() << endl;
	p1->a();

	cout << p1->isFoo() << endl;
	
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