NAME = cub3d

CC = cc

CFLAGS =	-Wall -Wextra -Werror -g \
			-IInclude 

LFLAGS =	-Llib \
			-lamoa -lmlx42 -ldl -lglfw -lXext \
			-lX11 -lm -lpthread

INC_ARCHIVES = lib/libmlx42.a

ERROR_MANAGEMENT = error_handler

MAIN = main

PARSE = parse parse_bis

EXECUTING = exec_init rendering game_loop exec_utils \
			raycasting raycasting_utils

FILES = $(ERROR_MANAGEMENT) \
$(MAIN) \
$(PARSE) \
$(EXECUTING)

SRC_FILES = $(addprefix src/ERROR_MANAGEMENT/, $(ERROR_MANAGEMENT)) \
$(addprefix src/MAIN/, $(MAIN)) \
$(addprefix src/PARSE/, $(PARSE))\
$(addprefix src/EXECUTING/, $(EXECUTING))

OBJ_DIR = obj/

SRCS = $(addsuffix .c, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

bonus: $(NAME_BONUS)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(INC_ARCHIVES) $(LFLAGS)

$(OBJ_DIR):
	mkdir $@

obj/%.o: src/*/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re