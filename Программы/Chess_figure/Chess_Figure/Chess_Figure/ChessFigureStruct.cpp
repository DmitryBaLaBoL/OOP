#include "ChessFigureStruct.h"
#include <string>

// �������� ���������� ��������� � ���� (8:8)
bool Chessmen::Check_Coordinate(int x, int y) {
	if (x > 0 && x < 9 && y > 0 && y < 9) return true;
	else {
		throw std::runtime_error("������������ �������� ��� ���������");
		return false;
	}
}

// ���������� ���������� �� x
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

// ���������� ���������� �� y
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

// ���������� ���������� �� x � �� y
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

// �������� ���������� x
int Chessmen::Get_X() {
	return x;
}

// �������� ���������� y
int Chessmen::Get_Y() {
	return y;
}

// �������� ������������ ������
string Chessmen::ToString() {
	return "������ ��������� �� (" + to_string(x) + ":" + to_string(y) + ")";
}



/// �����
// ����������� ������ ����� �� ����������� (1:1)
Pawn::Pawn() {
	x = 1; y = 2;
}

// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� ����� ����� �� cell ������
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


/// ����� 
// ����������� ������ ����� �� ����������� (1:1)
Rook::Rook() {
	x = 1; y = 1;
}

// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� ����� ����� �� cell ������
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

// ���������� ����� ����� �� cell ������
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

// ���������� ����� ����� �� cell ������
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

// ���������� ����� ������ �� cell ������
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


/// ����
// ����������� ������ ����� �� ����������� (1:3)
Elephant::Elephant() {
	x = 1; y = 3;
}

// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� ����� �����-������ �� cell ������
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

// ���������� ����� �����-������� �� cell ������
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

// ���������� ����� �����-������ �� cell ������
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

// ���������� ����� �����-������� �� cell ������
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

/// ����
// ����������� ������ ���� �� ����������� (1:2)
Horse::Horse() {
	x = 1; y = 2;
}

// ����������� ������ ���� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� ���� �� ��� �����-������
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

// ���������� ���� �� ��� �����-�������
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

// ���������� ���� �� ��� �����-������
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

// ���������� ���� �� ��� �����-�������
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


/// ������
// ����������� ������ ������ �� ����������� (1:5)
King::King() {
	x = 1; y = 5;
}

// ����������� ������ ������ �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� ������ ����� �� ���
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

// ���������� ������ ����� �� ���
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

// ���������� ������ ����� �� ���
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

// ���������� ������ ������ �� ���
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

// ���������� ������ �� ��� �����-������
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

// ���������� ������ �� ��� �����-�������
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

// ���������� ������ �� ��� �����-������
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

// ���������� ������ �� ��� �����-�������
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


/// �������� 
// ����������� ������ �������� �� ����������� (1:4)
Queen::Queen() {
	x = 1; y = 4;
}

// ����������� ������ �������� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
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

// ���������� �������� ����� �� cell ������
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

// ���������� �������� ����� �� cell ������
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

// ���������� �������� ����� �� cell ������
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

// ���������� �������� ������ �� cell ������
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

// ���������� �������� �� cell ������ �����-������
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

// ���������� �������� �� cell ������ �����-�������
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

// ���������� �������� �� cell ������ �����-������
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

// ���������� �������� �� cell ������ �����-�������
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