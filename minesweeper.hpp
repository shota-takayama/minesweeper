#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Mine {
public:
	Mine(int h, int w, int b);
	~Mine();
	void start();
	void print_matrix();
	void print_correct();
	void get_point(char msg[], int *pt, int threshold);
	bool open(int y, int x);
	bool clear();

private:
	int **matrix;
	bool **map;
	int height;
	int width;
	int bomb;
	int size;
	void create_check_array(bool *check);
	void create_matrix_and_map(bool *check);
};
