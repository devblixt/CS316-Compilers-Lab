compiler: microLexer.l microParser.y main.cpp
	@bison -d -o microParser.c microParser.y
	@flex microLexer.l
	@g++ lex.yy.c microParser.c makers.h main.cpp -o compiler
	
clean: 
	@rm -f lex.yy.c microParser.c microParser.h compiler
dev:
	@echo "Devdatt N\n200010012@iitdh.ac.in"
