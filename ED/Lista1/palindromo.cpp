#include <iostream>

int Palindromo(int esq, int dir, char palavra[]) {
    if (palavra[esq] == palavra[dir]) {

        if (dir - esq <= 1) {
            return 1;

        } else {
            dir -= 1; 
            esq += 1;

            return Palindromo(esq, dir, palavra);
        }

    } else {

        return 0;
    }
}

int main()
{
    int teste = 0;
    char bananinha [] = "avpa";
    teste = Palindromo(0,3,bananinha);
    std::cout << teste <<std::endl;
    return 0;
}

