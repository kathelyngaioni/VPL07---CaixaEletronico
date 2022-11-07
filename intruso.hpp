#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <iostream>
#include <string>
#include <set>

class Intruso {
private:
   std::set<std::string>entradas;
public:
    void set_senha_vazada(std::string vazou);
    std::string crack_senha();
};
#endif