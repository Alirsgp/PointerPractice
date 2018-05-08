#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
//assumes little endian
void printBits(size_t const size, void const * const ptr);
int main() {

	int n = 7;
	int a = (((!!n)) & 1) << 31;
	
	int b = (n + (~1 + 1));
	printBits(sizeof(n), &b);
	printBits(sizeof(n), &a);
	int ans = a >> b;
	int8_t x = (int8_t)-128;
	printBits(sizeof(x), &x);
	x = x >> 3;

	printBits(sizeof(n), &ans);
	printBits(sizeof(x), &x); 
	int o = 5;
	int v = 1;
	int r = o | v;
	printf("%d\n", r);

	int8_t negone = (int8_t)-128;
	int8_t negTwo = (int8_t)-1;
	int8_t answerOne = negone >> negTwo;
	printBits(sizeof(answerOne), &answerOne);

	uint16_t test1 = 0x704F;
	uint16_t test2 = 0x7053;
	uint16_t test3 = 0x7043;
	uint16_t test4 = 0x705F;

	uint16_t test5 = 0x001C;
	uint16_t test6 = 0xFFD3;
	uint16_t test7 = 0x0000;
	uint16_t test8 = 0xFFFF;

	if ((test1 ^ test2) == test5) {
		printf("I WONT\n");
	}

	if ((test1 ^ test2) == test6) {
		printf("EVER\n");
	}

	if ((test1 ^ test1) == test7) {
		printf("FORSAKE\n");
	}

	if ((test1 ^ test1) == test8) {
		printf("U\n");
	}

	int8_t ex1 = -5;
	printBits(1, &ex1);
	printf("%d\n", ex1 << 3);
	ex1 = ex1 << 4;
	//1111 1011
	//1111 1101
	//1111 1110
	printf("%d\n", ex1);
	printBits(1, &ex1);
	//1111 1011
	//1011 0000
	//0100 1111 -> invert
	//0101 0000 -> add 1


	int8_t ex2 = -7;
	//1111 1001
	printBits(1, &ex2);

	ex2 = ex2 >> 3;
	//1111 1111
	printBits(1, &ex2);

	int8_t ex3 = -7 >> 1;
	//1111 1100
	//-7 = 0000 0111 -> 1111 1000 -> 1111 1001
	// -7 >> 1 -> 1111 1100
	printBits(1, &ex3);

	printf("%d\n", ex3);


	printf("%d\n", 0x8);

	for (int i = 0; i < 3; i++) {
		printf("HI\n");
	}


	int8_t ag1 = 96;
	printBits(sizeof(ag1), &ag1);
	int8_t ag2 = ~ag1;
	printBits(sizeof(ag2), &ag2);
	int8_t ag4 = -ag1;
	printBits(sizeof(ag4), &ag4);
	int8_t ag3 = ag1 & ag2;
	printBits(sizeof(ag3), &ag3);

	char tempStr[] = "ali\n";
	printf("%lu\n", strlen(tempStr));

	int j = 0;
	while (tempStr[j] != '\0') {
		j++;
	}
	printf("%d\n", j);
	uint16_t mynum = 12345;
	printBits(sizeof(mynum), &mynum);

	int* P1 = &j;
	int* P2 = &j;

	
	int8_t am1 = 0b10010000;
	printf("%d\n", am1);
	printBits(sizeof(am1), &am1);
	am1 = am1 >> 2;
	//1110 0100
	printBits(sizeof(am1), &am1);
	am1 += 1;
	am1 = am1 << 3;
	printBits(sizeof(am1), &am1);

	int8_t am5 = -1;
	printBits(sizeof(am5), &am5);
	am5 = am5 << 2;
	printBits(sizeof(am5), &am5);

	

	int alla1 = 0x49;
	printBits(sizeof(alla1), &alla1);
	int alla2 = (alla1 << 9) + alla1;
	printBits(sizeof(alla2), &alla2);
	int alla3 = (alla2 << 18) + alla2;
	printBits(sizeof(alla3), &alla3);


	int16_t aTest1 = 0x49;
	printBits(sizeof(aTest1), &aTest1);
	int16_t aTest2 = (aTest1 << 9) + aTest1;
	printBits(sizeof(aTest2), &aTest2);
	return 0;

	//int16_t a = 0x49;
	//int16_t b = (a << 9) + a; //                    1001 0010 0100 1001
	//if 32 bits, just do c = (b << 18) + b;

	int16_t la = 5;
	printf("Hi %d\n", la + (~la + 1));
	printf("LOL\n");



}

//0x636e


//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

// 1100 0001 = 
// 1111 1111 = -1
// 1111 1110 = -2
// 1100 0001 = -65

// 0110 1010
// 1001 0101 = 
// 1001 0101 = -107
// 0110 1010 = 106
// = -1

// 12345

// 12345 : 2 = 6172 + 1
// 6172 : 2 = 3086 + 0
// 3086 : 2 = 1543 + 0
// 1543 : 2 = 771 + 1
// 771: 2 = 385 + 1
// 385: 2 = 192 + 1
// 192: 2 = 96 + 0
// 96: 2 = 48 + 0
// 48 : 2 = 24 + 0
// 24: 2 = 12 + 0
// 12: 2 = 6 + 0
// 6: 2 = 3 + 0
// 3 : 2 = 1 + 1
// 1: 2 = 0 + 1

//1000 0000 = -128
// -128 = a
// a >> 3
//0001 0000
//1110 1111
//1111 0000
//0001 0000

// 11000000111001

// 0110 0101 0010 1010
//   6     5     2    A



