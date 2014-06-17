
#include <maze/dfs.hpp>

int main() {

	jess::maze::description2 d(ivec2(10,10));

	jess::maze::dfs2 m(d);

	m.run();


}



