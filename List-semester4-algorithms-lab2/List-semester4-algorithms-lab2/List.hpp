﻿#pragma once

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

		Node* getByIndex(int index);

		// Вставляет элемнет в список после node
		void insert(Node* node, int value);

		// Вставляет элемент в список после перданного индекса
		void insert(int index, int value);

		void removeItem(Node* node);
		void removeItem(int index);

		int size();
		bool isEmpty();
		void clear();

		~List();

	private:

		Node m_head; // Не указатель
		Node* m_back;

		int m_size = 0;

	};

}; // namespace dg