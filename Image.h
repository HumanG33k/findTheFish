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
        vector<Pixel> getPixels();
        vector<Pixel> getMinimum();
        
        
        //void Algo(const Image sprite) const;
    //     void Load(char* filepath);
    //     void goToEndOfLine(FILE *fichier)
    //     {
    //         int ret = 0;
    //         if(fichier != NULL)
    //         {
    //             while(ret!=EOF && ret!=CR && ret!=LF) 
    //             {
    //                 ret = fgetc(fichier);
    //             }
    //         }
    //     }

    private:
        void createMinimum();
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
