# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:47:40 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STUDENT			=	jguyet

PROG1			=	scop

WHOAMI_CMD		=	$(shell whoami)

USER_HOME		=	$(addprefix "/Users/", $(WHOAMI_CMD))

BIN_BREW		=	$(addprefix $(USER_HOME), "/.brew/bin/brew")

LIBS_BREW		=	$(addprefix $(USER_HOME), "/.brew/lib/")

INCLUDES_BREW	=	$(addprefix $(USER_HOME), "/.brew/include/")

SDL2_INCLUDE_DIR_PATH	=	$(addprefix $(INCLUDES_BREW), "")

SDL2_INCLUDE_DIR		=	$(addprefix $(INCLUDES_BREW), "SDL2/")

SDL2_BIN_DIR_PATH		=	$(addprefix $(LIBS_BREW), "")

NAMEBASE    	=   $(shell basename $(PROG1) .a)

LENGTHNAME		=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS		=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRCDIR			=

OBJDIR			=	.objs/

INCDIR			=	includes/

LIBFTDIR		=	libft/

INCDIRLIBFT		=	$(LIBFTDIR)/includes/

LIBFTXDIR		=	libftx/

INCDIRLIBFTX	=	$(LIBFTXDIR)/includes/

SRCSPROG1		=	\
					srcs/scop/scop.c											\
					srcs/scop/window.c											\
					srcs/scop/context.c

DSRCSPROG1		=	$(addprefix $(SRCDIR), $(SRCSPROG1))

OBJSPROG1		=	$(addprefix $(OBJDIR), $(DSRCSPROG1:.c=.o))

OPENGL			=	-framework OpenGL -framework AppKit

.SILENT:

all:
	if test -f $(PROG1) ; then																\
		echo "make: Nothing to be done for \`all\`.";										\
	else																					\
		$(MAKE) -j $(STUDENT);																\
	fi

$(STUDENT): install_sdl
	make -C $(LIBFTDIR)
	make -C $(LIBFTXDIR)
	$(MAKE) $(PROG1)

$(PROG1):	$(OBJDIR) $(OBJSPROG1)
	$(CC) $(FLAGS) -o $(PROG1) $(OBJSPROG1) -L $(LIBFTDIR) -L $(LIBFTXDIR) -L $(SDL2_BIN_DIR_PATH) -lftprintf -lftx -lSDL2 $(OPENGL)
	echo "MAKE    [$(PROG1)]"
	echo "\033[38;5;227mAUTHOR  :\033[0m"
	cat auteur

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJSPROG1))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@																\
		-I $(INCDIR) -I $(INCDIRLIBFT) -I $(INCDIRLIBFTX) -I $(SDL2_INCLUDE_DIR_PATH)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"								\
	"MAKE    "$(NAMEBASE)" plz wait ..."	$(MAX_COLS)	$(MAX_COLS)	"[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "														\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K\033[0m";									\
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(LIBFTXDIR) clean

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "														\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K\033[0m";									\
	rm -rf $(PROG1)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) fclean
	make -C $(LIBFTXDIR) fclean

re:			fclean all

install_sdl:
	if [ -d $(SDL2_INCLUDE_DIR) ]; then \
		echo -en "\r\033[38;5;101mSDL2    [\033[0mINSTALLED\033[38;5;101m]\033[K\033[0m"; \
	else \
		echo -en "\r\033[38;5;101mSDL2    [\033[0mINSTALL\033[38;5;101m]\033[K\033[0m"; \
		$(BIN_BREW) install sdl2; \
    fi

.PHONY: all clean fclean re
