#pragma once
#include <iostream>
#include <windows.h> 
#include <conio.h> //���������� ��� �������� ���������� ���������� ������������
class Menu
{private:
	enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White,Purple	};//������������ )������� 
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //���������� ��������� ����
public:
	void instruction(void);//����� ������ ������ ���

	void setColor(Color text, Color background) //����� � ��������� ����� ���������� ���� ������
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); //����������� ��������� ������
	};

	void SetCursor(int x, int y) //�����  ��� ���� ��� ���������� ������� ������� � ������ �� �� � � Y
	{
		COORD myCoords = { x,y }; //����������� ���������
		SetConsoleCursorPosition(hStdOut, myCoords); //����� ���������� ������� �� ������� ����������
	};

	void Avake() //����� ���� ���������� ����� �����
	{
		setColor(White, Cyan); //���������� ���� ������ 
		SetCursor(24, 12); //����������� ������� �������
		std::cout << "�������� ���" << std::endl; //������� ������		
		std::cout << "\t\t����� ��� ���� �������" << std::endl;
		std::cout << "\t   ��� ���� �� ����������� ����������" << std::endl;
	};

	void Avakes(int c) //����� � ���� �� ��������� ��� ������ ������� �������
	{//����� ������� �� ��� ������� ���� ������� �����
		switch (c)
		{
		case 0:setColor(White, Black); break;//���� ����� �� ������ ��� �� ���� �����
		case 1:setColor(Black, Magenta); break;//���� ����� �� ������ ��� �� ���� �����
		case 2:setColor(Yellow, Blue); break;//����� ����� �� ������ ���
		case 3:setColor(Black, White); break;//���� ����� �� ����� ���
		case 4:setColor(Red, Green); break;//������ ����� �� �������� ������
		case 5:setColor(Brown, LightCyan); break;//�������� ����� �� ��� ���� ����� �� ��������
		default:setColor(White, Black); break;//
		}
	};
};