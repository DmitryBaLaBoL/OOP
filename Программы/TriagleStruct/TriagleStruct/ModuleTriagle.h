#pragma once
/*��������
������ ����������� +
������ ��� 6 +
��������� const � ���� +
get ��� ������ +
��� ������� ���� � ����������
UML ����� ��������
*/
#include <iostream>
#include <string>
using namespace std;

//����� - �����������
class Triangle {
private:
	// ����
	double Ax, Ay, Bx, By, Cx, Cy;

	// �������� ���� �� ��� ������� � ������ ������������
	bool Is_Coordinate(double newX, double newY, char top);

public: // ������
	// �����������, ������ ����������� � ������������ A(0:0) B(1:0) C(0:1)
	Triangle();

	// ����������� � ��������������� �������� ��������� ������
	Triangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y);

	// ������ ���� ������ ������������
	void Set_AllCoordinate(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y);

	// ������ ������� A
	void Set_CoordinateA(double NewCoorginateX, double NewCoorginateY);

	// ������ ������� B
	void Set_CoordinateB(double NewCoorginateX, double NewCoorginateY);

	// ������ ������� C
	void Set_CoordinateC(double NewCoorginateX, double NewCoorginateY);

	// ������ ���������� x ������� A
	double Get_X_A() const;

	// ������ ���������� x ������� B
	double Get_X_B() const;

	// ������ ���������� x ������� C
	double Get_X_C() const;

	// ������ ���������� y ������� A
	double Get_Y_A() const;

	// ������ ���������� y ������� B
	double Get_Y_B() const;

	// ������ ���������� y ������� C
	double Get_Y_C() const;

	// ��������� ����� ������� �������� ������� A
	double Length_A() const;

	// ��������� ����� ������� �������� ������� B
	double Length_B() const;

	// ��������� ����� ������� �������� ������� C
	double Length_C() const;

	// ������� ������������
	double Square() const;

	//�������� ������������
	double Perimetr() const;

	// ���� � ������� A
	double Angle_A() const;

	// ���� � ������� B
	double Angle_B() const;

	// ���� � ������� C
	double Angle_C() const;

	// ��������� ������ � ������������
	string Data_Triangle() const;
};

