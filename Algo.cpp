#include "Algo.h"

void Algo::algoCPU(Image picture, Image sprite) 
{
    clock_t tpsProg = clock();
    srand(time(NULL));

    int occur = 0;
    cout<<"Ligne"<<" | "<<"Num Ligne "<<" | "<<"Tps Exe"<<endl;
    cout<<"Sprite"<<" | "<<"Valid Sprite "<<" | "<<"Tps Exe"<<endl;
    
    for (int h_pic = 0; h_pic < (picture.getHeight() - sprite.getMinimumHeight()); ++h_pic) 
    {
        clock_t tpsLigne = clock();
        cout <<"picture.getWidth() - sprite.getMinimumWidth() : "<< (picture.getWidth() - sprite.getMinimumWidth())<<endl;
        cout << "picture.getWidth() : " <<picture.getWidth()<<endl;
        cout << "sprite.getMinimumWidth() : " <<sprite.getMinimumWidth()<<endl;
        for (int w_pic = 0; w_pic < (picture.getWidth() - sprite.getMinimumWidth()); ++w_pic) 
        {
            cout << "num premier Block : [ " << h_pic << " : " << w_pic << " ] </br>"<<endl;
            cout <<"test1"<<endl;
            if ((picture.getPixels().at(w_pic + sprite.getXFirst())) == (sprite.getMinimum().at(sprite.getXFirst()))) 
            {
                clock_t tpsSprite = clock();
                cout << "num premier pixel : " << sprite.getXFirst() << "</br>"<<endl;
                bool con;
                con = true;


                int h_sprt;
                int w_sprt;

                h_sprt = 0;
                w_sprt = sprite.getXFirst() + 1;

                
                while ((con) && (h_sprt < sprite.getMinimumHeight())) 
                {
                    while ((con) && (w_sprt < sprite.getMinimumWidth())) 
                    {
                        Pixel pSprite = sprite.getPixels().at(w_sprt + h_sprt * sprite.getWidth());

                        int indexP = w_pic + w_sprt + (h_pic + h_sprt) * picture.getWidth();
                        Pixel pPicture = picture.getPixels().at(indexP);
                        if (!pSprite.isWhite()) 
                        {
                            if (pSprite != pPicture) 
                            {
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
                
                if (con) 
                {
                    occur += 1;
                    cout << "DETECTION " << occur << " :  X :" << w_pic << "  Y : " << h_pic << endl;
                }            
                
                

                if (occur >= 50) 
                {
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



// __global__ void kernel (const vector<Pixel> dev_picture, const vector <Pixel> dev_sprite, const int size_picture, const int size_sprite)
// {
// //     __shared__ int ocuu
// //     int x = threadIdx.x+blockIdx.x*blockDim.x;
// //     int y = threadIdx.y+blockIdx.y*blockDim.y;
// }

void Algo::algoGPU(Image picture, Image sprite) 
{
//     // Pixel table on Device
//     vector <Pixel> dev_picture;
//     vector <Pixel> dev_sprite;
//     
//     const int size_pic = picture.getHeight()*picture.getWidth();
//     const int size_sprite = sprite.getMinimumWidth()*sprite.getMinimumHeight();
//     
//     // Allocate memory on Device
//     HANDLE_ERROR(cudaMalloc( dev_picture, size_pic));
//     HANDLE_ERROR(cudaMalloc( dev_sprite, size_sprite));
//     
//     // Copy from Host to Device
//     HANDLE_ERROR(cudaMemcpy(dev_picture, picture.getPixels(), size_pic,cudaMemcpyHostToDevice));
//     
//     HANDLE_ERROR(cudaMemcpy(dev_sprite, sprite.getPixels(), size_sprite,cudaMemcpyHostToDevice));
//     
//     // Configure kernel TODO
// //     dim3 threadsPerBlock(8, 8);
// //     dim3 numBlocks(width/threadsPerBlock.x, height/threadsPerBlock.y); 
// //     
//     //Chrono
//     ChronoGPU chr;
//     chr.start();
//     
//     // Launch kernel TODO
// //     computeSepia <<<numBlocks,threadsPerBlock>>>(dev_inPtr, dev_outPtr, width, height);
// 	//computeSepia(dev_inPtr, dev_outPtr, width, height);
//     
//     
//     chr.stop();
//     
//     
//     // Copy from Device to Host TODO
// //     HANDLE_ERROR(cudaMemcpy(outPtr, dev_outPtr, sizeImg, cudaMemcpyDeviceToHost));
// 
//     // Free memory on Device
//     cudaFree(dev_picture);
//     cudaFree(dev_sprite);
// 
//     return chr.elapsedTime();
//     

}










