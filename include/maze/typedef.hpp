#ifndef MAZE_TYPEDEF_HPP
#define MAZE_TYPEDEF_HPP

#include <glm/glm.hpp>

namespace maze {
	template<int N> struct traits {};
	template<> struct traits<2> {
		typedef glm::ivec2	ivec;
		typedef glm::vec2	vec;
	};
	template<> struct traits<3> {
		typedef glm::ivec3	ivec;
		typedef glm::vec3	vec;
	};

template<int D> struct lessv {

	typedef typename maze::traits<D>::ivec	ivec;
	typedef typename maze::traits<D>::vec		vec;


	bool operator() (const ivec& x, const ivec& y) const {
		for(int i = 0; i < D; i++) {
			if(x[i] != y[i]) return x[i] < y[i];
		}
		return false;
	}

	typedef ivec first_argument_type;
	typedef ivec second_argument_type;
	typedef bool result_type;
};

template<int D> using set_type =  std::set< typename maze::traits<D>::ivec, lessv<D> >;
template<int D> using ret_pair =  std::pair< bool, set_type<D> >;
template<int D> using sets_type = std::vector< set_type<D> >;

}

#endif
