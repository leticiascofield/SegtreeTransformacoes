#include "../include/Matriz.hpp"

Matriz::Matriz() {}

Matriz::Matriz(unsigned long long int x1, unsigned long long int x2, unsigned long long int x3, unsigned long long int x4) {
    m[0][0] = x1;
    m[0][1] = x2;
    m[1][0] = x3;
    m[1][1] = x4;
}