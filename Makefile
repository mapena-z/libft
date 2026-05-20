NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_bzero.c ft_isprint.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memset.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c

OBJECTS = $(SOURCES:.c=.o)

GREEN = \033[0;32m
NC = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
TOTAL_OBJ = $(words $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@$(MAKE) -s progress
	@echo ""
	@echo "$(GREEN)libft compilation completed!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

clean:
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)Cleaning up object files for libft...$(NC)"


fclean:
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)libft fully cleaned!$(NC)"

re: fclean all

progress:
	@$(eval COMPLETED = $(shell ls -1 $(OBJECTS) 2>/dev/null | wc -l))
	@$(eval PERCENTAGE = $(shell echo "scale=2; 100 * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval BAR_LENGTH = 50)
	@$(eval FILLED_LENGTH = $(shell echo "$(BAR_LENGTH) * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval EMPTY_LENGTH = $(shell echo "$(BAR_LENGTH) - $(FILLED_LENGTH)" | bc))
	@echo -n "$(GREEN)["
	@$(eval BAR = $(shell yes "=" | head -n $(FILLED_LENGTH) | tr -d '\n'))
	@$(eval EMPTY = $(shell yes " " | head -n $(EMPTY_LENGTH) | tr -d '\n'))
	@echo -n "$(BAR)$(EMPTY)"
	@echo -n "] $(PERCENTAGE)%"
	@echo -n "\r"
	@sleep 0.05

.PHONY: all clean fclean re progress