#include <iostream>
#include <vector>
#include <string>
#include <list>

struct Edge {
	int a, b, w;
};

void run();
void printHello();
std::list<Edge> getEdges();

template <typename T>
T prompt(const char label[]);

int main() {
	printHello();

	while (true) {
		run();

		if (prompt<std::string>("\nRepeat? (0 to exit): ") == "0") {
			break;
		}

		std::cout << "\n- - - - - - - - - -\n\n";
	}

	return 0;
}

void run() {
	auto edges = getEdges();

	for (auto e : edges) {
		std::cout << e.a << " " << e.b << " " << e.w << std::endl;
	}
}

std::list<Edge> getEdges() {
	int size = prompt<unsigned short>("Enter the number of edges: ");
	std::list<Edge> edges;

	for (int i = 0; i < size; i++) {
		std::cout << "- Edge " << i + 1 << std::endl;
		
		Edge edge;
		edge.a = prompt<int>("From: ");
		edge.b = prompt<int>("To: ");
		edge.w = prompt<int>("Weight: ");

		edges.push_back(edge);
	}

	return edges;
}

void printHello() {
	std::cout << "* * * Algorithms: Dijkstra's algorithm * * *\n\n";
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