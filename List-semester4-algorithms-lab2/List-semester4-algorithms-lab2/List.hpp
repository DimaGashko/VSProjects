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

		// Удаляет первый элемент из списка и возвращает его
		Node* popFront();

		// Удаляет последний элемент из списка и возвращает его
		Node* popBack();

		void pushFront();
		void pushBack();

		Node* getByIndex();

		void clear();

		~List();

	private:

		Node m_head; // Не указатель
		Node* m_back;

		int m_size;

	};

}; // namespace dg