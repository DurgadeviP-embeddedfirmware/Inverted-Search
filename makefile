obj:=$(patsubst %.c, %.o, $(wildcard *.c))

cal.exe:$(obj)
	gcc -o $@ $^

clean:
	rm *.o *.exe				