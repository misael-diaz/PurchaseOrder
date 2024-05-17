#!/usr/bin/make
#
# PurchaseOrder					May 16, 2024
#
# source: src/client/Makefile
# author: @misael-diaz
#
# Synopsis:
# Defines the Makefile for building the program with GNU make.
#
# Copyright (c) 2024 Misael Díaz-Maldonado
# This file is released under the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#

include make-inc

all: $(CLIENT_BIN)

$(CLIENT_BIN): $(CLIENT_OBJ)
	$(CXX) $(CXXOPT) $(CLIENT_OBJ) -o $(CLIENT_BIN)

$(CLIENT_OBJ): $(HEADERS) $(CLIENT_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(CLIENT_CXX) -o $(CLIENT_OBJ)

clean:
	/bin/rm -f *.obj *.bin
