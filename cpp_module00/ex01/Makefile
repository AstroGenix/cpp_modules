# Compiler and flags
CXX = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -I includes

# Colours
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Background Colours
BGRED = \033[1:37;41m
BGREEN = \033[1:37;42m
BGYELLOW = \033[1:37;43m
BGBLUE = \033[1:37;44m
BGPURPLE = \033[1:37;45m
BGCYAN = \033[1:37;46m

# Reset Colour
RC = \033[0m

# Definitions
NAME = phonebook
SRC_DIR = sources/
OBJ_DIR = objects/

# Project Files
SOURCE_FILES = phonebook contact
#B_SRC_FILES =

SOURCES			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SOURCE_FILES)))
OBJECTS			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE_FILES)))
#B_SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(B_SRC_FILES)))
#B_OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRC_FILES)))
OBJ_FILES		=	.cache_exists

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CXX) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@echo "$(BGBLUE)         phonebook compiled        $(RC)"

$(OBJ_DIR):
		@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
#		@echo "$(BGREEN)       Compiling needed files        $(RC)"
		@echo "$(GREEN) -> Compiled: $(RC) $<"
		@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) -> Removed: $(RC)$(OBJECTS)$<"
	@rm -fr $(OBJ_DIR)
	@rm -f $(OBJECTS)
	@echo "$(BGPURPLE)        Object files deleted       $(RC)"


fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) -> Removed: $(RC)$(NAME)"
	@echo "$(BGPURPLE)         Executable deleted        $(RC)"

re: fclean all

.PHONY: all clean fclean re