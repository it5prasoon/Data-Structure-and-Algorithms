#include<stdio.h>

void sort(int a[10], int n);

void sort(int a[10])
{
        int i,j,tmp;
       for (i = 0; i < 10; ++i) 
        {
            for (j = i + 1; j < 10; ++j)
              {
                 if (a[i] > a[j]) 
                   {
                    tmp =  a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    }
              }
        }
for(i=0;i<10;++i){
    printf("%d",a[i]);
}
}

int main(){
    int a[10],k;
        for(k=0;k<10;k++){
            scanf("%d",&a[k]);
        }
    sort(a[10]);


    return 0;
}