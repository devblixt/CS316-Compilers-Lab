dev: 
	@echo "Devdatt N\n200010012@iitdh.ac.in"

compiler: lex.yy.c parser.c main.cpp 
	@g++ -g lex.yy.c parser.c main.cpp wrapper.cpp -o a.out
	@chmod +x runme
parser.c: parser.y
	@bison -d $^ -o parser.c
lex.yy.c: scanner.l
	@flex $^
clean:
	@rm -f lex.yy.c parser.c parser.h a.out tiny
