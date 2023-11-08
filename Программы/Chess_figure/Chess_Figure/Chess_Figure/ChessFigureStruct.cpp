#include "ChessFigureStruct.h"
#include <string>

// Проверка входимости координат в поле (8:8)
bool Chessmen::Check_Coordinate(int x, int y) {
	if (x > 0 && x < 9 && y > 0 && y < 9) return true;
	else {
		throw std::runtime_error("Недопустимые значения для координат");
		return false;
	}
}

// Установить координату по x
void Chessmen::Set_X(int NewX) {
	try {
		if (Check_Coordinate(NewX, y)) {
			x = NewX;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Установить координату по y
void Chessmen::Set_Y(int NewY) {
	try {
		if (Check_Coordinate(x, NewY)) {
			y = NewY;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Установить координаты по x и по y
void Chessmen::Set_Coordinate(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX;
			y = NewY;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Получить координату x
int Chessmen::Get_X() {
	return x;
}

// Получить координату y
int Chessmen::Get_Y() {
	return y;
}

// Получить расположение фигуры
string Chessmen::ToString() {
	return "Фигура находится на (" + to_string(x) + ":" + to_string(y) + ")";
}



/// Пешка
// Конструктор создаёт пешку на координатах (1:1)
Pawn::Pawn() {
	x = 1; y = 2;
}

// Конструктор создаёт пешку на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
Pawn::Pawn(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 2;
		cout << e.what() << endl;
	}
}

// Перемещает пешку вперёд на cell клеток
void Pawn::Move_Forward(int cell) {
	try {
		if (Check_Coordinate(x,y + cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}


/// Ладья 
// Конструктор создаёт ладью на координатах (1:1)
Rook::Rook() {
	x = 1; y = 1;
}

// Конструктор создаёт ладью на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
Rook::Rook(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 1;
		cout << e.what() << endl;
	}
}

// Перемещает ладью вперёд на cell клеток
void Rook::Move_Forward(int cell) {
	try {
		if (Check_Coordinate(x, y + cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью назад на cell клеток
void Rook::Move_Back(int cell) {
	try {
		if (Check_Coordinate(x, y - cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью влево на cell клеток
void Rook::Move_Left(int cell) {
	try {
		if (Check_Coordinate(x - cell, y)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью вправо на cell клеток
void Rook::Move_Right(int cell) {
	try {
		if (Check_Coordinate(x + cell, y)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}


/// Слон
// Конструктор создаёт слона на координатах (1:3)
Elephant::Elephant() {
	x = 1; y = 3;
}

// Конструктор создаёт ладью на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
Elephant::Elephant(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 3;
		cout << e.what() << endl;
	}
}

// Перемещает ладью вперёд-налево на cell клеток
void Elephant::Move_ForwardLeft(int cell) {
	try {
		if (Check_Coordinate(x - cell, y + cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью вперёд-направо на cell клеток
void Elephant::Move_ForwardRight(int cell) {
	try {
		if (Check_Coordinate(x + cell, y + cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью назад-налево на cell клеток
void Elephant::Move_BackLeft(int cell) {
	try {
		if (Check_Coordinate(x - cell, y - cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает ладью назад-направо на cell клеток
void Elephant::Move_BackRight(int cell) {
	try {
		if (Check_Coordinate(x + cell, y - cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

/// Конь
// Конструктор создаёт коня на координатах (1:2)
Horse::Horse() {
	x = 1; y = 2;
}

// Конструктор создаёт коня на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
Horse::Horse(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 2;
		cout << e.what() << endl;
	}
}

// Перемещает коня на ход вперёд-налево
void Horse::Move_ForwardLeft() {
	try {
		if (Check_Coordinate(x - 1, y + 2)) {
			x = x - 1; y = y + 2;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает коня на ход вперёд-направо
void Horse::Move_ForwardRight() {
	try {
		if (Check_Coordinate(x + 1, y + 2)) {
			x = x + 1; y = y + 2;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает коня на ход назад-налево
void Horse::Move_BackLeft() {
	try {
		if (Check_Coordinate(x - 1, y - 2)) {
			x = x - 1; y = y - 2;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает коня на ход назад-направо
void Horse::Move_BackRight() {
	try {
		if (Check_Coordinate(x + 1, y - 2)) {
			x = x + 1; y = y - 2;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}


/// Король
// Конструктор создаёт короля на координатах (1:5)
King::King() {
	x = 1; y = 5;
}

// Конструктор создаёт короля на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
King::King(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 5;
		cout << e.what() << endl;
	}
}

// Перемещает короля вперёд на ход
void King::Move_Forward() {
	try {
		if (Check_Coordinate(x, y + 1)) {
			y = y + 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля назад на ход
void King::Move_Back() {
	try {
		if (Check_Coordinate(x, y - 1)) {
			y = y - 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля влево на ход
void King::Move_Left() {
	try {
		if (Check_Coordinate(x - 1, y)) {
			x = x - 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля вправо на ход
void King::Move_Right() {
	try {
		if (Check_Coordinate(x + 1, y)) {
			x = x + 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля на ход вперёд-налево
void King::Move_ForwardLeft() {
	try {
		if (Check_Coordinate(x - 1, y + 1)) {
			x = x - 1; y = y + 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля на ход вперёд-направо
void King::Move_ForwardRight() {
	try {
		if (Check_Coordinate(x + 1, y + 1)) {
			x = x + 1; y = y + 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля на ход назад-налево
void King::Move_BackLeft() {
	try {
		if (Check_Coordinate(x - 1, y - 1)) {
			x = x - 1; y = y - 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает короля на ход назад-направо
void King::Move_BackRight() {
	try {
		if (Check_Coordinate(x + 1, y - 1)) {
			x = x + 1; y = y - 1;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}


/// Королева 
// Конструктор создаёт королеву на координатах (1:4)
Queen::Queen() {
	x = 1; y = 4;
}

// Конструктор создаёт королеву на координатах (x:y), если координаты не входят в поле создаётся по умолчанию
Queen::Queen(int NewX, int NewY) {
	try {
		if (Check_Coordinate(NewX, NewY)) {
			x = NewX; y = NewY;
		}
	}
	catch (const std::exception& e) {
		x = 1; y = 4;
		cout << e.what() << endl;
	}
}

// Перемещает королеву вперёд на cell клеток
void Queen::Move_Forward(int cell) {
	try {
		if (Check_Coordinate(x, y + cell)) {
			y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву назад на cell клеток
void Queen::Move_Back(int cell) {
	try {
		if (Check_Coordinate(x, y - cell)) {
			y = y - cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву влево на cell клеток
void Queen::Move_Left(int cell) {
	try {
		if (Check_Coordinate(x - cell, y)) {
			x = x - cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву вправо на cell клеток
void Queen::Move_Right(int cell) {
	try {
		if (Check_Coordinate(x + cell, y)) {
			x = x + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву на cell клеток вперёд-налево
void Queen::Move_ForwardLeft(int cell) {
	try {
		if (Check_Coordinate(x - cell, y + cell)) {
			x = x - cell; y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву на cell клеток вперёд-направо
void Queen::Move_ForwardRight(int cell) {
	try {
		if (Check_Coordinate(x + cell, y + cell)) {
			x = x + cell;  y = y + cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву на cell клеток назад-налево
void Queen::Move_BackLeft(int cell) {
	try {
		if (Check_Coordinate(x - cell, y - cell)) {
			x = x - cell;  y = y - cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Перемещает королеву на cell клеток назад-направо
void Queen::Move_BackRight(int cell) {
	try {
		if (Check_Coordinate(x + cell, y - cell)) {
			x = x + cell; y = y - cell;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}