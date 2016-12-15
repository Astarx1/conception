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
			std::cout << cur_x << " ";
			tmp = up.at(cur_x) + pixel_in.read();

			pixel_out.write(abs((int)bd-(int)tmp));
			
			bd = tmp;
			up.at(cur_x) = pixel_in.read();

			if (cur_x == nx) {
				std::cout << std::endl;
				std::cout << "L : ";
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

void gh2D::setNx(unsigned nnx) {
	nx = nnx;
	cur_x = 0;

	std::cout << "Reallocation " << nnx << " elements" << std::endl;
	up.resize(nnx+1);	// Unique malloc
	for (int i = 0; i <= nnx; ++i) {
		up.at(i) = 0;
	}
	std::cout << "Fin reallocation" << std::endl;
}