#include <string>
#include <iostream>

// Classe para representar planetas, tem como parâmetros o nome e o tempo de visita
class Planet {
private:
    std::string name;
    int visitTime;
    

public:
    Planet();
    Planet(std::string name, int visitTime);

    int getTime();
    std::string getName();
};