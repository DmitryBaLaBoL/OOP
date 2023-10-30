#pragma once
/*Дописать
Второй конструктор +
Сеттер все 6 +
Поставить const у всех +
get все данные +
Атд формулы надо и подправить
UML также поменять
*/
#include <iostream>
#include <string>
using namespace std;

//Класс - треугольник
class Triangle {
private:
	// Поля
	double Ax, Ay, Bx, By, Cx, Cy;

	// Проверка есть ли уже вершина с такими координатами
	bool Is_Coordinate(double newX, double newY, char top);

public: // Методы
	// Конструктор, создаёт треугольник с координатами A(0:0) B(1:0) C(0:1)
	Triangle();

	// Конструктор с самостоятельным заданием координат вершин
	Triangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y);

	// Сеттер всех вершин треугольника
	void Set_AllCoordinate(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y);

	// Сеттер вершины A
	void Set_CoordinateA(double NewCoorginateX, double NewCoorginateY);

	// Сеттер вершины B
	void Set_CoordinateB(double NewCoorginateX, double NewCoorginateY);

	// Сеттер вершины C
	void Set_CoordinateC(double NewCoorginateX, double NewCoorginateY);

	// Геттер координаты x вершины A
	double Get_X_A() const;

	// Геттер координаты x вершины B
	double Get_X_B() const;

	// Геттер координаты x вершины C
	double Get_X_C() const;

	// Геттер координаты y вершины A
	double Get_Y_A() const;

	// Геттер координаты y вершины B
	double Get_Y_B() const;

	// Геттер координаты y вершины C
	double Get_Y_C() const;

	// Получение длины стороны напротив вершины A
	double Length_A() const;

	// Получение длины стороны напротив вершины B
	double Length_B() const;

	// Получение длины стороны напротив вершины C
	double Length_C() const;

	// Площадь треугольника
	double Square() const;

	//Периметр треугольника
	double Perimetr() const;

	// Угол у вершины A
	double Angle_A() const;

	// Угол у вершины B
	double Angle_B() const;

	// Угол у вершины C
	double Angle_C() const;

	// Получение данных о треугольнике
	string Data_Triangle() const;
};

