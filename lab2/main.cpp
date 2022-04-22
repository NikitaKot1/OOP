#include <cstdio>
#include "vector.hpp"

int main()
{
    Vector<int> vec = {1, 2, 3};
    int arr[3] = {2, 3, 4};
    size_t ss = 3;
    const Vector<int> vec2(ss, arr);
    //int t = vec & vec2;
    Vector<int> vec3 = {1, 2, 3};
    //vec3 = vec.skewMulVec(vec2);
    //vec3 = vec + vec2;
    //vec.skewMulEq(vec2);
    //double angl = vec.angle(vec2);
    //double angl = vec.lenght<double>();
    //printf("%d\n", t);
    return 0;
}
