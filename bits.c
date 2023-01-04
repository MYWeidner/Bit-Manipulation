/* Online calculators:
coversions --- https://www.rapidtables.com/convert/number/binary-to-decimal.html
shifts --- https://miniwebtool.com/bitwise-calculator/bit-shift/
*/

int bitXor(int x, int y) {
/* 
bitXor(4, 5) which is 0100 and 0101 in binary respectively, the result should be 1 or 0001 in binary. 

Step-by-step check:
(x & y): x = 0100; y = 0101 so x and y = 0100
(~x & ~y) = ~ x = 1011; ~y = 1010 so ~x and ~y = 1010
~(x & y) = 1011
~(~x & ~y) = 0101
~(x & y) & ~(~x & ~y) = 1010 and 0101 = 0001 (correct)
*/
  return ~(x & y) & ~(~x & ~y);
}

int thirdBits(void) {
/* thirdBits shifts hexadecimal 49 
hex 49 = 73 in decimal
73 = 0000000001001001 in binary signed 2's complement
x stores hexadecimal representation of number 73
y stores left shifted value of x by 9 which is 1001001000000000 (37,376 in dec)
z is the sum of x and y which is 73 + 37,376 = 37,449 in dec (00000000000000001001001001001001 in binary signed 2's complement)
Function returns z shifted left by 18 then added to z
z << 18 = 01001001001001000000000000000000 in bin (1227096064 in dec)
z << 18 + z = 1,227,096,064 + 37,449 = 1,227,133,513 (matches btest)
*/
  int x = 0x49;
  int y = (x << 9); // stores left shifted value of x by 9
  int z = (x + y); // sum x and y
  return (z << 18) + z; // returns z shifted left by 18 then added to z
}

int upperBits(int n) {
/* !!n & 1 return 1 if n is nonzero and 0 if n is zero
<< 31:left shift
n + ~0 is a way to avoid using the "-" sign since n + ~0 = n - 1 
>> n-1: right shift (arithmetic shift since we are padding with 1's)

example: upperBits(4)
4 in dec is 100 in binary
!!n & 1 returns 1
left shift 1 by 31 is 10000000000000000000000000000000
right shift 10000000000000000000000000000000 by n - 1 or 3 = 11110000000000000000000000000000 = 0xF0000000
*/
  return ((!!n & 1) << 31) >> (n + ~ 0);
}

int byteSwap(int x, int n, int m) {
/* 
example byteSwap(0x12345678, 1, 3) = 0x56341278:
n = n << 3: n is left shifted and updated to equal 8
m = m << 3: m is left shifted and updated to equal 24
(x >> n): x is 8-bit right shifted (using updated value of n in dec)
x = 0x12345678 = 0x123456 after shift
(x >> m): x is 24-bit right shifted (using updated value of m in dec)
x = 0x12345678 = 0x12 after shift
((x >> n) ^ (x >> m)): 0x123456 
                   XOR 0x12
                    =  0x123444
a = 0xFF & ((x >> n) ^ (x >> m)): 0xFF
                                & 0x123444
                                = 0x44
***a is updated to 0x44***
(a << n): shift a = 0x44 left by 8-bit
a = 0x4400 after shift
x = x ^ (a << n):0x12345678
            XOR  0x4400
              =  0x12341278
***x updated to 0x12341278***
(a << m): shift a = 0x44 left by 24-bit
a =  after shift 0x44000000
x = x ^ (a << m):0x12341278
            XOR  0x44000000
              =  0x56341278
*** x is 0x56341278 which ties to example
*/
    int a = 0;
    // Convert bytes to bits (1 byte = 8 bits)
    n = n << 3; // performs 3-bit left shift on n and fills empty bits with 0
    m = m << 3; // performs 3-bit left shift on m and fills empty bits with 0
    
    // get m and n bytes
    // shifts the binary value of variable x right by n-bit and right by m-bit
    // then performs a bitwise XOR operation and bitwise AND operation with hexadecimal value 0xFF (255)
    a = 0xFF & ((x >> n) ^ (x >> m));
    
    // performs n-bit left shift on variable a which was initialized as 0 and then an XOR bitwise operation is performed to update variable x
    x = x ^ (a << n); 
    
    // performs m-bit left shift on variable a which was initialized as 0 and then an XOR bitwise operation is performed to update variable x
    x = x ^ (a << m);
    
    return x;
}

