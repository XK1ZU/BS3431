/*
 *
 * main.cpp
 *
 */

#include <iostream>

#include "mseqgen.h"

int main()
{
	int i, ibit, qbit;
/*
 * iseq x15 + x13 + x9 + x8 + x7 + x5 + 1
 *      1  0 1 0 0 0 1   1    1  0 1 0 0 0 0 1
 * 0xa3a1
 * qseq x15 + x12 + x11 + x10 + x6 + x5 + x4 +x3 + 1
 *      1 0 0 1     1     1 0 0 0 1  1    1   1 0 0 1
 * 0x9c79
*/

	mseqgen iseq = mseqgen(0xa3a1, 1, 0xffff, 1);
	mseqgen qseq = mseqgen(0x9c79, 1, 0xffff, 1);
	for (i = 0; i < 64; i++) {
		ibit = iseq.mseqgen_get();
		qbit = qseq.mseqgen_get();
		std::cout << ibit << qbit << '\n';
	}
	
	return 0;
}
