#include <systemc.h>

#include <vector>
#include <iostream>

#include "gdr.h"

#ifndef GH2D_H
#define GH2D_H

/////////////////////
SC_MODULE (gh2D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;

	sc_out <sc_uint<8> > pixel_out;
	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;
	
	std::vector<sc_uint<8> > up;
	sc_uint<8> bd,tmp;

	unsigned nx;
	unsigned cur_x;

	void gh2DDerive(void);
	void setNx(unsigned nnx);
	SC_CTOR(gh2D)
	{
		SC_METHOD(gh2DDerive);
		bd = 0;
		tmp = 0;
		cur_x = 0;
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif