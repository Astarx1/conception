#include "gh1D.h"

void gh1D::gh1DDerive()
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
			pixel_out.write(abs(((int)before-(int)pixel_in.read())));
			before = pixel_in.read();
		}
	}
	// On laisse passer les controles
	bk_out = blank.read();
	hpix_out = clk.read(); 
}