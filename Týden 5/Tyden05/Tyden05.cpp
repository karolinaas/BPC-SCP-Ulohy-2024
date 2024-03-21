// Tyden05.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Tvar {
protected:
    int pocet_rozmeru;
    float *rozmery;
    std::string nazev_tvaru;

public:
    Tvar(int pocet_rozmeru) {
        rozmery = new float[this->pocet_rozmeru = pocet_rozmeru];
    }

    ~Tvar() {
        delete[] rozmery;
    }

    virtual std::string vykresleni(void) = 0;
    virtual float obvod(void) = 0;
    virtual float obsah(void) = 0;

    void tisk(void) {
        std::cout << vykresleni() << std::endl;
    }
};

class Kruh : public Tvar {
public:
    Kruh(float polomer) : Tvar(1) {
        rozmery[0] = polomer;
        nazev_tvaru = "Kruh";
    }

    virtual std::string vykresleni(void) {
        return std::string("Tvar: " + this->nazev_tvaru + "; Obvod: " + std::to_string(this->obvod()) + "; Obsah: " + std::to_string(this->obsah()));
    }
    virtual float obvod(void) {
        return 2 * M_PI * rozmery[0];
    }
    virtual float obsah(void) {
        return M_PI * rozmery[0] * rozmery[0];
    }
};

class Trojuhelnik : public Tvar {
public:
    Trojuhelnik(float a, float b, float c) : Tvar(3) {
        rozmery[0] = a;
        rozmery[1] = b;
        rozmery[2] = c;

        nazev_tvaru = "Trojuhelnik";
    }

    virtual std::string vykresleni(void) {
        return std::string("Tvar: " + this->nazev_tvaru + "; Pocet stran: " + std::to_string(this->pocet_rozmeru) + "; Obvod: " + std::to_string(this->obvod()) + "; Obsah: " + std::to_string(this->obsah()));
    }
    virtual float obvod(void) {
        float obvod = 0;

        for (int i = 0; i < pocet_rozmeru; i++) {
            obvod += rozmery[i];
        }

        return obvod;
    }
    virtual float obsah(void) {
        // Heronuv vzorec
        float s = this->obvod() / 2.0;
        
        return sqrt(s * (s - this->rozmery[0]) * (s - this->rozmery[1]) * (s - this->rozmery[2]));
    }
};

class Obdelnik : public Tvar {
public:
    Obdelnik(float a, float b) : Tvar(2) {
        rozmery[0] = a;
        rozmery[1] = b;

        nazev_tvaru = "Obdelnik";
    }

    virtual std::string vykresleni(void) {
        return std::string("Tvar: " + this->nazev_tvaru + "; Pocet stran: " + std::to_string(this->pocet_rozmeru * 2) + "; Obvod: " + std::to_string(this->obvod()) + "; Obsah: " + std::to_string(this->obsah()));
    }
    virtual float obvod(void) {
        float obvod = 0;

        for (int i = 0; i < pocet_rozmeru; i++) {
            obvod += rozmery[i];
        }

        return obvod * 2;
    }
    virtual float obsah(void) {
        return this->rozmery[0] * this->rozmery[1];
    }
};

class Barevny_Obdelnik : public Obdelnik {
protected:
    std::string barva;
public:
    Barevny_Obdelnik(float a, float b, std::string barva) : Obdelnik(a, b) {
        this->barva = barva;

        nazev_tvaru = "Barevny obdelnik";
    }

    virtual std::string vykresleni(void) {
        return std::string("Tvar: " + this->nazev_tvaru + "; Pocet stran: " + std::to_string(this->pocet_rozmeru * 2) + "; Obvod: " + std::to_string(this->obvod()) + "; Obsah: " + std::to_string(this->obsah()) + "; Barva: " + this->barva);
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Tvar *tvar[20];

    srand(time(NULL));
    
    for (int i = 0; i < 20; i++) {
        switch (rand() % 4) {
        case 0:
            tvar[i] = new Kruh(float(rand() % 100));
            break;
        case 1:
            tvar[i] = new Trojuhelnik(float(rand() % 100), float(rand() % 100), float(rand() % 100));
            break;
        case 2:
            tvar[i] = new Obdelnik(float(rand() % 100), float(rand() % 100));
            break;
        case 3:
            tvar[i] = new Barevny_Obdelnik(float(rand() % 100), float(rand() % 100), "cervena");
            break;
        }
    }

    for (int i = 0; i < 20; i++) {
        tvar[i]->tisk();
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
