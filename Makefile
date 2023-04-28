#NAMES
NAME= push_swap
NAME_BONUS= checker

#COMPILING
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

#DIRS
LIBFT_DIR= ./libft
INCS= ./include
SRCS_DIR= ./src
OBJS_DIR= ./obj

#LIBS
LIBFT= ${LIBFT_DIR}/libft.a
LIBFT_LIB= -L${LIBFT_DIR} -lft

#FILES
SRCF= parser

SRCS= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCF}))
OBJS= $(addprefix ${OBJS_DIR}/, $(addsuffix .o, ${SRCF}))

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} main.c
	${CC} ${CFLAGS} main.c ${OBJS} -I${INCS} ${LIBFT_LIB} -o ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -I${INCS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${LIBFT}:
	make bonus -sC ${LIBFT_DIR}

bonus:

clean:
	${RM} ${OBJS_DIR}
	make clean -sC ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -sC ${LIBFT_DIR}

re: fclean all

debug: ${LIBFT}
	${CC} -g3 main.c ${SRCS} -I./${INCS} ${LIBFT_LIB} -o ${NAME}

.PHONY: all
.SILENT:
