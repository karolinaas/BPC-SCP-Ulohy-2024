// Tyden06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

class Matice {
    float **matice;
    int pocet_radku, pocet_sloupcu;

public:
    // Incializující konstruktor
    Matice(int pocet_radku, int pocet_sloupcu) {
        matice = new float* [this->pocet_radku = pocet_radku];
        for (int i = 0; i < pocet_radku; i++) {
            matice[i] = new float[this->pocet_sloupcu = pocet_sloupcu];
        }
    }

    // Kopírovací konstruktor
    Matice(Matice &x) {
        matice = new float* [pocet_radku = x.pocet_radku];
        for (int i = 0; i < pocet_radku; i++) {
            matice[i] = new float[pocet_sloupcu = x.pocet_sloupcu];
        }

        for (int i = 0; i < pocet_radku; i++) {
            for (int j = 0; j < pocet_sloupcu; j++) {
                matice[i][j] = x.matice[i][j];
            }
        }
    }

    // Konverzní konstruktor, parametrem je 2D pole
    Matice(const float **x) {
        pocet_radku = sizeof(x) / sizeof(x[0]);
        pocet_sloupcu = sizeof(x[0]) / sizeof(x[0][0]);

        matice = new float* [pocet_radku];
        for (int i = 0; i < pocet_radku; i++) {
            matice[i] = new float[pocet_sloupcu];
        }

        for (int i = 0; i < pocet_radku; i++) {
            for (int j = 0; j < pocet_sloupcu; j++) {
                matice[i][j] = x[i][j];
            }
        }
    }

    // Destruktor
    ~Matice() {\
        for (int i = 0; i < pocet_radku; i++) {
            delete[] matice[i];
        }
        delete[] matice;
    }

    void fill(int max) {
        for (int i = 0; i < this->pocet_radku; i++) {
            for (int j = 0; j < this->pocet_sloupcu; j++) {
                matice[i][j] = float(rand() % max);
            }
        }
    }

    // Binární operátory
    friend Matice operator+(const Matice& operand1, const Matice& operand2);
    friend Matice operator-(const Matice& operand1, const Matice& operand2);
    friend Matice operator*(const Matice& operand1, const Matice& operand2);
    // Skalární operace
    friend Matice operator+(const Matice& operand1, const float& operand2);
    friend Matice operator-(const Matice& operand1, const float& operand2);
    friend Matice operator*(const Matice& operand1, const float& operand2);
    friend Matice operator/(const Matice& operand1, const float& operand2);


    // Unární operátor -
    Matice operator-() {
        Matice vysledek(this->pocet_radku, this->pocet_sloupcu);

        for (int i = 0; i < this->pocet_radku; i++) {
            for (int j = 0; j < this->pocet_sloupcu; j++) {
                vysledek.matice[i][j] = -this->matice[i][j];
            }
        }

        return vysledek;

    }

    // Operátor pøiøazení
    Matice& operator=(const Matice &x) {
        if (matice != NULL) {
            for (int i = 0; i < pocet_radku; i++) {
                delete[] matice[i];
            }
            delete[] matice;
        }

        matice = new float* [pocet_radku = x.pocet_radku];
        for (int i = 0; i < pocet_radku; i++) {
            matice[i] = new float[pocet_sloupcu = x.pocet_sloupcu];
        }

        for (int i = 0; i < pocet_radku; i++) {
            for (int j = 0; j < pocet_sloupcu; j++) {
                matice[i][j] = x.matice[i][j];
            }
        }

        return *this;
    }

    // Operátor [] pro indexování prvkù matice
    float* operator[](int i) const {
        return matice[i];
    }

    // Operátor << pro výpis matice na konzoli
    friend std::ostream& operator<<(std::ostream& out, Matice& x);
};

// Binární operátory
Matice operator+(const Matice& operand1, const Matice &operand2) {
    if (operand1.pocet_radku == operand2.pocet_radku && operand1.pocet_sloupcu == operand2.pocet_sloupcu) {
        Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

        for (int i = 0; i < operand1.pocet_radku; i++) {
            for (int j = 0; j < operand1.pocet_sloupcu; j++) {
                vysledek.matice[i][j] = operand1.matice[i][j] + operand2.matice[i][j];
            }
        }

        return vysledek;
    }
    else return NULL;
}

Matice operator-(const Matice& operand1, const Matice &operand2) {
    if (operand1.pocet_radku == operand2.pocet_radku && operand1.pocet_sloupcu == operand2.pocet_sloupcu) {
        Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

        for (int i = 0; i < operand1.pocet_radku; i++) {
            for (int j = 0; j < operand1.pocet_sloupcu; j++) {
                vysledek.matice[i][j] = operand1.matice[i][j] - operand2.matice[i][j];
            }
        }

        return vysledek;
    }
    else return NULL;
}

Matice operator*(const Matice& operand1, const Matice &operand2) {
    if (operand1.pocet_sloupcu == operand2.pocet_radku) {
        Matice vysledek(operand2.pocet_radku, operand1.pocet_sloupcu);

        for (int i = 0; i < operand1.pocet_radku; i++) {
            for (int j = 0; j < operand2.pocet_sloupcu; j++) {
                for (int k = 0; k < operand1.pocet_sloupcu; k++) {
                    vysledek.matice[i][j] = operand1.matice[i][k] * operand2.matice[k][j];
                }
            }
        }

        return vysledek;
    }
    else return NULL;
}

Matice operator+(const Matice& operand1, const float& operand2) {
    Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

    for (int i = 0; i < operand1.pocet_radku; i++) {
        for (int j = 0; j < operand1.pocet_sloupcu; j++) {
            vysledek.matice[i][j] = operand1.matice[i][j] + operand2;
        }
    }

    return vysledek;
}

Matice operator-(const Matice& operand1, const float& operand2) {
    Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

    for (int i = 0; i < operand1.pocet_radku; i++) {
        for (int j = 0; j < operand1.pocet_sloupcu; j++) {
            vysledek.matice[i][j] = operand1.matice[i][j] - operand2;
        }
    }

    return vysledek;
}

Matice operator*(const Matice& operand1, const float& operand2) {
    Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

    for (int i = 0; i < operand1.pocet_radku; i++) {
        for (int j = 0; j < operand1.pocet_sloupcu; j++) {
            vysledek.matice[i][j] = operand1.matice[i][j] * operand2;
        }
    }

    return vysledek;
}

Matice operator/(const Matice& operand1, const float& operand2) {
    Matice vysledek(operand1.pocet_radku, operand1.pocet_sloupcu);

    for (int i = 0; i < operand1.pocet_radku; i++) {
        for (int j = 0; j < operand1.pocet_sloupcu; j++) {
            vysledek.matice[i][j] = operand1.matice[i][j] / operand2;
        }
    }

    return vysledek;
}

std::ostream& operator<<(std::ostream& out, Matice& x) {
    for (int i = 0; i < x.pocet_radku; i++) {
        for (int j = 0; j < x.pocet_sloupcu; j++) {
            out << x.matice[i][j] << " ";
        }

        out << std::endl;
    }

    return out;
}

int main()
{
    std::cout << "Hello World!\n";

    srand(time(NULL));

    Matice A(3, 4), B(3, 4), C(3, 4);

    A.fill(20);
    B.fill(20);
    C.fill(20);

    C = -A + B + 3 + B[1][2];

    std::cout << A << std::endl << B << std::endl << C << std::endl;
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
