INCLUDE_PATH    := ./src
SOURCE_PATH     := ./src
DEPENDENCY_PATH := ./src/dep
OBJECT_PATH     := ./src/obj

PROGRAM_NAME    := clang-complete

CC := clang

LDLIBS := $(shell llvm-config-3.0 --ldflags) $(shell llvm-config-3.0 --libs all) -lstdc++ -lclang
CFLAGS += $(shell llvm-config-3.0 --cflags) -Wall -Wextra -pedantic -O3


include makefile.mk
