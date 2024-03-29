#ifndef __COMPLEX__
#define __COMPLEX__
#include <iostream>

class complex {

public:
    complex();
    complex(double a, double b);
    complex conj() const;

    friend complex operator + (const complex& , const complex& );
    friend complex operator - (const complex& , const complex& );
    friend complex operator * (const complex& , const complex& );
    friend complex operator / (const complex& , const complex& );
	friend std::ostream& operator << (std::ostream& out, const complex& complex);
	friend void operator >> (std::istream &in, complex& complex);
    friend bool operator == (const complex& , const complex& );

private:
    double r;
    double fi;
};

complex operator ""_xn (long double first);

#endif
