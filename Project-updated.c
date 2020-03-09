#include<stdio.h>
#include<stdlib.h>

typedef struct complex_no
{
    int re;
    int im;
} COMPLEX ;

COMPLEX cmp(int a, int b){
    COMPLEX x;
    x = {a, b};
    return x;
}

COMPLEX conjugate(struct complex_no a)
{
    struct complex_no a_con;
    a_con.re=a.re;
    a_con.im=a.im;
    return a_con;
}

// struct complex_no** comp_transpose(struct complex_no **a, int n)
// {
//     int temp;
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<i; j++)
//         {
//            temp = *(*(a+i)+j);
//            *(*(a+i)+j)=*(*(a+j)+i);
//            *(*(a+j)+i)=temp;
//         }
//     }
// }

// int ishermitian(struct complex_no **a, int n)
// {
//     struct complex_no hermit;
//     hermit = malloc(n*sizeof(struct complex_no *));

//     for (int i=0; i<n; i++)
//     {
//         hermit[i] = malloc(n*sizeof(struct complex_no));
//     }

//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             *(*(hermit+i)+j)=*(*(a+i)+j);
//         }
//     }

//     comp_transpose(hermit, n);

//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             *(*(hermit+i)+j)=conjugate(*(*(hermit+i)+j));
//         }
//     }

//     if (hermit==a)
//     {
//         return 1;
//     }

//     else
//     {
//         return 0;
//     }
// }

int sqr_size=3;
void transpose(int **a, int n)
{
    int temp;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
           temp = *(*(a+i)+j);
           *(*(a+i)+j)=*(*(a+j)+i);
           *(*(a+j)+i)=temp;
        }
    }
}

void cofactor(int **a, int **b, int i, int j, int n)
{
    int row=0, col=0;
    for (int loop_1=0; loop_1<n; loop_1++)
    {
        for (int loop_2=0; loop_2<n; loop_2++)
        {
            if (loop_1!=i&&loop_2!=j)
            {
                *(*(b+row)+col)=*(*(a+loop_1)+loop_2);
                col++;
                if (col==(n-1))
                {
                    col=0;
                    row++;
                }
            }
        }
    }
}

int determinant(int **a, int n)
{
    int res=0;
    int det_sign=1;
    int **cof_matrix;

    if (n==1)
    {
        return *(*(a+0)+0);
    }

    cof_matrix=(int**)malloc((n-1)*sizeof(int *));

    for (int i=0; i<(n-1); i++)
    {
        cof_matrix[i]=(int*)malloc((n-1)*sizeof(int));
    }

    for (int j=0; j<n; j++)
    {
        cofactor(a, cof_matrix, 0, j, n);
        res+=(det_sign*(*(*(a+0)+j))*determinant(cof_matrix, n-1));
        det_sign = 0-det_sign;
    }
    return res;
}



int main()
{
    COMPLEX **arr = (COMPLEX**)malloc(sqr_size * sizeof(COMPLEX*));

    for(int i = 0; i < sqr_size ; i++){
        arr[i] = (COMPLEX*)malloc(sqr_size * sizeof(COMPLEX));
    }

    for(int i = 0 ; i < sqr_size ; i++){
        for(int j = 0 ; j < sqr_size ; j++){
            arr[i][j].re = cmp(i, j).re;
            arr[i][j].im = cmp(i, j).im;
        }
        printf("\n");
    }
    for (int i=0; i<sqr_size; i++)
    {
        for (int j=0; j<sqr_size; j++)
        {
            printf("%d + %di\t", arr[i][j].re, arr[i][j].im);
        }
        printf("\n");
    }

    // int **a;

    // a = (int**)malloc(sqr_size*sizeof(int *));

    // for (int i=0; i<sqr_size; i++)
    // {
    //     a[i]= (int* )malloc(sqr_size*sizeof(int));
    // }

    // int start=1;

    // for (int i=0; i<sqr_size; i++)
    // {
    //     for (int j=0; j<sqr_size; j++)
    //     {
    //         a[i][j] = start;
    //         start+=1;
    //     }
    // }

    // for (int i=0; i<sqr_size; i++)
    // {
    //     for (int j=0; j<sqr_size; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // transpose(a, sqr_size);
    // printf("\n");

    // for (int i=0; i<sqr_size; i++)
    // {
    //     for (int j=0; j<sqr_size; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // int D;
    // D = determinant(a, sqr_size);
    // printf("%d\n", D);

    // free(a);

    return 0;
}
