/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_lst.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 17:00:45 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 22:07:32 by dguelpa     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/main_vm.h"

void		lstadd_vm(t_process **alst, t_process *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void		lstiter_vm(t_process *lst, void (*f)(t_process *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

void		lstnew_vm_init(t_process **new, int *reg)
{
	(*new)->live = 0;
	(*new)->carry = 0;
	(*new)->next = NULL;
	(*new)->creation = 0;
	(*new)->begin = reg[0];
	(*new)->cycle_delay = 0;
}

t_process	*lstnew_vm(int *reg, int reg_size)
{
	t_process	*new;
	int			var;

	var = -1;
	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if (!reg)
		new->reg = NULL;
	else
	{
		if (!(new->reg = malloc(REG_NUMBER + 1)))
			return (NULL);
		ft_memcpy(new->reg, reg, reg_size);
	}
	while (++var < 4)
	{
		new->params[var][0] = 0;
		new->params[var][1] = -1;
	}
	lstnew_vm_init(&new, reg);
	return (new);
}
