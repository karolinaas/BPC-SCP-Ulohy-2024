// Tyden08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <Windows.h>

template<class T> class LIFO {
    T* arr;
    int hloubka, posledni;

public:
    LIFO(int n) {
        arr = new T[hloubka = n];
        posledni = -1;
    }

    ~LIFO() {
        delete[] arr;
    }

    void Push(T T) {
        if (posledni + 1 == hloubka) {
            throw((std::string)"Pridani prvku do plneho zasobniku!");
        }

        posledni++;
        arr[posledni] = T;
    }

    T Pop() {
        if (posledni == -1) {
            throw((std::string)"Odebrani prvku z prazdneho zasobniku!");
        }

        posledni--;

        return arr[posledni + 1];
    }

    int get_hloubka() {
        return hloubka;
    }
};

class Prvek {};

int main()
{
    std::cout << "Hello World!\n";

    srand(time(NULL));

    LIFO<Prvek> lifo(1 + rand() % 10);

    std::cout << "Velikost LIFO: " << lifo.get_hloubka() << std::endl;

    while (1) {
        try {
            // Pokud je náhodné èíslo sudé tak push, pokud je liché tak pop
            if (rand() % 2) {
                Prvek x;
                lifo.Push(x);
            }
            else {
                lifo.Pop();
            }
        }
        catch(std::string error) {
            std::cout << error << std::endl;
        }

        Sleep(1);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
