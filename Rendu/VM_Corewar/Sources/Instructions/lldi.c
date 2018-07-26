/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lldi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 13:59:42 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 17:22:11 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/main_vm.h"

void		debug_lldi(t_process **proc, int fparam, int sparam)
{
	dprintf(1, "1st param = %d, sparam = %d, pc = %d\n",
			fparam, sparam, PROC->begin);
	dprintf(1, "register[%d] = %d\n",
			PROC->params[2][1],
			PROC->reg[PROC->params[2][1]]);
}

void		ft_lldi(t_process **proc)
{
	int				fparam;
	int				sparam;

	if (PROC->params[0][0] == 3)
		fparam =
			read_map((PROC->begin + PROC->params[0][1] % IDX_MOD), 4);
	else if (PROC->params[0][0] == 1)
		fparam = PROC->reg[PROC->params[0][1]];
	else
		fparam = PROC->params[0][1];
	if (PROC->params[1][0] == 2)
		sparam = PROC->params[1][1];
	else
		sparam = PROC->reg[PROC->params[1][1]];
	PROC->reg[PROC->params[2][1]] =
		read_map((fparam + sparam + PROC->begin), 4);
	PROC->carry = (!PROC->reg[PROC->params[2][1]] ? 1 : 0);
//	debug_lldi(proc, fparam, sparam);
}
