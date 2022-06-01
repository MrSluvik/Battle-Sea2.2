#pragma once
#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;

class Player
{
private:
	int x;
	int y;
	char ch;
public:
	Player() { x = 1; y = 1; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	char getCh() { return this->ch; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setCh(char ch) { this->ch = ch; }
};

class Pole {
private:
	int n;
	int m;
	char** matrix;
public:
	Pole(void);
	void printPole(Player& player);//друк пол€ п≥д час розтановки карабл≥в
	void printPole(int, int, char);//друк пол€ п≥д час руху по ньому

	void printPoleGame(Player& players, Pole& poles);//друк пол€ бою дл€ першого гравц€
	void printPoleGames(Player& playerq, Pole& poleq);	//друк пол€ бою дл€ другого гравц€	

	bool getAmount();//метод перев≥рки к≥лькост≥ поставлених кораблик≥в
	bool getShot(Player& playe, Pole& pol);//метод перев≥рки чи вистр≥л попав у карабель
	bool getWinner();//метод перев≥рки хто виграв
};