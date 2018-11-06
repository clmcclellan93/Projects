#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int roll() {
	int num;
	srand (time(0));
	num = rand() % 100 + 1;

 	return num;
}

int attackRoll(int str, int acc) {
	int num;
	srand (time(0));
	num = rand() % (100 / acc) + str + 1;
	
	return num; //TODO: implement as part of hero class?
}

class Hero {
public: 
Hero() {
	maxHealth = 20;
	health = maxHealth;
	strength = 10;
	accuracy = 10;
	defence = 10;
	dodge = 10;
	exp = 0;
	level = 1;
	alive = true;
}

int getHealth();
bool isAlive();
void heal();
void damage(int);
void attack();
void gainXp(int);
void levelUp();

private:
int maxHealth;
int health;
int strength;
int accuracy;
int defence;
int dodge;
int exp;
int level;
bool alive;

};

class Monster {
public:
Monster() {
	health = 100;
	alive = true;
}
int getHealth();
bool isAlive();
void damage(int);
void attack();

private:
bool alive;
int health;
int strength;
int accuracy;
int defence;
int dodge;

};

Hero Party [3];
Monster Encounter [5]; //TODO: add the heroes and monsters to their arrays

Hero hero;
Monster monster;

int main() {
	// hero.getHealth();
	// hero.heal();
	// monster.getHealth();
	// hero.attack();
	// monster.getHealth();

	while (monster.isAlive() && hero.isAlive()) {
		cout << "Attack!" << endl;
		hero.attack();
		// monster.getHealth();
		cout << "The monster's health is now " << monster.getHealth() << endl;
		if (monster.getHealth() <= 0) {
			cout << "You win!" << endl;
			hero.gainXp(1500);
		//	hero.levelUp();
		}
		else if (hero.getHealth() <= 0) cout << "GAME OVER" << endl;
		}
		
}

int Hero::getHealth() {
	return health;
}

void Hero::heal() {
	if (health <= maxHealth) {
		health += roll();
		if (health > maxHealth) {
			health = maxHealth;
		}
	}
	Hero::getHealth();
}

void Hero::damage(int dam) {
	if (roll() < dodge) dam = 0;
	else {
		dam -= defence;
	}
	health -= dam;
	if (health <= 0) alive = false;
}

void Hero::attack() {
	// int num = attackRoll(strength, accuracy); //TODO: figure out how to attack different mosnsters, case statement perhaps?
	monster.damage(attackRoll(strength, accuracy));
}

void Hero::levelUp() {
	if (exp >= (level * 1000)) {
		maxHealth += level * 10;
		health = maxHealth;
		exp -= (level * 1000);
		level += 1;
		cout << maxHealth << " " << level << " " << exp << endl;
	}
}

void Hero::gainXp(int xp) {
	exp += xp;
	cout << "Exp: " << exp << endl;
	this->levelUp();
}

bool Hero::isAlive() {
	return alive;
}

void Monster::damage(int dam) {
	health -= dam;
	if (health <= 0) alive = false;
}

int Monster::getHealth() {
	return health;
}

bool Monster::isAlive() {
	return alive;
}