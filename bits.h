int bitXor(int, int);
/* 
bitXor takes 2 numbers and returns a bit of 1 if x and y are different and 0 otherwise 
bitXor - x^y using only ~ and & 
Example: bitXor(4, 5) = 1
*/

int thirdBits();
/* 
 thirdBits - return word with every third bit (starting from the LSB - least significant bit) set to 1
 Legal ops: ! ~ & ^ | + << >>
*/

int upperBits(int);
/* 
 UpperBits - pads n upper bits with 1's
 You may assume 0 <= n <= 32
 Example: upperBits(4) = 0xF0000000
 In general, a shift (left or right) by a negative number is undefined behavior.
 For this problem alone, you can assume that a left shift with a negative value is OK.
 and the resulting behavior is e.g. (0xf << -1 is 0). You may see an error raised
 at runt-time but you can ignore that error.
 Legal ops: ! ~ & ^ | + << >>
*/

int byteSwap(int, int, int);
/* 
 byteSwap - swaps the nth byte and the mth byte
 Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
           byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 You may assume that 0 <= n <= 3, 0 <= m <= 3
 Legal ops: ! ~ & ^ | + << >>
*/

int copyLSB(int);
/*
copyLSB - set all bits of result to least significant bit of x
Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
Legal ops: ! ~ & ^ | + << >>
*/

int divpwr2(int, int);
/* 
divpwr2 - Compute x/(2^n), for 0 <= n <= 30
Round toward zero
Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
Legal ops: ! ~ & ^ | + << >>

There are 2 cases:
1. x is positive: x/(2^n) == x >> n
2. x is negative: x/(2^n) == (x+(2 << n) - 1) >> n
use ~0 for -1
So the code should return x >> n if x >= 0. Otherwise, if x's n lowest bit is 1, return (x >> n) + 1 (is negative)
*/

int isEqual(int, int);
/* 
 isEqual - return 1 if x == y, and 0 otherwise 
 Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 Legal ops: ! ~ & ^ | + << >>
*/

int isLess(int, int);
/* 
 isLess - if x < y  then return 1, else return 0 
 Example: isLess(4,5) = 1.
 Legal ops: ! ~ & ^ | + << >>
 
There are 2 cases:
1. x and y have the same sign and (x - y) = negative
2. x < 0 and y >= 0
*/

int rempwr2(int, int);
/* 
rempwr2 - Compute x%(2^n), for 0 <= n <= 30
Negative arguments should yield negative remainders
Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
Legal ops: ! ~ & ^ | + << >>
*/

int satMul2(int);
/*
satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
Examples: satMul2(0x30000000) = 0x60000000             
          satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
          satMul2(0x80000001) = 0x80000000 (saturate to TMin)
Legal ops: ! ~ & ^ | + << >>
*/

int bang(int);
/* 
bang - Compute !x without using !
the bang operator returns 0 is value is nonzero and 1 if value is zero
Examples: bang(3) = 0, bang(0) = 1
Legal ops: ~ & ^ | + << >>
*/

int reverseBits(int);
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
  Examples: reverseBits(0x11111111) = 0x88888888
            reverseBits(0xdeadbeef) = 0xf77db57b
            reverseBits(0x88888888) = 0x11111111
            reverseBits(0)  = 0
            reverseBits(-1) = -1
            reverseBits(0x9) = 0x90000000
Legal ops: ! ~ & ^ | + << >> and unsigned int type
*/

int ilog2(int);
/*
ilog2 - return floor(log base 2 of x), where x > 0
Example: ilog2(16) = 4
Legal ops: ! ~ & ^ | + << >>
*/

