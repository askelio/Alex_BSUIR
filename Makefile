all:
	gcc App.c -std=c89 -o App
	gcc -Dmain=_main App.c App_test.c -o App_Test
	