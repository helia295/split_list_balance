all:
	g++ -Wall -g product-digit-sum.cpp -o pds
	g++ -Wall -g split-list-balance.cpp -o slb
	
run:
	./pds
	./slb
	
try: all run
