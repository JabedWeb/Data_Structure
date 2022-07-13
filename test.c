#include<stdio.h>

void partition(int array[],int beg,int end);

int main()
{
    int n;
    printf("Please input the array length\n");
    scanf("%d",&n);
    int array[n];

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int beg=0;
    int end=n-1;
    partition(array,beg,end);

    for(int i=0;i<n;i++){
        printf("%d",array[i]);
    }
    return 0;
}
void partition(int array[],int beg,int end){
    int tem;
    if(beg<end){
    int pivot=beg;
    int left=beg;
    int right=end;
    while(left<right){
        while(left<right){
            if(array[left]<=array[pivot]){
                left++;
            }
        }
        while(left<right){
            if(array[right]>=array[pivot]){
                right--;
            }
        }
        if(left<right){
        tem=array[right];
        array[right]=array[left];
        array[left]=tem;
        }

    }
    tem=array[right];
    array[right]=array[beg];
    array[beg]=tem;
    partition(array,beg,right-1);
    partition(array,right+1,end);
    }
}