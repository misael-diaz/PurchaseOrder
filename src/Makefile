#!/usr/bin/make
#
# PurchaseOrder				May 16, 2024
#
# source: Makefile
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

all: clients employees

clients:
	@$(MAKE) -C client
employees:
	@$(MAKE) -C employee
clean:
	@$(MAKE) -C client clean
	@$(MAKE) -C employee clean
