a.out: main.o libass2_19CS30008.a
	cc main.o -L. -lass2_19CS30008

main.o: main.c myl.h
	cc -c main.c

libass2_19CS30008.a: ass2_19CS30008.o
	ar -rcs libass2_19CS30008.a ass2_19CS30008.o

ass2_19CS30008.o: ass2_19CS30008.c myl.h
	cc -c ass2_19CS30008.c

clean:
	rm a.out main.o libass2_19CS30008.a ass2_19CS30008.o 
