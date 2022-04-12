#ifndef NOBLE_H
#define NOBLE_H
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
	class Warrior;
	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& aNoble);
	public:
		Noble(const std::string& name);
		const std::string& getName() const;
		
		bool hire(Warrior& war);

		bool fire(Warrior& war);

		void removeWarrior(Warrior& war);

		bool battle(Noble& enemy);

	private:
		const std::string name;
		bool alive;
		std::vector<Warrior*> army;

		double getArmyStrength() const;

		void reduceStrength(double amount);

		void dies();
	};
}
#endif NOBLE_H
