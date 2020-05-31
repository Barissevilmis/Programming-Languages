all: flex bison 20945-hw4
flex: 20945-hw4.flx
	flex 20945-hw4.flx
bison: 20945-hw4.y
	bison -d 20945-hw4.y
20945-hw4: lex.yy.c 20945-hw4.tab.c
	gcc -o 20945-hw4 lex.yy.c 20945-hw4.tab.c -lfl
clean:
	rm -f 20945-hw4
	rm -f lex.yy.c 
	rm -f 20945-hw4.tab.c