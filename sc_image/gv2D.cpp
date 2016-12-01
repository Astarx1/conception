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
			std::cout << cur_x << " ";
			pixel_out.write(abs(b2.at(cur_x)-0.5*(b1.at(cur_x)+b3.at(cur_x))));
			
			b3.at(cur_x) = b2.at(cur_x);
			b2.at(cur_x) = b1.at(cur_x);
			b1.at(cur_x) = pixel_in.read();

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

void gv2D::setNx(unsigned nnx) {
	nx = nnx;
	std::cout << "Reallocation " << nnx << " elements" << std::endl;
	b1.resize(nnx+1);	// Unique malloc
	b2.resize(nnx+1);
	b3.resize(nnx+1);
	for (int i = 0; i <= nnx + 1; ++i) {
		b1.at(0);
		b2.at(0);
		b3.at(0);
	}
	std::cout << "Fin reallocation" << std::endl;
}