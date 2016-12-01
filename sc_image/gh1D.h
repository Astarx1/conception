#include <systemc.h>
#include "gdr.h"

#ifndef GH1D_H
#define GH1D_H

/////////////////////
SC_MODULE (gh1D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;
	sc_out <sc_uint<8> > pixel_out;

	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;
	
	sc_uint<8> before;

	void gh1DDerive(void);
	SC_CTOR(gh1D)
	{
		SC_METHOD(gh1DDerive);
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif