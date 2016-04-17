#include "Image.h"


using namespace std;

Image::Image(PPMBitmap img, int l, int h, bool isSprite) : _img(img), _width(l), _height(h), _isSprite(isSprite) {
    Pixel pix(0, 0, 0);
    
    this->_pixels.reserve (this->getWidth()*this->getHeight());
    PPMBitmap::RGBcol col;

    for (long i = 0; i < _height; i++) 
    {
        for (long j = 0; j < _width; j++) 
        {
            //correction
            col = img.getPixel(i, _width - j - 1);
            pix.setr(col.r);
            pix.setg(col.g);
            pix.setb(col.b);
            this->_pixels.push_back(pix);
        }
    }

    if (_isSprite) 
    {
        this->createMinimum();

    }
}

int Image::getMinimumHeight() 
{
    return this->_minimumHeight;
}

int Image::getMinimumWidth() 
{
    return this->_minimumWidth;
}

int Image::getWidth() 
{
    return this->_width;
}

int Image::getHeight() 
{
    return this->_height;
}

vector<Pixel> Image::getMinimum() 
{
    return this->_minimumPicture;
}

vector<Pixel> Image::getPixels() 
{
    return this->_pixels;
}

int Image::getXFirst() 
{
    return this->x_first;
}


void Image::createMinimum() 
{
    int y_min = this->getHeight();
    int y_max = 0;
    int x_min = this->getWidth();
    int x_max = 0;
    cout<<endl;
    for (int h = 0; h < this->_height; ++h) 
    {
        for (int w = 0; w < this->_width; ++w) 
        {
            //cout<<w<<" "<<h<<" | "<<endl;
            
            if ((this->_pixels.at(w + h * this->_width)).isWhite() == false) 
            {
                //cout<< "Pixel [ "<< w <<" "<< h <<" ] not white."  <<endl;   
                cout << "x";
                //traitement gauche droite
                if (y_min >= h) 
                {
                    cout<< "ymin en cours : "<<y_min<<endl;
                    y_min = h;
                    cout<< "ymin apres : "<<y_min<<endl;
                }
               
                if (x_min > w) 
                {
                    cout<< "xmin en cours : "<<x_min<<endl;
                    x_min = w;
                    cout<< "xmin apres : "<<x_min<<endl;
                }

                //traitement haut bas

                if (y_max < h) 
                {
                    y_max = h;
                }
                if (x_max < w) 
                {
                    x_max = w;
                }


            } else 
            {
                cout << "o";
            }
        }
        cout <<"</br>"<< endl;
        //cout << endl;
    }

    //int w_min = x_min + y_min * _width;
    //    int w_max = x_max + y_min * _width;

    int h_min = x_min + y_max * _width;
    int h_max = x_max + y_max * _width;


    for (int h = h_min; h <= h_max; h += _width) 
    {

        for (int w = 0; w <= (x_max - x_min); w+=1) 
        {

            this->_minimumPicture.push_back(this->_pixels.at(h + w));

        }
    }

    this->_minimumWidth = x_max - x_min+1;
    cout << "x_max" <<x_max<<endl;
    cout <<"xmin" <<x_min<<endl;
    cout <<"ymin" <<y_min<<endl;
    cout <<"ymax : " <<y_max<<endl;
    this->_minimumHeight = y_max - y_min+1;
    this->x_center = this->_minimumWidth / 2;
    this->y_center = this->_minimumHeight / 2;

    this->firstXCoord();
}

void Image::firstXCoord() 
{
    int i =0; 
    cout <<"avant white"<<endl;
    cout <<"w : "<<this->_minimumWidth<<endl;
    cout <<"h : "<<this->_minimumHeight<<endl;
    while (this->_minimumPicture.at(i).isWhite())
    {
        i++;       
        cout <<"i :"<< i <<endl;
        if (this->_minimumPicture.at(i).isWhite())
        {
            cout <<"white true"<<endl;
        }
        else
        {
               cout <<"white false"<<endl;
        }
    }
    cout<<"fin du while"<<endl;
    this->x_first = i;
    cout <<"fin"<<endl;
}


