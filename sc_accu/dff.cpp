
#include "/home/romain/systemc-2.3.1/include/systemc.h"
#include "dff.h"

void dff::d2q() {
	if (reset) q = 0;
	else  q = d;
}


