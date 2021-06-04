#include <stdio.h>
int absolute(int k)
{
	if(k >= 0)
	{
		k = k;
	}
	else
	{
		k = k + 2*(0 - k);
	}
	return k;
}
int main()
{
	int size,car_number;
	int t = 0,x,y;
	printf("Size: \n");
	scanf("%d",&size);
	if(size > 50 || size < 1)
	{	
		do
		{
			printf("Size must be between 50 and 1\n");
			printf("Size: \n");
			scanf("%d",&size);
		}while(size < 1 || size > 50);
	}
	printf("Cars: \n");
	scanf("%d",&car_number);
	int grid[size][size] ;
	for(x=0;x<size;x++)
	{
		for(y=0;y<size;y++)
		{
			grid[x][y] = 0;
		}
	}
	if(car_number >= 1 && car_number < (size*size))
	{
		do
		{
			printf("Locations: \n");
			scanf("%d %d",&x,&y);
			x = x - 1;
			y = y - 1;
			grid[x][y] = 1;
			t = t + 1;
		}while(t < car_number);
		t = 0;
	}
	int a,b,c,d,e = 1,f = 1,g,h,distance1,distance2 = 0;
	int distance[size][size];
	for(x=0;x<size;x++)
	{
		for(y=0;y<size;y++)
		{
			distance[x][y] = 0;
		}
	}
	for(a = 0;a < size; a++)
	{
		for(b = 0;b < size;b++)
		{
			if(grid[a][b] == 0)
			{
				for(c = 0;c < size;c++)
				{
					for(d = 0;d < size;d++)
					{
						if(grid[c][d] == 1)
						{
							g = c - a;
							h = d - b;
							distance1 = absolute(g) + absolute(h);
							if(distance2 == 0)
							{
								distance2 = distance1;
								distance[a][b] = distance2;
							}
							else if(distance1 < distance2)
							{
								distance2 = distance1;
								distance[a][b] = distance2;
							}
							else
							{
								distance2 = distance2;
							}
						}
					}
				}
			}
			distance2 = 0;
		}
	}
	
	int m = 0;
	for(a=0;a<size;a++)
	{
		for(b=0;b<size;b++)
		{
			if(distance[a][b] > m)
			{
				m = distance[a][b];
				e = a + 1;
				f = b + 1;
			}
		}
	}
	
	if(car_number == (size*size))
	{
		printf("Best Slot Found In: 0 0\n");
	}
	else
	{
	printf("Best Slot Found In: %d %d\n",e,f);
	}
	
	return 0;
}