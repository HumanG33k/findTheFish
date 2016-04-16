/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jerome
 *
 * Created on 15 avril 2016, 22:14
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "ppm.hpp"
#include "Image.h"
#include "Algo.h"

using namespace std;




int main(int argc, char **argv)
{
    if ( argc!= 3)
    {
        cout << "il n'y a pas le bon nombre d'argument" <<endl;
    }
    else 
    {
        char temp1 [2048];
        char temp2 [2048];
        /*
        temp1 >> argv[1];
        temp2 >> argv[2];*/
        
        cout<< temp1 << " "<< temp2 <<endl;

        
        
        /*if ( scanf( argv[1], "%s", &temp1 ) != 1 )
        {
             cout << "error" << endl;
        }
        
        if ( scanf( argv[2], "%s", &temp2 ) != 1 )
        {
            cout << "error" << endl;
        }*/
        
        // Get image
        const PPMBitmap img( argv[1] );
        const int img_width	= img.getWidth();
        const int img_height	= img.getHeight();
        
        
        Image picture(img,img_width,img_height);
        
        // Get sprite
        //const PPMBitmap sprt( temp2 );
        const PPMBitmap sprt( argv[2] );
        const int sprt_width  = sprt.getWidth();
        const int sprt_height	= sprt.getHeight();
        
        
        Image sprite(sprt,sprt_width,sprt_height, true);
        

        Algo::algoCPU(picture, sprite);
        

        
    
        
    }
}


