#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Noble& aNoble) {
		os << aNoble.name;
		if (!aNoble.army.size()) {
			os << " has no army\n";
		} else {
			os << " has an army of " << aNoble.army.size() << endl;
			for (size_t i = 0; i < aNoble.army.size(); ++i) {
				os << "\t" << aNoble.army[i]->getName() << ": " <<
					aNoble.army[i]->getStrength() << endl;
			}
		}
		return os;
	}

	Noble::Noble(const string& name) : name(name), alive(true) {}
	const string& Noble::getName() const { return name; }

	bool Noble::hire(Warrior& war) {
		if (!alive) {
			cerr << name << " cannot hire warriors because he is dead\n";
			return false;
		}
		if (war.getBoss()) {
			cerr << war.getName() << " already works for "
				<< war.getBoss()->getName() << endl;
			return false;
		war.setBoss(this);
		army.push_back(&war);
		return true;
	}

	bool Noble::fire(Warrior& war) {
		if (!alive) {
			cerr << name << " cannot fire warriors because he is dead\n";
			return false;
		}
		if (!army.size()) {
			cerr << name << " has not hired any warriors\n";
			return false;
		}
		if (war.getBoss() != this){
			cerr << war.getName() << " does not work for " << name << endl;
			return false;
		}
		removeWarrior(war);
		cout << "You don't work for me anymore, " << war.getName() << "! -- "
			<< name << endl;
		return true;
	}

	void Noble::removeWarrior(Warrior& war) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &war) {
				army[i] = nullptr;
				for (size_t j = i + 1; j < army.size(); ++j) {
					army[j - 1] = army[j];
					army[j] = nullptr;
				}
				army.pop_back();
				war.removeBoss();
				return;
			}
		}
		cerr << war.getName() << " is not in " << name << "'s army\n";
	}

	bool Noble::battle(Noble& enemy) {
		cout << name << " battles " << enemy.name << endl;
		if (this == &enemy) {
			cerr << name << " cannot fight himself\n";
			return false;
		}
		if (!alive && !enemy.alive) {
			cerr << "Oh, NO! They're both dead! Yuck!\n";
			return false;
		} else if (!alive) {
			cerr << "He's dead, " << enemy.name << endl;
			return false;
		} else if (!enemy.alive) {
			cerr << "He's dead, " << name << endl;
			return false;
		}

		double strength = getArmyStrength();
		double enemyStrength = enemy.getArmyStrength();

		if (strength > enemyStrength) {
			reduceStrength(enemyStrength / strength);
			enemy.dies();
			cout << name << " defeats " << enemy.name << endl;
		} else if (enemyStrength > strength) {
			enemy.reduceStrength(strength / enemyStrength);
			dies();
			cout << enemy.name << " defeats " << name << endl;
		} else {
			dies();
			enemy.dies();
			cout << "Mutual Annihilation: " << name << " and "
				<< enemy.name << " die at each other's hands\n";
		}
		return true;
	}
	
	double Noble::getArmyStrength() const {
		if (!alive) { return -1; }
		double totalStrength = 0;
		for (const Warrior* warP : army) {
			totalStrength += warP->getStrength();
		}
		return totalStrength;
	}

	void Noble::reduceStrength(double amount) {
		for (Warrior* warP : army) {
			warP->reduceStrength(amount);
		}
	}

	void Noble::dies() {
		alive = false;
		for (Warrior* warP : army) {
			warP->dies();
		}
	}
}