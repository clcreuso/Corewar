/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_cycle.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dguelpa <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 23:44:30 by dguelpa      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 23:57:12 by dguelpa     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/main_vm.h"

void	run_2(t_process **proc, t_process **begin)
{
	if (PROC->op == ZJMP)
		ft_zjmp(proc);
	if (PROC->op == LDI)
		ft_ldi(proc);
	if (PROC->op == STI)
		ft_sti(proc);
	if (PROC->op == FORK)
		ft_fork(proc, begin);
	if (PROC->op == LLD)
		ft_lld(proc);
	if (PROC->op == LLDI)
		ft_lldi(proc);
	if (PROC->op == LFORK)
		ft_lfork(proc, begin);
	if (PROC->op == AFF)
		ft_aff(proc);
}

void	run_1(t_process **proc, t_process **begin)
{
	if (PROC->op == LIVE)
		ft_live(proc);
	if (PROC->op == LD)
		ft_ld(proc);
	if (PROC->op == ST)
		ft_st(proc);
	if (PROC->op == ADD)
		ft_add(proc);
	if (PROC->op == SUB)
		ft_sub(proc);
	if (PROC->op == AND)
		ft_and(proc);
	if (PROC->op == OR)
		ft_or(proc);
	if (PROC->op == XOR)
		ft_xor(proc);
}

void	run(t_process **proc, t_process **begin)
{
	if (PROC->op >= ZJMP && PROC->op <= AFF)
		run_2(proc, begin);
	if (PROC->op >= LIVE && PROC->op <= XOR)
		run_1(proc, begin);
}
