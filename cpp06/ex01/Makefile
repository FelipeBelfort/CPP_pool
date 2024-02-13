NAME			=	conversion01

GCC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98

FILES			=	main

CLASSES			=	Serializer

INTERFACES		=	Data

OBJS_DIR		=	objs/

HEADER			=	$(CLASSES:=.hpp) $(INTERFACES:=.hpp)

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
