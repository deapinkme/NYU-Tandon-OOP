/Andrea M. Stojanovski HW7

#ifndef PROTECTOR_H
#define PROTECTOR_H
#include <string>
#include <iostream>

namespace WarriorCraft {
	class Lord;

	class Protector {
		friend std::ostream& operator<<(std::ostream& os, const Protector& rhs);
	public:
		Protector(const std::string& name, double strength);
		double getStrength() const;
		const std::string& getName() const;
		
		void defend(double amount);

		bool setBoss(Lord* lordP);

		bool removeBoss(Lord* lordP);

		bool runaway();

	protected:
		const std::string& getBossName() const;
	private:
		double strength;
		std::string name;
		Lord* bossP;

		virtual void fightingWords() const = 0;
	};

	class Wizard : public Protector {
	public:
		using Protector::Protector;

	private:
		void fightingWords() const;
	};

	class Warrior : public Protector {
	public:
		using Protector::Protector;
		void fightingWords() const;
	private:
	};

	class Archer : public Warrior {
	public:
		using Warrior::Warrior;
	private:
		void fightingWords() const;
	};

	class Swordsman : public Warrior {
	public:
		using Warrior::Warrior;
	private:
		void fightingWords() const;
	};
}

#endif
