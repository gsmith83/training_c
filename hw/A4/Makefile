flags := -pthread -O2 -fmessage-length=0 -pedantic-errors -std=gnu99 -Werror -Wall -Wextra -Wwrite-strings -Winit-self -Wcast-align -Wcast-qual -Wpointer-arith -Wstrict-aliasing -Wformat=2 -Wmissing-include-dirs -Wno-unused-parameter -Wshadow -Wuninitialized -Wold-style-definition

problem_1: problem_1.c
	gcc $(flags) problem_1.c -o problem_1

problem_2: problem_2.c
	gcc $(flags) problem_2.c -o problem_2
	
clean:
	rm -f *.o *.out problem_1 problem_2