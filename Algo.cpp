/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algo.cpp
 * Author: jerome
 * 
 * Created on 15 avril 2016, 22:33
 */

#include "Algo.h"

void Algo::algoCPU(Image picture, Image sprite) {
    clock_t tpsProg = clock();
    srand(time(NULL));

    int occur = 0;
    cout<<"Ligne"<<" | "<<"Num Ligne "<<" | "<<"Tps Exe"<<endl;
    cout<<"Sprite"<<" | "<<"Valid Sprite "<<" | "<<"Tps Exe"<<endl;
    
    for (int h_pic = 0; h_pic < picture.getHeight() - sprite.getMinimumHeight(); ++h_pic) {
        
        clock_t tpsLigne = clock();
        for (int w_pic = 0; w_pic < picture.getWidth() - sprite.getMinimumWidth(); ++w_pic) {
            cout << "num premier Block : [ " << h_pic << " : " << w_pic << " ] </br>"<<endl;
            
            if ((picture.getPixels().at(w_pic + sprite.getXFirst())) == (sprite.getMinimum().at(sprite.getXFirst()))) {
                clock_t tpsSprite = clock();
                cout << "num premier pixel : " << sprite.getXFirst() << "</br>"<<endl;
                bool con;
                con = true;


                int h_sprt;
                int w_sprt;

                h_sprt = 0;
                w_sprt = sprite.getXFirst() + 1;

                
                while (con && h_sprt < sprite.getMinimumHeight()) {
                    while (con && w_sprt < sprite.getMinimumWidth()) {
                        Pixel pSprite = sprite.getPixels().at(w_sprt + h_sprt * sprite.getWidth());

                        int indexP = w_pic + w_sprt + (h_pic + h_sprt) * picture.getWidth();
                        Pixel pPicture = picture.getPixels().at(indexP);
                        if (!pSprite.isWhite()) {
                            if (pSprite != pPicture) {
                                con = false;
                            }
                        }
                        ++w_sprt;
                    }
                    w_sprt = 0;
                    ++h_sprt;
                }
                
                tpsSprite = clock() - tpsSprite;
                cout<<"Sprite"<<" | "<<con<<" | "<<(float)tpsSprite/CLOCKS_PER_SEC<<endl;
                
                if (con) {
                    occur += 1;
                    cout << "DETECTION " << occur << " :  X :" << w_pic << "  Y : " << h_pic << endl;
                }            
                
                

                if (occur >= 50) {
                    break;
                }
            }
        }
        tpsLigne = clock() - tpsLigne ;
        cout<<"Ligne"<<" | "<<h_pic<<" | "<<(float)tpsLigne/CLOCKS_PER_SEC<<endl;
    }
    tpsProg = clock()-tpsProg;
    cout<<"Algo"<<" | "<<(float)tpsProg/CLOCKS_PER_SEC<<endl;
}

void Algo::algoGPU(Image picture, Image sprite) {



}
