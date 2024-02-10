// funkce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void sude(int n);
void liche(int n);
void prvocisla(int n);
void faktorial(int n);

int main()
{
    std::cout << "Hello World!\n";

    sude(10);
    liche(10);
    prvocisla(20);
    faktorial(10);
}

void sude(int n) {
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            std::cout << i << " ";

        }
    }

    std::cout << std::endl;
}

void liche(int n) {
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 1) {
            std::cout << i << " ";

        }
    }

    std::cout << std::endl;
}

void prvocisla(int n) {
    int je_prvocislo = 1;

    for (int i = 2; i <= n; i++) {
        int je_prvocislo = 1;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                je_prvocislo = 0;
                break;
            }
        }

        if (je_prvocislo) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

void faktorial(int n) {
    if (n == 0) {
        std::cout << 0 << std::endl;
    }

    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    std::cout << fact << std::endl;
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
