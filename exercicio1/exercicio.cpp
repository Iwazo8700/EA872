
#include<iostream>
#include<memory>

class coord{
	public:
		coord();
		int x, y;
		void coord_new(int a, int b);
};

coord::coord(){
	x = 0;
	y = 0;

}

void coord::coord_new(int a, int b){
	x = a;
	y = b;
}

class cube{
	public:
		cube();
		int x,y,z;
		void cube_new(int a, int b, int c);
		void cube_print_volume();

};

cube::cube(){
	x = 0;
	y = 0;
	z = 0;
}

void cube::cube_new(int a, int b, int c){
	x = a;
	y = b;
	z = c;
}

void cube::cube_print_volume(){
	std::cout << x*y*z << std::endl;
}

int main( ){
	std::unique_ptr<coord> c1 (new coord);
	std::unique_ptr <cube> c2 (new cube);
	
	c1->coord_new(50, 10);
	c2->cube_new(10, 20, 30);
	c2->cube_print_volume();
	return 0;
}


