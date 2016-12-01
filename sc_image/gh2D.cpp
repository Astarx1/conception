#include "gh2D.h"

void gh2D::gh2DDerive()
{
	// reset
	if (reset.read() == 0)
	{
		pixel_out.write(0);
	}
	else if (clk.event() && clk.read()==1)
	{	
		if(blank.read() == 1)
		{
			pixel_out.write(abs(b2-0.5*(b1+b3)));
			b3 = b2;
			b2 = b1;
			b1 = pixel_in.read();
		}
	}
	// On laisse passer les controles
	bk_out = blank.read();
	hpix_out = clk.read(); 
}