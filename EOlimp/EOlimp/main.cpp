#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void processTest();

struct command0 {
	int p, q, v;
};

struct command1 {
	int p, v;
};

int main() {
	queue<int[2]> q;

	q.push({ 1, 2 });
	fout << q.front()[0] << " " << q.front()[1];// << q.front()[2];

	return 0;
	int t, n;
	fin >> t;

	for (int i = 0; i < t; i++) {
		fin >> n;

		processTest();
	}

	return 0;
}

void processTest() {
	int c; 
	fin >> c;

	queue<int> commands;
	queue<command0> cs0;
	list<command1> cs1;

	for (int i = 0; i < c; i++) {
		int command;
		fin >> command;
		commands.push(command);
		

	}
}