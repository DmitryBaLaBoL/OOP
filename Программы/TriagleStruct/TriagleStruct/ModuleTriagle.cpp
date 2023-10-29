#include "ModuleTriagle.h"
#include <corecrt_math.h>
#include <corecrt_math_defines.h>


// Конструктор
Triangle::Triangle() {
	Ax = 0; Ay = 0;
	Bx = 1; By = 0;
	Cx = 0; Cy = 1;
}

// Сеттер вершины A
void Triangle::Set_CoordinateA(double NewCoorginateX, double NewCoorginateY) {
	Ax = NewCoorginateX; Ay = NewCoorginateY;
}

// Сеттер вершины B
void Triangle::Set_CoordinateB(double NewCoorginateX, double NewCoorginateY) {
	Bx = NewCoorginateX; By = NewCoorginateY;
}

// Сеттер вершины C
void Triangle::Set_CoordinateC(double NewCoorginateX, double NewCoorginateY) {
	Cx = NewCoorginateX; Cy = NewCoorginateY;
}

// Геттер координаты x вершины A
double Triangle::Get_X_A() {
	return Ax;
}

// Геттер координаты x вершины B
double Triangle::Get_X_B() {
	return Bx;
}

// Геттер координаты x вершины C
double Triangle::Get_X_C() {
	return Cx;
}

// Геттер координаты y вершины A
double Triangle::Get_Y_A() {
	return Ay;
}

// Геттер координаты y вершины B
double Triangle::Get_Y_B() {
	return By;
}

// Геттер координаты y вершины C
double Triangle::Get_Y_C() {
	return Cy;
}

// Получение длины стороны напротив вершины A
double Triangle::Length_A() {
	return pow(pow(Bx-By,2) + pow(Cx-Cy,2), 0.5);
}

// Получение длины стороны напротив вершины B
double Triangle::Length_B() {
	return pow(pow(Ax - Ay, 2) + pow(Cx - Cy, 2), 0.5);
}

// Получение длины стороны напротив вершины C
double Triangle::Length_C() {
	return pow(pow(Ax - Ay, 2) + pow(Bx - By, 2), 0.5);
}

// Площадь треугольника
double Triangle::Square() {
	double p = Perimetr() / 2;
	return pow(p * (p - Length_A()) * (p - Length_B()) * (p - Length_C()), 0.5);
}

//Периметр треугольника
double Triangle::Perimetr() {
	return Length_A() + Length_B() + Length_C();
}

// Угол у вершины A
double Triangle::Angle_A() {
	return acos((pow(Length_B(), 2) + pow(Length_C(), 2) - pow(Length_A(),2)) / (2 * Length_B() * Length_C())) * 180 / M_PI;
}

// Угол у вершины B
double Triangle::Angle_B() {
	return acos((pow(Length_A(), 2) + pow(Length_C(), 2) - pow(Length_B(), 2)) / (2 * Length_A() * Length_C())) * 180 / M_PI;
}

// Угол у вершины C
double Triangle::Angle_C() {
	return acos((pow(Length_A(), 2) + pow(Length_B(), 2) - pow(Length_C(), 2)) / (2 * Length_A() * Length_B())) * 180 / M_PI;
}
