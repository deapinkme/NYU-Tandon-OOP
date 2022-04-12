#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
using namespace std;

namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Warrior& aWar) {
		os << "Warrior: " << aWar.name << ", Strength: " <<
			aWar.strength << ", Boss: ";
		if (!aWar.bossP) {
			os << "None\n";
		} else {
			os << aWar.bossP->getName() << endl;
		}
		return os;
	}

	Warrior::Warrior(const string& name, double strength)
		: name(name), strength(strength), bossP(nullptr) {}
	const string& Warrior::getName() const { return name; }
	const double& Warrior::getStrength() const { return strength; }
	const Noble* Warrior::getBoss() const { return bossP; }

	void Warrior::setBoss(Noble* aNoble) {
		bossP = aNoble;
	}

	void Warrior::removeBoss() {
		bossP = nullptr;
	}

	bool Warrior::runaway() {
		if (!bossP) {
			cerr << name << " does not have a boss to run away from\n";
			return false;
		}
		cout << name << " flees in terror, abandoning his lord, "
			<< bossP->getName() << endl;
		bossP->removeWarrior(*this);
		return true;
	}

	void Warrior::reduceStrength(double amount) {
		strength -= (strength * amount);
	}
	void Warrior::dies() {
		strength = -1;
	}
}