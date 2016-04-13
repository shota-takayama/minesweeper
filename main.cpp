#include "minesweeper.hpp"

int main(int argc, char* argv[]) {
	
	int height = argc == 4 ? atoi(argv[1]) : 10;
	int width = argc == 4 ? atoi(argv[2]) : 10;
	int bombs = argc == 4 ? atoi(argv[3]) : 10;
	if(bombs > height * width) {
		printf("!!!too many bombs!!!\n");
		return 0;
	}

	Mine mine(height, width, bombs);
	mine.start();
	int pt_y = 0, pt_x = 0;
	while(1) {
		printf("\n");
		mine.print_matrix();
		mine.get_point((char *)"  input point y: ", &pt_y, height);
		mine.get_point((char *)"  input point x: ", &pt_x, width);
		if(!mine.open(pt_y, pt_x)) {
			printf("\x1b[31m\n  !!!failed!!!\n\x1b[39m");
			mine.print_correct();
			break;
		}
		if(mine.is_clear()) {
			printf("\x1b[33m\n  !!!success!!!\n\x1b[39m");
			mine.print_correct();
			break;
		}
	}

	return 0;
}