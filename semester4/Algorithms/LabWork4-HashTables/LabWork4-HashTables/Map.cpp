#include "Map.hpp"

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
		m_map[key] = val;
	}

	int Map::get(std::string &key) {
		return m_map[key];
	}

	std::vector<std::pair<std::string, int>> Map::toVector()	{
		std::vector<std::pair<std::string, int>> vec(m_map.begin(), m_map.end());

		return vec;
	}

	Map::~Map() = default;
}
