BASE=ass6_19CS10064_19CS30008
DIR=./test-outputs

tinyC: lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o
	g++ lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o -lfl -o tinyC

$(BASE)_target_translator.o: $(BASE)_target_translator.cxx
	g++ -c $(BASE)_target_translator.cxx

$(BASE)_translator.o: $(BASE)_translator.h $(BASE)_translator.cxx
	g++ -c $(BASE)_translator.h
	g++ -c $(BASE)_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

$(BASE).tab.o: $(BASE).tab.c
	g++ -c $(BASE).tab.c

lex.yy.c: $(BASE).l $(BASE).tab.h $(BASE)_translator.h
	flex $(BASE).l

$(BASE).tab.c: $(BASE).y
	bison -dtv $(BASE).y

$(BASE).tab.h: $(BASE).y
	bison -dtv $(BASE).y

lib$(BASE).a: $(BASE).o
	ar -rcs lib$(BASE).a $(BASE).o

$(BASE).o: $(BASE).c myl.h
	gcc -c $(BASE).c

$(BASE).c:
	touch $(BASE).c

test: tinyC lib$(BASE).a
	./tinyC 1 < test-inputs/$(BASE)_test1.c > $(BASE)_quads1.out

	gcc -c $(BASE)_1.s

	gcc $(BASE)_1.o -o test1 -L. -l$(BASE) -no-pie

clean:
	rm -f lex.yy.c *.tab.c *.tab.h *.output *.o *.s *.a *.out *.gch tinyC test1
