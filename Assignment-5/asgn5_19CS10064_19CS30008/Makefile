BASE=asgn5_19CS10064_19CS30008

output.txt: a.out $(BASE)_test.c
	./a.out < $(BASE)_test.c > output.txt

a.out: lex.yy.o y.tab.o $(BASE)_translator.o
	cc lex.yy.o y.tab.o $(BASE)_translator.o -lfl

$(BASE)_translator.o: $(BASE)_translator.h $(BASE)_translator.cxx
	cc -c $(BASE)_translator.h
	cc -c $(BASE)_translator.cxx

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

test: a.out
	@echo "\nTest Inputs are in ./test-inputs. Running on test files\n"
	./a.out < test-inputs/$(BASE)_test1.c > test-outputs/$(BASE)_quads1.out
	./a.out < test-inputs/$(BASE)_test2.c > test-outputs/$(BASE)_quads2.out
	./a.out < test-inputs/$(BASE)_test3.c > test-outputs/$(BASE)_quads3.out
	./a.out < test-inputs/$(BASE)_test4.c > test-outputs/$(BASE)_quads4.out
	./a.out < test-inputs/$(BASE)_test5.c > test-outputs/$(BASE)_quads5.out
	@echo "\nTest outputs generated and written to ./test-outputs!\n"

clean:
	rm -f lex.yy.c y.tab.c y.tab.h y.output *.o a.out *.gch test-outputs/*_quads*.out