#!/usr/bin/make
#
# PurchaseOrder					May 16, 2024
#
# source: src/employee/Makefile
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

all: $(EMPLOYEE_BIN)

$(EMPLOYEE_BIN): $(EMPLOYEE_OBJ)
	$(CXX) $(CXXOPT) $(EMPLOYEE_OBJ) -o $(EMPLOYEE_BIN)

$(EMPLOYEE_OBJ): $(HEADERS) $(EMPLOYEE_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(EMPLOYEE_CXX) -o $(EMPLOYEE_OBJ)

clean:
	/bin/rm -f *.obj *.bin
