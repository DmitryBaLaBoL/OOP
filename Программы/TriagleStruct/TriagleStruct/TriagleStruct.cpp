﻿// TriagleStruct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ModuleTriagle.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle Test(1,2, 3,4, 5,6);
    cout << Test.Data_Triangle();
    
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
