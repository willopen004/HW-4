/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define N 4

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
 void merge_up(int a[], int na, int b[], int nb, int c[])
{
   int ia = 0, ib = 0, ic = 0;
   for(; (ia < na) && (ib < nb);)
   {
       if(a[ia] < b[ib]) {
           c[ic] = a[ia];
           ia++;
       }
       else {
           c[ic] = b[ib];
           ib++;
       }
       ic++;
   }
   for(;ia < na; ia++, ic++) c[ic] = a[ia];
   for(;ib < nb; ib++, ic++) c[ic] = b[ib];
}

void merge_down(int a[], int na, int b[], int nb, int c[])
{
int ia = 0, ib = 0, ic = 0;
   for(; (ia < na) && (ib < nb);)
   {
       if(a[ia] > b[ib]) {
           c[ic] = a[ia];
           ia++;
       }
       else {
           c[ic] = b[ib];
           ib++;
       }
       ic++;
    }
   for(;ia < na; ia++, ic++) c[ic] = a[ia];
   for(;ib < nb; ib++, ic++) c[ic] = b[ib];
}

int merge_sort(int ar[], int n, int flag)
{
    int len;
    int *temp_array, *base;
    temp_array = (int*)malloc(sizeof(int)*n);
    if(temp_array == NULL) {
        printf("Dynamic Allocation Error in merge_sort");
        return 1;
    }
    for (len = 1; len < n; len *= 2) {
        for(base = ar; base < ar + n-1; base += 2 * len) {
            if (flag == 0){
                merge_up(base, len, base + len, len, temp_array);
            }
            if (flag == 1){
                merge_down(base, len, base + len, len, temp_array);
            }
        memcpy(base, temp_array, 2*len*sizeof(int));
        }
    }

    free(temp_array);
    return 0;
}



int main()
{
    int n, i, j;
    int** a;
    scanf("%d", &n);
    a = (int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        a[i] = (int*)malloc(n*sizeof(int));
    }
    for(i= 0; i<n; i++){
        for(j= 0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i= 0; i<n; i++){
        merge_sort(a[i], n, i%2);
    }
    for(i= 0; i<n; i++){
        for(j= 0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
