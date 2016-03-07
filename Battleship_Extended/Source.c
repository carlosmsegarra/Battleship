#include <stdio.h>

void main(){
	
	srand(time(NULL));
	int x = 0, y = 0;
	int left = 10;
	int hit = 0;

	printf("Write the dimensions of the board.\n");
	printf("Write the number of rows: ");
	scanf_s("%d", &x);
	printf("Write the number of columns: ");
	scanf_s("%d", &y);
	
	char* map = (char*)malloc(x * y * sizeof(char));
	
	for (int i = 0; i < (x * y); ++i){
		map[i] = '.';
	}

	int a = rand() % (x * y);
	int b = rand() % (x * y);
	int c = rand() % (x * y);
	int d = rand() % (x * y);

	int b1 = 0;
	int c1 = 0;
	int d1 = 0;

	for (int i = 0; i < 3; ++i){
		int p = rand() % (5 - 1) + 1;

		switch (p){
		case 1:
			p = 1;
			break;
		case 2:
			p = -1;
			break;
		case 3:
			p = y;
			break;
		case 4:
			p = -y;
			break;
		}

		if (i == 0){
			b1 = p;
		}
		else if (i == 1){
			c1 = p;
		}
		else if (i == 2){
			d1 = p;
		}
	}

	while (left > 0){

		int x_coord = 0, y_coord = 0;
		hit = 0;

		for (int i = 0; i < x; ++i){
			for (int j = 0; j < y; ++j){
				printf("%c ", map[j + i * y]);
			}
			printf("\n");
		}

		printf("\nBoats left: %d", left);

		printf("\n\nWrite the X-coord: ");
		scanf_s("%d", &x_coord);
		printf("Write the Y-coord: ");
		scanf_s("%d", &y_coord);
		--x_coord;
		--y_coord;

		if ((y_coord + x_coord * y) == a){
			if (map[y_coord + x_coord * y] != 'A'){
				map[y_coord + x_coord * y] = 'A';
				hit = 1;
				--left;
			}
		}
		else if ((y_coord + x_coord * y) == b || (y_coord + x_coord * y) == (b + b1)){
			if (map[y_coord + x_coord * y] != 'B'){
				map[y_coord + x_coord * y] = 'B';
				hit = 1;
				--left;
			}
		}
		else if ((y_coord + x_coord * y) == c || (y_coord + x_coord * y) == (c + c1) || (y_coord + x_coord * y) == (c + c1 + c1)){
			if (map[(y_coord + x_coord * y)] != 'C'){
				map[(y_coord + x_coord * y)] = 'C';
				hit = 1;
				--left;
			}
		}
		else if ((y_coord + x_coord * y) == d || (y_coord + x_coord * y) == (d + d1) || (y_coord + x_coord * y) == (d + d1 + d1) || (y_coord + x_coord * y) == (d + d1 + d1 + d1)){
			if (map[(y_coord + x_coord * y)] != 'D'){
				map[(y_coord + x_coord * y)] = 'D';
				hit = 1;
				--left;
			}
		}

		if (hit == 1){
			printf("\n\nHit!\n");
		}
		else{
			printf("\n\nMiss!\n");
		}
	}

	getchar();
	getchar();
}