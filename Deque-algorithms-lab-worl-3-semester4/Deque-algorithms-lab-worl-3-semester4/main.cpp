#include <iostream>
#include <string>

#include "StaticDeque.hpp"
#include "DinamicDeque.hpp"
#include "Deque.hpp"

void printHello();
void createDeque();
void runCommands();
void printHr();

template <typename T>
T prompt(const char label[]);

void cliHelp(), cliFront(), cliBack(), cliPushFront();
void cliPushBack(), cliPopFront(), cliPopBack();

dg::Deque* deque;

int main() {
	printHello();
	createDeque();
	runCommands();

	system("pause");
	return 0;
}

void runCommands() {
	cliHelp();

	while(true) {
		std::string command = prompt<std::string>("> ");

		if (command == "front") cliFront();
		else if (command == "back") cliBack();
		else if (command == "pushFront") cliPushFront();
		else if (command == "pushBack") cliPushBack();
		else if (command == "popFront") cliPopFront();
		else if (command == "popBack") cliPopBack();
		else if (command == "help") cliHelp();
		else if (command == "exit") break;
		else {
			std::cout << "Wrong command. Try again" << std::endl;
		}
		
		printHr();
	}
}

void createDeque() {
	int type = prompt<int>("Select Deque type\n(if 1 - static, otherwise - dinamic): ");

	if (type == 1) {
		int capacity = prompt<unsigned short>("Enter capacity: ");
		deque = new dg::StaticDeque(capacity);
	}
	else {
		deque = new dg::DinamicDeque;
	}
}

void printHello() {
	std::cout << "= = = Console Deque = = =\n\n";
}

void printHr() {
	std::cout << "- - - - - - - - -" << std::endl;
}

void cliHelp() {
	std::cout << "Commands:" << std::endl
		<< "> front #print first item" << std::endl
		<< "> back #pring last item" << std::endl
		<< "> pushFront #add item to front" << std::endl
		<< "> pushBach #add item to back" << std::endl
		<< "> popFront #remove firstElement" << std::endl
		<< "> popBack #remove lastElement" << std::endl
		<< std::endl
		<< "> help #print help" << std::endl
		<< "> exit #close the program" << std::endl
		<< std::endl;
}

void cliFront() {
	std::cout << "cliFront" << std::endl;
}

void cliBack() {
	std::cout << "cliBack" << std::endl;
}

void cliPushFront() {
	std::cout << "Front" << std::endl;
}

void cliPushBack() {
	std::cout << "cliPushFront" << std::endl;
}

void cliPopFront() {
	std::cout << "cliPopFront" << std::endl;
}

void cliPopBack() {
	std::cout << "cliPopBack" << std::endl;
}

template <typename T>
T prompt(const char label[]) {
	std::cout << label;

	while (true) {
		T val;
		std::cin >> val;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong. Try again: ";
		}
		else {
			std::cin.ignore(32767, '\n');
			return val;
		}

	}

}