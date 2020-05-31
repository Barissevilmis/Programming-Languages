all: flex bison 20945-hw3
flex: 20945-hw3.flx
	flex 20945-hw3.flx
bison: 20945-hw3.y
	bison -d 20945-hw3.y
20945-hw3: lex.yy.c 20945-hw3.tab.c
	gcc -o 20945-hw3 lex.yy.c 20945-hw3.tab.c -lfl
clean:
	rm -f 20945-hw3
	rm -f lex.yy.c 
	rm -f 20945-hw3.tab.c