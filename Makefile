CC=g++         
CCFLAGS= -std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer

driver: driver.o pca.o
	$(CC) $(CCFLAGS) driver.o pca.o -o driver

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

pca.o: pca.cpp pca.h
	$(CC) $(CCFLAGS) -c pca.cpp

clean:
	@rm -f *.o && rm -f driver
   
run:
	@./driver

