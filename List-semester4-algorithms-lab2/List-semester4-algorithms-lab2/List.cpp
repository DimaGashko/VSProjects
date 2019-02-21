#include "List.hpp"

namespace dg {

	List::List() {

	}

	List::Node* List::front() {
		return m_head.next;
	}

	List::Node* List::back() {
		return m_back;
	}

	void List::pushFront(int value) {
		auto newNode = new Node();
		newNode->value = value;
		newNode->next = m_head.next;

		if (m_head.next) {
			m_head.next->prev = newNode;
		}
		else {
			m_back = newNode;
		}

		m_head.next = newNode;
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
			m_head.next = newNode;
		}

		m_back = newNode;
		m_size++;
	}

	void List::popFront() {
		if (!m_head.next) return;
		auto deleted = m_head.next;

		m_head.next = m_head.next->next;
		delete deleted;

		if (m_head.next) {
			m_head.next->prev = nullptr;
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
			m_head.next = nullptr;
		}
		
		m_size--;
	}

	List::Node* List::getByIndex(int index) {
		if (index < 0 || index >= m_size) return nullptr;

		Node* next = m_head.next;

		for (int i = 1; i <= index; i++) {
			next = next->next;
		}

		return next;
	}

	void List::insert(Node* node, int value) {
		if (!node) return;


	}

	void List::insert(int index, int value) {
		insert(getByIndex(index), value);
	}

	void List::removeItem(Node* node) {
		if (!node) return;


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

		m_head.next = nullptr;
		m_back = nullptr;
	}

	List::~List() {

	}

}; // namespace dg
