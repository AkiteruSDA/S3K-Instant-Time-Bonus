include ../../config.mak

INCLUDES=-I../../
BUILDDIR=../../build
CFLAGS=-Wall -g -DUNIT_TEST $(INCLUDES)
LD_FLAGS=-L../../build

default:
	$(CC) -o symbol_address symbol_address.c \
	  ../../build/naken_asm.a \
	  $(CFLAGS)

clean:
	@rm -f symbol_address
	@echo "Clean!"

