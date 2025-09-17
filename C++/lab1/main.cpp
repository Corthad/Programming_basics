#include <iostream>
#include <typeinfo>
#include <limits>

int main()
{
    bool a1;

    short b1;
    unsigned short b2;
    int b3, x0, y0, y1, y2; 
    unsigned int b4;
    long b5;
    unsigned long b6;
    long long b7;
    unsigned long long b8;

    signed char c1;
    unsigned char c2;

    float d1;
    double d2, x1, x2, z0, z1, z2;
    long double d3;

    using namespace std;

    x1 = numeric_limits<bool>::min();
    x2 = numeric_limits<bool>::max();
    cout << "Type = " << typeid(a1).name() << ". size = " << sizeof(a1) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = numeric_limits<short>::min();
    x2 = numeric_limits<short>::max();
    cout << "Type = " << typeid(b1).name() << ". size = " << sizeof(b1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<unsigned short>::min();
    x2 = numeric_limits<unsigned short>::max();
    cout << "Type = " << typeid(b2).name() << ". size = " << sizeof(b2) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<int>::min();
    x2 = numeric_limits<int>::max();
    cout << "Type = " << typeid(b3).name() << ". size = " << sizeof(b3) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<unsigned int>::min();
    x2 = numeric_limits<unsigned int>::max();
    cout << "Type = " << typeid(b4).name() << ". size = " << sizeof(b4) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<long>::min();
    x2 = numeric_limits<long>::max();
    cout << "Type = " << typeid(b5).name() << ". size = " << sizeof(b5) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<unsigned long>::min();
    x2 = numeric_limits<unsigned long>::max();
    cout << "Type = " << typeid(b6).name() << ". size = " << sizeof(b6) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<long long>::min();
    x2 = numeric_limits<long long>::max();
    cout << "Type = " << typeid(b7).name() << ". size = " << sizeof(b7) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<unsigned long long>::min();
    x2 = numeric_limits<unsigned long long>::max();
    cout << "Type = " << typeid(b8).name() << ". size = " << sizeof(b8) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = numeric_limits<signed char>::min();
    x2 = numeric_limits<signed char>::max();
    cout << "Type = " << typeid(c1).name() << ". size = " << sizeof(c1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<unsigned char>::min();
    x2 = numeric_limits<unsigned char>::max();
    cout << "Type = " << typeid(c2).name() << ". size = " << sizeof(c2) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = numeric_limits<float>::min();
    x2 = numeric_limits<float>::max();
    cout << "Type = " << typeid(d1).name() << ". size = " << sizeof(d1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<double>::min();
    x2 = numeric_limits<double>::max();
    cout << "Type = " << typeid(d2).name() << ". size = " << sizeof(d2) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = numeric_limits<long double>::min();
    x2 = numeric_limits<long double>::max();
    cout << "Type = " << typeid(d3).name() << ". size = " << sizeof(d3) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    cin >> y1 >> y2;
    y0 = y1 + y2;
    cout << "y1 + y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 - y2;
    cout << "y1 + y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 * y2;
    cout << "y1 + y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 / y2;
    cout << "y1 + y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 % y2;
    cout << "y1 % y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";

    z1 = y1;
    z2 = y2;
    z0 = z1 / z2;
    cout << "z1 / z2 = " << z0 << " Type = " << typeid(z0).name() << "\n";

}