#include <stdio.h>
#include <math.h>

int main(){                                     // Bubble Sort Algorithm [O(n^2)]

    int n;
    printf("Size of Array: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int i=1;
    while(i<=pow(n,2)){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        i++;
    }

    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }

    return 0;
}