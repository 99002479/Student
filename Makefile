all: all.out 
all.out : box.o wcbox.o boxdb.o box-test.o boxdb-test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
boxdb-test.o: boxdb-test.cpp box.h wcbox.h boxdb.h
	g++ $< -c
box-test.o: box-test.cpp box.h wcbox.h
	g++ $< -c
boxdb.o : boxdb.cpp boxdb.h wcbox.h box.h
	g++ $< -c
wcbox.o : wcbox.cpp wcbox.h box.h
	g++ $< -c    
box.o : box.cpp box.h
	g++ $< -c
clean:
	rm -rf *.o *.out
