
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

/*
void LOG(double* kernel, float sigma) {
    int fil, col, size = 3;
    double sum = 0;
    
    for(int i = 0 ; i < size*size ; ++i) {
        fil = (int) i/size;
        col = i - size * fil;

        int x = col - (int)(size/2);
        int y = (int)(size/2) - fil;

        kernel[i] = ((x*x + y*y - 2*sigma*sigma) / (sigma*sigma*sigma*sigma)) * exp(-(x*x + y*y) / (2*sigma*sigma));
    }
}

void mhEdge(int** gImg, int** eImg, int w, int h, float sigma) {
    
    // 3*3의 LOG 필터 생성
    double* kernel = malloc(3*3*sizeof(double));
    double** lap = malloc(w*h*sizeof(double));
    LOG(kernel, sigma);

    // smooting
    for(int i = 1 ; i < w ; ++i) {
        for(int j = 1 ; j < h ; ++j) {

            int v = 0;

            for(int mx = 0 ; mx < 3 ; ++mx)
                for(int my = 0 ; my < 3 ; ++my)
                    v += kernel[mx*3 + my] * gImg[i + mx - 1][j + my -1];

            v /= 3;

            lap[i][j] = v;
        }
    }

    // get threshold
    double max_l = 0;
    for(int i = 0 ; i < w ; ++i)
        for(int j = 0 ; j < h ; ++j) {
            if(abs(eImg[i][j] > max_l))
                max_l = abs(lap[i][j]);
        }

    // find zero cross
    for(int i = 1 ; i < w ; ++i) {
        for(int j = 1 ; j < h ; ++j) {
            if((lap[i-1][j] * lap[i+1][j] < 0) && (abs(lap[i-1][j] - lap[i+1][j]) > max_l))
                eImg[i][j] = 255;
            else if((lap[i][j-1] * lap[i][j+1] < 0) && (abs(lap[i][j-1] - lap[i][j+1]) > max_l))
                eImg[i][j] = 255;
            else if((lap[i-1][j-1] * lap[i+1][j+1] < 0) && (abs(lap[i-1][j-1] - lap[i+1][j+1]) > max_l))
                eImg[i][j] = 255;
            else if((lap[i+1][j-1] * lap[i-1][j+1] < 0) && (abs(lap[i+1][j-1] - lap[i-1][j+1]) > max_l))
                eImg[i][j] = 255;
        }    
    }

}
*/

/*
int **filter(int **inImg, int w, int h, double sigma)
{

    double r, sum = 0.0, s = 2.0 * sigma * sigma;
    double **kernel = calloc(w * h * sizeof(double));
    int **outImg = malloc(w * h * sizeof(int));

    for (int i = -2; i <= 2; ++i)
    {
        for (int j = -2; j <= 2; ++j)
        {
            r = sqrt(i * i + j * j);
            kernel[i + 2][j + 2] = (exp(-(r * r) / s)) / (M_PI * s);
            sum += kernel[i + 2][j + 2];
        }
    }

    for (int i = 2; i < w; ++i)
    {
        for (int j = 2; j < h; ++j)
        {
            int v = 0;

            for (int ki = 0; ki < 5; ++ki)
            {
                for (int kj = 0; kj < 5; ++kj)
                {
                    v += kernel[ki][kj] * inImg[i + ki - 2][j + kj - 2];
                }
            }

            outImg = v / 20;
        }
    }

    return outImg;
}

void sift(int **gImg, int w, int h)
{
    int **octave[5][30];

    for (int i = 1; i <= 4; ++i)
    {
        // create octave
        for (int j = 2; j <= 7; ++j)
        {
            int **tImg1, tImg2;
            tImg1 = filter(gImg, w, h, j-1);
            tImg2 = filter(gImg, w, h, j);

            int** ocImg = malloc(w*h*sizeof(int));

            for(int oi = 0 ; oi < w ; ++oi)
                for(int oj = 0 ; oj < h ; ++oj)
                    ocImg[oi][oj] = tImg1[oi][oj] - tImg2[oi][oj];

            octave[i][j-1] = ocImg;
        }

        int** downImg = malloc((w/2)*(h/2)*sizeof(int));
        // down sampling
        for(int wi = 0 ; wi < w/2 ; ++wi) {
            for(int wj = 0 ; wj < h/2 ; ++wj) {
                downImg[wi][wj] = gImg[wi*2][wj*2];
            }
        }
        free(gImg);
        gImg = downImg;

        w /= 2;
        h /= 2;

    }
}

*/


