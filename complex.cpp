#include "complex.hpp"
#include <cmath>


complex::complex() {
    r = 0;
    fi = 0;    
}

complex::complex(double a, double b)  {
    if ( b >= 2 ) {
        b = fmod( b, 2 );
    } else if ( b < 0 ) {
        b = fmod( b, 2 ) + 2;
    }
    r = a;
    fi = b;
}

complex complex::conj() const {
    complex result;
    result.r = r;
    result.fi = -fi;
    return result;
}

std::ostream& operator << (std::ostream& out, const complex& complex) { 
	return out << complex.r << " " << complex.fi << "p";
}

void operator >> (std::istream &in,  complex& complex) {
    in >> complex.r >> complex.fi;
    if ( complex.fi >= 2 ) {
        complex.fi = fmod( complex.fi, 2 );
    } else if ( complex.fi < 0 ) {
        complex.fi = fmod( complex.fi, 2 ) + 2;
    }
}
bool operator == (const complex& a, const complex& b) {
    if (a.r == b.r and a.fi == b.fi) {
        return true;
    }
    return false;
}

complex operator + (const complex& a, const complex& b) {
    complex result;
    double cos_1 = cos ( a.fi * M_PI );
    double cos_2 = cos ( b.fi * M_PI );
    double sin_1 = sin ( a.fi * M_PI );
    double sin_2 = sin ( b.fi * M_PI );
    double a_1 = a.r * cos_1;
    double a_2 = b.r * cos_2;
    double b_1 = a.r * sin_1;
    double b_2 = b.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = sqrt( a_r * a_r + b_r * b_r );
    //ПЕРВАЯ ЧЕТВЕРТЬ    
    if (a_r / result.r > 0 and b_r /result.r >= 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ВТОРАЯ
    if (a_r / result.r <= 0 and b_r /result.r > 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ТРЕТЬЯ
    if (a_r / result.r >= 0 and b_r /result.r < 0) {
        result.fi = ( asin ( b_r / result.r) ) / M_PI;
    }
    //ЧЕТВЕРТАЯ
    if (a_r / result.r < 0 and b_r /result.r <= 0) {
        result.fi = - ( acos ( a_r / result.r) ) / M_PI;
    }
    return result;
}

complex operator - (const complex& a, const complex& b) {
    complex result;
    double cos_1 = cos ( a.fi * M_PI );
    double cos_2 = cos ( (b.fi - 1) * M_PI );
    double sin_1 = sin ( a.fi * M_PI );
    double sin_2 = sin ( (b.fi - 1) * M_PI );
    double a_1 = a.r * cos_1;
    double a_2 = b.r * cos_2;
    double b_1 = a.r * sin_1;
    double b_2 = b.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = sqrt( a_r * a_r + b_r * b_r );
    //ПЕРВАЯ ЧЕТВЕРТЬ    
    if (a_r / result.r > 0 and b_r /result.r >= 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ВТОРАЯ
    if (a_r / result.r <= 0 and b_r /result.r > 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ТРЕТЬЯ
    if (a_r / result.r >= 0 and b_r /result.r < 0) {
        result.fi = ( asin ( b_r / result.r) ) / M_PI;
    }
    //ЧЕТВЕРТАЯ
    if (a_r / result.r < 0 and b_r /result.r <= 0) {
        result.fi = - ( acos ( a_r / result.r) ) / M_PI;
    }

    return result;
}

complex operator * (const complex& a, const complex& b) {
    complex result;
    result.r = a.r * b.r;
    result.fi = a.fi + b.fi;
    return result;
}

complex operator / (const complex& a, const complex& b) {
    complex result;
    result.r = a.r / b.r;
    result.fi = a.fi - b.fi;
    return result;
}

complex operator"" _xn(long double first) {
	complex p(first, 0.0);
	return p;
}


