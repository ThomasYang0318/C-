#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *a){
    for(int i = 7 - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            int temp = 0;
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    int lest = 0;
    int second = -1;
    int third = -1;
    for(int i = 1; i < 10; i++){
        if(second == -1 && a[i] != a[lest]){
            second = i;
        }
        else if(third == -1 && a[i] != a[lest] && a[i] != a[second]){
            third = i;
        }

        if(second != -1 && third != -1){
            break;
        }
    }
    printf("lest :");
    for(int i = 0; i < second; i++){
        printf("%d ", a[i]);
    }
    printf("\nsecond :");
    for(int i = second; i < third; i++){
        printf("%d ", a[i]);
    }
    printf("\nthird :");
    for(int i = third; i < 10; i++){
        if(a[i] == a[third])
            printf("%d ", a[i]);
    }
}

int main(){
    int a[7] = {0, 1, 0, 1, 1, 3, 2, 3, 100, 32};
    sort(a);
    // for(int i = 0; i < 7; i++){
    //     printf("%d ", a[i]);
    // }
}