int copyLSB(int x) {
/* shift 31 bits to the left to remove all but least significant bit
next, perform right arithmetic shift of 31 bits to copy least significant bit
example: int 5 converts to 101 in binary. The last digit is 1 and copied so the result is 1111 and F in hexadecimal.
*/
  return ((x << 31) >> 31);
}

int divpwr2(int x, int n) {
/* example divpwr2(15,1) = 7: 
x = 15 in dec and 1111 in bin
n = 1 in dec and 0001 in bin
isnegative: last bit is 1 so this returns 0
lowBitHas1:
(1 << n) = perform 1-bit left shift on 1 which equals 0011
((1 << n)+ ~0) = 0011 - 0001 = 0010
(x & ((1 << n)+ ~0)) = 1111
                    &  0010
                    =  0010
!!(x & ((1 << n)+ ~0)) = !!(0010) = 1
return 1 if answer is nonzero and 0 otherwise
return:
(x >> n) = perform 1-bit right shift on 1111 = 0111 which 7 in binary
(isnegative & lowBitHas1) = 0 & 1 = 0
(x >> n) + (isnegative & lowBitHas1) = 7 + 0 = 7 (test passed)
*/    
    int isnegative = (x >> 31) & 0x1; // extract sign of bit; if x < 0, then 1; otherwise 0
    int lowBitHas1 = !!(x & ((1 << n)+ ~0)); // if x < 0 and x's n lowest bit has 1, then 1; otherwise, 0
    return (x >> n) + (isnegative & lowBitHas1);
}

int isEqual(int x, int y) {
/* Use the fact that XOR returns 0 when values are the same. So negating an XOR with ! bang operator will return 1 when values are the same (i.e. returns the opposite). !XOR is essentially ==.
XOR(5, 5) = 0 (would return 1 if values were different)
!XOR(5, 5) = 1
*/
  return !(x ^ y);
}

int isLess(int x, int y) {
/*
Notes:
use x - y for x + ~y + 1
x ^ y returns 0 when x = y
Positive signed bin #'s start with 0; negative start with 1 
(https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html)

example isLess(4,5) = 1:
x = 0100
y = 0101
sign_x = 1st digit is 0 so x is positive
sign_y = 1st digit is 0 so y is also positive
x_minus_y = 0100
          + 1010
          + 0001
          = 1111
sign_x_minus_y = 1 so x - y is negative
res_1:
(sign_x ^ sign_y) = 0 XOR 0 = 0
!(sign_x ^ sign_y) = 1 so signs are the same (both positive)
(sign_x_minus_y ^ 1) = 1
                   XOR 1
                     = 0
(!(sign_x ^ sign_y)) & (sign_x_minus_y ^ 1) = 1 & 0 = 0
res_2:
(!sign_x) = 1
(!sign_x) & sign_y = 1 & 0 = 0
return:
(res_1 | res_2) = 0 OR 0 = 0
!(res_1 | res_2) = 1
*/
    // sign_x and sign_y determines if values are negative (1) or positive (0) by right shifting to 1st digit
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    
    // case 1
    int x_minus_y = x + ~y + 1; // x - y
    int sign_x_minus_y = x_minus_y >> 31; // determine if x - y is negative (1) by checking first bit
    int res_1 = (!(sign_x ^ sign_y)) & (sign_x_minus_y ^ 1); // if x and y have the same sign and x - y is negative (1), then return 1 else return 0
    
    // case 2
    // if signs of x and y are opposite, return 1 if x < y and 0 otherwise
    int res_2 = (!sign_x) & sign_y;
    
    return !(res_1 | res_2);

}

int rempwr2(int x, int n) {
    int isnegative = (x >> 31) & 0x1; // extract sign of bit; if x < 0, then 1; otherwise 0
    int lowBitHas1 = !!(x & ((1 << n)+ ~0)); // if x < 0 and x's n lowest bit has 1, then 1; otherwise, 0
    int divpwr2_res = (x >> n) + (isnegative & lowBitHas1);
    
    /* divpwr2_res returns result of divpwr2
    return rempwr2(x, n) = x -(divpwr2(x, n) << n)
    used 2's complement for subtraction (x - y = x + ~y + 1) */
    return x + ((~(divpwr2_res) + 1) << n);
}

