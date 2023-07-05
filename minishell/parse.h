#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

enum e_character {
	WORD,
	INPUT_RDR,
	OUTPUT_RDR,
	DOUBLE_OUTPUT_RDR,
	DOUBLE_INPUT_RDR,
	PIPE,
	DOLLAR
};

enum e_loc_quot {
	none,
	head_end,
	midle
};

typedef struct s_type_counter{
	int	dollar;
	int	rdr;
	int	heredoc;
	int	word;
	int	pipe;
}					t_type_counter;

typedef struct s_arg {
	char				*content;
    enum e_character	type;
    struct s_arg		*next;
}					t_arg;

#endif