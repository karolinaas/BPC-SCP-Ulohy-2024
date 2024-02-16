// Tyden02.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

void bubble(int *A, int *B, int lenght);
void cramer(int **C, int *D);

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    int *A, *B, **C;
    A = new int[argc - 1];
    B = new int[argc - 1];
    C = new int*[3];
    for (int i = 0; i < 3; i++) {
        C[i] = new int[3];
    }

    // Naplnění pole A argumenty
    for (int i = 0; i < argc - 1; i++) {
        A[i] = atoi(argv[i + 1]);
    }

    // Naplnění pole C argumenty
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = atoi(argv[])
        }
    }

    bubble(A, B, argc - 1);

    // Vypsání pole A
    std::cout << "A: ";
    for (int i = 0; i < argc - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // Vypsání pole B
    std::cout << "B: ";
    for (int i = 0; i < argc - 1; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    for (int i = 0; i < 3; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}

void bubble(int *A, int *B, int lenght) {
    
    // Naplnění pole B polem A
    for (int i = 0; i < lenght; i++) {
        B[i] = A[i];
    }
    int temp;

    // Třídění pole B
    for (int i = 0; i < lenght - 1; i++) {
        for (int j = 0; j < lenght - i - 1; j++) {
            if (B[j] > B[j + 1]) {
                temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
            }
        }
    }
}

void cramer(int** C, int* D) {

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
