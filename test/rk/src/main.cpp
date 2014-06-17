
#include <maze/rk.hpp>

int main() {

	jess::maze::description2 d(ivec2(10,10));

	jess::maze::rk2 m(d);

	m.run();


}



