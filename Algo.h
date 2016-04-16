/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algo.h
 * Author: jerome
 *
 * Created on 15 avril 2016, 22:33
 */

#ifndef ALGO_H
#define ALGO_H

#include "Image.h"
#include <time.h>


class Algo {
public:
    static void algoCPU(Image picture,Image sprite );
    static void algoGPU(Image picture,Image sprite );
    
private:

};

#endif /* ALGO_H */

