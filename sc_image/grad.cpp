#include "grad.h"

/*void grad::gradDerive()
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
			tmpv = abs((int) up.at(cur_x) - (int) pixel_in.read());
			int gv = abs((int)bdv+(int)tmpv);
			if (gv > 255) gv = 255;
			bdv = tmpv;

			tmph = (int) up.at(cur_x) + (int) pixel_in.read();
			int gh = abs((int)bdh-(int)tmph);
			//if (gh > 255) gh = 255;
			bdh = tmph;

			pixel_out.write(sqrt(gv*gv+gh*gh)); 
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
}*/
int max (int a, int b, int c) {
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c) 
		return b;
	else 
		return c;
}
int sqrt_ (int a, int b) {
	return max (abs (a), abs (b), 0.75*(abs(a) + abs(b)));
}
void grad::gradDerive() {
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
			tmpv = abs((int) up.at(cur_x) - (int) pixel_in.read());
			int gv = abs((int)bdv+(int)tmpv);
			if (gv > 255) gv = 255;
			bdv = tmpv;

			tmph = (int) up.at(cur_x) + (int) pixel_in.read();
			int gh = abs((int)bdh-(int)tmph);
			//if (gh > 255) gh = 255;
			bdh = tmph;

			pixel_out.write(sqrt_(gv,gh)); 
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

void grad::setNx(unsigned nnx) {
	nx = nnx;
	cur_x = 0;

	std::cout << "Reallocation " << nnx << " elements" << std::endl;
	up.resize(nnx+1);	// Unique malloc
	for (int i = 0; i <= nnx; ++i) {
		up.at(i) = 0;
	}
	std::cout << "Fin reallocation" << std::endl;
}