/*
void harris(int **bImg, int w, int h)
{
    int **dx, dy, dydx, dx2, dy2;
    int kernel[3] = {-1, 0, 1};
    int g[3][3] = {{0.075, 0.124, 0.075}, {0.124, 0.204, 0.124}, {0.075, 0.124, 0.075}};


    // differential
    dx = malloc(w * h * sizeof(int));
    dy = malloc(w * h * sizeof(int));
    dydx = malloc(w * h * sizeof(int));
    dx2 = malloc(w * h * sizeof(int));
    dy2 = malloc(w * h * sizeof(int));

    for (int i = 0; i < w; ++i)
        for (int j = 1; j < h - 1; ++j)
            dx[i][j] = bImg[i][j - 1] * (-1) + bImg[i][j + 1];

    for (int i = 1; i < w - 1; ++i)
        for (int j = 0; j < h; ++j)
            dy[i][j] = bImg[i - 1][j] * (-1) + bImg[i + 1][j];

    for (int i = 0; i < w; ++i)
        for (int j = 1; j < h - 1; ++j)
            dydx[i][j] = dy[i][j - 1] * (-1) + dy[i][j + 1];

    for (int i = 0; i < w; ++i)
        for (int j = 1; j < h - 1; ++j)
            dx2[i][j] = dx[i][j - 1] * (-1) + dx[i][j + 1];

    for (int i = 1; i < w - 1; ++i)
        for (int j = 0; j < h; ++j)
            dy2[i][j] = dy[i + 1][j] * (-1) + dy[i + 1][j];


    // gaussian
    double **gdx, gdy, gdydx, gdx2, gdy2;

    gdx = malloc(w * h * sizeof(double));
    gdy = malloc(w * h * sizeof(double));
    gdydx = malloc(w * h * sizeof(double));
    gdx2 = malloc(w * h * sizeof(double));
    gdy2 = malloc(w * h * sizeof(double));

    for (int i = 1; i < w; ++i)
    {
        for (int j = 1; j < h; ++j)
        {

            double vdx = 0, vdy = 0, vdydx = 0, vdx2 = 0, vdy2 = 0;

            for (int mx = 0; mx < 3; ++mx)
                for (int my = 0; my < 3; ++my)
                {
                    vdx += g[mx][my] * dx[i + mx - 1][j + my - 1];
                    vdy += g[mx][my] * dy[i + mx - 1][j + my - 1];
                    vdydx += g[mx][my] * dydx[i + mx - 1][j + my - 1];
                    vdx2 += g[mx][my] * dx2[i + mx - 1][j + my - 1];
                    vdy2 += g[mx][my] * dy2[i + mx - 1][j + my - 1];
                }

            gdx[i][j] = vdx;
            gdy[i][j] = vdy;
            gdydx[i][j] = vdydx;
            gdx2[i][j] = vdx2;
            gdy2[i][j] = vdy2;
        }
    }

    // find moment and calculate c value
    // find keypoints using threshold

    // k value
    double k = 1;
    double threshold = 0.1;

    int** keypoints;
    keypoints = malloc(w*h*sizeof(int));

    for(int i = 0 ; i < w ; ++i) {
        for(int j = 0 ; j < h ; ++j) {
            double p, r, q, c;

            p = gdy2[i][j];
            r = gdydx[i][j];
            q = gdx2[i][j];

            c = (p*q - r*r) - k*((p + q)*(p + q));

            if(c > threshold) { 
                keypoints[i][j] = 1;
            }
        }
    }
}
*/