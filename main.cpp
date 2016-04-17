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
        
        cout<< temp1 << " "<< temp2 <<endl;

        // Get image
        const PPMBitmap img( argv[1] );
        const int img_width	= img.getWidth();
        const int img_height	= img.getHeight();
        
        
        Image picture(img,img_width,img_height);
        
        // Get sprite
        const PPMBitmap sprt( argv[2] );
        const int sprt_width  = sprt.getWidth();
        const int sprt_height	= sprt.getHeight();
        
        
        Image sprite(sprt,sprt_width,sprt_height, true);
        

        Algo::algoCPU(picture, sprite);
    }
    cout <<"fin prog ! "<<endl;
    return 0;
}


