#include "List.hpp"

namespace dg {

	List::List() {

	}

	List::Node* List::front() {
		return m_front;
	}

	List::Node* List::back() {
		return m_back;
	}

	void List::pushFront(int value) {
		auto newNode = new Node();
		newNode->value = value;
		newNode->next = m_front;

		if (m_front) {
			m_front->prev = newNode;
		}
		else {
			m_back = newNode;
		}

		m_front = newNode;
		m_size++;
	}

	void List::pushBack(int value) {
		auto newNode = new Node();
		newNode->value = value;
		newNode->prev = m_back;

		if (m_back) {
			m_back->next = newNode;
		}
		else {
			m_front = newNode;
		}

		m_back = newNode;
		m_size++;
	}

	void List::popFront() {
		if (!m_front) return;
		auto deleted = m_front;

		m_front = m_front->next;
		delete deleted;

		if (m_front) {
			m_front->prev = nullptr;
		}
		else {
			m_back = nullptr;
		}

		m_size--;
	}

	void List::popBack() {
		if (!m_back) return;
		auto deleted = m_back;

		m_back = m_back->prev;
		delete deleted;

		if (m_back) {
			m_back->next = nullptr;
		}
		else {
			m_front = nullptr;
		}

		m_size--;
	}

	List::Node* List::getByIndex(int index) {
		if (index < 0 || index >= m_size) return nullptr;

		Node * next = m_front;

		for (int i = 1; i <= index; i++) {
			next = next->next;
		}

		return next;
	}

	void List::insert(Node* node, int value) {
		if (!node) return;

		if (node == m_back) {
			pushBack(value);
			return;
		}

		auto newNode = new Node();
		newNode->value = value;
		newNode->next = node->next;
		newNode->prev = node;

		if (node->next) node->next->prev = newNode;
		node->next = newNode;

		m_size++;
	}

	void List::insert(int index, int value) {
		insert(getByIndex(index), value);
	}

	void List::removeItem(Node * node) {
		if (!node) return;

		if (node == m_front) {
			popFront();
			return;
		}

		if (node == m_back) {
			popBack();
			return;
		}

		if (node->prev) node->prev->next = node->next;
		if (node->next) node->next->prev = node->prev;

		delete node;
		m_size--;
	}

	void List::removeItem(int index) {
		removeItem(getByIndex(index));
	}

	int List::size() {
		return m_size;
	}

	bool List::isEmpty() {
		return m_size == 0;
	}

	void List::clear() {
		Node* prev = m_back;

		while (prev) {
			auto deleted = prev;
			prev = prev->prev;

			delete deleted;
		}

		m_front = nullptr;
		m_back = nullptr;
	}

	List::~List() {
		clear();
	}

}; // namespace dg
