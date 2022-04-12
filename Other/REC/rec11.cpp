// Andrea Morgan Stojanovski
// REC 11

#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
	virtual void makeSound() const = 0;
	virtual void normalPlay() const = 0;
}; // inst class

class MIL {
public:
	MIL() {}
	void receiveInstr(Instrument& inst) {
		inst.makeSound();
		if (instInInventory(inst)) {
			cerr << "Instrument in inventory\n";
			return;
		} // if
		for (size_t i = 0; i < inventory.size(); ++i) {
			if (!inventory[i]) { 
				inventory[i] = &inst; 
				return;
			} // if
		} // for
		inventory.push_back(&inst);
	} // void
	Instrument* loanOut() {
		for (size_t i = 0; i < inventory.size(); ++i) {
			if (inventory[i]) {
				Instrument* toLoan(inventory[i]);
				inventory[i] = nullptr;
				return toLoan;
			} // if
		} // for
		return nullptr;
	} // instr
	void dailyTestPlay() const {
		if (!hasInventory()) {
			cerr << "MIL has no instruments\n";
			return;
		} // if
		for (Instrument* currInst : inventory) {
			if (currInst) {
				currInst->makeSound();
			} // if
		} // for
	} //void

private:
	vector<Instrument*> inventory;
	bool instInInventory(Instrument& anInst) const {
		for (Instrument* instP : inventory) {
			if (instP == &anInst) { return true; }
		}
		return false;
	}
	bool hasInventory() const {
		if (inventory.size()) {
			for (Instrument* instP : inventory) {
				if (instP) { return true; }
			}
		}
		return false;
	}
};

class Musician {
public:
	Musician() : instr(nullptr) {}
	void acceptInstr(Instrument* instPtr) { instr = instPtr; }
	Instrument* giveBackInstr() {
		Instrument* result(instr);
		instr = nullptr;
		return result;
	}
	void testPlay() const {
		if (instr) instr->makeSound();
		else cerr << "have no instruments\n";
	}
	void normalPlay() const {
		if (instr) { instr->normalPlay(); }
	}
private:
	Instrument* instr;
};

class Orch {
public:
	void addPlayer(Musician& aMusician) {
		if (members.size() == 25) {
			cerr << "Orchestra member capacity reached\n";
			return;
		}
		if (musicianInOrch(aMusician)) {
			cerr << "Musician in orchestra\n";
			return;
		}
		members.push_back(&aMusician);

	}
	void play() const {
		for (Musician* memberP : members) {
			memberP->normalPlay();
		}
		cout << endl;
	}
private:
	vector<Musician*> members;
	bool musicianInOrch(Musician& aMusician) const {
		for (Musician* musP : members) {
			if (musP == &aMusician) { return true; }
		}
		return false;
	}
};

class Brass : public Instrument {
public:
	Brass(unsigned mpSize): mouthpieceSize(mpSize){}
	void makeSound() const {
		cout << "To make a sound.. blow on a mouthpiece of size "
			<< mouthpieceSize << endl;
	}
private:
	const unsigned mouthpieceSize;
};

class Trumpet : public Brass {
public:
	using Brass::Brass;
	void normalPlay() const { cout << "Toot"; }
};

class Trombone : public Brass {
public:
	using Brass::Brass;
	void normalPlay() const {cout << "Blat";}
};


class String : public Instrument {
public:
	String(unsigned pitch) : stringPitch(pitch) {}
	void makeSound() const {
		cout << "To make a sound... bow a string with pitch "
			<< stringPitch << endl;
	}
private:
	const unsigned stringPitch;
};

class Violin : public String {
public:
	using String::String;
	void normalPlay() const { cout << "Screech";}
};

class Cello : public String {
public:
	using String::String;
	void normalPlay() const { cout << "Squawk";}
};


class Percussion : public Instrument {
public:
	using Instrument::Instrument;
	void makeSound() const {
		cout << "To make a sound.. hit me!\n";
	}
};

class Cymbal : public Percussion {
public:
	using Percussion::Percussion;
	void normalPlay() const { cout << "Crash";}
};

class Drum : public Percussion {
public:
	using Percussion::Percussion;
	void normalPlay()  const {cout << "Boom";}
};

// PART ONE
// int main() {

	// cout << "Define some instruments ------------------------------------\n";
	// Drum drum;
	// Cello cello(673);
	// Cymbal cymbal;
	// Trombone tbone(4);
	// Trumpet trpt(12) ;
	// Violin violin(567) ;

	// use the debugger to look at the mill
	// cout << "Define the MILL --------------------------------------------\n";
	// MILL mill;

	// cout << "Put the instruments into the MILL --------------------------\n";
	// mill.receiveInstr(trpt);
	// mill.receiveInstr(violin);
	// mill.receiveInstr(tbone);
	// mill.receiveInstr(drum);
	// mill.receiveInstr(cello);
	// mill.receiveInstr(cymbal);

	// cout << "Daily test -------------------------------------------------\n"
	// 	<< "dailyTestPlay()" << endl;
	// mill.dailyTestPlay();
	// cout << endl;

	// cout << "Define some Musicians---------------------------------------\n";
	// Musician harpo;
	// Musician groucho;

	// cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
	// groucho.testPlay();	
	// cout << endl;
	// groucho.acceptInstr(mill.loanOut());
	// cout << endl;
	// groucho.testPlay();
	// cout << endl;
	// cout << "dailyTestPlay()" << endl;
	// mill.dailyTestPlay();

	// cout << endl << endl;

	// groucho.testPlay();	
	// cout << endl;
	// mill.receiveInstr(*groucho.giveBackInstr());
	// harpo.acceptInstr(mill.loanOut());
	// groucho.acceptInstr(mill.loanOut());
	// cout << endl;
	// groucho.testPlay();
	// cout << endl;
	// harpo.testPlay();
	// cout << endl;
	// cout << "dailyTestPlay()" << endl;
	// mill.dailyTestPlay();

	// cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";

	// // fifth
	// mill.receiveInstr(*groucho.giveBackInstr());
	// cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
	// mill.receiveInstr(*harpo.giveBackInstr());


	// cout << endl;
	// cout << "dailyTestPlay()" << endl;
	// mill.dailyTestPlay();
	// cout << endl;

	// cout << endl;
// }

// PART TWO
int main() {
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

} // main
