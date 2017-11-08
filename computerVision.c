
/*
int Otsu(int Xsize, int Ysize, int** gImg, int** bImg){
    // m = mean , w = weight, var = variance, B = background, F = foreground

    int hist[256], i, j, wB = 0, wF = 0, threshold = 0, total = Xsize * Ysize;
    float sum = 0, sumB = 0, varM = 0, mB, mF, varBet;

    memset(hist, 0, sizeof(hist));
    memset(bImg, 0, sizeof(bImg));

    // make histogram
    for(i = 0 ; i < Ysize ; ++i)
        for(j = 0 ; j < Xsize ; ++j)
            hist[gImg[i][j]] += 1;

    for(i = 0 ; i < 256 ; ++i)
        sum += i * hist[i];

    for(i = 0 ; i < 256 ; ++i){
        
        // weight for mean, cal
        wB += hist[i];
        if(wB == 0) 
            continue;
        wF = total - wB;
        if(wF == 0) 
            break;

        sumB += (float) (i * hist[i]);

        // mean
        mB = sumB / wB;
        mF = (sum - sumB) / wF;

        // Between class variance
        // wholeVar - InclassVar 
        varBet = (float) wB * (float) wF * (mB - mF) * (mB - mF);

        // max(wholeVar - InclassVar) is min sub
        if(varBet > varM){
            varM = varBet;
            threshold = i;
        }

    }


    // binarization
    for(i = 0 ; i < Ysize ; ++i)
        for(j = 0 ; j < Xsize ; ++j){
            if(gImg[i][j] < threshold)
                bImg[i][j] = 0;
            else
                bImg[i][j] = 1;
        }
}
*/




/*
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int label = 0;
void grassFire(int** bImg, int** lImg,int y, int x)
{
    int i;

	if(bImg[y][x] == 1){		

		lImg[y][x] = label;

        for(i = 0 ; i < 8 ; ++i){

            int to_x = x + dx[i], to_y = y + dy[i];

            if(to_x >= 0 && to_x < Xsize && to_y >= 0 && to_y < Ysize){
                grassFire(to_y, to_x);
	        }

        }
	}
	else 
        return;
}
void callgrass(int** bImg, int** lImg, int Xsize, int Ysize)
{
    int i,j;

    memset(lImg, 0, sizeof(lImg));

	for(j = 0 ; j < Ysize; ++j){
		for(i = 0; i < Xsize; ++i){	

			if(bImg[j][i]==1){
				++label;
				grassFire(bImg, lImg, j, i);
			}

		}
	}
}
*/


// // 팽창
// void dilation(int** gImg, int** gmImg, int Xsize, int Ysize)
// {
//     int mask[3][3] = { 1, 2, 1,
//                        2, 4, 2,
//                        1, 2, 1};
//     int i, j, mask_i, mask_j, max;

//     for(i = 0 ; i < Ysize ; ++i){
//         for(j = 0 ; j < Xsize ; ++j){
//             max = -1;

//             for(mask_i = -1 ; mask_i <= 1 ; ++mask_i){
//                 for(mask_j = -1 ; mask_j <= 1 ; ++mask_j){
//                     int s = i+mask_i, t = j+mask_j, tmp_max;

//                     if(s >= 0 && s < Ysize && t >= 0 && t < Xsize){
//                         if(gImg[s][t] != 0){
//                             tmp_max = gImg[s][t] + mask[mask_i+1][mask_j+1];

//                             if(max < tmp_max)
//                                 max = tmp_max;
//                         }
//                     }
//                 }
//             }

//             if(max != -1)
//                 if(max < 256)
//                     gmImg[i][j] = max;
//                 else
//                     gmImg[i][j] = 255;
//         }
//     }
// }

// // 침식
// void erosion(int** gImg, int** gmImg, int Xsize, int Ysize)
// {
//     int mask[3][3] = { 1, 2, 1,
//                        2, 4, 2,
//                        1, 2, 1};
//     int i, j, mask_i, mask_j, min;

//     for(i = 0 ; i < Ysize ; ++i){
//         for(j = 0 ; j < Xsize ; ++j){
//             min = 1000;

//             for(mask_i = -1 ; mask_i <= 1 ; ++mask_i){
//                 for(mask_j = -1 ; mask_j <= 1 ; ++mask_j){
//                     int s = i+mask_i, t = j+mask_j, tmp_min;

//                     if(s >= 0 && s < Ysize && t >= 0 && t < Xsize){
//                         if(gImg[s][t] != 0){
//                             tmp_min = gImg[s][t] - mask[mask_i+1][mask_j+1];

//                             if(min > tmp_min)
//                                 min = tmp_min;
//                         }
//                     }
//                 }
//             }

//             if(min != 1000)
//                 if(min >= 0)
//                     gmImg[i][j] = min;
//                 else
//                     gmImg[i][j] = 0;
//         }
//     }
// }


/*
// cImg가 r,g,b 값을 갖는 객체로 가정시
// rgb가 감마보정되지 않은 디지털 값으로 가정시

void rgbToycc(rgb** cImg, ycc** yImg, Xsize, Ysize)
{
    int i,j;

    for(i = 0 ; i < Ysize ; ++i)
        for(j = 0 ; j < Xsize ; ++j)
        {
            yImg[i][j].y = 0.257*cImg[i][j].r + 0.504*cImg[i][j].g + 0.098*cImg[i][j].b + 16;
            yImg[i][j].cb = (-1*0.148*cImg[i][j].r) - 0.291*cImg[i][j].g + 0.439*cImg[i][j].b + 128;
            yimg[i][j].cr = 0.439*cImg[i][j].r - 0.368*cImg[i][j].g - 0.071*cImg[i][j].b + 128;
        }
}
void yccTorgb(rgb** cImg, ycc** yImg, Xsize, Ysize)
{
    int i,j;

    for(i = 0 ; i < Ysize ; ++i)
        for(j = 0 ; j < Xsize ; ++j)
        {
            cImg[i][j].r = 1.164*(yImg[i][j].y-16) + 1.596*(yImg[i][j].cr-128);
            cImg[i][j].g = 1.164*(yImg[i][j].y-16) - 0.813*(yImg[i][j].cr-128) - 0.392*(yImg[i][j].cb-128);
            cImg[i][j].b = 1.164*(yImg[i][j].y-16) + 2.017*(yImg[i][j].cb-128);
        }
}

*/


/*
// 1, 0 으로 binarization 실시 시
// array counting 까지

int hough(int** bImg, int** hough, int Xsize, int Ysize)
{
    int rangeOfrho = (int) sqrt(Xsize*Xsize + Ysize*Ysize) + 1;
    int i,j,theta;
    float rho, rad = PI/180;

    memset(hough, 0, sizeof(hough));

    for(i = 0 ; i < Ysize ; ++i){
        for(j = 0 ; j < Xsize ; ++j){
            if(bImg[i][j] == 1){
                for(theta = -90 ; theta <= 180 ; ++theta){
                    rho = i*cos(theta*rad) + y*sin(theta*rad);

                    if(rho > 0 && rho < rangeOfrho){
                        hough[(int)rho][(int)(theta+90)]++;
                    }
                }
            }
        }
    }
}

*/