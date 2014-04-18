#ifndef __JESS_MAZE_DESCRIPTION_HPP__
#define __JESS_MAZE_DESCRIPTION_HPP__

#include <vector>

namespace jess
{
	namespace maze
	{
		struct description
		{
			description( int, int );

			int*	size_;
			int	c_;
			int	N_;

			bool			check();
			int			comp_to_flat( std::vector<int> );
			std::vector<int>	flat_to_comp( int );
			std::vector<int>	adjacent_to( int );
		};
	}
}

#endif
