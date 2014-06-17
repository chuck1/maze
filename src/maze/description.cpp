#include <iostream>

#include <maze/description.hpp>

jess::maze::description2::description2(ivec2 size):
	size_(size)
{
}
bool	jess::maze::description2::check()
{
	return 1;
}
std::set<ivec2>		jess::maze::description2::adjacent_to(ivec2 i) {
	
	//std::cout << "adjacent_to" << std::endl;
	
	std::set<ivec2> ret;
	
	if(i.x < (size_.x - 1)) ret.insert(i + ivec2( 1, 0));
	if(i.x > 0)		ret.insert(i + ivec2(-1, 0));
	if(i.y < (size_.y - 1)) ret.insert(i + ivec2( 0, 1));
	if(i.y > 0)		ret.insert(i + ivec2( 0,-1));

	return ret;
}


