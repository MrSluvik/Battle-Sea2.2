#pragma once
#include <iostream>
#include <windows.h> //включает функции WinAPI sleep(), beep() и т.д
#include <conio.h> //библиотека для создания текстового интерфейса пользователя
class Menu
{public:
	void instruction(void);//метод виводу інструкції

	enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };//кольори 
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //Дескриптор активного вікна

	void setColor(Color text, Color background) //метод з допомогою якого відбудеться зміна текста
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); //встановлюєм параметри текста
	};

	void SetCursor(int x, int y) //метод  для того щоб встановити позицію курсора в консолі по вісі Х і Y
	{
		COORD myCoords = { x,y }; //ініціалізація координат
		SetConsoleCursorPosition(hStdOut, myCoords); //спосіб переміщення курсора на відповідні координати
	};

	void Avake() //метод який виведеться самий перша
	{
		setColor(White, LightBlue); //встановлюю колір текста (білий на голубому)
		SetCursor(24, 12); //встановлюєм позицію курсора
		std::cout << "МОРСЬКИЙ БІЙ" << std::endl; //виводим надпис
		std::cout << "\t\tВерсія для двох гравців" << std::endl;
		std::cout << "\t\tБез бота та автоматичної розтановки" << std::endl;
	};

	void Avakes(int c) //метод в меню за допомогою якої будуть мінятись кольори
	{//можна зробити ще різні варіації фонів колборів хватає
		switch (c)
		{
		case 0:setColor(White,Black); break;//чорні букви на такому фоні як колір брейк
		case 1:setColor(Black, Magenta); break;//чорні букви на такому фоні як колір брейк
		case 2:setColor(Yellow, Blue); break;//жовто букви на сиьому фоні
		case 3:setColor(Black, White); break;//чорні букви на білому фоні
		case 4:setColor(Red, Green); break;//червоні букви на зеленому кольорі
		case 5:setColor(Brown, LightCyan); break;//коричневі букви на фоні щось схоже до смарагда
		default:break;
		}
	};
};