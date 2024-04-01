#include <iostream>
#include "file1.h"

int globalVariable = 10;

void function1() {
    std::cout << "globalVariable in file1.cpp: " << globalVariable << std::endl;
}