/*
 *
 * mseqgen.cpp
 *
 */

#include <stdint.h>
#include <bitset>
#include <iostream>
#include <math.h>
#include "mseqgen.h"

static void print_b_arr_64(uint64_t val, unsigned int len)
{
	std::bitset<8> x(val);
	std::bitset<16> y(val);
	std::bitset<32> w(val);
	std::bitset<64> z(val);
	switch (len) {
	case 8:
                std::cout << x << '\n';
		break;
	case 16:
                std::cout << y << '\n';
		break;
	case 32:
		std::cout << w << '\n';
		break;
	default:
		std::cout << z << '\n';
	}
}

static unsigned int cmp_parity(uint64_t data)
{
	uint32_t v;

	v = data ^ (data >> 32);
	v ^= v >> 16;
	v ^= v >> 8;
	v ^= v >> 4;
	v ^= v >> 2;
	return (unsigned int)(v ^ (v >> 1)) & 1;
}

mseqgen::mseqgen(uint64_t polynom, uint64_t init, uint64_t mask, unsigned int alg)
{
	unsigned int shift;

	shift = 8 * sizeof(uint64_t) - 1;

	ini_polynom = polynom;
	ini_data = init;
	ini_mask = mask;
	ini_alg = alg;

	cmp_data = init;
	cmp_polynom = polynom | 1;
	cmp_mask = 1;
	cmp_mask <<= shift;
	print_b_arr_64(polynom, 16);
	print_b_arr_64(cmp_data, 64);
	while (shift--) {
		if (polynom & cmp_mask) {
			break;
		}
		cmp_mask >>= 1;
	}
	len_mask = cmp_mask - 1;
	len_mask <<= 1;
	len_mask += 1;
	return;
}

mseqgen::~mseqgen()
{
}

unsigned int mseqgen::mseqgen_get(void)
{
	unsigned int res = 0;
	unsigned int par = 0;

	if (ini_alg) {
		if (cmp_data & (uint64_t)1) {
			res = 1;
			cmp_data ^= cmp_polynom;
		}
		cmp_data >>= 1;
		return res;
	}
	print_b_arr_64(cmp_data, 64);
	cmp_data <<= 1;
	cmp_data &= len_mask;
	par = cmp_parity(cmp_data);
	if (cmp_data & cmp_mask) {
		res = 1;
		cmp_data ^= cmp_polynom;
	}
	return par;
}

