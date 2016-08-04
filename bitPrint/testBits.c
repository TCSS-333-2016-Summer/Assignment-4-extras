#include "bitPrint.h"

uint16_t pushBits(unsigned char a, unsigned char r, unsigned char g, unsigned char b);


int main(){
	unsigned char a=200,b=211,g=155,r=1;
	printBitsEndian(&a,1,1);
	printBitsEndian(&r,1,1);
	printBitsEndian(&g,1,1);
	printBitsEndian(&b,1,1);
	uint16_t b16=pushBits(a,r,g,b);
	printBitsEndian(&b16,2,1);
	return 1;
}

uint16_t pushBits(unsigned char a, unsigned char r, unsigned char g, unsigned char b){
	//4-4-4-4
	//AAAAAAAA >> 4
	//0000AAAA
	//OR
	//AAAAAAAA &
	//11110000  
	// F   0
	//0xF0
	//AAAA0000
	
	uint16_t a4= a >> 4; 
	uint16_t r4= r >> 4;
	uint16_t g4= g >> 4;
	uint16_t b4= b >> 4;
	//AAAARRRRGGGGBBBB
	uint16_t bit16= (a4 << 12) | (r4 << 8) | (g4 << 4) | (b4 );
	return bit16 ;
}
