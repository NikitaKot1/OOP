#ifndef EXCEPTIONREALISATION_HPP
#define EXCEPTIONREALISATION_HPP

#include "exceptionRoot.hpp"

VectorsException::VectorsException(string fileName, string className, int curLine, 
                                   const char *errTime, string information)
{
    exceptInformation = "File: " + fileName + "\nClass: " + className + "\nLine: "
                        + std::to_string(curLine) + "\nTime: " + errTime +
                        "\nInformation: " + information;
}

const char *VectorsException::what() const noexcept
{
    return exceptInformation.c_str();
}

#endif