#include <iostream>

int main()
{
    double zahl1, zahl2;

    std::string myString = "Hello World!";
    std::cout << "Hello World!" << std::endl;
    std::cout << myString.length() << std::endl;
    std::cout << "Konkatenierungstest:" << myString.size() << " Zahl1: " << zahl1 << " Zahl2:" << zahl2 << std::endl;
    std::cin >> zahl1;
    std::cin >> zahl2;
    std::cout << "Summe: " << zahl1 + zahl2 << std::endl;
}