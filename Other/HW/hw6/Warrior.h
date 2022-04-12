#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include <string>

namespace WarriorCraft {
	class Noble;
	class Warrior {
		friend std::ostream& operator<<(std::ostream& os, const Warrior& aWar);
	public:
		Warrior(const std::string& name, double strength);
		const std::string& getName() const;
		const double& getStrength() const;
		const Noble* getBoss() const;

		void setBoss(Noble* aNoble);
		void removeBoss();

		bool runaway();

		void reduceStrength(double amount);
		void dies();

	private:
		const std::string name;
		double strength;
		Noble* bossP;
	};
}

#endif WARRIOR_H