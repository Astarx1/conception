#include <systemc.h>

#include <vector>
#include <iostream>

#include "gdr.h"

#ifndef GH1D_H
#define GH1D_H

/////////////////////
SC_MODULE (gv1D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;

	sc_out <sc_uint<8> > pixel_out;
	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;
	
	std::vector<sc_uint<8> > before;
	unsigned nx;
	unsigned cur_x;

	void gv1DDerive(void);
	void setNx(unsigned nnx);

	SC_CTOR(gv1D)
	{
		SC_METHOD(gv1DDerive);
		cur_x = 1;
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif