#include<cstdio>       

using namespace std;
​
#define find_cell(r, c) 3*(r/3)+(c/3)
​
int tmp;
int sdoku[9][10] = { 0, };
bool chk_row[9][10] = { false, };
bool chk_col[9][10] = { false, };
bool chk_cell[9][10] = { false, };
​
void print_sdoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sdoku[i][j]);
        }
        printf("\n");
    }
}
​
void solve_sdoku() 
{
    int r = -1, c = -1;

    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (sdoku[i][j] == 0) 
            {
                r = i;
                c = j;
                break;
            }
        }

        if (r != -1) 
            break;
    }
​
    if (r == -1) 
    {
        print_sdoku();
    }
​
    for (int num = 1; num <= 9; num++) 
    {
        if (!chk_row[r][num] && !chk_col[c][num] && !chk_cell[find_cell(r, c)][num]) 
        {
            chk_row[r][num] = chk_col[c][num] = chk_cell[find_cell(r, c)][num] = true;
        
            sdoku[r][c] = num;
        
            solve_sdoku();
        
            sdoku[r][c] = 0;
        
            chk_row[r][num] = chk_col[c][num] = chk_cell[find_cell(r, c)][num] = false;
        }
    }
}
​
int main() 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            scanf("%d", &tmp);
            sdoku[i][j] = tmp;
​
            chk_row[i][tmp] = true;
            chk_col[j][tmp] = true;
            chk_cell[find_cell(i, j)][tmp] = true;
        }
    }
​
    solve_sdoku();
​
    return 0;
}