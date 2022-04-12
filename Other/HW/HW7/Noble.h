// Andrea M. Stojanovski

#ifndef NOBLE_H
#define NOBLE_H	
#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft {
	class Protector;

	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);

	public:
		Noble(const std::string& name, double strength=0);
		const std::string& getName() const;

		void battle(Noble& enemy);

	protected:
		double getStrength() const;		
		void setStrength(double newStrength);

	private:
		double strength;
		std::string name;

		virtual void winBattle(double amount) = 0;
		virtual void loseBattle() = 0;
		virtual void displayStrength(std::ostream& os) const = 0;
	};

	class PersonWithStrengthToFight: public Noble {
	public:
		using Noble::Noble;
	private:
		void winBattle(double amount);

		void loseBattle();

		void displayStrength(std::ostream& os = std::cout) const;
	};
	
	class Lord : public Noble {
	public:
		using Noble::Noble;

		bool hires(Protector& protec);
		bool fires(Protector& protec);
		bool removeProtector(Protector* protecP);


	private:
		std::vector<Protector*> army;

		void winBattle(double amount);
		void loseBattle();
		void displayStrength(std::ostream& os = std::cout) const;

	};
}

#endif 