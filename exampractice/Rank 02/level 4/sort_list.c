#include "sort_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list *start;
	
	start = lst;
	while (lst && lst -> next)
	{
		if ((*cmp)(lst -> data, lst -> next -> data) == 0)
		{
			swap = lst -> data;
			lst -> data = lst -> next -> data;
			lst -> next -> data = swap;
			lst = start;
		}
		else
		{
			lst = lst -> next;
		}
	}
	return (start);
}
/*t_list *create_node(int data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int ascending(int a, int b)
{
    return (a <= b);
}

int main()
{
    t_list *list = create_node(3);
    list->next = create_node(1);
    list->next->next = create_node(2);
    list->next->next->next = create_node(4);

    printf("Original list: ");
    print_list(list);

    list = sort_list(list, ascending);

    printf("Sorted list: ");
    print_list(list);

    // Free the list
    t_list *tmp;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;
}*/