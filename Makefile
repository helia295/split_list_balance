all:
	g++ -Wall product-digit-sum.cpp -o pds
	
run:
	./pds
	
try: all run
