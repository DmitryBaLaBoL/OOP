#pragma once
#include <iostream>
using namespace std;
virtual class Chessmen  {
protected:
	// x - координата фигуры по x
	// y - координата фигуры по y
	// Начало берём в нижней части шахматной доски
	int x, y;

	// Проверка входимости координат в поле (8:8)
	bool Check_Coordinate(int x, int y);

public:
	// Установить координату по x
	void Set_X(int NewX);
	// Установить координату по y
	void Set_Y(int NewY);
	// Установить координаты по x и по y
	void Set_Coordinate(int NewX, int NewY);

	// Получить координату x
	int Get_X();
	// Получить координату y
	int Get_Y();
	// Получить расположение фигуры
	string ToString();

};

class Pawn : public Chessmen {
public:
	// Конструктор создаёт пешку на координатах (1:2)
	Pawn();
	// Конструктор создаёт пешку на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	Pawn(int NewX, int NewY);
	// Перемещает пешку вперёд на cell клеток
	void Move_Forward(int cell);
};

class Rook : public Chessmen {
public:
	// Конструктор создаёт ладью на координатах (1:1)
	Rook();
	// Конструктор создаёт ладью на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	Rook(int NewX, int NewY);
	// Перемещает ладью вперёд на cell клеток
	void Move_Forward(int cell);
	// Перемещает ладью назад на cell клеток
	void Move_Back(int cell);
	// Перемещает ладью влево на cell клеток
	void Move_Left(int cell);
	// Перемещает ладью вправо на cell клеток
	void Move_Right(int cell);
};

class Elephant : public Chessmen {
public:
	// Конструктор создаёт слона на координатах (1:3)
	Elephant();

	// Конструктор создаёт ладью на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	Elephant(int NewX, int NewY);

	// Перемещает ладью вперёд-налево на cell клеток
	void Move_ForwardLeft(int cell);

	// Перемещает ладью вперёд-направо на cell клеток
	void Move_ForwardRight(int cell);

	// Перемещает ладью назад-налево на cell клеток
	void Move_BackLeft(int cell);

	// Перемещает ладью назад-направо на cell клеток
	void Move_BackRight(int cell);
};

class Horse : public Chessmen {
public:
	// Конструктор создаёт коня на координатах (1:2)
	Horse();

	// Конструктор создаёт коня на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	Horse(int NewX, int NewY);

	// Перемещает коня на ход вперёд-налево
	void Move_ForwardLeft();

	// Перемещает коня на ход вперёд-направо
	void Move_ForwardRight();

	// Перемещает коня на ход назад-налево
	void Move_BackLeft();

	// Перемещает коня на ход назад-направо
	void Move_BackRight();
};

class King : public Chessmen {
public:
	// Конструктор создаёт короля на координатах (1:5)
	King();

	// Конструктор создаёт короля на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	King(int NewX, int NewY);

	// Перемещает короля вперёд на ход
	void Move_Forward();

	// Перемещает короля назад на ход
	void Move_Back();

	// Перемещает короля влево на ход
	void Move_Left();

	// Перемещает короля вправо на ход
	void Move_Right();

	// Перемещает короля на ход вперёд-налево
	void Move_ForwardLeft();

	// Перемещает короля на ход вперёд-направо
	void Move_ForwardRight();

	// Перемещает короля на ход назад-налево
	void Move_BackLeft();

	// Перемещает короля на ход назад-направо
	void Move_BackRight();
};

class Queen : public Chessmen {
	// Конструктор создаёт королеву на координатах (1:4)
	Queen();

	// Конструктор создаёт королеву на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
	Queen(int NewX, int NewY);

	// Перемещает королеву вперёд на cell клеток
	void Move_Forward(int cell);

	// Перемещает королеву назад на cell клеток
	void Move_Back(int cell);

	// Перемещает королеву влево на cell клеток
	void Move_Left(int cell);

	// Перемещает королеву вправо на cell клеток
	void Move_Right(int cell);

	// Перемещает королеву на cell клеток вперёд-налево
	void Move_ForwardLeft(int cell);

	// Перемещает королеву на cell клеток вперёд-направо
	void Move_ForwardRight(int cell);

	// Перемещает королеву на cell клеток назад-налево
	void Move_BackLeft(int cell);

	// Перемещает королеву на cell клеток назад-направо
	void Move_BackRight(int cell);
};