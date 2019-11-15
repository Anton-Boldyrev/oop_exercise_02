#include "complex.hpp"
#include <cmath>

int main() {
    complex a, b, ans;
    std::cin >> a;
    std::cin >> b;
    std::cout << "First number : " << a << "\n";     
    std::cout << "second number : " << b << "\n";
    std::cout << " +    =  " << a + b << "\n";
	std::cout << " -    =  " << a - b << "\n";
	std::cout << " *    =  " << a * b << "\n";
	std::cout << " /    =  " << a / b << "\n";
    ans = a.conj(a);
    std::cout << "conj  =  " << ans << "\n";
    ans = b.conj(b);
    std::cout << "conj  =  " << ans << "\n";
    if ( a == b ) {
        std::cout << "a    ==    b\n";    
    } else {
        std::cout << "a    !=    b\n";
    } 

    complex c = 2.4_xn;
    std::cout << c << std::endl;
}
