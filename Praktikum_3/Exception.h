//
// Created by ceres on 01.05.18.
//

#ifndef PRAKTIKUM_2_EXCEPTION_H
#define PRAKTIKUM_2_EXCEPTION_H


#include <string>

class Exception {

    std::string err;

public:
    Exception(std::string err);
    std::string toString();
};


#endif //PRAKTIKUM_2_EXCEPTION_H
