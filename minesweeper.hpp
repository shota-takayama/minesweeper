#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Mine {
private:
	int **matrix;
	bool **map;
	int height;
	int width;
	int bomb;

public:
	Mine(int h, int w, int N);
	~Mine();
	void start();
	void print_matrix();
	void print_correct();
	bool open(int y, int x);
	bool clear();
};
