util_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CC ?=gcc
PREFIX ?=/usr/local

CFLAGS += -std=c99 -Iinclude -O3
#CFLAGS += -ffast-math
FLAGS +=  -fstrict-aliasing
#-mfpmath=sse
CFLAGS += -Wall -Wextra
CFLAGS += -mtune=native

CFLAGS += -fomit-frame-pointer

USE_DOUBLE    = 0
USE_COVERAGE ?= 0
USE_MEMCHECK ?= 1
USE_LTO      ?= 0

include common.mk
