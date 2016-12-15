#include "gv2D.h"

void gv2D::gv2DDerive()
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
			//std::cout << cur_x << " ";
			tmp = abs((int) up.at(cur_x) - (int) pixel_in.read());
			int a = abs((int)bd+(int)tmp);
			if (a > 255) a = 255;
			pixel_out.write((unsigned char) a); 
			
			bd = tmp;
			up.at(cur_x) = pixel_in.read();

			if (cur_x == nx) {
				cur_x = 1;
			}
			else {
				cur_x++;
			}
		}
	}

	// On laisse passer les controles
	bk_out = blank.read();
	hpix_out = clk.read(); 
}

void gv2D::setNx(unsigned nnx) {
	nx = nnx;
	cur_x = 0;

	std::cout << "Reallocation " << nnx << " elements" << std::endl;
	up.resize(nnx+1);	// Unique malloc
	for (int i = 0; i <= nnx; ++i) {
		up.at(i) = 0;
	}
	std::cout << "Fin reallocation" << std::endl;
}