int satMul2(int x) {
/* Positive overflow occurs when most significant bit (MSB) of x is 0 and MSB of product is 1. This returns Tmax.
Negative overflow occurs when most significant bit (MSB) of x is 1 and MSB of product is 0. This returns Tmin.
If there is no overflow, then return product.
*/
    int Tmin = (1 << 31); // gives Tmin
    int Tmax = ~Tmin; // gives Tmax
    int mult = x + x; // multplies x by 2
    int signBit = x >> 31; // mask of MSB of x
    int overflow = (x ^ mult) >> 31; // check for overflow; if there is overflow, then 0xfffffff, else 0
    int sat = overflow & (signBit ^ Tmax); // returns Tmax if +overflow occurred; all 0's if - overflow or no overflow
    return sat | (~overflow & mult); // return Tmin if - overflow or Tmax if + overflow
}

int bang(int x) {
/* example: bang(3)
3 in dec is 0011 in binary
neg_x = 1100 + 0001 = 1101
flag_1 = 1
flag_2 = 0
(flag_1 | flag_2) & 0x1 = 1 or 0 is true so equals 1
~(flag_1 | flag_2) & 0x1 = returns opposite of sign bit so bang(3) = 0
*/
  int neg_x = ~x + 1; // gives logical negative of x
  int flag_1 = (x >> 31) & 0x1; // extract sign bit of x
  int flag_2 = (neg_x >> 31) & 0x1; // extract sign bit logical negative of x
  return ~(flag_1 | flag_2) & 0x1;
}

int reverseBits(int x) {
    /* left hand side of operations accumulate bit chunks with a right shift and accumulate in reverse order
    with a left shift. Function uses divide and conquer approach.
    example reverseBits(0x11111111) = 0x88888888:
    0x11111111 = 00010001000100010001000100010001
    step 1 - swap adjacent bits: 00010001000100010001000100010001
    after swap = 00_10_00_10_00_10_00_10_00_10_00_10_00_10_00_10
    step 2 - swap 2-bit chunk: 00_10_00_10_00_10_00_10_00_10_00_10_00_10_00_10
    after swap = 10_00_10_00_10_00_10_00_10_00_10_00_10_00_10_00
    step 3 - swap 4-bit chunk: 1000_1000_1000_1000_1000_1000_1000_1000
    after swap = 1000_1000_1000_1000_1000_1000_1000_1000
    step 4 - swap 8-bit chunk = 10001000_10001000_10001000_10001000
    after swap = 10001000_10001000_10001000_10001000
    step 5 - swap 16-bit chunk: 1000100010001000_1000100010001000
    after swap = 10001000100010001000100010001000
    in hex this final bin equals 0x88888888
    */
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1); // swap adjacent bits
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2); // swap 2-bit chunk
    x = ((x >> 4) & 0x0f0f0f0f) | ((x & 0x0f0f0f0f) << 4); // swap 4-bit chunk
    x = ((x >> 8) & 0x00ff00ff) | ((x & 0x00ff00ff) << 8); // swap 8-bit chunk
    x = ((x >> 16) & 0x0000ffff) | ((x & 0x0000ffff) << 16); // swap 16-bit chunk
  return x;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    /* Similiar to binary search for finding leftmost 1 in 32 bits
    example ilog2(16) = 4:
    step 1: (!!(16 >> 16)) << 4 = 0 << 4 = 0 = res
    step 2: 0 + ((!!(16 >> (0+8))) << 3 = 0 + ((!! 16 >> 8)) << 3 =
    0 << 3 = 0 = res
    step 3: 0 + ((!!(16 >> (0 + 4))) << 2) = 0 + ((!!(16 >> 4))) << 2) =
    0 + (1 << 2) = 0 + 4 = 4 = res
    step 4: 4 + ((!!(16 >> (4 + 2))) << 1) = 4 + ((!!(16 >> 6))) << 1) =
    4 + (0 << 1) = 4 + 0 = 4 = res
    step 5: 4 + (!!(16 >> (4 + 1))) = 4 + (!!(16 >> 5)) = 4 + 0 = 4
    result = 4
    */
    int res;
    res = (!!(x >> 16)) << 4; // step 1
    res = res + ((!!(x >> (res + 8))) << 3); // step 2  
    res = res + ((!!(x >> (res + 4))) << 2); // step 3
    res = res + ((!!(x >> (res + 2))) << 1); // step 4
    res = res + (!!(x >> (res + 1))); // step 5
  return res;
}
