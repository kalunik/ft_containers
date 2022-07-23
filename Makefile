CC		=	c++
RM		=	rm -f
CFLAGS	=	-I./ -std=c++98 -Wall -Wextra -Werror -ggdb3
LEAKS	=	leaks
LKFLAG	=	-atExit --
NAME	=	containers
INCL	=	stack.hpp \
			vector.hpp \
			iterators/bidirectional_iterator.h \
			iterators/iterator_traits.hpp \
			iterators/random_access_iterator.hpp \
			iterators/reverse_iter.hpp

SRCS	=	main.cpp

OBJS	=	$(patsubst %.cpp, %.o, $(SRCS))

all:
			$(MAKE) $(NAME)

$(NAME):	$(OBJS)
			@$(CC) -o $(NAME) $(OBJS)
			@echo "$(NAME) is ready to use ✅ "

%.o:		%.cpp Makefile $(INCL)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM)	$(OBJS)
			@echo ".o Deleted 🗿"

fclean: 	clean
			@$(RM)	 $(NAME)
			@echo "Deleted 😬"

re:			fclean all

run:		all
			./$(NAME)

leaks:		all
			$(LEAKS) $(LKFLAG) ./$(NAME)

.PHONY: all bonus clean fclean re run