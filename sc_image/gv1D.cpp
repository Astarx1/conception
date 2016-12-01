#include "gv1D.h"

void gv1D::gv1DDerive()
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
			pixel_out.write(abs(pixel_in.read()-before.at(cur_x)));
			before.at(cur_x) = pixel_in.read();
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

void gv1D::setNx(unsigned nnx) {
	nx = nnx;
	std::cout << "Reallocation " << nnx << " elements" << std::endl;
	before.resize(nnx+1);	// Unique malloc
	for (int i = 0; i <= nnx + 1; ++i) {
		before.at(0);
	}
	std::cout << "Fin reallocation" << std::endl;
}