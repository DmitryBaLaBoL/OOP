#include "ModuleTriagle.h"
#include <corecrt_math.h>
#include <corecrt_math_defines.h>



// �������� ���� �� ��� ������� � ������ ������������
bool Triangle::Is_Coordinate(double newX, double newY, Vertex Top)
{
	switch (Top) {
	case Vertex::A: if ((newX == Bx && newY == By) || (newX == Cx && newY == Cy)) return true; else return false;
	case Vertex::B: if ((newX == Ax && newY == Ay) || (newX == Cx && newY == Cy)) return true; else return false;
	case Vertex::C: if ((newX == Ax && newY == Ay) || (newX == Bx && newY == By)) return true; else return false;
	}

}

// �����������, ������ ����������� � ������������ A(0:0) B(1:0) C(0:1)
Triangle::Triangle() {
	Ax = 0; Ay = 0;
	Bx = 1; By = 0;
	Cx = 0; Cy = 1;
}
// ����������� � ��������������� �������� ��������� ������
Triangle::Triangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
	Ax = 0; Ay = 0; Bx = 1; By = 0; Cx = 0; Cy = 1;
	Set_AllCoordinate(a_x, a_y, b_x, b_y, c_x, c_y);


}

// ������ ���� ������ ������������
void Triangle::Set_AllCoordinate(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
	double oldxA = Ax, oldyA = Ay, oldxB = Bx, oldyB = By, oldxC = Cx, oldyC = Cy;
	if (!Is_Coordinate(a_x, a_y, A)) { Ax = a_x; Ay = a_y; }
	else { Ax = oldxA; Ay = oldyA; Bx = oldxB; By = oldyB; Cx = oldxC; Cy = oldyC; exit; };
	if (!Is_Coordinate(b_x, b_y, B)) { Bx = b_x; By = b_y; }
	else { Ax = oldxA; Ay = oldyA; Bx = oldxB; By = oldyB; Cx = oldxC; Cy = oldyC; exit; };
	if (!Is_Coordinate(c_x, c_y, C)) { Cx = c_x; Cy = c_y; }
	else { Ax = oldxA; Ay = oldyA; Bx = oldxB; By = oldyB; Cx = oldxC; Cy = oldyC; exit; };
}

// ������ ������� A
void Triangle::Set_CoordinateA(double NewCoorginateX, double NewCoorginateY) {
	if (Is_Coordinate(NewCoorginateX, NewCoorginateY, A))
		cout << endl << "������� ������������ (" << NewCoorginateX << ":" << NewCoorginateY << ") ��� ������" << endl;
	else { Ax = NewCoorginateX; Ay = NewCoorginateY; }
}

// ������ ������� B
void Triangle::Set_CoordinateB(double NewCoorginateX, double NewCoorginateY) {
	if (Is_Coordinate(NewCoorginateX, NewCoorginateY, B))
		cout << endl << "������� ������������ (" << NewCoorginateX << ":" << NewCoorginateY << ") ��� ������" << endl;
	else { Bx = NewCoorginateX; By = NewCoorginateY; }
}

// ������ ������� C
void Triangle::Set_CoordinateC(double NewCoorginateX, double NewCoorginateY) {
	if (Is_Coordinate(NewCoorginateX, NewCoorginateY, C))
		cout << endl << "������� ������������ (" << NewCoorginateX << ":" << NewCoorginateY << ") ��� ������" << endl;
	else { Cx = NewCoorginateX; Cy = NewCoorginateY; }
}

// ������ ���������� x ������� A
double Triangle::Get_X_A() const {
	return Ax;
}

// ������ ���������� x ������� B
double Triangle::Get_X_B() const {
	return Bx;
}

// ������ ���������� x ������� C
double Triangle::Get_X_C() const {
	return Cx;
}

// ������ ���������� y ������� A
double Triangle::Get_Y_A() const {
	return Ay;
}

// ������ ���������� y ������� B
double Triangle::Get_Y_B() const {
	return By;
}

// ������ ���������� y ������� C
double Triangle::Get_Y_C() const {
	return Cy;
}

// ��������� ����� ������� �������� ������� A
double Triangle::Length_A() const {
	return pow(pow(Cx - Bx, 2) + pow(Cy - By, 2), 0.5);
}

// ��������� ����� ������� �������� ������� B
double Triangle::Length_B() const {
	return pow(pow(Ax - Cx, 2) + pow(Ay - Cy, 2), 0.5);
}

// ��������� ����� ������� �������� ������� C
double Triangle::Length_C() const {
	return pow(pow(Ax - Bx, 2) + pow(Ay - By, 2), 0.5);
}

// ������� ������������
double Triangle::Square() const {
	double p = Perimetr() / 2;
	return pow(p * (p - Length_A()) * (p - Length_B()) * (p - Length_C()), 0.5);
}

//�������� ������������
double Triangle::Perimetr() const {
	return Length_A() + Length_B() + Length_C();
}

// ���� � ������� A, � ��������
double Triangle::Angle_A() const {
	return acos((pow(Length_B(), 2) + pow(Length_C(), 2) - pow(Length_A(), 2)) / (2 * Length_B() * Length_C())) * 180 / M_PI;
}

// ���� � ������� B, � ��������
double Triangle::Angle_B() const {
	return acos((pow(Length_A(), 2) + pow(Length_C(), 2) - pow(Length_B(), 2)) / (2 * Length_A() * Length_C())) * 180 / M_PI;
}

// ���� � ������� C, � ��������
double Triangle::Angle_C() const {
	return acos((pow(Length_A(), 2) + pow(Length_B(), 2) - pow(Length_C(), 2)) / (2 * Length_A() * Length_B())) * 180 / M_PI;
}

// ��������� ������ � ������������
string Triangle::To_String() const {
	return "���������� ������������: A(" + ::to_string(Ax) + ":" + ::to_string(Ay) + ") " +
		"B(" + ::to_string(Bx) + ":" + ::to_string(By) + ") " +
		"C(" + ::to_string(Cx) + ":" + ::to_string(Cy) + ")";
}

