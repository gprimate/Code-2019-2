#include <iostream>

int Cal2n (int n) {
    if (n >= 1) {
        return 2 * Cal2n(n - 1);
    } else {
        return 1;
    }
}

int main()
{
    int teste = 4;
    
    std::cout << Cal2n(teste) <<std::endl;
    return 0;
}