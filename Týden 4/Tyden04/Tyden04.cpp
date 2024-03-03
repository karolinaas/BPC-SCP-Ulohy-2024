// Tyden04.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string.h>
#include <cstdlib>

class pole {
    // Jednorozměrné pole typu int
    int *p, s;

public:
    // Konstruktor s jedním parametrem udávajícím velikost alokace
    pole(int s) {
        p = new int[this->s = s];
    }

    // Konstruktor se dvěma parametry, první udává velikost alokace, druhý hodnotu, na kterou se nastaví všechny prvky pole
    pole(int s, int value) {
        p = new int[this->s = s];

        for (int i = 0; i < s; i++) {
            p[i] = value;
        }
    }

    // Konverzní konstruktor s parametrem char*, který přiřadí ASCII hodnoty jednotlivých znaků prvkům pole
    pole(const char* c) {
        s = strlen(c);
        p = new int[s];

        for (int i = 0; i < s; i++) {
            p[i] = c[i];
        }
    }

    // Kopírovací konstruktor
    pole(pole &x) {
        p = new int[s = x.s];

        for (int i = 0; i < x.s; i++) {
            p[i] = x.p[i];
        }
    }

    // Metoda pro naplnění pole náhodnými hodnotami
    void randomize(void) {
        for (int i = 0; i < this->s; i++) {
            this->p[i] = rand();
        }
    }

    // Metoda pro sčítání jednotlivých prvků dvou polí
    void soucet(pole &A) {
        for (int i = 0; i < this->s; i++) {
            this->p[i] += A.p[i];
        }
    }

    // Metoda pro tisk pole na konzoli
    void tisk(void) {
        for (int i = 0; i < this->s; i++) {
            std::cout << this->p[i] << " ";
        }

        std::cout << std::endl;
    }

    // Destruktor dealokující zapouzdřenou paměť
    ~pole() {
        delete[] p;
    }

    friend void friend_soucet(pole &A, pole &B, pole &C);
};

// Metoda pro sčítání dvou polí
void friend_soucet(pole &A, pole &B, pole &C) {
    for (int i = 0; i < C.s; i++) {
        C.p[i] = A.p[i] + B.p[i];
    }
}

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "Alokace se dvema parametry:" << std::endl;
    pole A(3, 3);
    A.tisk();

    std::cout << "Alokace s jednim parametrem a naplneni nahodnymi hodnotami:" << std::endl;
    pole B(3);
    B.randomize();
    B.tisk();

    std::cout << "Konverzni konstruktor:" << std::endl;
    pole C("ahoj");
    C.tisk();

    std::cout << "Kopirovaci konstruktor (kopirovani z nahodneho pole):" << std::endl;
    pole D(B);
    D.tisk();

    std::cout << "Metoda pro scitani:" << std::endl;
    pole E(3, 2), F(3, 4);
    E.tisk();
    F.tisk();
    E.soucet(F);
    E.tisk();

    std::cout << "Spratelena metoda pro scitani:" << std::endl;
    pole G(10, 120), H(10, 240), I(10);
    friend_soucet(G, H, I);
    G.tisk();
    H.tisk();
    I.tisk();
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
