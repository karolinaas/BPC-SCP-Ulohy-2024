// Tyden03.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <math.h>

class Complex {
    double real, imag;

public:
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex() {

    }

    void setr(double r) {
        this->real = r;
    }

    void seti(double i) {
        this->imag = i;
    }

    double getr(void) {
        return this->real;
    }

    double geti(void) {
        return this->imag;
    }

    double modul(void) {
        return sqrt(this->real * this->real + this->imag * this->imag);
    }

    double faze(void) {
        return atan(this->imag / this->real);
    }

    void tisk(void) {
        if (imag >= 0) {
            std::cout << this->real << "+" << this->imag << "i" << std::endl;

        }
        else {
            std::cout << this->real << this->imag << "i" << std::endl;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Complex A(2, 5), *C;
    C = new Complex[10];

    std::cout << "Static real: " << A.getr() << std::endl;
    std::cout << "Static imag: " << A.geti() << std::endl << std::endl;

    std::cout << "Modul: " << A.modul() << std::endl;
    std::cout << "Faze: " << A.faze() << std::endl << std::endl;

    std::cout << "Static tisk: ";
    A.tisk();
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        C[i].setr(i);
        C[i].seti(-i);

        C[i].tisk();
    }
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
