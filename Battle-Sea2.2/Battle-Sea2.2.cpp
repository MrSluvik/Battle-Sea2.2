//дописати меню через світч а також функцію в макса позичити про правила
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Player.h"
#include "Menu.h"
#include<string>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x = 1; int y = 1, i = 0;	
	int X = 1; int Y = 1;
	char Ch;
	char ch = 'X';
	int c = 0;
	string name1;
	string name2;

	Pole pole;//створює об'єкт класу поле для першого гравця
	Player player;//створює об'єкт класу гравець перший 
	Menu menu;
	menu.Avake(); Sleep(15000); system("cls");	
	//встановлюю
	menu.Avakes(0); cout << "\t\t\t\tЗавантаження. . . . ." << endl; Sleep(20000); system("cls");

	menu.Avakes(0);//повертаю стоковий вигляд консолі
	cout << "Виберіть фон та колір тексту який буде під час гри " << endl;
	cout << "0-стокова консоль\n1- чорні букви на  ліловому фоні \n2-жовті букви на синьому фоні\n3-чорні букви на білому фоні\n4-червоні букви на зеленому кольорі\n5-коричневі букви насвітло смарагдовому фоні" <<endl ;
	cin >> c; cin.ignore(100, '\n');//ігноруєм розрив рядка інакше наступна фраза не введеться а перекина далі
	menu.Avakes(c);//змінюю колір консолі
	system("cls");
	cout << "Введіть ім'я першого гравця :" << endl;
	getline(cin, name1); cout << endl; system("cls");
	cout << "Введіть ім'я другого гравця :" << endl;
	getline(cin, name2); cout << endl; system("cls");

	menu.Avakes(c);cout << "\t\t\t\tЗавантаження. . . . ." << endl; Sleep(10000); system("cls");
	//фон консолі
	menu.instruction();//вивожу інструкцію 
	Sleep(120000);
	system("cls");
	cout << "\n\n\t\tРозтановка кораблів" << endl;
	
	while (pole.getAmount() != true) //цикл робить доти доки на полі не буде зайнято 20 клітинок(така кількість всіх палуб кораблів)
	{
		char key = _getch();

		if (key == 'w') x--;
		if (key == 's') x++;
		if (key == 'a') y--;
		if (key == 'd') y++;
		if (key == 'H' || key == 'h') { menu.instruction(); Sleep(120000); }//якщо гравець захоче ще раз прочитати правила 
		if (x == 0 or x == 12 - 1 or y == 0 or y == 12 - 1) //умова,за якої при виході за межі поля, вказівник повертається 
		{
			x = 5;
			y = 5;
		}
		if (key == 'c') 
		{
			ch = 'X';
			player.setX(x);
			player.setY(y);
			player.setCh(ch);
			system("cls");

			pole.printPole(player);
		}
		else 
		{
			system("cls");
			pole.printPole(x, y, '*');
		}
		cout << "\n\n\t\tЗараз кораблі розтавляє - " <<name1<< endl;
		Sleep(100);
	}
	system("cls");

	Pole pole2;//створює об'єкт класу поле для другого гравця
	Player player2;//створює об'єкт класу гравець перший 

	while (pole2.getAmount() != true)//цикл робить доти доки на полі не буде зайнято 20 клітинок(така кількість всіх палуб кораблів)
	{
		char key = _getch();//зміна отримує нажату клавішу
		if (key == 'w') x--;//що відбувається
		if (key == 's') x++;//під час
		if (key == 'a') y--;//нажаття 
		if (key == 'd') y++;//клавіш віжповідних
		if (key == 'H' || key == 'h') { menu.instruction(); Sleep(120000); }//якщо гравець захоче ще раз прочитати правила 
		if (x == 0 or x == 12 - 1 or y == 0 or y == 12 - 1)//умова,за якої при виході за межі поля, вказівник повертається 
		{
			x = 5;
			y = 5;
		}
		if (key == 'c')
		{
			ch = 'X';
			player2.setX(x);
			player2.setY(y);
			player2.setCh(ch);
			system("cls");

			pole2.printPole(player2);
		}
		else
		{
			system("cls");
			pole2.printPole(x, y, '*');
		}
		cout << "\n\n\t\tЗараз кораблі розтавляє -"<<name2 << endl;
		Sleep(100);
	}
	system("cls");

	Pole pole11;//створює об'єкт класу поле ,для першого гравця
	Pole Pole22;//створює об'єкт класу поле, для другого гравця

	while (true)
	{		
			char key = _getch();//зміна отримує нажату клавішу
			if (key == 'w') x--;//що відбувається
			if (key == 's') x++;//під час
			if (key == 'a') y--;//нажаття 
			if (key == 'd') y++;//клавіш віжповідних
			if (key == 'H' || key == 'h') { menu.instruction(); Sleep(120000); }//якщо гравець захоче ще раз прочитати правила 
			if (x == 0 or x == 12 - 1 or y == 0 or y == 12 - 1)//умова,за якої при виході за межі поля, вказівник повертається 
			{
				x = 5;
				y = 5;
			}

			if (key == 'c' && i == 0)
			{
				Ch = '0';
				player.setX(x);
				player.setY(y);
				player.setCh(Ch);
				system("cls");

				pole11.printPoleGame(player, pole2);
				cout << name1 << endl; Sleep(100);
				if (pole11.getShot(player, pole2) == false)
				{
					i = 1;
					cout << "Не попав" << endl;
				}
				else
				{
					i = 0;
					cout << "Попав" << endl;
				}
				if (pole11.getWinner() == true) { cout << "Переміг гравець "<<name1 << endl; break; }
				Sleep(1000);//роблю затримку щоб було видно як походив перший гравець 
			}
			char Key = _getch();//зміна отримує нажату клавішу
			if (Key == 'w') X--;//що відбувається
			if (Key == 's') X++;//під час
			if (Key == 'a') Y--;//нажаття 
			if (Key == 'd') Y++;//клавіш віжповідних
			if (key == 'H' || key == 'h') { menu.instruction(); Sleep(120000); }//якщо гравець захоче ще раз прочитати правила 
			if (X == 0 or X == 12 - 1 or Y == 0 or Y == 12 - 1)//умова,за якої при виході за межі поля, вказівник повертається 
			{
				X = 5;
				Y = 5;
			}
			if (Key == 'c' && i == 1) 
			{
				Ch = 'O';
				player2.setX(X);
				player2.setY(Y);
				player2.setCh(Ch);
				system("cls");

				Pole22.printPoleGames(player2, pole);
				cout << name2 << endl; Sleep(100);
				if (Pole22.getShot(player2, pole) == false)
				{
					i = 0;
					cout << "Не попав" << endl;
				}
				else 
				{
					i = 1;
					cout << "Попав" << endl;
				}
				if (Pole22.getWinner() == true) { cout << "Переміг гравець  " <<name2<< endl; break; }
			}
		
		else 
		{
			system("cls");			
			if (i == 0) 
			{
				pole11.printPole(x, y, '*');
			}
			else if(i==1) 
			{
				Pole22.printPole(X,Y, '*');
			}
		}
	}
}