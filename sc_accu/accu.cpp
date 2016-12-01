#include "systemc.h"
#include "accu.h"

void accu::add2x8() 
{
	if (raz) sum2reg = 0x7F;
	else {
		e1 = data.read();
		//e2 = q2sum.read(); // mieux avec read()
		sum2reg = sum2reg.read()-e1;
		somme.write(sum2reg);
	}
}
