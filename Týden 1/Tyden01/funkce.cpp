#include "funkce.h"

#include <iostream>

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
