#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "surrogatePair.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int main(int argc, char **argv)
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
{
	uint32_t val1;
	uint32_t val2;
	uint16_t pair[2];
	
	val1 = 1;
	while(val1)
	{
		printf("Enter value in hex (range 0x10000 to 10FFFF) 0 to quit: ");
		scanf("%x", &val1);
		if(val1)
		{
			encodeSurrogatePair(val1, pair);
			printf("val=0x%06X pairs=0x%04X 0x%04X\n", val1, pair[0], pair[1]);
			val2 = decodeSurrogatePair(pair);
			printf("Decoded value=0x%06X\n", val2);
		}
	}
	
	return 0;
}
