// Tyden07.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

template<class T> class Pole {
    T* pole;
    int size;

public:
    // Konstruktor s jedním parametrem alokující paměť pro vnitřní pole prvků
    Pole(int size) {
        pole = new T[this->size = size];
    }

    // Operátor [] pro přímé indexování prvků pole (čtení i přiřazení)
    T& operator[](int i) {
        return pole[i];
    }

    // Destruktor dealokující vnitřní pole
    ~Pole() {
        delete[] pole;
    }

    // Deklarace spřátelené operátorové funkce pro přesměrování pole na konzoli
    template<class P> friend std::ostream& operator<<(std::ostream& out, Pole<P> &p);
};

template<class P> std::ostream& operator<<(std::ostream& out, Pole<P> &p) {
    for (int i = 0; i < p.size; i++) {
        out << p.pole[i] << " ";
    }

    out << std::endl;

    return out;
}

class Osoba {
    int ID, telefon;
    std::string jmeno, prijmeni;

public:
    // Metody pro nastavení proměnných
    void setID(int value) {
        ID = value;
    }

    void setJmeno(std::string value) {
        jmeno = value;
    }

    void setPrijmeni(std::string value) {
        prijmeni = value;
    }

    void setTelefon(int value) {
        telefon = value;
    }

    // Deklarace spřátelené funkce pro přesměrování objektu Osoba na konzoli
    friend std::ostream& operator<<(std::ostream& out, Osoba& o);
};

std::ostream& operator<<(std::ostream& out, Osoba& o) {
    out << o.ID << ": " << o.jmeno << " " << o.prijmeni << ", " << o.telefon << std::endl;

    return out;
}


int main()
{
    std::cout << "Hello World!\n";

    Pole<int> A(10);
    Pole<Osoba> B(10);

    std::string jmena[10] = { "Jan", "Michal", "Pavel", "Jakub", "Martin", "Tomas", "Ota", "Radek", "Zdenek", "Radim" };
    std::string prijmeni[10] = { "Mikulka", "Fiala", "Roubal", "Dohnal", "Friedl", "Kriz", "Korinek", "Sedlacek", "Drexler", "Dedek" };

    for (int i = 0; i < 10; i++) {
        A[i] = i + 1;

        B[i].setID(i + 1);
        B[i].setJmeno(jmena[rand() % 10]);
        B[i].setPrijmeni(prijmeni[rand() % 10]);
        B[i].setTelefon(1000 + rand() % 9000);
    }

    std::cout << A << std::endl << B << std::endl;

    return 0;
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
