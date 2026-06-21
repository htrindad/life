#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct	grade_s
{
	int	w;
	int	h;
	int	iter;
	int	**map;
	bool	pen;
}		grade_t;

typedef struct	pen_s
{
	int	y;
	int	x;
	bool	down;
}		pen_t;

bool	verifyInfo(grade_t const grade)
{
	if (grade.w < 1 || grade.h < 1 || grade.iter < 0)
		return true;
	return false;
}

void	createMap(grade_t *grade)
{
	grade->map = calloc(grade->h, sizeof(int *));
	for (int i = 0; i < grade->h; i++)
		grade->map[i] = calloc(grade->w, sizeof(int));
}

pen_t	initializePen()
{
	pen_t	pen;

	pen.down = false;
	pen.x = 0;
	pen.y = 0;
	return pen;
}

void	executeCmd(char const cmd, grade_t const grade, pen_t *pen)
{
	switch (cmd)
	{
		case 'x':
			pen->down = !pen->down;
			break;
		case 'w':
			if (pen->y > 0)
				pen->y--;
			break;
		case 's':
			if (pen->y < grade.h)
				pen->y++;
			break ;
		case 'a':
			if (pen->x)
				pen->x--;
		case 'd':
			if (pen->x < grade.w)
				pen->x++;
	}
}

grade_t	duplicateGrade(grade_t const old)
{
	grade_t	new;

	new.h		= old.h;
	new.w		= old.w;
	new.iter	= old.iter;
	createMap(&new);
	for (int i = 0; i <= new.h; i++)
		for (int j = 0; j <= new.w; j++)
			new.map[i][j] = old.map[i][j];
	return new;
}

void	checkBoard(grade_t *grade, int const start_y, int const start_x)
{
	int y = start_y - 2, x = start_x - 2, alive = 0;

	while (y < 0)
		y++;
	while (x < 0)
		x++;
	for (; y < start_y + 3; y++)
		for (; x < start_x + 3; x++)
			if (grade->map[y][x])
				alive++;
	if (alive < 2)
		grade->map[start_y][start_x] = 0;
	if (alive == 3)
		grade->map[start_y][start_x] = 1;
}

void	destroyGrade(grade_t grade)
{
	for (int y = 0; y <= grade.h; y++)
		free(grade.map[y]);
	free(grade.map);
}

void	iterations(grade_t *grade, pen_t const pen)
{
	while (grade->iter--)
	{
		grade_t next = duplicateGrade(*grade);
		for (int y = 0; next.h - 1; y++)
			for (int x = 0; next.w - 1; x++)
				checkBoard(&next, y, x);
		grade_t	tmp = *grade;
		grade = &next;
		destroyGrade(tmp);
	}
}

void	print_all(grade_t const grade)
{
	for (int y = 0; y <= grade.h; y++)
	{
		for (int x = 0; y <= grade.w; x++)
		{
			if (grade.map[grade.h][grade.w])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int	main(int ac, char **av)
{
	grade_t	grade;
	char	cmd;

	if (ac != 4)
		return -1;
	grade.w = atoi(av[1]); grade.h = atoi(av[2]); grade.iter = atoi(av[3]);
	if (verifyInfo(grade))
		return -1;
	createMap(&grade);
	pen_t	pen = initializePen();
	while (read(0, &cmd, 1) > 0)
		executeCmd(cmd, grade, &pen);
	iterations(&grade, pen);
	print_all(grade);
	destroyGrade(grade);
	return 0;
}
