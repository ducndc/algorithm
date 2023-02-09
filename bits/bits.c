#include <stdio.h>
#include <limits.h> //CHAR_BIT is defined in limits.h

/*Bit Shifting Exercises */

/* get_bits: get n bits from position p*/
unsigned get_bits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
	/*Explanation:
		(p+1-n) gets you the number of bits you'll have to shift off to move 
		the n bits at position p to the rightmost position (x >> ... )  shifts 
		the bits you don't need off and leaves you with the n bits you want. 
		~0 gives you all 1's (~0 << n) causes you to have 0's in the first n 
		places of the bits and 1's everywhere else
		~(~0 << n) causes you to have 1's in the first n places of the bits and 
		0's everywhere else. 
		(x >> (p+1-n)) & ~(~0 << n) applies the mask you've made to the actual 
		bits you're trying to get. 
		and leaves all the other positions at 0
	*/
}

/* Exercise 2-6
Write a function set_bits(x,p,n,y) that returns x with the n bits that 
begin at position p set to the rightmost n bits of y leaving the other bits 
unchanged
*/
unsigned set_bits(unsigned x, int p, int n, unsigned y)
{
	return ((x >> (p+1-n)) << (p+1-n)) | get_bits(y,p,n);
}
 
/* Exericse 2-7
Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p  inverted 
(i.e 1 changed into 0 and vice versa) leaving the others unchanged
*/
unsigned invert(unsigned x, int p, int n)
{
	//function composition is easier to understand than
	/*
		((x >> (p+1-n)) << (p+1-n)) | ~((x >> (p+1-n)) & ~(~0 << n))
	*/
	return set_bits(x,p,n,~get_bits(x,p,n));
}


/* Exercise 2-8
Write a function right_rotated(x,n) that returns the value of the integer x rotated 
to the right by n bit positions
*/
unsigned right_rotated(unsigned x, int n)
{
	return (x << ((sizeof(x)*CHAR_BIT) -n)) | (x >> n) ;
}


int main()
{
	unsigned int x = 5; // 0101
	unsigned int y = 6; // 0110
	printf("%d\n", get_bits(y, 2, 2));		//0011
	printf("%d\n", set_bits(x, 2, 2, y));	//0111
	printf("%d\n", invert(x, 2, 2));		//0110
	printf("%u\n", right_rotated(y, 2));	//0b10000000000000000000000000000001
	printf("%u\n", right_rotated(x, 2));	//0b01000000000000000000000000000001
	
	return 0;
}
