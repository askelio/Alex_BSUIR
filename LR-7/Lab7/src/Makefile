all: buildMain buildTest

buildMain:
	g++ -o main Lab7/src/main.cpp Lab7/src/MarriageAgency.cpp Lab7/src/People.cpp

buildTest:
	g++ --coverage Lab7/src/test.cpp Lab7/src/MarriageAgency.cpp Lab7/src/People.cpp -o test
	./test
	gcov MarriageAgency.cpp 
	gcov People.cpp
	
