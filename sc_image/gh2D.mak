# makefile
###############################################################
# export LD_LIBRARY_PATH=/usr/lsa/apps/systemc-2.3.1/lib-linux64/
# export SYSTEMC_HOME="/usr/lsa/apps/systemc-2.3.1"
#################################################################
MODULE = gh2D
SRCS = gdr.cpp sc_image.cpp gh2D.cpp tb_gh2D.cpp
OBJS = $(SRCS:.cpp=.o)

##########################################################################"
TARGET_ARCH = linux64
SYSTEMC=/home/romain/systemc-2.3.1

CC = g++
OPT    = -O3 -Wno-deprecated
CFLAGS = $(OPT) -fexceptions

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux64

LIBS   =  -lsystemc -lm

EXE    = $(MODULE).x

.SUFFIXES: .cc .cpp .o .x

$(EXE): $(OBJS) $(SYSTEMC)/lib-linux64/libsystemc.a 
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE)
