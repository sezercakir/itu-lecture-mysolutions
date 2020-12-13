#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//√(u(u-a)(u-b)(u-c)) u=(a+b+c)/2
struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
typedef struct triangle temp;
void sort_by_area(triangle* tr, int n) {
	int areacontrol1;int areacontrol2;
	temp *temptri = malloc(1 * sizeof(triangle));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			{	
				
				areacontrol1 = (tr[j-1].a+tr[j-1].b+tr[j-1].c)*(tr[j-1].a+tr[j-1].b-tr[j-1].c)*(tr[j-1].a-tr[j-1].b+tr[j-1].c)*(-tr[j-1].a+tr[j-1].b+tr[j-1].c);
				areacontrol2 = (tr[j].a+tr[j].b+tr[j].c)*(tr[j].a+tr[j].b-tr[j].c)*(tr[j].a-tr[j].b+tr[j].c)*(-tr[j].a+tr[j].b+tr[j].c);
				if (areacontrol1 > areacontrol2)
				{
					temptri->a = tr[j-1].a;temptri->b=tr[j-1].b;temptri->c = tr[j-1].c;
					tr[j-1].a = tr[j].a;tr[j-1].b = tr[j].b;tr[j-1].c= tr[j].c;
					tr[j].a = temptri->a;tr[j].b= temptri->b;tr[j].c = temptri->c;
				}
			}	
	}
	
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
