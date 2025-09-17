#include <iostream>
#include <math.h>

int main()
{
    bool a1;

    short b1;
    unsigned short b2;
    int b3, y0, y1, y2; 
    unsigned int b4;
    long b5;
    unsigned long b6;
    long long b7, x0, x1, x2;
    unsigned long long b8;

    signed char c1;
    unsigned char c2;

    float d1;
    double d2, z1, z2, z3;
    long double d3;

    std::cout << "size bool = " << sizeof(a1) << ". Value = 2\n";

    x0 = pow(2, sizeof(b1)*8 - 1);
    x1 = x0 * (-1);
    x2 = x0 - 1;
    std::cout << "size short = " << sizeof(b1) << ". Value from " << x1 << " to " << x2 << "\n";

    x0 = pow(2, sizeof(b2)*8);
    x1 = x0 * (-1);
    x2 = x0 - 1;
    std::cout << "size unsigned short = " << sizeof(b2) << ". Value from " << 0 << " to " << x2 << "\n";

    x0 = pow(2, sizeof(b3)*8 - 1);
    x1 = x0 * (-1);
    x2 = x0 - 1;
    std::cout << "size int = " << sizeof(b3) << ". Value from " << x1 << " to " << x2 << "\n";

    x0 = pow(2, sizeof(b4)*8);
    x1 = x0 * (-1);
    x2 = x0 - 1;
    std::cout << "size unsigned int = " << sizeof(b4) << ". Value from " << 0 << " to " << x2 << "\n";

    x0 = sizeof(b6)*8 - 1;
    x2 = x1 = x0;
    std::cout << "size long = " << sizeof(b5) << ". Value from (-1) * 2^" << x1 << " to 2^" << x2 << "\n";

    x0 = sizeof(b6)*8;
    x2 = x1 = x0;
    std::cout << "size unsigned long = " << sizeof(b6) << ". Value from " << 0 << " to 2^" << x2 << "\n";

    x0 = sizeof(b7)*8 - 1;
    x2 = x1 = x0;
    std::cout << "size long long = " << sizeof(b7) << ". Value from (-1) * 2^" << x1 << " to 2^" << x2 << "\n";

    x0 = sizeof(b8)*8;
    x2 = x1 = x0;
    std::cout << "size unsigned long long = " << sizeof(b8) << ". Value from " << 0 << " to 2^" << x2 << "\n";


    x0 = pow(2, sizeof(c1)*8 - 1);
    x1 = x0 * (-1);
    x2 = x0 - 1;    
    std::cout << "size signed char = " << sizeof(c1) << ". Value from " << x1 << " to " << x2 << "\n";

    x0 = pow(2, sizeof(c2)*8);
    x1 = x0 * (-1);
    x2 = x0 - 1;
    std::cout << "size unsined char = " << sizeof(c2) << ". Value from " << 0 << " to " << x2 << "\n";

    std::cout << "size float = " << sizeof(d1) << "\n";
    std::cout << "size double = " << sizeof(d2) << "\n";
    std::cout << "size long double = " << sizeof(d3) << "\n";


    std::cin >> y1 >> y2;
    y0 = y1 + y2;
    std::cout << "y1 + y2 = " << y0 << " Type = int\n";
    y0 = y1 - y2;
    std::cout << "y1 + y2 = " << y0 << " Type = int\n";
    y0 = y1 * y2;
    std::cout << "y1 + y2 = " << y0 << " Type = int\n";
    y0 = y1 / y2;
    std::cout << "y1 + y2 = " << y0 << " Type = int\n";
    y0 = y1 % y2;
    std::cout << "y1 % y2 = " << y0 << " Type = int\n";
    
    std::cin >> z1 >> z2;
    z3 = z1 / z2;
    std::cout << "z1 / z2 = " << z3 << " Type = double\n";

}