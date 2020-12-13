#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	int length;
	int height;
	int width;
};

typedef struct box box;

int get_volume( struct box box1) {
	int volume = box1.length * box1.height * box1.width;
	return volume;
}

int is_lower_than_max_height( struct box box1) {
	if (box1.height<41)
	{
		return 1;
	}
	else{
		return 0;
	}
	return 0;
	
}
int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}