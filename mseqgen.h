/*
 *
 * mseqgen.h
 *
 */

#ifndef MSEQGEN_H_
#define MSEQGEN_H_
#include <stdint.h>

class mseqgen {
public:
	mseqgen(uint64_t polynom, uint64_t init, uint64_t mask, unsigned int alg);
	virtual ~mseqgen();
	unsigned int mseqgen_get(void);

private:
	uint64_t ini_data;
	uint64_t ini_polynom;
	uint64_t ini_mask;
	uint64_t ini_alg;
	uint64_t cmp_polynom;
	uint64_t cmp_data;
	uint64_t cmp_mask;
	uint64_t len_mask;
};

#endif /* MSEQGEN_H_ */
