#include <string>
#include <iostream>

class Planet {
private:
    std::string name;
    int visitTime;
    

public:
    Planet();
    Planet(std::string name, int visitTime);

    int getTime();
    std::string getName();

    void setTime(int visitTime);
};