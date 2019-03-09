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

		std::vector<Slot> m_slots;

		int hash(std::string &key, int i) const;

		static void checkKey(std::string &key);
	};

}; 
