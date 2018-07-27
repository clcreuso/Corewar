/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_vm.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 16:14:53 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/27 08:24:24 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAIN_VM_H
# define MAIN_VM_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../../Libft/Includes/libft.h"
# include "../../Libft/Includes/libftprintf.h"

# define USE1 "Usage: ./corewar [-d N] [[-n number] champion1.cor] ...\n"
# define USE2 "\t-d N\t: dump memory after nbr_cycles then exit\n"
# define USE3 "\t-n number\t: set the number of the next player\n"
# define IND_SIZE			2
# define PROC				(*proc)
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE
# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3
# define MIN_REG			1
# define MAX_REG			16
# define LIVE	1
# define LD		2
# define ST		3
# define ADD	4
# define SUB	5
# define AND	6
# define OR		7
# define XOR	8
# define ZJMP	9
# define LDI	10
# define STI	11
# define FORK	12
# define LLD	13
# define LLDI	14
# define LFORK	15
# define AFF	16
# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define REG_NUMBER			16
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

typedef char				t_arg_type;

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct				s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}							t_header;

typedef struct				s_op
{
	char			*name;
	char			nparams;
	char			params[4];
	char			opcode;
	int				cycles;
	char			*desc;
	char			info_params;
	char			size_dir;
}							t_op;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃ typedef struct				s_process
**┃ {
**┃ 	int					*reg;			| reg for the mighty champion
**┃ 	char				carry;			| Dayum carry
**┃ 	unsigned char		*params;		| Current instruction saved
**┃ 	char				ocp;			| Current ocp
**┃ 	int					cycle_delay;	| Cycles needed to exec instruct
**┃ 	int					live;			| Num o live since last cycle_to_die
**┃ 	struct s_process	*next;			| Next and older process
**┃ }							t_process;
**┃
**┃ Linked list ordered from the younger to the older, finaly linked to NULL,
**┃ in order to respect the ancestral rule which allows the youngest to begin
**┃ with hostilities.
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct				s_process
{
	int					num;
	int					*reg;
	int					begin;
	char				carry;
	int					params[4][2];
	char				op;
	int					player;
	int					creation;
	int					cycle_delay;
	int					live;
	struct s_process	*next;
}							t_process;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃ typedef struct				s_champ
**┃ {
**┃ 	unsigned int	magic;			| Magic f**kin number
**┃ 	unsigned int	prog_size;		| Champion size
**┃ 	char			*filename;		| Filename
**┃ 	int				live;			| Obsolete ? Mb total lives for champion
**┃ 	char			*name;			| Apocalyptic name of Hell
**┃ 	char			*comment;		| Funniest comment written by bonobos
**┃ 	int				num;			| Number of player
**┃ 	unsigned char	*instructions;	| Finnest part of the champion
**┃ }							t_champ;
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
typedef struct				s_champ
{
	unsigned int	magic;
	unsigned int	prog_size;
	int				live;
	char			*name;
	char			*comment;
	char			*filename;
	int				num;
	unsigned char	*instructions;
}							t_champ;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃ typedef struct				s_vm
**┃ {
**┃ 	int				cycle_to_die;	| Various limit of CYCLE_TO_DIE
**┃ 	unsigned int	cycle;			| Total number of cycles passed
**┃ 	unsigned int	checks;			| Num of cycle_to_die passed w/o changes
**┃ 	t_champ			**champion;		| Tab of structs, with champs inside
**┃ 	t_process		*list_process;	| Linked list of proc., younger to older
**┃ 	unsigned char	*map;			| The ARENA of MEM_SIZE
**┃ 	char			*p_map;			| 'Filter map', for colors
**┃ 	int				dump;			| Flag dump
**┃ 	unsigned int	d_cycles;		| Nombre de cycles avant le dump
**┃ 	unsigned int	nb_players;		| Nombre de players
**┃ }							t_vm;
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct				s_vm
{
	int				nb_proc;
	int				cycle_to_die;
	unsigned int	cycle;
	unsigned int	checks;
	t_champ			**champion;
	t_process		*list_process;
	int				nb_live;
	int				last_live;
	unsigned char	*map;
	char			*p_map;
	int				dump;
	int				v;
	int				d_size;
	unsigned int	d_cycles;
	unsigned int	nb_players;
}							t_vm;

t_vm						*g_vm;

void						parse_args(char const **argv);
void						init_champs(char const **argv);
void						init_vm(char const **argv);
int							init_process(unsigned int a);
int							read_champ(int i);
int							read_header(int i);
int							read_code(int i, int fd);
void						process_remove_if_live(t_process **begin_list);
void						print_usage(void);
void						error_vm(char *s, int c);
int							check_data(void);
void						introduction(void);
int							cycling(void);
int							read_params(int cursor, t_op instruction,
							t_process **proc);
void						lstiter_vm(t_process *lst,
							void (*f)(t_process *elem));
void						lstadd_vm(t_process **alst, t_process *mew);
t_process					*lstnew_vm(int *reg, int reg_size);
int							ft_dump(void);
int							print_color(int i, int *p, int pc);
t_process					*get_last_proc(void);
void						process(void);
void						read_instruction(t_process **proc);
int							read_reg(int cursor);
int							read_ind(int cursor);
int							read_dir(int cursor, t_op instruction);
void						exec(t_process **proc, t_process **begin);
void						ft_print_nb_proc(t_process *begin);
void						print_instruction(t_process *proc);
t_op						*get_op_tab();
t_op						get_opcode(char op_code);
int							check_ocp(int instruct, int ocp);
int							free_all(void);
void						free_process(t_process *list);
int							read_map(int index);
unsigned char				*itoo(int nb);
void						print(int player, int index, int value);
void						ft_live(t_process **proc);
void						ft_ld(t_process **proc);
void						ft_st(t_process **proc);
void						ft_add(t_process **proc);
void						ft_sub(t_process **proc);
void						ft_and(t_process **proc);
void						ft_or(t_process **proc);
void						ft_xor(t_process **proc);
void						ft_zjmp(t_process **proc);
void						ft_ldi(t_process **proc);
void						ft_sti(t_process **proc);
void						ft_fork(t_process **proc, t_process **begin);
void						ft_lld(t_process **proc);
void						ft_lldi(t_process **proc);
void						ft_lfork(t_process **proc, t_process **begin);
void						ft_aff(t_process **proc);
int							check_reg(t_process *proc);

#endif
