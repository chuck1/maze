#ifndef __JESS_MAZE_DFS_HPP__
#define __JESS_MAZE_DFS_HPP__

#include <galaxy/maze/base.hpp>

namespace jess
{
	namespace maze
	{
		class dfs: public jess::maze::base
		{
			public:
				dfs( description );
				void	run();
				void	visit_cells_with_high_wall_adjacency();
				bool	randomly_select_unvisited_neighbor();
				bool	backtrack();


				int			i_;
				std::vector<bool>	ispath;
				std::vector<bool>	dead;
				std::vector<bool>	unvisited;




		};
	}
}

#endif
