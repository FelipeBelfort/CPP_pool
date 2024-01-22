NAME			=	interface_recap

GCC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98

FILES			=	main

# CLASSES			=	AMateria Ice Cure ICharacter IMateriaSource Character MateriaSource
CLASSES			=	AMateria Ice ICharacter Character

OBJS_DIR		=	objs/

HEADER			=	$(CLASSES:=.hpp)

SRC				=	$(FILES:=.cpp) $(CLASSES:=.cpp)

OBJ				=	$(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))

RM				=	rm -fr

$(OBJS_DIR)%.o	: %.cpp $(HEADER)
				$(GCC) $(CFLAGS) -c $< -o $@

all				:	$(NAME)

$(NAME)			: $(OBJS_DIR) $(OBJ) Makefile
			$(GCC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJS_DIR)		:
			mkdir -p $(OBJS_DIR)

clean			:
			$(RM) $(OBJS_DIR)

fclean			:	clean
			$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
