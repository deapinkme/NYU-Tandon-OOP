// Andrea M. Stojanovski hw7

#include "Protector.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Protector& rhs) {
		os << rhs.name << ", strength: " << rhs.strength << endl;
		return os;
	}

	Protector::Protector(const string& name, double strength)
		: name(name), strength(strength), bossP(nullptr) {}

	double Protector::getStrength() const { return strength; }

	const string& Protector::getName() const { return name; }

	const string& Protector::getBossName() const { return bossP->getName(); }

	bool Protector::setBoss(Lord* lordP) {
		if (strength < 0) {
			cerr << name << " is dead\n";
			return false;
		}
		if (bossP) {
			cerr << name << " already has a boss\n";
			return false;
		}
		bossP = lordP;
		return true;
	}
	
	bool Protector::removeBoss(Lord* lordP) { 
		if (!bossP) {
			cout << name << " does not have a boss\n";
			return false;
		}
		if (lordP != bossP) {
			cout << lordP->getName() << "is not " << name << "'s boss\n";
			return false;
		}
		bossP = nullptr;	
		return true;
	}

	bool Protector::runaway() {
		if (strength < 0) {
			cout << name << " cannot runaway because he is dead\n";
			return false;
		}
		if (!bossP) {
			cout << name << " does not have a boss to runaway from\n";
			return false; 
		}
		cout << name << " flees in terror, abandoning their lord, "
			<< bossP->getName() << endl;
		bossP->removeProtector(this); 
		return true;
	}
	
	void Protector::defend(double amount) {
		if (strength < 0) { return; }
		fightingWords();
		if (amount < 0) {
			strength = -1;
		} else {
			strength -= (strength * amount);
		}
	}

	void Wizard::fightingWords() const { cout << "POOF!\n"; }

	void Warrior::fightingWords() const {
		cout << getName() << " says: Take that in the name of my lord, "
			<< getBossName() << endl;

	}

	void Archer::fightingWords() const { 
		cout << "TWANG! ";
		Warrior::fightingWords();
	}

	void Swordsman::fightingWords() const { 
		cout << "CLANG! ";
		Warrior::fightingWords();
	}
}