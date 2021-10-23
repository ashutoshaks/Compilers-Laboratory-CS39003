BASE=asgn5_19CS10064_19CS30008

a.out: lex.yy.o y.tab.o $(BASE)_translator.o
	g++ lex.yy.o y.tab.o $(BASE)_translator.o -lfl

$(BASE)_translator.o: $(BASE)_translator.h $(BASE)_translator.cxx
	g++ -c $(BASE)_translator.h
	g++ -c $(BASE)_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: $(BASE).l y.tab.h $(BASE)_translator.h
	flex $(BASE).l

y.tab.c: $(BASE).y
	yacc -dtv $(BASE).y -Wconflicts-sr

y.tab.h: $(BASE).y
	yacc -dtv $(BASE).y -Wconflicts-sr

$(BASE).c:
	touch $(BASE).c

test: a.out
	@echo "\nTest Inputs are in ./test-inputs. Running on test files\n"
	./a.out < test-inputs/$(BASE)_test1.c > test-outputs/$(BASE)_quads1.out
	@echo "\nTest outputs generated and written to ./test-outputs!\n"

clean:
	rm -f lex.yy.c *.tab.c *.tab.h *.output *.o a.out *.gch test-outputs/*_quads*.out