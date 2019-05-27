TARGET = main
LINKFILE += main.o
LINKFILE += say_goodbey.o
LINKFILE += say_hello.o

${TARGET}:${LINKFILE}
	gcc -o $@ $^

$< : main.c
	gcc -c 
$
	echo"*****$^	***** $@"
	echo"*************excute TARGET **************"
	#./${TARGET}
	echo"*************excute TARGET **************"


#main : main.o say_hello.o say_goodbey.o
#	gcc -o main main.o  say_hellolo.o  say_goodbey.o
#main.o:main.c
#	gcc -c main.c
#say_hello.o:say_hello.c
#	gcc -c say_hello.c
#say_goodbey.o:say_goodbey.c
#	gcc -c say_goodbey.c
#clean:
#	rm -rf *.o
#	rm -rf main
#	rm -rf a.out
