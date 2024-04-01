#include <iostream>
#include "file2.h"

extern int globalVariable;

void function2() {
    std::cout << "globalVariable in file2.cpp: " << globalVariable << std::endl;
}