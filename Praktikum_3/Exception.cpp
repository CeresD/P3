//
// Created by ceres on 01.05.18.
//

#include "Exception.h"

Exception::Exception(std::string err) {

    this->err = err;
}

std::string Exception::toString() {

    return err;
}