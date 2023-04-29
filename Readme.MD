## CS316 Compilers Lab

PA 1 : Implementation of a scanner for the MICRO language. Everything works. 

PA 2 : Implementation of a Parser for the MICRO language. 

PA 3 : Adding a Symbol table to the lexer and parser. 

PA 4 : Generating an AST and 3AC code for the AST

PA 5 : Code generation for WHILE/CONTINUE/BREAK statements

PA 6 : Code generation for multiple functions. Has some bugs, such as string declarations inside functions. A major bug was that return expressions containing parameters which are also the formal parameters of the function, do not work. These bugs have been fixed in PA 7. 

PA 7 : Optimizing the tiny code generation such that it uses only 4 registers. I have gone for the naive approach here and have spilled registers as I have used it, but a more intelligent approach would involve using liveness analysis. I did not have time to fix some bugs like setting the default return value of a function to 0 if return statement is absent. 

Contributions and Pull Requests are much appreciated. 

PS: Thanks to @Arvind-kumar-M-08 for providing me additional.zip which contain MICRO programs with which you can potentially detect your compiler's faults. The additional programs are very useful. 
