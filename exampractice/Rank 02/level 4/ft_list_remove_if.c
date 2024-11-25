void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;
	
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	while (*begin_list)
	{
		if (cmp(*begin_list -> data, data_ref) == 0)
		{
			temp = *begin_list;
			*begin_list = (*begin_list) -> next;
			free (temp);
		}
		else
		{
			begin_list = &((*begin_list) -> next);
		}
	}
}
