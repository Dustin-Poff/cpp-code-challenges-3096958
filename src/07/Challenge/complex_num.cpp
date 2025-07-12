#include "complex_num.h"

complex_num::complex_num(double r, double i){
    // Write your code here
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here
    z.real = real * w.real - imaginary * w.imaginary;
    z.imaginary = real * w.imaginary + imaginary * w.real;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    z.real = ((real * w.real + imaginary * w.imaginary))/(std::pow(w.real, 2.0) + std::pow(w.imaginary, 2.0));
    z.imaginary = ((imaginary * w.real - real * w.imaginary)/(std::pow(w.real, 2.0) + std::pow(w.imaginary, 2.0)));
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    if (imaginary < 0)
    {
        std::cout << real << " - " << std::abs(imaginary) << "i";
    } else{
        std::cout << real << " + " << imaginary << "i";
    }
    
}