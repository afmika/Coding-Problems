/**
 * @author afmika
 * */
#include <bits/stdc++.h>

using namespace std;
uint8_t b2digitsCount(uint32_t n) {
	return 1 + log((double) n) / log(2.);
}

uint8_t cidr_jump_table (uint32_t netmask) {
	
	uint32_t m = 0b11111111111111111111111111111111;
	uint8_t dg = b2digitsCount(netmask);
	
	// netmask should only contain 1's (right -> left)
	uint32_t invalid_check_mask = m ^ (m << dg);
	uint32_t temp = (m ^ netmask) & invalid_check_mask;
	if ( temp > 0 )
		return 0;
			
	// we are good
	return dg;
}

int main() {
	// tests
	printf("%d \n", cidr_jump_table(0b101)); // 0
	printf("%d \n", cidr_jump_table(0b111)); // 3
	printf("%d \n", cidr_jump_table(0b11)); // 2
	printf("%d \n", cidr_jump_table(0b1111101111)); // 0
	printf("%d \n", cidr_jump_table(0b11111)); // 5
	printf("%d \n", cidr_jump_table(0b11101111110)); // 0
	printf("%d \n", cidr_jump_table(0b111111111111111)); // 15
	printf("%d \n", cidr_jump_table(0b1111111111111111)); // 16
	printf("%d \n", cidr_jump_table(0b11111111111111111111111111111111)); // 32
	return 0;
}
