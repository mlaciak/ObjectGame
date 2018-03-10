#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
	static int ID;
	int IID;
	string Name;
	int Life;
	int Damage1, Damage2;
	int Armor;

public:
	int getDamage1() const
	{
		return Damage1;
	}
	void setDamege1(int a)
	{
		Damage1 = a;
	}
	int getDamage2() const
	{
		return Damage2;
	}
	void setDamege2(int a)
	{
		Damage2 = a;
	}
	int getArmor() const
	{
		return Armor;
	}
	void setArmor(int a)
	{
		Armor = a;
	}
	static int getID()
	{
		return ID;
	}
	int getIID()
	{
		return IID;
	}
	int getLife() const
	{
		return Life;
	}
	string getName() const
	{
		return Name;
	}
	void setID()
	{
		ID++;
	}
	void setIID(int a = getID())
	{
		IID = a;
	}
	void setLife(int a)
	{
		Life = a;
	}
	void setName(string a)
	{
		Name = a;
	}
	virtual ~Person() {}
};
int Person::ID = 0;

class Character
	:public Person
{
public:
	friend	ostream& operator<< (ostream &wyjscie, const Character & x);
	int LevelOfCharacter;
	int Level;
	int Experience;
	int NL; // NEXT LEVEL EXPERIENCE
public:
	Character()
	{
		setID();
		setIID(getID());
		setName("Player One");
		setArmor(100);
		setDamege1(15);
		setDamege2(23);
		LevelOfCharacter = 1;
		setLife(400 + 3 * LevelOfCharacter);
		Level = 1;
		Experience = 1;
		NL = 10;
	}
	Character(string name, int life, int armor, int damage, int loc, int lvl, int exp, int ne)
	{
		setID();
		setIID(getID());
		setName(name);
		setLife(life);
		setArmor(armor);
		setDamege1(damage);
		setDamege2(damage + 3);
		LevelOfCharacter = loc;
		Level = lvl;
		Experience = exp;
		NL = ne;
	}
	Character(Character &w)
	{
		setID();
		setIID(getID());
		setName(w.getName());
		setLife(w.getLife());
		setArmor(w.getArmor());
		setDamege1(w.getDamage1());
		setDamege2(w.getDamage2());
		LevelOfCharacter = w.LevelOfCharacter;
		Level = w.Level;
		Experience = w.Experience;
		NL = w.NL;
	}
	void NextLvl()
	{
		Experience++;
		if (Experience == NL)
		{
			setLevelOfCharacter(LevelOfCharacter + 1);
		}
	}
	void setLevelOfCharacter(int a)
	{
		LevelOfCharacter = a;
		setLife(getLife() + 30 * a);
		setDamege1(getDamage1() + getDamage1()*a);
		setDamege2(getDamage1() + 5);
		setArmor(getArmor() + 10 * a);
		NL = a * 15;
	}
	void wypisz()
	{
		cout << "Gracz.: " << getName() << endl
			<< "Zycie.: " << getLife() << endl
			<< "Obrona.: " << getArmor() << endl
			<< "Obrazenia.: " << getDamage1() << " - " << getDamage2() << endl
			<< "poziom postaci " << LevelOfCharacter << endl
			<< "aktualny poziom gry.: " << Level << endl
			<< "doswiadczenie .: " << Experience << endl;
	}
	int getLevel()
	{
		return Level;
	}
	~Character()
	{
		setIID(getIID() - 1);
	}
};
ostream& operator<< (ostream &wyjscie, const Character & x)
{
	wyjscie << "Gracz.: " << x.getName() << endl
		<< "Zycie.: " << x.getLife() << endl
		<< "Obrona.: " << x.getArmor() << endl
		<< "Obrazenia.: " << x.getDamage1() << " - " << x.getDamage2() << endl
		<< "poziom postaci " << x.LevelOfCharacter << endl
		<< "aktualny poziom gry.: " << x.Level << endl
		<< "doswiadczenie .: " << x.Experience << " / " << x.NL << endl;
	return wyjscie;
}
class Enemy
	:public Person
{
public:
	friend ostream& operator<< (ostream &wyjscie, const Enemy & x);
	Enemy()
	{
		setID();
		setIID(getID());
		setName("Sesyja");
		setArmor(100);
		setDamege1(10);
		setDamege2(33);
		setLife(400);
	}
	Enemy(string name, int armor, int damage, int life)
	{
		setID();
		setIID(getID());
		setName("Sesyja");
		setArmor(armor);
		setDamege1(damage);
		setDamege2(getDamage1() + 3);
		setLife(life);
	}
	~Enemy() {}
	void wypisz()
	{
		cout << "Przeciwnik.: " << getName() << endl
			<< "Zycie.: " << getLife() << endl
			<< "Obrona.: " << getArmor() << endl
			<< "Obrazenia.: " << getDamage1() << " - " << getDamage2() << endl;
	}
	void Levelup(int a)
	{
		setLife(getLife() + 3 * a);
		setDamege1(getDamage1() + getDamage1()*a);
		setDamege2(getDamage1() + 5);
		setArmor(getArmor() + getArmor()*a);
	}
};
ostream& operator<< (ostream &wyjscie, const Enemy & x)
{
	wyjscie << "Przeciwnik.: " << x.getName() << endl
		<< "Zycie.: " << x.getLife() << endl
		<< "Obrona.: " << x.getArmor() << endl
		<< "Obrazenia.: " << x.getDamage1() << " - " << x.getDamage2() << endl;
	return wyjscie;

}
class NamesOfAttacks
{
public:
	string N[10];
	NamesOfAttacks()
	{
		N[0] = "Blade Burner";
		N[1] = "Charged Seed";
		N[2] = "Photon Glare";
		N[3] = "Rapid   Soul";
		N[4] = "Shootin Cort";
		N[5] = "Brain Wizard";
		N[6] = "Ripping  Orb";
		N[7] = "Hyper Cutter";
		N[8] = "Dyna Inferno";
		N[9] = "Devil   Ways";
	}
};
class Attack
	:public NamesOfAttacks
{
public:
	string Name;
	int Power;
	Attack()
	{
		int a = ((rand() % 10) + 0);
		Name = N[a];
		Power = ((rand() % 70) + 30);
	}
};