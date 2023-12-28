#pragma once
#include <iostream>
using namespace std;
virtual class Chessmen  {
protected:
	// x - ���������� ������ �� x
	// y - ���������� ������ �� y
	// ������ ���� � ������ ����� ��������� �����
	int x, y;

	// �������� ���������� ��������� � ���� (8:8)
	bool Check_Coordinate(int x, int y);

public:
	// ���������� ���������� �� x
	void Set_X(int NewX);
	// ���������� ���������� �� y
	void Set_Y(int NewY);
	// ���������� ���������� �� x � �� y
	void Set_Coordinate(int NewX, int NewY);

	// �������� ���������� x
	int Get_X();
	// �������� ���������� y
	int Get_Y();
	// �������� ������������ ������
	string ToString();

};

class Pawn : public Chessmen {
public:
	// ����������� ������ ����� �� ����������� (1:2)
	Pawn();
	// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	Pawn(int NewX, int NewY);
	// ���������� ����� ����� �� cell ������
	void Move_Forward(int cell);
};

class Rook : public Chessmen {
public:
	// ����������� ������ ����� �� ����������� (1:1)
	Rook();
	// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	Rook(int NewX, int NewY);
	// ���������� ����� ����� �� cell ������
	void Move_Forward(int cell);
	// ���������� ����� ����� �� cell ������
	void Move_Back(int cell);
	// ���������� ����� ����� �� cell ������
	void Move_Left(int cell);
	// ���������� ����� ������ �� cell ������
	void Move_Right(int cell);
};

class Elephant : public Chessmen {
public:
	// ����������� ������ ����� �� ����������� (1:3)
	Elephant();

	// ����������� ������ ����� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	Elephant(int NewX, int NewY);

	// ���������� ����� �����-������ �� cell ������
	void Move_ForwardLeft(int cell);

	// ���������� ����� �����-������� �� cell ������
	void Move_ForwardRight(int cell);

	// ���������� ����� �����-������ �� cell ������
	void Move_BackLeft(int cell);

	// ���������� ����� �����-������� �� cell ������
	void Move_BackRight(int cell);
};

class Horse : public Chessmen {
public:
	// ����������� ������ ���� �� ����������� (1:2)
	Horse();

	// ����������� ������ ���� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	Horse(int NewX, int NewY);

	// ���������� ���� �� ��� �����-������
	void Move_ForwardLeft();

	// ���������� ���� �� ��� �����-�������
	void Move_ForwardRight();

	// ���������� ���� �� ��� �����-������
	void Move_BackLeft();

	// ���������� ���� �� ��� �����-�������
	void Move_BackRight();
};

class King : public Chessmen {
public:
	// ����������� ������ ������ �� ����������� (1:5)
	King();

	// ����������� ������ ������ �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	King(int NewX, int NewY);

	// ���������� ������ ����� �� ���
	void Move_Forward();

	// ���������� ������ ����� �� ���
	void Move_Back();

	// ���������� ������ ����� �� ���
	void Move_Left();

	// ���������� ������ ������ �� ���
	void Move_Right();

	// ���������� ������ �� ��� �����-������
	void Move_ForwardLeft();

	// ���������� ������ �� ��� �����-�������
	void Move_ForwardRight();

	// ���������� ������ �� ��� �����-������
	void Move_BackLeft();

	// ���������� ������ �� ��� �����-�������
	void Move_BackRight();
};

class Queen : public Chessmen {
	// ����������� ������ �������� �� ����������� (1:4)
	Queen();

	// ����������� ������ �������� �� ����������� (x:y), ���� ���������� �� ������ � ���� �������� �� ���������
	Queen(int NewX, int NewY);

	// ���������� �������� ����� �� cell ������
	void Move_Forward(int cell);

	// ���������� �������� ����� �� cell ������
	void Move_Back(int cell);

	// ���������� �������� ����� �� cell ������
	void Move_Left(int cell);

	// ���������� �������� ������ �� cell ������
	void Move_Right(int cell);

	// ���������� �������� �� cell ������ �����-������
	void Move_ForwardLeft(int cell);

	// ���������� �������� �� cell ������ �����-�������
	void Move_ForwardRight(int cell);

	// ���������� �������� �� cell ������ �����-������
	void Move_BackLeft(int cell);

	// ���������� �������� �� cell ������ �����-�������
	void Move_BackRight(int cell);
};