#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void bitPrint(void *array, int nElements, int size){
	//char temp[size]; //VLA
	//char temp[32];
	char temp[MB_LEN_MAX];
	char *carray=(char*) array;
 for(int i=0;i <nElements;i++){
		memcpy(temp,carray+size*i,size);
		for(int j=size-1;j >=0; j--){
			//11110000
			//00000001 >> 7
			//00000001 & 1
			//00000001
			
			//00000011  >> 6
			//00000001  & 1
			for(int b = 7; b >=0 ; b--){
			 printf("%d",(temp[j] >> b) & 1);
			}
			printf(" ");
		}
		printf("\n");
	}	
}

int main(){
	int a[5]={1,3,7,15,0xFF000000};
	bitPrint(a,5,sizeof(int));
	return 0;
}
