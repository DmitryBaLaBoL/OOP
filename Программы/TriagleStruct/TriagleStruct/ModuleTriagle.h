#pragma once

using namespace std;

//����� - �����������
class Triangle {
private:
	// ����
	double Ax, Ay, Bx, By, Cx, Cy;

public: // ������
	// �����������
	Triangle();

	// ������ ������� A
	void Set_CoordinateA(double NewCoorginateX, double NewCoorginateY);

	// ������ ������� B
	void Set_CoordinateB(double NewCoorginateX, double NewCoorginateY);

	// ������ ������� C
	void Set_CoordinateC(double NewCoorginateX, double NewCoorginateY);

	// ������ ���������� x ������� A
	double Get_X_A();

	// ������ ���������� x ������� B
	double Get_X_B();

	// ������ ���������� x ������� C
	double Get_X_C();

	// ������ ���������� y ������� A
	double Get_Y_A();

	// ������ ���������� y ������� B
	double Get_Y_B();

	// ������ ���������� y ������� C
	double Get_Y_C();

	// ��������� ����� ������� �������� ������� A
	double Length_A();

	// ��������� ����� ������� �������� ������� B
	double Length_B();

	// ��������� ����� ������� �������� ������� C
	double Length_C();

	// ������� ������������
	double Square();

	//�������� ������������
	double Perimetr();

	// ���� � ������� A
	double Angle_A();

	// ���� � ������� B
	double Angle_B();

	// ���� � ������� C
	double Angle_C();
};

