#include <iostream>
#include <typeinfo>

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

    x1 = 0;
    x2 = 1;
    cout << "Type = " << typeid(a1).name() << ". size = " << sizeof(a1) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = SHRT_MIN;
    x2 = SHRT_MAX;
    cout << "Type = " << typeid(b1).name() << ". size = " << sizeof(b1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = 0;
    x2 = USHRT_MAX;
    cout << "Type = " << typeid(b2).name() << ". size = " << sizeof(b2) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = INT_MIN;
    x2 = INT_MAX;
    cout << "Type = " << typeid(b3).name() << ". size = " << sizeof(b3) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = 0;
    x2 = UINT_MAX;
    cout << "Type = " << typeid(b4).name() << ". size = " << sizeof(b4) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = LONG_MIN;
    x2 = LONG_MAX;
    cout << "Type = " << typeid(b5).name() << ". size = " << sizeof(b5) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = 0;
    x2 = ULONG_MAX;
    cout << "Type = " << typeid(b6).name() << ". size = " << sizeof(b6) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = LLONG_MIN;
    x2 = LLONG_MAX;
    cout << "Type = " << typeid(b7).name() << ". size = " << sizeof(b7) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = 0;
    x2 = ULLONG_MAX;
    cout << "Type = " << typeid(b8).name() << ". size = " << sizeof(b8) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = SCHAR_MIN;
    x2 = SCHAR_MAX;
    cout << "Type = " << typeid(c1).name() << ". size = " << sizeof(c1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = 0;
    x2 = UCHAR_MAX;
    cout << "Type = " << typeid(c2).name() << ". size = " << sizeof(c2) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    x1 = FLT_MIN;
    x2 = FLT_MAX;
    cout << "Type = " << typeid(d1).name() << ". size = " << sizeof(d1) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = DBL_MIN;
    x2 = DBL_MAX;
    cout << "Type = " << typeid(d2).name() << ". size = " << sizeof(d2) << ". Value from " << x1 << " to " << x2 << "\n";

    x1 = LDBL_MIN;
    x2 = LDBL_MAX;
    cout << "Type = " << typeid(d3).name() << ". size = " << sizeof(d3) << ". Value from " << x1 << " to " << x2 << "\n";

    cout << "\n";
    cin >> y1 >> y2;
    y0 = y1 + y2;
    cout << "y1 + y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 - y2;
    cout << "y1 - y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 * y2;
    cout << "y1 * y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 / y2;
    cout << "y1 / y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    y0 = y1 % y2;
    cout << "y1 % y2 = " << y0 << " Type = " << typeid(y0).name() << "\n";
    
    z1 = y1;
    z2 = y2;
    z0 = z1 / z2;
    cout << "z1 / z2 = " << z0 << " Type = " << typeid(z0).name() << "\n";
    double z10;
    z10 = 10 + 10.5;
    cout << "z10 = " << z10 << " Type = " << typeid(z10).name() << endl;
}