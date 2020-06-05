//By ADITYA KALRA, IT, 11912038

#include<stdio.h>
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}
int part(int arr[],int lower,int upper){
    int i=lower-1;
    int pivot = arr[upper];
    int j;
    for ( j = lower; j < upper; j++)           
    {
        if(pivot>arr[j]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[upper]);
    return i+1;
}
void quickSort(int arr[],int lower,int upper){
    if(lower<upper)
	{
        int partition = part(arr,lower,upper);
        quickSort(arr,lower,partition-1);       
        quickSort(arr,partition+1,upper);
    }
}
int main(){
    int arr[] = {5,7,2,6,1,9,8,3};
    quickSort(arr,0,7);
    int i;
    for ( i = 0; i < 8; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}











//The program is created by ADITYA KALRA
