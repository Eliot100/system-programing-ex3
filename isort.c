#include <stdio.h>
#define size 50
//input :The function will get an array pointer and a number of moves
//output:Returns the exponent that all numbers move one forward
void shift_element(int *arr,int i){
    while (i>0){ 	
      *(arr+i+1)=*(arr+i);
	  i--;
    }
}
//input  :The puncture gets array
//output :sort they array

void insertion_sort(int *arr,int len){
    for (int i=1, j=0;i<len;i++) {
		j=i-1;
		if(*(arr+j)>*(arr+i)){
			while(*(arr+j)>*(arr+i)){
				j--;
			}
			int temp=*(arr+i);
			shift_element((arr+j),(i-j-1));
			*(arr+j+1)=temp;
        }
    }  
}
int main(){
    int arr[size]={0};
    for(int i=0; i<(size); i++){  //data reception 
        scanf("%d",&arr[i]);
	}
    insertion_sort(arr,size); // sort arr
    for(int i=0; i< size; i++){ //Data Display after sort
		if(i==0)
			printf("%d",arr[i]);
		else {printf(",%d",arr[i]);}
	}
	printf("\n");
    return 0;
}