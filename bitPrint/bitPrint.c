#include "bitPrint.h"
static void reverseBytes(void *ptr, char nBytes);
static void printBits(void *ptr, char nBytes);

static void printBits(void *ptr, char nBytes){
	char *cPtr = (char*) ptr;
	for(int i=0;i<nBytes;i++){
		//for example to gt second byte
		//1100 0000 >> 6 = 0000 0011
		//               & 0000 0001     
		//                 0000 0001
		for(int b=7;b>=0;b--){
			printf("%d",(cPtr[i] >> b) & 1);
		}	
		printf(" ");
	}
	printf("\n");
}
static void reverseBytes(void *ptr, char nBytes){
	char *left=(char*) ptr;
	char *right=left+nBytes-1;
	while(left <right){
		char temp=*left;
		*left++=*right;
		*right--=temp;
	}
}
void printBitsEndian(void *ptr, char nBytes, char endian){
	if(nBytes == 1 || !endian) {
		printBits(ptr,nBytes);
	 return;
	}
	
	uint16_t test=1;
	//0000 0000  0000 0001 BigEndian
	//0000 0001  0000 0000 Little Endian
	char *a = (char*) & test; //pointer cast to byte type
	char BigEndianSystem=a[1] & 1; //look at second byte
	fprintf(stderr,"%d\n",BigEndianSystem);
	if(endian == 1 && BigEndianSystem) printBits(ptr,nBytes);
	else if(endian ==1 && !BigEndianSystem){
		reverseBytes(ptr,nBytes);
		printBits(ptr,nBytes);
	}
	else if(endian=-1 && BigEndianSystem){
		reverseBytes(ptr,nBytes);
		printBits(ptr,nBytes);
	}
	else{
		printBits(ptr,nBytes);
	}	
}

