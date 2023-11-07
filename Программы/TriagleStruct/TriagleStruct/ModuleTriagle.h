#pragma once

/* ������ 1 ������ ������ � ������
* 2 ������ � �������� ��������
* 3 ������������ �����
* 4 ������ ������������ �������
* 5 ������ � ������ ������
*/
#include <iostream>
#include <string>
using namespace std;

//����� - �����������
class Triangle {
private:
	// ����
	enum Vertex { A, B, C };
	// Ax - ���������� ������� A �� x,Ay - ���������� ������� A �� y
	// Bx - ���������� ������� B �� x,By - ���������� ������� B �� y
	// Cx - ���������� ������� C �� x,Cy - ���������� ������� C �� y
	double Ax, Ay, Bx, By, Cx, Cy;

	// �������� ���� �� ��� ������� � ������ ������������
	bool Is_Coordinate(double newX, double newY, Vertex);

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

	// ������ ���������� x ������� A (const �.�. ����� �� ������ �������� �����)
	double Get_X_A() const;

	// ������ ���������� x ������� B (const �.�. ����� �� ������ �������� �����)
	double Get_X_B() const;

	// ������ ���������� x ������� C (const �.�. ����� �� ������ �������� �����)
	double Get_X_C() const;

	// ������ ���������� y ������� A (const �.�. ����� �� ������ �������� �����)
	double Get_Y_A() const;

	// ������ ���������� y ������� B (const �.�. ����� �� ������ �������� �����)
	double Get_Y_B() const;

	// ������ ���������� y ������� C (const �.�. ����� �� ������ �������� �����)
	double Get_Y_C() const;

	// ��������� ����� ������� �������� ������� A (const �.�. ����� �� ������ �������� �����)
	double Length_A() const;

	// ��������� ����� ������� �������� ������� B (const �.�. ����� �� ������ �������� �����)
	double Length_B() const;

	// ��������� ����� ������� �������� ������� C (const �.�. ����� �� ������ �������� �����)
	double Length_C() const;

	// ������� ������������ (const �.�. ����� �� ������ �������� �����)
	double Square() const;

	//�������� ������������ (const �.�. ����� �� ������ �������� �����)
	double Perimetr() const;

	// ���� � ������� A, � �������� (const �.�. ����� �� ������ �������� �����)
	double Angle_A() const;

	// ���� � ������� B, � �������� (const �.�. ����� �� ������ �������� �����)
	double Angle_B() const;

	// ���� � ������� C, � �������� (const �.�. ����� �� ������ �������� �����)
	double Angle_C() const;

	// ��������� ������ � ������������ (const �.�. ����� �� ������ �������� �����)
	string To_String() const;
};

