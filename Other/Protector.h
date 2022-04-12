// Andrea Morgan Stojanovski
// Homework 7

#ifndef PROTECTOR_H
#define PROTECTOR_H
#include <string>
#include <iostream>

namespace WarriorCraft {
	class Lord;

	class Protector {
		friend std::ostream& operator<<(std::ostream& os, const Protector& rhs); // display
	public:
		Protector(const std::string& name, double strength);
		double getStrength() const;
		const std::string& getName() const;
		void defend(double amount); // includes cerr
		bool setBoss(Lord* lordP); // includes cerr
		bool removeBoss(Lord* lordP); // includes cerr
		bool runaway(); // includes cerr

	protected:
		const std::string& getBossName() const;
	private:
		double strength;
		std::string name;
		Lord* bossP;
		virtual void fightingWords() const = 0;
	}; // class

	class Wizard : public Protector {
	public:
		using Protector::Protector;

	private:
		void fightingWords() const;
	}; // class

	class Warrior : public Protector {
	public:
		using Protector::Protector;
		void fightingWords() const;
	private:
	}; // class

	class Archer : public Warrior {
	public:
		using Warrior::Warrior;
	private:
		void fightingWords() const;
	}; //class

	class Swordsman : public Warrior {
	public:
		using Warrior::Warrior;
	private:
		void fightingWords() const;
	}; //class
} // namespace

#endif
