#include <stdio.h>
int i,j;
int main()
{
    int A[3][3]={{2,1,3},{6,5,4},{8,7,9}};
    int B[3][3]={{4,2,9},{1,8,3},{7,5,6}};
    printf("A = \n");
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("B = \n");
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("%d ",B[i][j]);
        }
       printf("\n");
    }
    printf("\n");
    sumOfAB(A,B);
    maxInA(A);
    sumOfRow(B);
}

int sumOfAB(int a[3][3],int b[3][3]){
    printf("C = \n");
    int C[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            C[i][j]=a[i][j]+b[i][j];
            printf("%2d ",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
    }

int maxInA(int a[3][3]){
    printf("The maximum value of array A = ");
    int check[1];
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            if (a[i][j]>a[i][j+1]){
                check[0]=a[i][j];
            }else{
                check[0]=a[i][j+1];
            }
        }
    }
    printf("%d\n\n",check[0]);
    return 0;
}
int sumOfRow(int b[3][3]){
    int sum;
    int raw=0;
    for(i=0;i<3;i++){
        sum=0;
        for(j=0;j<3;j++){
            sum+=b[i][j];
        }
        raw+=1;
        printf("Sum of raw %d : %d\n",raw,sum);
    }
    return 0;
}
