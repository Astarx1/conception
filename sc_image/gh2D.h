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
	
	sc_uint<8> b1;
	sc_uint<8> b2;
	sc_uint<8> b3;

	void gh2DDerive(void);

	SC_CTOR(gh2D)
	{
		SC_METHOD(gh2DDerive);
		b1 = 0;
		b2 = 0;
		b3 = 0;
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif