#ifndef MAZE_TYPEDEF_HPP
#define MAZE_TYPEDEF_HPP

#include <glm/glm.hpp>

typedef glm::ivec2 ivec2;

struct lessv {
	bool operator() (const ivec2& x, const ivec2& y) const {
		if(x.x == y.x) return x.y < y.y;
		return x.x < y.x;
	}
	typedef ivec2 first_argument_type;
	typedef ivec2 second_argument_type;
	typedef bool result_type;
};

typedef std::set<ivec2,lessv>				set_type;
typedef std::pair< bool, set_type >			ret_pair;
typedef std::vector< set_type >				sets_type;

#endif
