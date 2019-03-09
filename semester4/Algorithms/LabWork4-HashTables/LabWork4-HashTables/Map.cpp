#include "Map.hpp"
#include <stdexcept>

namespace dg {

	Map::Map() : 
		Map(1579)
	{

	}

	Map::Map(int capacity) :
		m_capacity(capacity),
		m_slots(m_capacity)
	{

	}

	void Map::set(std::string &key, int val) {
		checkKey(key);

		int index = hash(key);

		for (int i = 0; i < m_capacity; i++) {
			auto& item = m_slots[index];

			if (item.first == key || item.first.empty()) {
				item.first = key;
				item.second = val;

				return;
			}

			index = (index + 1) % m_capacity;
		}

		throw std::runtime_error("Map is full");
	}

	int Map::get(std::string &key) {
		checkKey(key);

		int index = hash(key);

		for (int i = 0; i < m_capacity; i++) {
			const auto& item = m_slots[index];

			if (item.first == key || item.first.empty()) {
				return item.second;
			}

			index = (index + 1) % m_capacity;
		}

		return 0;
	}

	int Map::hash(std::string& key) const {
		static int d = 256;
		int hash = 0;

		for (auto c : key) { 
			hash += c * d;
		}

		hash = hash % m_capacity;

		return hash;
	}

	std::vector<Map::Slot> Map::toVector()	{
		std::vector<Slot> vec;

		for (auto &slot : m_slots) {
			if (slot.first.empty()) continue;

			vec.push_back(slot);
		}

		return vec;
	}

	void Map::checkKey(std::string& key) {
		if (key.empty()) throw std::runtime_error("The key can't be empty");
	}

	Map::~Map() = default;
}
