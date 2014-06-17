#ifndef __JESS_MAZE_DFS_HPP__
#define __JESS_MAZE_DFS_HPP__

#include <maze/base.hpp>

namespace jess { namespace maze {
		class dfs2: public jess::maze::base2 {
			public:
				dfs2(description2);
				void	run();
				void	visit_cells_with_high_wall_adjacency();
				bool	randomly_select_unvisited_neighbor();
				bool	backtrack();

				bool&			get_ispath(ivec2 const &);
				bool&			get_dead(ivec2 const &);
				bool&			get_unvisited(ivec2 const &);

				ivec2			i_;
				bool*			ispath;
				bool*			dead;
				bool*			unvisited;




		};
	}
}

#endif
