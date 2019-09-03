#include <iostream>

int Palindromo(int esq, int dir, char palavra[]) {
    int limite = dir;

    for (esq; esq < limite; esq++) {
   
        if (palavra[esq] != palavra[dir]) {
            return 0;

        } else if (dir - esq <= 1) {
            return 1;

        } else {
            dir -= 1;
        }
    }

    return 0;
}

int main()
{
    int teste;
    char bananinha [] = "arara";
    teste = Palindromo(0,4,bananinha);
    std::cout << teste <<std::endl;
    return 0;
}