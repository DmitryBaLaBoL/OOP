#include "MatrixStruct.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix Test(3,3), Test1(3, 3), Test2(3, 3);
    Test.fill_matrix_oneEl(10);
    Test1.fill_matrix_oneEl(20);
    Test.get_matrix();
    Test1.get_matrix();
    Test *= 132;
    Test.get_matrix();
    Test += 132;
    Test.get_matrix();
    

}

