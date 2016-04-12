#include "minesweeper.hpp"

Mine::Mine(int h, int w, int b) {
	height = h;
	width = w;
	bomb = b;
	int size = height * width;
	matrix = (int **)malloc(sizeof(int *) * height);
	map = (bool **)malloc(sizeof(bool *) * height);

	srand((unsigned int)time(NULL)); 
	int *random = (int *)malloc(sizeof(int) * bomb);
	bool *check = (bool *)malloc(sizeof(bool) * size);
	for(int _b = 0; _b < bomb; _b++) {
		while(1) {
			int val = rand() % size;
			if(!check[val]) {
				check[val] = true;
				random[_b] = val;
				break;
			}			
		}
	}

	for(int y = 0; y < height; y++) {
		matrix[y] = (int *)malloc(sizeof(int) * width);
		map[y] = (bool *)malloc(sizeof(bool) * width);
		for(int x = 0; x < width; x++) {
			int index = y * width + x;
			if(check[index]) {
				matrix[y][x] = -1;
			}
			map[y][x] = false;
		}
	}
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			int val = matrix[y][x];
			if(val != -1) {
				int count = 0;
				for(int j = -1; j <= 1; j++) {
					for(int i = -1; i <= 1; i++) {
						int _y = y + j, _x = x + i;
						if(_y >= 0 && _x >= 0 && _y < height && _x < width && matrix[_y][_x] == -1) {
							count++;
						}
					}
				}
				matrix[y][x] = count;
			}
		}
	}
}

Mine::~Mine() {
	free(matrix);
	free(map);
}

void Mine::start() {
	printf("\n\x1b[37m  !!!size:%dx%d, bomb:%d start!!!\n\x1b[39m", height, width, bomb);
}

void Mine::print_matrix() {
	printf("     ");
	for(int x = 0; x < width; x++) {
		printf("%3d", x);
	}
	printf("\n");
	printf("     ");
	for(int x = 0; x < width; x++) {
		printf("---");
	}
	printf("\n");
	for(int y = 0; y < height; y++) {
		printf("%3d |", y);
		for(int x = 0; x < width; x++) {
			if(map[y][x] == false) {
				printf("  ?");
			}
			else {
				int val = matrix[y][x];
				if(val > 0) {
					printf("\x1b[37m%3d\x1b[39m", val);
				}
				else if(val == 0) {
					printf("  -");
				}
				else if(val == -1) {
					printf("\x1b[31m  *\x1b[39m");
				}
			}
		}
		printf("\n");
	}
}

void Mine::print_correct() {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			map[y][x] = true;
		}
	}
	print_matrix();
}

bool Mine::open(int y, int x) {
	int val = matrix[y][x];
	if(val == -1) {
		return false;
	}
	else if(val == 0) {
		for(int j = -1; j <= 1; j++) {
			for(int i = -1; i <= 1; i++) {
				int _y = y + j, _x = x + i;
				if(_y >= 0 && _x >= 0 && _y < height && _x < width) {
					if(!map[_y][_x] && matrix[_y][_x] != -1) {
						map[_y][_x] = true;
						open(_y, _x);
					}
				}
			}
		}
		return true;
	}
	else {
		map[y][x] = true;
		return true;
	}
}

bool Mine::clear() {
	int count = 0;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			if(!map[y][x]) {
				count++;
			}
		}
	}

	if(count == bomb) {
		return true;
	}
	else {
		return false;
	}
}
