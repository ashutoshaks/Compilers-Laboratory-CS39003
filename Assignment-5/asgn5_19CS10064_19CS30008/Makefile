BASE=asgn5_19CS10064_19CS30008

output.txt: a.out $(BASE)_test.c
	./a.out < $(BASE)_test.c > output.txt

a.out: lex.yy.o y.tab.o $(BASE).o
	cc lex.yy.o y.tab.o $(BASE).o -lfl

lex.yy.o: lex.yy.c
	cc -c lex.yy.c

y.tab.o: y.tab.c
	cc -c y.tab.c

$(BASE).o: $(BASE).c
	cc -c $(BASE).c

lex.yy.c: $(BASE).l y.tab.h 
	flex $(BASE).l

y.tab.c: $(BASE).y
	bison -dty $(BASE).y

y.tab.h: $(BASE).y
	bison -dty $(BASE).y

$(BASE).c:
	touch $(BASE).c

clean:
	rm output.txt a.out lex.yy.* y.tab.* $(BASE).o