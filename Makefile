#NAMES
NAME= push_swap

#COMPILING
CC= cc
CFLAGS= -Wall -Wextra -Werror

#DIRS
LIBFT_DIR= ./libft
INCS= ./include
SRCS_DIR= ./src
OBJS_DIR= ./obj

#FILES
SRCF= 

SRCS= $(addprefix ${SRCS_DIR}/ $(addsuffix .c, ${SRCF}))
OBJS= $(addprefix ${OBJS_DIR}/ $(addsuffix .c, ${SRCF}))

all: ${NAME}

