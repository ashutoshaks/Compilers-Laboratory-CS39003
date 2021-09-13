output.txt: a.out ass3_19CS10064_19CS30008_test.c
	./a.out < ass3_19CS10064_19CS30008_test.c > output.txt

a.out: lex.yy.c ass3_19CS10064_19CS30008.c
	cc lex.yy.c ass3_19CS10064_19CS30008.c -lfl

lex.yy.c: ass3_19CS10064_19CS30008.l 
	flex ass3_19CS10064_19CS30008.l

ass3_19CS10064_19CS30008.c:
	touch ass3_19CS10064_19CS30008.c

clean:
	rm a.out lex.yy.c output.txt