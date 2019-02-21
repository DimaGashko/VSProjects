#pragma once

namespace dg {

	class List {
	public:
		List();

		struct Node {
			int value;
			Node* next;
			Node* prev;
		};

		Node* front();
		Node* back();

		void pushFront(int value);
		void pushBack(int value);

		void popFront();
		void popBack();

		Node* getByIndex(unsigned int);

		void clear();

		~List();

	private:

		Node m_head; // Не указатель
		Node* m_back;

		int m_size = 0;

		// Возвращает элемент по индексу перебирая с начала
		Node* getByIdnexLeft(unsigned int);

		// Возвращает элемент по индексу перебирая с конца
		Node* getByIdnexRight(unsigned int);

	};

}; // namespace dg