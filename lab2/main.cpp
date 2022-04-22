#include <cstdio>
#include "vector.hpp"

template <typename Type>
string stringVector(const Vector<Type> &vec)
{
    string rez = "";
    for (auto cur : vec)
        rez += to_string(cur) + ", ";
    return rez;
}

int main()
{
    Vector<double> initializerListExample = {1, 2, 3};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(3, 6.66);
    Vector<long double> emptyVector(0);


    std::cout<< "initializerListInit: "<< stringVector(initializerListExample) << std::endl;
    std::cout<< "lenInit: "<< stringVector(lenExample) << std::endl;
    std::cout<< "LenFillInit with 6.66 filler: "<< stringVector(lenFillExample) << std::endl;
    std::cout<< "Empty vector: "<< stringVector(emptyVector) << std::endl;

    Vector<int> operVecF = {1, 2, 1};
    Vector<int> operVecS = {3, 2, 4};

    std::cout<< "\nLenFill and InitList angle: "<< lenFillExample.angle(initializerListExample)<< std::endl;

    std::cout<< "\nFor vectors: "<< stringVector(operVecF) << " and "<< stringVector(operVecS) << std::endl;
    std::cout<< "Vectors *: "<< stringVector(operVecF * operVecS) << std::endl;
    std::cout<< "Vectors ^: "<< stringVector(operVecF ^ operVecS) << std::endl;
    std::cout<< "Vectors /: "<< stringVector(operVecF / operVecS) << std::endl;
    std::cout<< "Vectors +: "<< stringVector(operVecF + operVecS) << std::endl;
    std::cout<< "Vectors -: "<< stringVector(operVecF - operVecS) << std::endl;

    Vector<float> orthVecF = {1, 0, 0};
    Vector<float> orthVecS = {0, 1, 0};
    Vector<float> nonOrthVec = {1, 2, 3};

    std::cout<< "\nShould be perpendicular: "<< orthVecF.perpendicular(orthVecS) << std::endl;
    std::cout<< "Shouldn't be perpendicular: "<<orthVecF.perpendicular(nonOrthVec) << std::endl;

    Vector<int> colVecF = {1, 0, 0};
    Vector<int> colVecS = {1, 0, 0};

    std::cout<< "\nShould be parallel: "<< colVecF.parallel(colVecS) << std::endl;
    std::cout<< "Shouldn't be parallel: "<< colVecF.parallel(operVecF) << std::endl;

    try {
        orthVecF.parallel(lenExample);
    } catch (VectorsException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    std::cout<< "\nVector "<< colVecS<< " length is: "<< colVecS.lenght<float>()<<std::endl;

    std::cout<< "\nAt 1 el of vector "<< stringVector(nonOrthVec) << " we have "<< nonOrthVec.at(1)<<std::endl;
    std::cout<< "At 2 el of vector "<< stringVector(nonOrthVec) << " we have "<< nonOrthVec.at(2)<<std::endl;

    try {
        std::cout<< "At 5 el of vector "<< stringVector(nonOrthVec) << " we have\n"<< nonOrthVec.at(5)<<std::endl;
    } catch (VectorsException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    std::cout<< "Is vector "<< stringVector(nonOrthVec) << " unit? Answer: "<< nonOrthVec.isSingleVector()<< std::endl;

    std::cout<< "\nIs vector "<< stringVector(nonOrthVec) << " zero? Answer: "<< nonOrthVec.isZeroVector()<< std::endl;
    std::cout<< "Is vector "<< stringVector(lenExample) << " zero? Answer: "<< lenExample.isZeroVector()<< std::endl;

    std::cout<< "\nIncrement to all coords 4 of "<< stringVector(nonOrthVec) << " is: "<< stringVector(nonOrthVec.sumEl(4))<<std::endl;
    std::cout<< "Decrement to all coords 4 of "<< stringVector(nonOrthVec) << " is: "<< stringVector(nonOrthVec.difEl(4)) <<std::endl;
    std::cout<< "Div to all coords 4 of "<< stringVector(nonOrthVec) << " is: "<< stringVector(nonOrthVec.divEl(4)) <<std::endl;
    std::cout<< "Mul to all coords 4 of "<< stringVector(nonOrthVec) << " is: " << stringVector(nonOrthVec.vecMulEl(4)) <<std::endl;

    std::cout<< "\nFor each: ";
    for (auto elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each &: ";
    for (auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each const &: ";
    for (const auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nNonNeg: "<< stringVector(nonOrthVec)<< std::endl;
    nonOrthVec = nonOrthVec.negative();
    std::cout<< "Neg: "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec += 1;
    std::cout<< "+= 1 "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec -= 1;
    std::cout<< "-= 1 "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec *= 2;
    std::cout<< "*= 2 "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec /= 2;
    std::cout<< "/= 2 "<< stringVector(nonOrthVec) << std::endl;

    std::cout<< "The same with phrases... "<< std::endl;

    nonOrthVec.sumEq(1);
    std::cout<< "+= 1 "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec.difEq(1);
    std::cout<< "-= 1 "<< stringVector(nonOrthVec) << std::endl;

    nonOrthVec.vecMulEq(2);
    std::cout<< "*= 2 "<< stringVector(nonOrthVec)<< std::endl;

    nonOrthVec.divEq(2);
    std::cout<< "/= 2 "<< stringVector(nonOrthVec) << std::endl;

    std::cout<< stringVector(nonOrthVec) << " + 3 = "<< stringVector(nonOrthVec + float(3)) << std::endl;
    std::cout<< stringVector(nonOrthVec) << " - 3 = "<< stringVector(nonOrthVec - float(3)) << std::endl;
    std::cout<< stringVector(nonOrthVec) << " / 3 = "<< stringVector(nonOrthVec / float(3)) << std::endl;
    std::cout<< stringVector(nonOrthVec) << " * 3 = "<< stringVector(nonOrthVec * float(3)) << std::endl;

    return 0;
}
