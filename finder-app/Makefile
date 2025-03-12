#CROSS_COMPILE := aarch64-none-linux-gnu-

writer: writer.c
ifndef CROSS_COMPILE
	gcc writer.c -o writer
endif
ifdef CROSS_COMPILE
	$(CROSS_COMPILE)gcc writer.c -o writer
endif

clean:
	rm -f writer *.o