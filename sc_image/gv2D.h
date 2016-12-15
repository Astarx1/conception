#include <systemc.h>

#include <vector>
#include <iostream>

#include "gdr.h"

#ifndef GV2D_H
#define GV2D_H

/////////////////////
SC_MODULE (gv2D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;

	sc_out <sc_uint<8> > pixel_out;
	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;
	
	std::vector<sc_uint<8> > up;
	sc_uint<8> bd, tmp;

	unsigned nx;
	unsigned cur_x;

	void gv2DDerive(void);
	void setNx(unsigned nnx);

	SC_CTOR(gv2D)
	{
		SC_METHOD(gv2DDerive);
		cur_x = 1;
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif