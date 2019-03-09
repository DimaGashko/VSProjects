#include "Map.hpp"
#include <stdexcept>

namespace dg {

	Map::Map() : 
		Map(1000)
	{

	}

	Map::Map(int capacity) :
		m_capacity(capacity),
		m_slots(m_capacity)
	{

	}

	void Map::set(std::string &key, int val) {
		checkKey(key);

		auto &item = m_slots[hash(key)];

		if (item.first.empty()) {
			m_size++;
		}

		item.first = key;
		item.second = val;
	}

	int Map::get(std::string &key) {
		checkKey(key);

		const auto &item = m_slots[hash(key)];
		

		return item.second;
	}

	int Map::hash(std::string& key) const {
		int hash = 0;

		for (auto c : key) { 
			hash += static_cast<int>(c);
		}

		hash = hash % m_capacity;

		return hash;
	}

	std::vector<Map::Slot> Map::toVector()	{
		std::vector<Slot> vec(m_size);
		int index = 0;

		for (auto &slot : m_slots) {
			if (slot.first.empty()) continue;

			vec[index++] = slot;
		}

		return vec;
	}

	void Map::checkKey(std::string& key) {
		if (key.empty()) throw std::runtime_error("The key can't be empty");
	}

	Map::~Map() = default;
}
