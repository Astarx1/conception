#include <systemc.h>

#include <vector>
#include <iostream>

#include "gdr.h"

#ifndef GRAD_H
#define GRAD_H

/////////////////////
SC_MODULE (grad)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;

	sc_out <sc_uint<8> > pixel_out;
	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;
	
	std::vector<sc_uint<8> > up;
	int bdv,tmpv;
	int bdh,tmph;

	unsigned nx;
	unsigned cur_x;

	void gradDerive(void);
	void setNx(unsigned nnx);

	SC_CTOR(grad)
	{
		SC_METHOD(gradDerive);
		cur_x = 1;
		sensitive << clk << blank << pixel_in << reset;
	}
};

#endif