#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void
encodeSurrogatePair(uint32_t value, uint16_t *pair)
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
{
    unsigned int code;
	
    assert(0x10000 <= value && value <= 0x10FFFF);
    code = (value - 0x10000);
    pair[0] = 0xD800 | (code >> 10);
    pair[1] = 0xDC00 | (code & 0x3FF);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
uint32_t
decodeSurrogatePair(uint16_t *pair)
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
{
    uint32_t code;
	
    assert(0xD800 <= pair[0] && pair[0] <= 0xDBFF);
    assert(0xDC00 <= pair[1] && pair[1] <= 0xDFFF);
    code = 0x10000;
    code += (pair[0] & 0x03FF) << 10;
    code += (pair[1] & 0x03FF);
	
    return code;
}