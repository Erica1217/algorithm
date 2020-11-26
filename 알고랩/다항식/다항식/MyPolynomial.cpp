#include "MyPolynomial.h"
#include <algorithm>
/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned e)
{
    polynomial.push_back(myTerm(c,e));
    if(e>degree)
    {
        degree=e;
    }
}

bool cmp(myTerm a, myTerm b)
{
    if(a.getExp() > b.getExp())
    {
        return false;
    }
    return true;
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
    for(int i=0 ; i<nTerms*2 ; i+=2)
    {
        polynomial.push_back(myTerm(mono[i],mono[i+1]));
        if(mono[i+1]>degree)
        {
            degree = mono[i+1];
        }
    }
    sort(polynomial.begin(), polynomial.end(), cmp);
}

myPolynomial::myPolynomial(vector<myTerm> polynomial):polynomial(polynomial)
{
    for(int i=0 ; i<polynomial.size() ; i++)
    {
        if(degree< polynomial[i].getExp())
        {
            degree =polynomial[i].getExp();
        }
    }
}
                             
// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly)
{
    this->polynomial = poly.polynomial;
    this->degree = poly.getDegree();
}
// overloaded operators
bool myPolynomial::operator== (const myPolynomial &poly) const
{
    if(poly.degree != this->degree)
    {
        return false;
    }
    if(poly.polynomial.size() != this->polynomial.size())
    {
        return false;
    }
    for(int i=0 ; i<polynomial.size() ; i++)
    {
        if(poly.polynomial[i] != this->polynomial[i])
        {
            return false;
        }
    }
    return true;
    
}
bool myPolynomial::operator != (const myPolynomial &poly) const
{
    return !(poly== (*this));
}

myPolynomial myPolynomial::operator -() const
{
    vector<myTerm> v;
    for(int i=0 ; i<polynomial.size() ; i++)
    {
        v.push_back(-polynomial[i]);
    }
    return myPolynomial(v);
}

myPolynomial myPolynomial::operator +(const myPolynomial &poly) const
{
    vector<myTerm> p;
     int a=0, b=0;
     while(a<poly.polynomial.size() || b< this->polynomial.size())
     {
         if(b>= this->polynomial.size())
         {
             p.push_back(poly.polynomial[a++]);
         }
         else if(a>= poly.polynomial.size())
         {
             p.push_back(this->polynomial[b++]);
         }
         else if(this->polynomial[b].exp ==  poly.polynomial[a].exp)
         {
             int coeff = this->polynomial[b].coeff + poly.polynomial[a].coeff;
             p.push_back(myTerm(coeff,this->polynomial[b].exp));
             a++;
             b++;
         }
         else if(this->polynomial[b].exp <  poly.polynomial[a].exp)
         {
             p.push_back(myTerm(poly.polynomial[a]));
             a++;
         }
         else
         {
             p.push_back(myTerm(this->polynomial[b]));
             b++;
         }
     }
    return myPolynomial(p);
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const
{
    return (*this)+ (-poly);
}
myPolynomial myPolynomial::operator *(int k) const
{
    for(int i=0 ; i<k ; i++)
    {
        
    }
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const
{
    
}

myPolynomial& myPolynomial::operator += (const myPolynomial &poly)
{
 
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly)
{
    return (*this) + -poly;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly)
{
    
}
myPolynomial& myPolynomial::operator *= (int k)
{
    vector<myTerm> v;
    for(int i=0 ; i< polynomial.size() ; i++)
    {
        myTerm p = polynomial[i];
        v.push_back(myTerm(p.getCoeff()*k, p.exp));
    }
    return myPolynomial(v);
}

myPolynomial::long operator() (int x) const; // evaluate the polynomial
myPolynomial::int getDegree() const // get a degree of the polynomial
{
    return degree;
}
myPolynomial::unsigned getNumTerms() const // number of terms in the polynomial
{
    return polynomial.size();
}
myPolynomial::myPolynomial ddx() const // derivative of a polynomial
{
    int data[v.size()*2]={0,};
    int num=0;
    for(int i=0 ; i<polynomial.size()*2 ; i+=2)
    {
        if(polynomial[i].exp!=0)
        {
            data[num] = polynomial[i].ddx().coeff;
            data[num+1] = polynomial[i].ddx().exp;
            num+=2;
        }
    }
    return myPolynomial(num/2,data);
}
// friend operators and functions
myPolynomial operator *(int k, const myPolynomial &poly);

// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    /********************* add your code here ********************************/
    return outStream;
}


const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x
