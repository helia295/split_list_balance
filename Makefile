all:
	g++ -Wall -g product-digit-sum.cpp -o pds
	
run:
	./pds
	
try: all run
