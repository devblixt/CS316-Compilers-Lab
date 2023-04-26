dev: 
	@echo "Devdatt N\n200010012@iitdh.ac.in"

compiler: lex.yy.c
	@g++ $< -o compiler

lex.yy.c: scanner.l 
	@flex $^

clean: lex.yy.c 
	@rm lex.yy.c 

#if lex.yy.c is not made, it will probably make it again!