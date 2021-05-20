all: buildMain buildTest

buildMain:
	g++ -o main main.cpp MarriageAgency.cpp People.cpp

buildTest:
	g++ --coverage Lab7/src/test.cpp Lab7/src/MarriageAgency.cpp Lab7/src/People.cpp -o test
	./test
	gcov MarriageAgency.cpp 
	gcov People.cpp
	
