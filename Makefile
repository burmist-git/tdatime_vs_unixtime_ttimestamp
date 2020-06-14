########################################################################
#                                                                      #
# Copyright(C) 2019 - LBS - (Single person developer.)                 #
# Tue Apr 16 13:42:43 JST 2019                                         #
# Autor: Leonid Burmistrov                                             #
#                                                                      #
# Script description:                                                  #
#                                                                      #
# Input paramete:                                                      #
#                                                                      #
#                                                                      #
# This software is provided "as is" without any warranty.              #
########################################################################

ROOTCFLAGS  = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS    = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS   = $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTLDFLAGS = $(shell $(ROOTSYS)/bin/root-config --ldflags)

# add xml files
ROOTLIBS += -lMLP -lXMLIO

CXX  = g++
CXX += -I./     

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated
CXXFLAGS += $(ROOTCFLAGS)
CXXFLAGS += $(ROOTLIBS)
CXXFLAGS += $(ROOTGLIBS)
CXXFLAGS += $(ROOTLDFLAGS)
CXXFLAGSDICT = -g -Wall -fPIC -Wno-deprecated

.PHONY: all clean

#----------------------------------------------------#

all: tDatime_vs_unixTime_tTimeStamp

tDatime_vs_unixTime_tTimeStamp: tDatime_vs_unixTime_tTimeStamp.cc
	$(CXX) $< $(CXXFLAGS) -o $@ 

clean: 
	rm -f *~
	rm -f .*~
	rm -f tDatime_vs_unixTime_tTimeStamp
