#ifndef __JESS_MAZE_BASE_HPP__
#define __JESS_MAZE_BASE_HPP__

#include <vector>
#include <set>

#include <galaxy/maze/description.hpp>

namespace jess
{
	namespace maze
	{
		class base
		{
			public:
				base( description );
				void			print_maze( std::vector<bool> );
				std::set<int>		adjacent_wall_to( int );

				description		desc_;
				std::vector<bool>	wall_;
		};
	}
}


#endif
