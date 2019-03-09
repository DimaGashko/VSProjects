#pragma once

#include <map>
#include <string>
#include <vector>

namespace dg {

	class Map {
	public:
		Map();
		Map(int capacity);

		void set(std::string &key, int val);
		int get(std::string &key);

		std::vector<std::pair<std::string, int>> toVector();

		~Map();

	private:
		int m_capacity;

		std::vector<std::pair<std::string, int>> m_slots;

		std::map<std::string, int> m_map;

		int getHash(std::string &key) const;
	};

}; 
