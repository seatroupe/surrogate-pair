#ifndef SURROGATE_PAIR_H
#define SURROGATE_PAIR_H

void      encodeSurrogatePair(uint32_t value, uint16_t *pair);
uint32_t  decodeSurrogatePair(uint16_t *pair);

#endif