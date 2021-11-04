BASE=ass6_19CS10064_19CS30008

tinyC: lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o
	g++ lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o -lfl -o tinyC
	@echo "\nMake process successful. The binary generated is tinyC\n"

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
	@mkdir -p test-outputs
	@mkdir -p bin

	@echo "\nRunning Test 1\n"
	./tinyC 1 < test-inputs/$(BASE)_test1.c > test-outputs/$(BASE)_quads1.out
	mv $(BASE)_1.s test-outputs/$(BASE)_1.s
	gcc -c test-outputs/$(BASE)_1.s -o test-outputs/$(BASE)_1.o
	gcc test-outputs/$(BASE)_1.o -o bin/test1 -L. -l$(BASE) -no-pie

	@echo "\nRunning Test 2\n"
	./tinyC 2 < test-inputs/$(BASE)_test2.c > test-outputs/$(BASE)_quads2.out
	mv $(BASE)_2.s test-outputs/$(BASE)_2.s
	gcc -c test-outputs/$(BASE)_2.s -o test-outputs/$(BASE)_2.o
	gcc test-outputs/$(BASE)_2.o -o bin/test2 -L. -l$(BASE) -no-pie

	@echo "\nRunning Test 3\n"
	./tinyC 3 < test-inputs/$(BASE)_test3.c > test-outputs/$(BASE)_quads3.out
	mv $(BASE)_3.s test-outputs/$(BASE)_3.s
	gcc -c test-outputs/$(BASE)_3.s -o test-outputs/$(BASE)_3.o
	gcc test-outputs/$(BASE)_3.o -o bin/test3 -L. -l$(BASE) -no-pie

	@echo "\nRunning Test 4\n"
	./tinyC 4 < test-inputs/$(BASE)_test4.c > test-outputs/$(BASE)_quads4.out
	mv $(BASE)_4.s test-outputs/$(BASE)_4.s
	gcc -c test-outputs/$(BASE)_4.s -o test-outputs/$(BASE)_4.o
	gcc test-outputs/$(BASE)_4.o -o bin/test4 -L. -l$(BASE) -no-pie

	@echo "\nRunning Test 5\n"
	./tinyC 5 < test-inputs/$(BASE)_test5.c > test-outputs/$(BASE)_quads5.out
	mv $(BASE)_5.s test-outputs/$(BASE)_5.s
	gcc -c test-outputs/$(BASE)_5.s -o test-outputs/$(BASE)_5.o
	gcc test-outputs/$(BASE)_5.o -o bin/test5 -L. -l$(BASE) -no-pie

	@echo "\nRunning Test 6\n"
	./tinyC 6 < test-inputs/$(BASE)_test6.c > test-outputs/$(BASE)_quads6.out
	mv $(BASE)_6.s test-outputs/$(BASE)_6.s
	gcc -c test-outputs/$(BASE)_6.s -o test-outputs/$(BASE)_6.o
	gcc test-outputs/$(BASE)_6.o -o bin/test6 -L. -l$(BASE) -no-pie

	@echo "\nThe three address quads, assembly files and object files are in test-outputs/\n"
	@echo "The binaries for the test files are in bin/\n"

clean:
	rm -f lex.yy.c *.tab.c *.tab.h *.output *.o *.s *.a *.out *.gch tinyC test-outputs/* bin/*
