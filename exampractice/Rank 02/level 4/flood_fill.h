#ifndef FLOOD_FILL
# define FLOOD_FILL

typedef struct s_point
{
	int x;
	int y;
}	t_point;

void flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point current, char to_fill);

#endif
