
#include <maze/dfs.hpp>

int main() {

	maze::description<2> d(glm::ivec2(10,10));

	maze::dfs<2> m(d);

	m.run();


}



