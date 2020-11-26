#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value+realPart, imaginaryPart);
}

myComplex operator +(int value, const myComplex& number)
{
    return myComplex(value+number.realPart, number.imaginaryPart);
}

myComplex& myComplex::operator ++()
{
    setRealPart(realPart+1);
    return (*this);
}
myComplex myComplex::operator ++(int)
{
    myComplex tmp(*this);
    operator++();
    return tmp;
}

myComplex& myComplex::operator --()
{
    setRealPart(realPart-1);
    return (*this);
}
myComplex myComplex::operator --(int)
{
    myComplex tmp(*this);
    operator--();
    return tmp;
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}

// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) &&
    (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator !=(const myComplex& number) const
{
    return !((*this) == number);
}

bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}

bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}

bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}

bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator -(const myComplex& number)
{
    return myComplex(realPart - number.getRealPart(), imaginaryPart-number.getImaginaryPart());
}

myComplex operator -(int value, const myComplex& number)
{
    return myComplex(value-number.getRealPart(), number.getImaginaryPart()*-1);
}

myComplex myComplex::operator *(int value){
    return myComplex(value*realPart, value*imaginaryPart);
}

myComplex myComplex::operator *(const myComplex& number){
    int ac = realPart*number.realPart;
    int bd = imaginaryPart * number.imaginaryPart;
    int ad = realPart*number.imaginaryPart;
    int bc = imaginaryPart * number.realPart;
    return myComplex(ac-bd,ad+bc);
}

myComplex operator *(int value, const myComplex& number)
{
    return myComplex(value*number.getRealPart(), value*number.getImaginaryPart());
}

myComplex myComplex::operator ~(){
    return myComplex(realPart, -imaginaryPart);
}

myComplex myComplex::operator +=(int value)
{
    myComplex tmp = (*this)+value;
    set(tmp.realPart, tmp.imaginaryPart);
    return tmp;
}

myComplex myComplex::operator *=(int value)
{
    myComplex tmp = (*this)*value;
    set(tmp.realPart, tmp.imaginaryPart);
    return tmp;
}
myComplex myComplex::operator -=(int value){
    myComplex tmp = (*this)-value;
    set(tmp.realPart, tmp.imaginaryPart);
    return tmp;
}

myComplex myComplex::operator +=(const myComplex& number)
{
    set(realPart+number.realPart, imaginaryPart+number.imaginaryPart);
    return number+(*this);
}

myComplex myComplex::operator *=(const myComplex& number)
{
    myComplex tmp((*this)*number);
    set(tmp.realPart, tmp.imaginaryPart);
    return tmp;
}
myComplex myComplex::operator -=(const myComplex& number)
{
    myComplex tmp((*this)-number);
    set(tmp.realPart, tmp.imaginaryPart);
    return tmp;
}

// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.getRealPart() << "," << number.getImaginaryPart() << ")";
    return outStream;
}
istream &operator >>(istream &inStream, myComplex& number)
{
    int inputRealPart, inputImageinaryPart;
    inStream >> inputRealPart >> inputImageinaryPart;
    number.set(inputRealPart, inputImageinaryPart);
    return inStream;
}
