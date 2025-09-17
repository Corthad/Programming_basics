#include <iostream>
#include <math.h>

int main()
{
    bool a1;
    short b1;
    unsigned short b2;
    int x1, b3; 
    unsigned int b4;
    long b5;
    unsigned long b6;
    long long b7;
    unsigned long long b8;
    signed char c1;
    unsigned char c2;
    float d1;
    double d2;
    long double d3;
    x1 = pow(2, 8*sizeof(b3));

    std::cout << "size bool = " << sizeof(a1) << ". Value = 2\n";
    std::cout << "size short = " << sizeof(b1) << ". Value from " << (-1) * pow(2, 8*sizeof(b1)-1) << " to " << pow(2, 8 * sizeof(b1)-1) - 1 << "\n";
    std::cout << "size unsigned short = " << sizeof(b2) << ". Value from " << 0 << " to " << pow(2, 8 * sizeof(b2))-1 << "\n";
    std::cout << "size int = " << sizeof(b3) << ". Value from " << x1 << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size unsigned int = " << sizeof(b4) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size long = " << sizeof(b5) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size unsigned long = " << sizeof(b6) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size long long = " << sizeof(b7) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size unsigned long long = " << sizeof(b8) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size signed char = " << sizeof(c1) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size unsined char = " << sizeof(c2) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size float = " << sizeof(d1) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size double = " << sizeof(d2) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";
    std::cout << "size long double = " << sizeof(d3) << ". Value from " << pow(2, 8*sizeof(a1)) << " to " << pow(2, 8 * sizeof(a1)) << "\n";


    std::cin >> b1 >> b2;
    x1 += 1;
    x1 -= 2;
    x1 *= 10;
    x1 /= 3;
    x1 %= 7;
    std::cout << b1 << b2;

}

