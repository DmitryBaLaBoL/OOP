// TriagleStruct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ModuleTriagle.h"
#include <cassert>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    // Assert
    Triangle Test,Test_1(-2,3, 5,6, 7,-1);
    // Assert 1 объекта, координаты A(0:0) B(3;0) C(0:4)
    Test.Set_AllCoordinate(0, 0, 3, 0, 0, 4);
    assert(Test.Length_A() == 5);
    assert(Test.Length_B() == 4);
    assert(Test.Length_C() == 3);
    assert(Test.Perimetr() == 12);
    assert(Test.Square() == 6);
    assert(Test.Angle_A() == 90);
    assert(abs(Test.Angle_B() - 53.13010) < 0.0001);
    assert(abs(Test.Angle_C() - 36.86990) < 0.0001);
    // Assert 2 объекта, координаты A(-2:3) B(5;6) C(7:-1)
    assert(abs(Test_1.Length_A() - 7.28) < 0.001); 
    assert(abs(Test_1.Length_B() - 9.849) < 0.001);
    assert(abs(Test_1.Length_C() - 7.616) < 0.001);
    assert(abs(Test_1.Perimetr() - 24.745) < 0.001);
    assert(abs(Test_1.Square() - 27.5) < 0.001);
    assert(abs(Test_1.Angle_A() - 47.161) < 0.001);
    assert(abs(Test_1.Angle_B() - 82.747) < 0.001);
    assert(abs(Test_1.Angle_C() - 50.092) < 0.001);


    //Пример 1
    /*Пример 1
* Создать объект Test1 класса Triangle с координатами A(1:1) B(4:1) C(5:1)
* Вычислить длины и углы сторон AB,AC,BC, а также периметр и площадь треугольника
* Затем поменять координаты на A(-2:3) B(5:6) C(7:1)
* Вычислить площадь и периметр
*/
    Triangle Test1(1, 1, 4, 1, 1, 5);
    cout << "Пример 1:" << endl;
    Test1.To_String();
    cout << "AB = " << Test1.Length_C() ;
    cout << "   AC = " << Test1.Length_B() ;
    cout << "   BC = " << Test1.Length_A() << endl;
    cout << "Угол А = " << Test1.Angle_A();
    cout << "   Угол B = " << Test1.Angle_B();
    cout << "   Угол B = " << Test1.Angle_C() << endl;
    cout << "Периметр треугольника = " << Test1.Perimetr() << endl;
    cout << "Площадь треугольника = " << Test1.Square() << endl;
    Test1.Set_AllCoordinate(-2, 3, 5, 6, 7, -1);
    cout << "Периметр треугольника = " << Test1.Perimetr() << endl;
    cout << "Площадь треугольника = " << Test1.Square() << endl;

    // Пример 2
    /* Создать массив 4 объектов класса Triangle, задать различные координаты
    * Вычислить сумму всех углов этих треугольников, если правильно должно быть 720
    * Посчитать сумму площадей этих треугольников
    */
    cout << endl << "Пример 2: " << endl;
    Triangle Triangles[4];
    Triangles[1].Set_AllCoordinate(-2, 3, 5, 6, 7, -1);
    Triangles[2].Set_AllCoordinate(2, -3, 4, 5, 1, -1);
    Triangles[3].Set_AllCoordinate(1, -1, -1, 1, 1, 1);
    double symAngle = 0, symSquare = 0;
    for (int i = 0; i < 4; i++)
    {
        symSquare = symSquare + Triangles[i].Square();
        symAngle = symAngle + Triangles[i].Angle_A() + Triangles[i].Angle_B() + Triangles[i].Angle_C();
    }
    cout << "Сумма всех углов = " << symAngle << endl;
    cout << "Сумма всех площадей = " << symSquare << endl;

    // Пример 3
    /*Создать динамический объект по умолчанию, посчитать длины сторон
    * Затем поменять координаты вершины B на (3:0) и вывести снова длины сторон
    */
    cout << endl << "Пример 3: " << endl;
    Triangle* Test3 = new Triangle;
    cout << "BC = " << Test3->Length_A();
    cout << "  AC = " << Test3->Length_B();
    cout << "  AB = " << Test3->Length_C() << endl;
    Test3->Set_CoordinateB(3, 0);
    cout << "BC = " << Test3->Length_A();
    cout << "  AC = " << Test3->Length_B();
    cout << "  AB = " << Test3->Length_C() << endl;

    // Пример 4 
    /* Создать массив из 4 динамических объектов, вывести координаты всех объектов и их площади
    */
    cout << endl << "Пример 4: " << endl;
    Triangle* Arr_Triangles[4];
    Arr_Triangles[0] = new Triangle;
    Arr_Triangles[1] = new Triangle(-2, 3, 5, 6, 7, -1);
    Arr_Triangles[2] = new Triangle(1, -1, -1, 1, 1, 1);
    Arr_Triangles[3] = new Triangle(2, -3, 4, 5, 1, -1);
    for (int i = 0; i < 4; i++)
    {
        cout << i << ") " << Arr_Triangles[i]->To_String() << " Площадь: " << Arr_Triangles[i]->Square() << endl;
    }
    // Пример 5 
    /* Создать объект Test5 класса Triangle с координатами A(4:2) B(1:1) C(2:5) 
    Сохранить его в файл и считать в новый объект Test55
    */
    cout << endl << "Пример 5: " << endl;
    string s = "a.txt";
    Triangle Test5(4, 2, 1, 1, 2, 5);
    cout << Test5.To_String() << endl;
    // Запись в файл
    ofstream outFile;
    outFile.open(s);
    if (outFile.is_open()) {
        outFile << Test5.Get_X_A() << endl << Test5.Get_Y_A() << endl;
        outFile << Test5.Get_X_B() << endl << Test5.Get_Y_B() << endl;
        outFile << Test5.Get_X_C() << endl << Test5.Get_Y_C() << endl;
    }
    outFile.close();
    Triangle Test55;
    // Считывание с файла
    ifstream FromFile;
    FromFile.open(s);
    double x, y;
    if (FromFile.is_open()) {
        FromFile >> x; FromFile >> y;
        Test55.Set_CoordinateA(x, y);
        FromFile >> x; FromFile >> y;
        Test55.Set_CoordinateB(x, y);
        FromFile >> x; FromFile >> y;
        Test55.Set_CoordinateC(x, y);

    }
    FromFile.close();
    cout << Test55.To_String() << endl;




    /*Test.Set_AllCoordinate(24, -5, 2, 17, 2, 17);
    cout << Test.Get_X_A() << endl;
    cout << Test.Get_Y_A() << endl;
    cout << Test.Get_X_B() << endl;
    cout << Test.Get_Y_B() << endl;
    cout << Test.Get_X_C() << endl;
    cout << Test.Get_Y_C() << endl;*/
    /*cout << Test.Get_X_A() << endl;
    cout << Test.Get_Y_A() << endl;
    Test.Set_CoordinateA(1, 0);
    cout << Test.Get_X_A() << endl;
    cout << Test.Get_Y_A() << endl;*/
    /*cout << Test.Length_A() << endl;
    cout << Test.Length_B() << endl;
    cout << Test.Length_C() << endl;
    cout << Test.Perimetr() << endl;
    cout << Test.Square() << endl;
    cout << Test.Get_X_A() << endl;
    cout << Test.Get_Y_A() << endl;
    cout << Test.Get_X_B() << endl;
    cout << Test.Get_Y_B() << endl;
    cout << Test.Get_X_C() << endl;
    cout << Test.Get_Y_C() << endl;
    cout << Test.Angle_A() << endl;
    cout << Test.Angle_B() << endl;
    cout << Test.Angle_C() << endl;*/
}
