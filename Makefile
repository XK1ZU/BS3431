CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=-g

SRCS=main.cpp mseqgen.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: cdma

cdma: $(OBJS)
	$(CXX) $(LDFLAGS) -o cdma $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) *.o cdma

include .depend
