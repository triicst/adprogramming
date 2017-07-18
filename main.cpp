/* 
 * File:   main.cpp
 * Author: maciek
 *
 * Created on 29 październik 2013, 17:15
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>

#include "Matrix.hpp"

using namespace std;

int main()
{
    try
    {
        cout << "********************************************************" << endl;
        cout << "****************   Start of tests   ********************" << endl;
        cout << "********************************************************" << endl;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\tTworzenie różnych rodzajów macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        Matrix X, Y(2,16);
        cout << "Macierz X" << X << endl;
        cout << "Macierz Y" << Y << endl;
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\tWprowadzanie danych do macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << "Macierz X przed wprowadzeniem danych" << X << endl;
        X.setData("14,45 , 3, 78,90,58,34,234,34");
        cout << "...po wprowadzeniu danych" << X << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "Pobieranie informacji o liczbie wierszy i kolumn macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << endl << "Utworzenie macierzy W o rozmiarach 6 wierszy na 4 kolumn";
        Matrix W(6,4);
        cout << W;
        cout << "Liczba wierszy to: " << getNumberOfRows(W) << endl;
        cout << "Liczba kolumn to: " << getNumberOfColumns(W) << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "\t\tPrzypisywanie (kopiowanie) macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << "Przypisanie macierzy Y = X" << endl;
        cout << "Macierz X" << X;
        cout << "...przypisanie Y = X..." << endl;
        Y = X;
        cout << "Macierz Y" << Y << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "\t\tPobieranie elementu macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << "Macierz Y o wymiarach 3x3" << Y << endl;
        cout << "Pobranie elemenutu z tablicy Y(1,1) = " << Y(1,1) << endl;
        cout << "Pobranie elemenutu z tablicy Y(3,3) = " << Y(3,3) << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "\tNajwyższa wartość w macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << "Macierz X" << X << endl;
        cout << "Najwyższa wartość w macierzy X to: " << X.highestValue() << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "\tDodawanie i odejmowanie macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << endl << "Dodanie macierzy Y do macierzy X -> X+=Y" << endl;
        X+=Y;
        cout << X << endl;
        cout << "Odjęcie macierzy Y od macierzy X -> X-=Y" << endl;
        X-=Y;
        cout << X << endl;
        
        
        cout << endl << "------------------------------------------------------------" << endl;
        cout << endl << "\t\tMnożenie macierzy" << endl;
        cout << endl << "------------------------------------------------------------" << endl;
        
        cout << endl << "Utworzenie macierzy A i B" << endl;
        Matrix a(3,2), b(2,3);
        a.setData("2,2,3,3,4,4");
        b.setData("2,3,4,2,3,4");
        cout << "Macierz a" << a << "Macierz b" << b << endl;
        cout << "Pomnożenie macierzy a * b i wyświetlenie macierzy c" << endl;
        Matrix c=a*b;
        cout << "Macierz c" << c;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tPotęgowanie macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << "Macierz Z";
        Matrix Z(3,3), temp;
        Z.setData("1,2,3,1,2,3,1,2,3");
        temp = Z;
        cout << Z << endl;
        
        cout << endl << "Potęgowanie macierzy Z^0" << endl;
        temp = Z^0;
        cout << temp << endl;
        
        cout << "Potęgowanie macierzy Z^1" << endl;
        temp = Z^1;
        cout << temp << endl;
        
        cout << "Potęgowanie macierzy Z^2" << endl;
        temp = Z^2;
        cout << temp << endl;
        
        cout << "Potęgowanie macierzy Z^3" << endl;
        temp = Z^3;
        cout << temp << endl;
        
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tTransponowanie macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << "Macierz b" << b << endl;
        cout << "Transponowanie macierzy b" << endl;
        b = b.transpose();
        cout << b << endl;
        
        Matrix b1(5,5);
        b1.setData("1,2,3,6,5,4,3,7,2,1,2,3,4,4,0,0,5,4,3,2,3,4,6,9,1");
        cout << "Macierz b1" << b1 << endl;
        cout << "Transponowanie macierzy b1" << endl;
        b1 = b1.transpose();
        cout << b1;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\tUsuwanie kolumn i wierszy z macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << endl << "Usuwanie 3 kolumny z macierzy e" << endl;
        Matrix e(4,4);
        e.setData("1,2,3,6,5,4,3,7,2,1,2,3,4,4,0,0");
        cout << "Macierz e" << e;
        e = removeColumn(e,4);
        cout << e << endl;
        
        cout << endl << "Usuwanie 3 wiersza z macierzy e" << endl;
        cout << "Macierz e" << e;
        e = removeRow(e,4);
        cout << e << endl;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tOblicznie wyznacznika macierzy" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << endl << "Wyznacznik macierzy f" << endl;
        Matrix f(1,1);
        f.setData("68");
        cout << "Macierz f" << f;
        cout << "Wyznacznik macierzy = " << determinant(f) << endl;
        
        cout << endl << "Wyznacznik macierzy g" << endl;
        Matrix g(2,2);
        g.setData("3,2,4,-2");
        cout << "Macierz g" << g;
        cout << "Wyznacznik macierzy = " << determinant(g) << endl;
        
        cout << endl << "Wyznacznik macierzy g1" << endl;
        Matrix g1(2,2);
        g1.setData("0,1,1,-1");
        cout << "Macierz g1" << g1;
        cout << "Wyznacznik macierzy = " << determinant(g1) << endl;
        
        cout << endl << "Wyznacznik macierzy h" << endl;
        Matrix h(2,2);
        h.setData("-1000,+2000,-234,-23");
        cout << "Macierz h" << h;
        cout << "Wyznacznik macierzy = " << determinant(h) << endl;
        
        cout << endl << "Wyznacznik macierzy i" << endl;
        Matrix i(3,3);
        i.setData("1,2,3,6,5,4,3,7,2");
        cout << "Macierz i" << i;
        cout << "Wyznacznik macierzy = " << determinant(i) << endl;
        
        cout << endl << "Wyznacznik macierzy p" << endl;
        Matrix p(4,4);
        p.setData("1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2");
        cout << "Macierz p" << p;
        cout << "Wyznacznik macierzy = " << determinant(p) << endl;
        
        cout << endl << "Wyznacznik macierzy qq" << endl;
        Matrix qq(7,7);
        qq.setData("1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1");
        cout << "Macierz p" << qq;
        cout << "Wyznacznik macierzy = " << determinant(qq) << endl;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tOdwracanie macierzy R" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        Matrix R(3,3), R1;
        R.setData("1,1,3,3,1,3,2,2,2");
        //R.setData("1,2,1,1,0,1,2,1,-1");
        cout << "Macierz R" << R;
        cout << "Wyznacznik macierzy R: " << determinant(R) << endl;
        
        cout << endl << "Macierz odwrotna do macierzy R";
        R1 = R^-1;
        cout << R1 << endl;
        cout << "Sprawdzenie R*R^-1";
        R = R*R1;
        cout << R;
        
        
        Matrix S(7,7), S1;
        S.setData("1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1,3,-4,2,3,0,2,-1,2,1,0,3,0,0,5,2,1");
        cout << endl << endl << "Macierz S" << S;
        cout << "Wyznacznik macierzy S: " << determinant(S) << endl;
        
        cout << endl << "Macierz odwrotna do macierzy S";
        S1 = S^-1;
        cout << S1 << endl;
        cout << "Sprawdzenie S*S^-1";
        S = S*S1;
        cout << S;
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tFunkcje dodatkowe += helpery" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        cout << "-1%2 = " << -1%2 << endl;
        cout << "0%2 = " << 0%2 << endl;
        cout << "1%2 = " << 1%2 << endl;
        cout << "2%2 = " << 2%2 << endl;
        cout << "3%2 = " << 3%2 << endl;
        cout << "4%2 = " << 4%2 << endl;
        cout << "------" << endl;
        cout << "0 = " << 0 << endl;
        cout << "-0 = " << -0 << endl;
        cout << "-(0) = " << -(0) << endl;
        cout << "(-0) = " << (-0) << endl;
        
        
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "\t\tMetoda Najmniejszych Kwadratów" << endl;
        cout << endl << "--------------------------------------------------------" << endl;
        
        Matrix X1(9,2), Y1(9,1), Result;
        X1.setData("2,1,3,1,4,1,6,1,8,1,9,1,11,1,12,1,13,1");
        Y1.setData("12,11,15,17,16,19,21,20,19");
        
        cout << "Macierz X1:" << X1 << endl;
        cout << "Macierz Y1:" << Y1 << endl;
        
        Result = X1.transpose() * X1;
        Result = Result^-1;
        Result = Result * (X1.transpose() * Y1);
        
        cout << "Wynik:" << Result << endl;
        
        cout << endl << "********************************************************";
        cout << endl << "******************   End of tests   ********************";
        cout << endl << "********************************************************" << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;
}
