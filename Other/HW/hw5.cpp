// Andrea M. Stojanovski

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Warrior {
	friend ostream&operator<<(ostream& os, const Warrior& war) {
		os << war.name << ": " << war.strength;
		return os;
	}
public:
	Warrior(const string& name, double strength)
		: name(name), strength(strength), hasAJob(false) {
	}
	const string& getName() const { return name; }
	double getStrength() const { return strength; }
	bool hasJob() const { return hasAJob; }

	void changeStrength(double amount) {
		strength -= (strength * amount);
	}

	void dies() {
		strength = 0;
	}

	void hired() {
		hasAJob = true;
	}

	void fired() {
		hasAJob = false;
	}
private:
	string name;
	double strength;
	bool hasAJob;

};

class Noble {
	friend ostream& operator<<(ostream& os, const Noble& noble) {
		os << noble.name << " has an army of " << noble.army.size() << endl;
		for (const Warrior* warP : noble.army) {
			os << "\t" << *warP << endl;
		}
		return os;
	}
public:
	Noble(const string& name) : name(name), alive(true) {}
	const string& getName() const { return name; }
	bool hire(Warrior* warP) {
		if (!alive) {
			cerr << name << " is already dead\n";
			return false;
		}
		if (warP->hasJob()) {
			cerr << warP->getName() << " already has a job\n";
			return false;
		}
		army.push_back(warP);
		warP->hired();
		return true;
	}
	bool fire(Warrior* warP) {

		if (!alive) {
			cerr << name << " and his warriors are already dead\n";
			return false;
		}
		if (army.size() == 0) {
			cerr << name << " has not hired any warriors\n";
			return false;
		}
		if (!warP->hasJob()) {
			cerr << warP->getName() << " does not have a job\n";
			return false;
		}

		size_t ind;
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == warP) {
				ind = i;
				break;
			}
			if (i == (army.size() - 1) && army[i] != warP) {
				cerr << "A warrior named " << warP->getName() << " is not in " <<
					name << "'s army\n";
				return false;
			}
		}
		cout << "You don't work for me anymore " << warP->getName()
			<< "! -- " << name << endl;
		warP->fired();

		for (size_t i = ind; i < army.size(); ++i) {
			if (army[i] == warP) {
				army[i] = nullptr;
			}
			else if (i > 0 && !army[i - 1]) {
				army[i - 1] = army[i];
				army[i] = nullptr;
			}
			if (i == (army.size() - 1) && !army[i]) {
				army.pop_back();
			}
		}
		return true;
	}

	bool battle(Noble* enemyP) {

		cout << name << " battles " << enemyP->name << endl;
		if (this == enemyP) {
			cerr << name << " cannot battle himself\n";
			return false;
		}
		if (!alive && !enemyP->alive) {
			cerr << "Oh, NO! They're both dead! Yuck!\n";
			return false;
		} else if (!alive) {
			cerr << "He's dead, " << enemyP->name << endl;
			return false;
		} else if (!enemyP->alive) {
			cerr << "He's dead, " << name << endl;
			return false;
		}

		double strength = this->getArmyStrength();
		double enemyStrength = enemyP->getArmyStrength();

		if (strength > enemyStrength) {
			reduceStrength(enemyStrength / strength);
			enemyP->dies();
			cout << name << " defeats " << enemyP->name << endl;
		} else if (enemyStrength > strength) {
			enemyP->reduceStrength(strength / enemyStrength);
			dies();
			cout << enemyP->name << " defeats " << name << endl;
		} else {
			dies();
			enemyP->dies();
			cout << "Mutual Annihilation: " << name << " and "
				<< enemyP->name << " die at each other's hands\n";
		}
		return true;
	}
private:
	string name;
	bool alive;
	vector<Warrior*> army;

	double getArmyStrength() const {
		if (!alive) {
			return 0;
		}
		double totalStrength = 0;
		for (const Warrior* warP : army) {
			totalStrength += warP->getStrength();
		}
		return totalStrength;
	}

	void reduceStrength(double amount) {
		for (Warrior* warP : army) {
			warP->changeStrength(amount);
		}
	}
	void dies() {
		alive = false;
		for (Warrior* warP : army) {
			warP->dies();
		}
	}

};


Noble* getNoble(const string& name, const vector<Noble*>& nobles);
Warrior* getWarrior(const string& name, const vector<Warrior*>& wars);
bool createNoble(ifstream& warFile, vector<Noble*>& nobles);
bool createWarrior(ifstream& warFile, vector<Warrior*>& wars);
void clear(vector<Noble*>& nobles, vector<Warrior*>& wars);
void status(const vector<Noble*>& nobles, const vector<Warrior*>& wars);
bool hire(ifstream& warFile, vector<Noble*>& nobles, vector<Warrior*>& wars);
bool fire(ifstream& warFile, vector<Noble*>& nobles, vector<Warrior*>& wars);
bool battle(ifstream& warFile, vector<Noble*>& nobles);

