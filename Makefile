all: 
	g++ nonRecursiveCrawler.cpp -I/home/x-machine/boost/include -L/home/x-machine/boost/lib -lboost_system -lboost_filesystem
#	g++ recursiveCrawler.cpp -I/home/x-machine/boost/include -L/home/x-machine/boost/lib -lboost_system -lboost_filesystem

#Please use the following command to run the object file
#	LD_LIBRARY_PATH=/home/x-machine/boost/lib/ ./a.out
