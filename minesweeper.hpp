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
	bool is_clear();

private:
	int **matrix;
	bool **map;
	int height;
	int width;
	int bombs;
	int size;
	void create_check_array(bool *check);
	void create_matrix_and_map(bool *check);
	bool is_number(char str[]);
};
