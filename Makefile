SRC=engine

CXX=g++
CC=gcc

ALL_CPPFLAGS=-std=gnu++2b -Wno-gnu-array-member-paren-init -I .

DBG_CPPFLAGS:=$(ALL_CPPFLAGS) -g
DEV_CPPFLAGS:=$(ALL_CPPFLAGS) -Ofast -march=native

SRC_FILES:=$(shell python3 scripts/ls_ext.py --dir $(SRC) .cpp)
OBJECTS:=$(patsubst $(SRC)/%.cpp,%.o,$(SRC_FILES))

DBG_BIN=dbg_bin
DEV_BIN=dev_bin

DBG_TARGET=dbg_build
DEV_TARGET=dev_build

DBG_OBJECTS:=$(patsubst %,$(DBG_BIN)/%,$(OBJECTS))
DEV_OBJECTS:=$(patsubst %,$(DEV_BIN)/%,$(OBJECTS))

$(DEV_TARGET): $(DEV_OBJECTS)
	$(CXX) $^ -o dev_bin/$@

$(DEV_OBJECTS): $(DEV_BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(DEV_CPPFLAGS) -c $^ -o $@

.PHONY: clean
clean: clean_dbg clean_dev

.PHONY: dbg_clean
dbg_clean:
	rm $(shell python3 scripts/ls_ext.py --dir $(DBG_BIN) .o)
	rm $(DBG_BIN)/$(DBG_TARGET)

.PHONY: dev_clean
dev_clean:
	rm $(shell python3 scripts/ls_ext.py --dir $(DEV_BIN) .o)
	rm $(DEV_BIN)/$(DEV_TARGET)
