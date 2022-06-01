#include "Player.h"
#include <iostream>
Pole::Pole() {
	this->n = 11;
	this->m = 11;
	this->matrix = nullptr;
	this->matrix = new char* [n];
	
	for (int i = 0; i < n; i++)
	{
		this->matrix[i] = new char[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][j] = '-';
		}
	}
}

void Pole::printPole(Player& player) {
	char arr[11]{ '-','A', 'B', 'C','D','E','F','G','H','I','J' };
	int x = player.getX();
	int y = player.getY();
	char ch = player.getCh();

	matrix[x][y] = ch;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			cout << this->matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void Pole::printPole(int x, int y, char ch)
{
	char arr[11]{ '-','A', 'B', 'C','D','E','F','G','H','I','J' };
	if (getAmount() == true) {}
	else {
		if (matrix[x][y] == 'X') {//роблю
			matrix[x][y] = 'X';
		}
		else if (matrix[x][y] == '0')//штуку
		{
			matrix[x][y] = '0';
		}
		else if (matrix[x][y] == 'O')//щоб п≥д час
		{
			matrix[x][y] = 'O';
		}
		else if (matrix[x][y] == '#')//руху по полю
		{
			matrix[x][y] = '#';
		}
		else if (matrix[x][y] == '~')//в≥дпов≥дн≥ значки
		{
			matrix[x][y] = '~';
		}
		else if (matrix[x][y] == '*') //не стирались
		{
			matrix[x][y] = '-';
		}
		else {
			matrix[x][y] = ch;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->matrix[i][0] = arr[i];
				this->matrix[0][j] = arr[j];
				cout << this->matrix[i][j] << "\t";
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (this->matrix[i][j] == '*') {
					this->matrix[i][j] = '-';
				}
			}
		}
	}
}

void Pole::printPoleGame(Player& players, Pole& poles)//друк пол€ бою дл€ першого гравц€
{
	char arr[11]{ '-','A', 'B', 'C','D','E','F','G','H','I','J' };
	int x = players.getX();
	int y = players.getY();
	char ch = players.getCh();

	if (poles.matrix[x][y] == 'X') {
		matrix[x][y] = ch;
	}
	else if(poles.matrix[x][y] != 'X') {
		matrix[x][y] = '#';		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			cout << this->matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void Pole::printPoleGames(Player& playerq, Pole& poleq)////друк пол€ бою дл€ другого гравц€
{	
	char arr[11]{ '-','A', 'B', 'C','D','E','F','G','H','I','J' };
	int x = playerq.getX();
	int y = playerq.getY();
	char ch = playerq.getCh();

	if (poleq.matrix[x][y] == 'X') {
		matrix[x][y] = ch;		
	}
	else if (poleq.matrix[x][y] != 'X') {
		matrix[x][y] = '~';
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			cout << this->matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

bool Pole::getAmount()
{
	int value = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (this->matrix[i][j] == 'X') {
				value++;
				if (value == 20) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Pole::getShot(Player& playe, Pole& pol)
{
	int x = playe.getX();
	int y = playe.getY();
	char ch = playe.getCh();
	if (pol.matrix[x][y] == 'X' && matrix[x][y] == ch) {
		return true;
	}
	else if (pol.matrix[x][y] != 'X' && (matrix[x][y] =='~'|| matrix[x][y] == '#')) {
		return false;
	}	
}

bool Pole::getWinner()
{
	int sum = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			if (this->matrix[i][j] == '0') {
				sum++;
			}
			if (this->matrix[i][j] == 'O') {
				sum2++;
			}			
		}		
	}
	if (sum == 20) {
		return true;
	}
	if (sum2 == 20) {
		return true;
	}	
}