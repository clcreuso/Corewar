/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_register.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 15:24:47 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 15:25:12 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/main_vm.h"

int				check_registers(t_process *proc)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (proc->fetchqueue[i][0] == 1 && proc->fetchqueue[i][1] < 1)
			return (0);
	return (1);
}
