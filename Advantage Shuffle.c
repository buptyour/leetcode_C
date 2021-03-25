#include <stdlib.h>

int cmp(const void* _a, const void* _b){
    int* a = (int*) _a;
    int* b = (int*) _b;
    return *a - *b;
}


int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    qsort(A,ASize,sizeof(int),cmp);
    int* Return = (int*)malloc(sizeof(int)*ASize);
    int C[ASize],D[ASize];
    for(int i=0;i<ASize;i++) {
        C[i] = 0;
        D[i] = 0;
    }

    for(int i=0;i<ASize;i++){
        for(int j=0;j<BSize;j++){
            if(A[j]>B[i]&&C[j]==0){
                C[j] = 1;
                Return[i] = A[j];
                D[i] = 1;
                break;
             }
        }
    }

    for(int i=0;i<ASize;i++){
        if(D[i] == 0){
            for(int j=0;j<ASize;j++){
                if(C[j] == 0) {
                    Return[i] = A[j];
                    D[i] = 1;
                    C[j] = 1;
                    break;
                }

            }
        }
    }
    returnSize = &ASize;
    for(int i=0;i<*returnSize;i++)
        printf("%d ",Return[i]);

    return Return;

}


int main(){
    int num;
    scanf("%d",&num);
    int A[num],B[num];
    int* C = (int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++)
        scanf("%d",&A[i]);

    for(int i=0;i<num;i++)
        scanf("%d",&B[i]);

    C = advantageCount(A,num,B,num,&num);

}
