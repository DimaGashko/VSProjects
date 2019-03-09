#pragma once

#include <string>
#include <vector>

namespace dg {

	class Map {
	public:

		typedef std::pair<std::string, int> Slot;

		Map();
		Map(int capacity);

		void set(std::string &key, int val);
		int get(std::string &key);

		std::vector<Slot> toVector();

		~Map();

	private:
		int m_capacity;
		int m_size = 0;

		std::vector<Slot> m_slots;

		int hash(std::string &key) const;
	};

}; 
