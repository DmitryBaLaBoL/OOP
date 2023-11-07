#pragma once

/* Пример 1 просто работа с класса
* 2 Работа с массивом обьектов
* 3 Динамический класс
* 4 Массив динамических классов
* 5 Работа с фалйом класса
*/
#include <iostream>
#include <string>
using namespace std;

//Класс - треугольник
class Triangle {
private:
	// Поля
	enum Vertex { A, B, C };
	// Ax - Координата вершины A по x,Ay - Координата вершины A по y
	// Bx - Координата вершины B по x,By - Координата вершины B по y
	// Cx - Координата вершины C по x,Cy - Координата вершины C по y
	double Ax, Ay, Bx, By, Cx, Cy;

	// Проверка есть ли уже вершина с такими координатами
	bool Is_Coordinate(double newX, double newY, Vertex);

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

	// Геттер координаты x вершины A (const т.к. метод не меняет значений полей)
	double Get_X_A() const;

	// Геттер координаты x вершины B (const т.к. метод не меняет значений полей)
	double Get_X_B() const;

	// Геттер координаты x вершины C (const т.к. метод не меняет значений полей)
	double Get_X_C() const;

	// Геттер координаты y вершины A (const т.к. метод не меняет значений полей)
	double Get_Y_A() const;

	// Геттер координаты y вершины B (const т.к. метод не меняет значений полей)
	double Get_Y_B() const;

	// Геттер координаты y вершины C (const т.к. метод не меняет значений полей)
	double Get_Y_C() const;

	// Получение длины стороны напротив вершины A (const т.к. метод не меняет значений полей)
	double Length_A() const;

	// Получение длины стороны напротив вершины B (const т.к. метод не меняет значений полей)
	double Length_B() const;

	// Получение длины стороны напротив вершины C (const т.к. метод не меняет значений полей)
	double Length_C() const;

	// Площадь треугольника (const т.к. метод не меняет значений полей)
	double Square() const;

	//Периметр треугольника (const т.к. метод не меняет значений полей)
	double Perimetr() const;

	// Угол у вершины A, в градусах (const т.к. метод не меняет значений полей)
	double Angle_A() const;

	// Угол у вершины B, в градусах (const т.к. метод не меняет значений полей)
	double Angle_B() const;

	// Угол у вершины C, в градусах (const т.к. метод не меняет значений полей)
	double Angle_C() const;

	// Получение данных о треугольнике (const т.к. метод не меняет значений полей)
	string To_String() const;
};

