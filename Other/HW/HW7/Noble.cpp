//Andrea M. Stojanovski hw7
#include "Noble.h"
#include "Protector.h"

using namespace std;
namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Noble& rhs) {
		rhs.displayStrength(os);
		return os;
	}

	Noble::Noble(const string& name, double strength)
		: strength(strength), name(name) {};

	const string& Noble::getName() const { return name; }
	double Noble::getStrength() const { return strength; }
	void Noble::setStrength(double newStrength) { strength = newStrength; }

	void Noble::battle(Noble& enemy) {
		cout << name << " battles " << enemy.name << endl;

		if (this == &enemy) {
			cerr << name << " cannot fight himself\n";
			return;
		}
		if (strength < 0 && enemy.strength < 0) {
			cerr << "Oh, NO! They're both dead! Yuck!\n";
			return;
		} else if (strength < 0) {
			cerr << "He's dead " << enemy.name << endl;
			return;
		} else if (enemy.strength < 0) {
			cerr << "He's dead " << name << endl;
			return;
		}

		if (strength > enemy.strength) {
			winBattle(enemy.strength / strength);
			enemy.loseBattle();
			cout << name << " defeats " << enemy.name << endl;
		} else if (enemy.strength > strength) {
			enemy.winBattle(strength / enemy.strength);
			loseBattle();
			cout << "Ugh!\n" << enemy.name << " defeats " << name << endl;
		} else {
			loseBattle();
			enemy.loseBattle();
			cout << "Mutual Annihilation: " << name << " and "
				<< enemy.name << " die at each other's hands\n";
		}
	}


	void PersonWithStrengthToFight::winBattle(double amount) {
		double strength = getStrength();
		strength -= (strength * amount);
		setStrength(strength);
	}
	void PersonWithStrengthToFight::loseBattle() {
		setStrength(-1);
	}
	void PersonWithStrengthToFight::displayStrength(ostream& os) const {
		os << getName();
		if (getStrength() < 0) { os << "is dead\n"; }
		else { os << "'s strength is " << getStrength() << endl; }
	}

	bool Lord::hires(Protector& protec) {
		if (getStrength() < 0) {
			cerr << getName() << " cannot hire warriors because he is dead\n";
			return false;
		}
		if (protec.setBoss(this)) {
			army.push_back(&protec);
			setStrength(getStrength() + protec.getStrength());
			return true;
		}
		return false;
	}

	bool Lord::fires(Protector& protec){
		if (getStrength() < 0) {
			cerr << getName() << " cannot fire warriors because he is dead\n";
			return false;
		}
		if (!army.size()) {
			cerr << getName() << " has not hired any warriors\n";
			return false;
		}
		if (!removeProtector(&protec)) { return false; }
		cout << "You don't work for me anymore, " << protec.getName() << "! -- "
			<< getName() << endl;
		return true;
	}

	bool Lord::removeProtector(Protector* protecP) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == protecP) {
				army[i] = nullptr;
				if (!protecP->removeBoss(this)) {
					return false;
				}
				for (size_t j = i + 1; j < army.size(); ++j) {
					army[j - 1] = army[j];
					army[j] = nullptr;
				}
				army.pop_back();
				setStrength(getStrength() - protecP->getStrength());
				return true;
			}
		}
		cerr << protecP->getName() << " is not in " << getName() << "'s army\n";
		return false;
	}

	void Lord::winBattle(double amount) {
		double newStrength = 0;
		for (Protector* protec : army) {
			protec->defend(amount);
			newStrength += protec->getStrength();
		}
		setStrength(newStrength);
	}

	void Lord::loseBattle() {
		for (Protector* protec : army) {
			protec->defend(-1);
		}
		setStrength(-1);
	}

	void Lord::displayStrength(ostream& os) const {
		os << getName();
		if (!army.size()) { cout << " has no army\n"; }
		else {
			os << ": " << endl;
			for (const Protector* protec : army) {
				os << "\t" << *protec;
			}
		}
	}
}