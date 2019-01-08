##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/
D_SRCT	=	./tests/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)ls.c		\
		$(D_SRC)option.c	\
		$(D_SRC)sort.c		\
		$(D_SRC)cmp.c		\
		$(D_SRC)display.c	\
		$(D_SRC)display_file.c	\
		$(D_SRC)none_file.c	\
		$(D_SRC)sort_str.c	\
		$(D_SRC)tab_dir.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_ls

CFLAGS	=	-W -Wall -Wextra -I$(D_INC) -g

LDFLAGS	=	-L$(D_LIB) -lmy

TEST_LDFLAGS =	$(LDFLAGS) -lcriterion

TEST_CFLAGS =	$(CFLAGS) --coverage

TESTS_SRC	=	$(D_SRCT)test_map.c		\

all: $(NAME)

libmy:
	make -C $(D_LIB)

clean:
	rm -f $(OBJ)

clean_tests:
	rm -f *.gcno *.gcda

fclean:
	$(MAKE) clean
	$(MAKE) -C $(D_LIB) fclean
	$(MAKE) clean_tests
	rm -f $(NAME)
	rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:
	$(MAKE) fclean
	$(MAKE) all

tests: $(OBJ) clean
	$(MAKE) -C lib/my
	gcc -o unit_test $(TESTS_SRC) $(TEST_LDFLAGS) $(TEST_CFLAGS)

coverage:
	gcovr --exclude tests/

.PHONY: all clean fclean re