int main() {
	vector<Noble*> nobles;
	vector<Warrior*> warriors;
	ifstream warriorFile("nobleWarriors.txt");
	if (!warriorFile) {
		cerr << "Could not open file.";
		exit(1);
	}
	string command;
	while (warriorFile >> command) {
		if (command == "Status") {
			status(nobles, warriors);
		} else if (command == "Clear") {
			clear(nobles, warriors);
		} else if (command == "Warrior") {
			createWarrior(warriorFile, warriors);
		} else if (command == "Noble") {
			createNoble(warriorFile, nobles);
		} else if (command == "Fire") {
			fire(warriorFile, nobles, warriors);
		} else if (command == "Hire") {
			hire(warriorFile, nobles, warriors);
		} else if (command == "Battle") {
			battle(warriorFile, nobles);
		}
	}

	warriorFile.close();
}

Noble* getNoble(const string& name, const vector<Noble*>& nobles) {
	for (Noble* nobleP : nobles) {
		if (nobleP->getName() == name) {
			return nobleP;
		}
	}
	return nullptr;
}

Warrior* getWarrior(const string& name, const vector<Warrior*>& wars) {

	for (size_t i = 0; i < wars.size(); ++i) {
		if (wars[i]->getName() == name) {
			return wars[i];
		}
	}

	return nullptr;
}

bool createNoble(ifstream& warFile, vector<Noble*>& nobles){
	string name;
	warFile >> name;

	if (getNoble(name, nobles)) {
		cerr << "A noble named " << name << " already exists\n";
		return false;
	}
	Noble* nobleP = new Noble(name);
	nobles.push_back(nobleP);
	return true;
}

bool createWarrior(ifstream& warFile, vector<Warrior*>& wars) {
	string name;
	double strength;
	warFile >> name >> strength;

	if (getWarrior(name, wars)) {
		cerr << "A warrior named " << name << " already exists\n";
		return false;
	}
	Warrior* warP = new Warrior(name, strength);
	wars.push_back(warP);
	return true;
}

void clear(vector<Noble*>& nobles, vector<Warrior*>& wars) {
	for (size_t i = 0; i < nobles.size(); ++i) {
		delete nobles[i];
		nobles[i] = nullptr;
	}
	nobles.clear();

	for (size_t i = 0; i < wars.size(); ++i) {
		delete wars[i];
		wars[i] = nullptr;
	}
	wars.clear();
}

void status(const vector<Noble*>& nobles, const vector<Warrior*>& wars) {
	cout << "Status\n" << "=====\n" << "Nobles:\n";
	for (Noble* nobleP : nobles) {
		cout << *nobleP;
	}
	if (nobles.size() == 0) {
		cout << "NONE\n";
	}
	cout << "Unemployed Warriors:\n";
	int joblessWarsCount = 0;
	for (Warrior* warP : wars) {
		if (!warP->hasJob()) {
			cout << *warP << endl;
			++joblessWarsCount;
		}
	}
	if (joblessWarsCount == 0) {
		cout << "NONE\n";
	}

}
bool hire(ifstream& warFile, vector<Noble*>& nobles, vector<Warrior*>& wars) {
	string nobleName, warName;
	warFile >> nobleName >> warName;
	Noble* nobleP = getNoble(nobleName, nobles);
	Warrior* warP = getWarrior(warName, wars);

	if (!nobleP) { 
		cerr << "A noble named " << nobleName << " does not exist\n";
		return false;
	}
	if (!warP) {
		cerr << "A warrior named " << warName << " does not exist\n";
		return false;
	}
	return nobleP->hire(warP);
}

bool fire(ifstream& warFile, vector<Noble*>& nobles, vector<Warrior*>& wars) {
	string nobleName, warName;
	warFile >> nobleName >> warName;
	Noble* nobleP = getNoble(nobleName, nobles);
	Warrior* warP = getWarrior(warName, wars);

	if (!nobleP) {
		cerr << "A noble named " << nobleName << " does not exist\n";
		return false;
	}
	if (!warP) {
		cerr << "A warrior named " << warName << " does not exist\n";
		return false;
	}
	return nobleP->fire(warP);
}
bool battle(ifstream& warFile, vector<Noble*>& nobles) {
	string nobleOneName, nobleTwoName;
	warFile >> nobleOneName >> nobleTwoName;
	Noble* nobleOneP = getNoble(nobleOneName, nobles);
	Noble* nobleTwoP = getNoble(nobleTwoName, nobles);
	return nobleOneP->battle(nobleTwoP);
}
