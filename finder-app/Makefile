  ifdef CROSS_COMPILE 
    endif
	ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
    CC = aarch64-none-linux-gnu-gcc -g -Wall -c -o writer.o
	else 
    CC = gcc -g -Wall -I/ -o writer
	endif
 
default: 
	$(CC) writer.c 
		
.PHONY: clean

clean:
	rm -f *.o writer