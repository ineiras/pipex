NAME = pipex

SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/
LIBFT_DIR = $(INC_DIR)libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

CC = cc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -I$(INC_DIR) -I$(LIBFT_DIR) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT) :
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean:
	@rm -f $(NAME)
	@make clean

re:	
	@make fclean
	@echo "Cleaning Everything..."
	@make 
