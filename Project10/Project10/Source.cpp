#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include "Klasy.h"
using namespace std;
void GAME();
void fight(Character&, Enemy&);
void atak1(Character&, Enemy&);
void atak2(Character&, Enemy&);
int main()
{
	srand(time(NULL) * 1010);
	while (1)
	{
		cout << "Lets play a game? Choose whise!\n"
			<< "1. Start New Game\n"
			<< "2. Show last player score\n"
			<< "3. EXIT :( \n";
		int a = 0;
		cin >> a;
		while (a > 3)
		{
			cout << "wrong number! \n";
			cin >> a;
			cout << "\n\n";
		}
		switch (a)
		{
		case 1:
			system("cls");
			GAME();
			break;
		case 2:
		{
			fstream plik;
			plik.open("score.txt", ios::in | ios::out);
			if (plik.good() == true)
			{
				string dane;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				getline(plik, dane);
				cout << dane << endl;
				plik.close();
			}
			else
			{
				cout << "blad otwarcia pliku!\n";
			}
			break;
		}
		case 3:
			system("cls");
			break;
		}
		if (a == 3)
			break;
	}
	system("pause");
	return 0;
}
void GAME()
{
	cout << "Set player name.: ";
	string a;
	cin >> a;
	Character A;
	A.setName(a);
	system("cls");
	while (A.getLife() > 0)
	{
		Enemy B;
		fight(A, B);
	}
	system("cls");
	cout << A;
	cout << endl;
	//zapis do pliku	
	fstream plik;
	plik.open("score.txt", ios::out);
	if (plik.good() == true)
	{

		plik << "Gracz.: " << A.getName() << endl
			<< "Obrona.: " << A.getArmor() << endl
			<< "Obrazenia.: " << A.getDamage1() << " - " << A.getDamage2() << endl
			<< "poziom postaci " << A.LevelOfCharacter << endl
			<< "aktualny poziom gry.: " << A.Level << endl
			<< "doswiadczenie .: " << A.Experience << endl;
		plik.close();
	}
	else
	{
		cout << "blad otwarcia pliku!\n";
	}
}
void fight(Character &A, Enemy &B)
{
	while ((A.getLife() > 0) && (B.getLife() > 0))
	{
		cout << A;
		cout << endl;
		cout << B;
		atak1(A, B);
		if (A.getLife() != 0)
		{
			if (B.getLife() == 0)
			{
				system("pause");
			}
			else
			{
				atak2(A, B);
			}
		}
		if (B.getLife() == 0)
		{
			A.NextLvl();
		}
		cout << endl;
		system("cls");
	}
}
void atak1(Character &A, Enemy &B)
{
	cout << "\n\nChoose one of 3 attack, or healing.:\n\n";
	Attack T[3];
	int H = ((rand() % 80) + 1);
	cout << "1. " << T[0].Name << "\t" << T[0].Power << "  % dmg\n";
	cout << "2. " << T[1].Name << "\t" << T[1].Power << "  % dmg\n";
	cout << "3. " << T[2].Name << "\t" << T[2].Power << "  % dmg\n";
	cout << "4. " << "Healing" << " + " << H << " HP\n";
	cout << "5. " << "Leave" << " Cry a river\n";
	cout << "wybieram.: ";
	int a = 10;
	while (a > 5)
	{
		cin >> a;
	}
	if (a < 4)
	{
		int b = (A.getDamage2() - A.getDamage1());
		int dmg = ((rand() % b) + A.getDamage1());
		int x = ((dmg * T[a - 1].Power) / B.getArmor());
		int restoflife = B.getLife() - x;
		if (restoflife < 0)
		{
			restoflife = 0;
		}
		cout << "\n" << A.getName() << " used " << T[a - 1].Name << " Power, and dealt " << dmg*T[a - 1].Power << " dmg\n";
		cout << "Enemy Life " << B.getLife() << " - " << x << " = " << restoflife << endl;
		B.setLife((B.getLife() - ((dmg * T[a - 1].Power) / B.getArmor())));
	}
	else if (a == 4)
	{
		system("cls");
		cout << "\n" << A.getName() << " used Healing, + " << H << " HP\n";
		cout << A.getName() << " Life " << A.getLife() << " + " << H << " = " << A.getLife() + H << endl << endl
			;
		A.setLife(A.getLife() + H);
		A.wypisz();
	}
	else
	{
		A.setLife(0);
	}
	if (B.getLife() < 0)
	{
		B.setLife(0);
	}
}
void atak2(Character &A, Enemy &B)
{
	Attack T[3];
	int a = ((rand() % 3) + 0);
	int b = (B.getDamage2() - B.getDamage1());
	int dmg = ((rand() % b) + B.getDamage1());
	int x = ((dmg * T[a].Power) / A.getArmor());
	cout << "\n" << B.getName() << " used " << T[a].Name << " Power, and dealt " << dmg*T[a].Power << " dmg\n";
	cout << A.getName() << " Life " << A.getLife() << " - " << x << " = " << A.getLife() - x << endl;

	A.setLife((A.getLife() - ((dmg * T[a].Power) / A.getArmor())));
	if (A.getLife() < 0)
	{
		A.setLife(0);
	}
	cout << endl;
	system("pause");
}