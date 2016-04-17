#include "pixel.h"
#include <iostream> 
using namespace std;
Pixel::Pixel(const int r, const int g, const int b)
{
    this->r=r;
    this->g=g;
    this->b=b;
}

Pixel::~Pixel() 
{
}

bool Pixel::operator !=(const Pixel &second) const 
{
    if (this->r==second.r && this->g==second.g && this->b==second.b) 
    {
        return false;
    }
    else 
    {
        return true;
    }
}

bool Pixel::operator ==(const Pixel &second) const 
{
    if (this->r==second.r && this->g==second.g && this->b==second.b) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int Pixel::getr() const 
{ 
    return this->r;
}

int Pixel::getg() const 
{ 
    return this->g;
}

int Pixel::getb() const 
{ 
    return this->b;
}

void Pixel::setr(int in) 
{ 
    this->r=in;
}

void Pixel::setg(int in) 
{ 
    this->g=in;
}

void Pixel::setb(int in) 
{ 
    this->b=in;
}

bool Pixel::isWhite() 
{
    bool result = false;
    if ((this->r == 255) && (this->g == 255) && (this->b == 255 ))
    {
      result = true;  
    }
    
    return result;
}
