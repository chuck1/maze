#ifndef __JESS_MAZE_DESCRIPTION_HPP__
#define __JESS_MAZE_DESCRIPTION_HPP__

#include <vector>
#include <set>

struct ivec2 {
	ivec2(int nx, int ny): x(nx), y(ny) {}
	ivec2		operator+(ivec2 const & rhs) const {
		return ivec2(x + rhs.x, y + rhs.y);
	}
	bool		operator<(ivec2 const & rhs) const {
		if(x == rhs.x) return (y < rhs.y);
		return (x < rhs.x);
	}
	int x,y;
};

namespace jess
{
	namespace maze
	{

		struct description2 {

			description2(ivec2);

			ivec2			size_;

			bool			check();
			std::set<ivec2>		adjacent_to(ivec2 i);
		};
	}
}

#endif
