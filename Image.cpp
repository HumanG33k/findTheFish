#include "Image.h"


using namespace std;

Image::Image(PPMBitmap img, int l, int h, bool isSprite) : _img(img), _width(l), _height(h), _isSprite(isSprite) {
    Pixel pix(0, 0, 0);
    PPMBitmap::RGBcol col;

    for (long i = 0; i < _height; i++) {
        for (long j = 0; j < _width; j++) {
            //correction
            col = img.getPixel(i, _width - j - 1);
            pix.setr(col.r);
            pix.setg(col.g);
            pix.setb(col.b);
            this->_pixels.push_back(pix);
        }
    }

    if (_isSprite) {
        this->createMinimum();

    }
}

int Image::getMinimumHeight() {
    return this->_minimumHeight;
}

int Image::getMinimumWidth() {
    return this->_minimumWidth;
}

int Image::getWidth() {
    return this->_width;
}

int Image::getHeight() {
    return this->_height;
}

vector<Pixel> Image::getMinimum() {
    return this->_minimumPicture;
}

vector<Pixel> Image::getPixels() {
    return this->_pixels;
}

int Image::getXFirst() {
    return this->x_first;
}



void Image::createMinimum() {
    int y_min = _height;
    int y_max = 0;
    int x_min = _width;
    int x_max = 0;
    cout<<endl;
    for (int h = 0; h < this->_height; ++h) {
        for (int w = 0; w < this->_width; ++w) {
            //cout<<w<<" "<<h<<" | "<<endl;
            
            if ((this->_pixels.at(w + h * this->_width)).isWhite() == false) {
                //cout<< "Pixel [ "<< w <<" "<< h <<" ] not white."  <<endl;   
                cout << "x";
                //traitement gauche droite
                if (y_min >= h) {
                    y_min = h;
                }
                if (x_min >= w) {
                    x_min = w;
                }

                //traitement haut bas

                if (y_max >= h) {
                    y_min = h;
                }
                if (x_min >= w) {
                    x_min = w;
                }


            } else {
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


    for (int h = h_min; h <= h_max; h += _width) {

        for (int w = 0; w <= x_max - x_min; ++w) {

            this->_minimumPicture.push_back(this->_pixels.at(h + w));

        }
    }

    this->_minimumWidth = x_max - x_min;
    this->_minimumHeight = y_max - y_min;
    this->x_center = this->_minimumWidth / 2;
    this->y_center = this->_minimumHeight / 2;

    this->firstXCoord();
}

void Image::firstXCoord() {


    int i =0; 
    while (!this->_minimumPicture.at(i).isWhite()) {
        ++i;       
    }
    this->x_first = i;







}






/*
void Image::Algo(const Image sprite) const 
{
    bool Occu[this->_l-sprite._l][this->_h-sprite._h];
    Pixel null_pix(255, 255, 255);
    int cmptOcc=0;
    
    for (int i=0; i<this->_l-sprite._l;i++)
    {
        for (int j=0; j<this->_h-sprite._h; j++)
        {
            Occu[i][j]=true;
            for (int m=0; m<sprite._l; m++)
            {
                for (int n=0; n<sprite._h; n++)
                {
                    if (sprite._data[m+n*sprite._l]/=null_pix) 
                    {
                        if (this->_data[i+m+(j+n)*this->_l]/=sprite._data[m+n*sprite._l])
                        {
//                              cout << "taille l-> " << this->_l<< endl;
                             cout << "i+m" <<i+m << endl;
                              cout << "j+n"<<j+n << endl;
                            Occu[i][j]=false;
                        }
                    }
                }
                 cout << "sorti 2for2" << endl;
            }
             cout << "sorti 2for1" << endl;
            if (Occu[i][j])
            {
                cmptOcc++;
                cout <<"DETECTION "<<cmptOcc<<" : X :"<<i<<"  Y : "<<j << endl;
            }
        }
    }
}
 */
// void Image::Load(char* filepath) {
//         Pixel pix(0,0,0);
//         FILE* fichier;
//         fichier = fopen(filepath, "r");
// 
//         if (fichier != NULL)
//         {
//             int ret = 0;
//             char rets[3];
//             fscanf(fichier, "%s", rets);
//             long compteur = 1;
// 
// 
//             if(strcmp(rets, "P3") == 0)
//             {
//                 fscanf(fichier, "%d", &ret);
// 
//                 while(ret!=EOF)
//                 {
//                     if(ret == '#')
//                     {
//                         goToEndOfLine(fichier);
//                     }
//                     else
//                     {
//                         if(compteur == 1)
//                             this->l = ret;
// 
//                         else if (compteur == 2)
//                         {
//                             this->h = ret;
// 
//                             this->data = (Pixel *) malloc(sizeof(Pixel) * this->l * this->h);
//                         }
//                         else if(compteur == 3) {}
// 
//                         else
//                         {
//                             for(long i=0; i < this->l; i++)
//                             {
//                                 for(long j=0; j < this->h; j++)
//                                 {
//                                     int tmp[3];
//                                     fscanf(fichier, "%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
//                                     pix.setr(tmp[0]);
//                                     pix.setg(tmp[1]);
//                                     pix.setb(tmp[2]);
//                                     ret = pix.getr();
//                                     this->data[i+j*this->l] = pix;
//                                 }
//                             }
// 
// 
//                         }
// 
//                         fscanf(fichier, "%d", &ret);
//                         compteur++;
//                     }
//                 }
// 
//             }
// 
//             fclose(fichier);
//         }
// }
