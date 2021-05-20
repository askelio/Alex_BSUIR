all: buildMain buildTest

buildMain:
	g++ -o main main.cpp MarriageAgency.cpp People.cpp

buildTest:
	g++ --coverage src/test.cpp src/MarriageAgency.cpp src/People.cpp -o test
	./test
	gcov MarriageAgency.cpp 
	gcov People.cpp
	
