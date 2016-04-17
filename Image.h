#ifndef IMAGE_H
#define IMAGE_H
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "ppm.hpp"
#include "pixel.h"

using namespace std;

class Image
{
    public:
        Image(PPMBitmap img, int l, int h,bool isSprite=false);
        
        int getMinimumWidth();
        int getMinimumHeight();
        int getWidth();
        int getHeight();
        int getXFirst();
        
        //vecteur de pixels de l'image
        vector<Pixel> getPixels();
        //vecteur de pixels du sprite réduit
        vector<Pixel> getMinimum();

    private:
        //permet de réduire le sprite pour enlever les bords blancs inutiles
        void createMinimum();
        //une fois le sprite réduit, permet d'avoir la coordonnée du premier pixel non blanc
        void firstXCoord();
        
        PPMBitmap _img;
        int _width;
        int _height;
        int _minimumWidth;
        int _minimumHeight;
        vector <Pixel> _pixels;
        vector <Pixel> _minimumPicture;
        bool _isSprite;
        int x_center;
        int y_center;
        int x_first;
        
};

#endif // IMAGE_H
