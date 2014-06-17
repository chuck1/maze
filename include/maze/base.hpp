#ifndef __JESS_MAZE_BASE_HPP__
#define __JESS_MAZE_BASE_HPP__

#include <vector>
#include <set>

#include <maze/description.hpp>

typedef std::set<ivec2>				set_type;
typedef std::pair< bool, set_type >		ret_pair;
typedef std::vector< set_type >			sets_type;

/*
 * return indices of sets in \c sets containing cells at \c ind
 */
std::set<std::size_t>		sets_containing(
		std::set<ivec2> ind,
		sets_type sets );
bool				are_of_different_sets(
		std::set<ivec2> adj,
		sets_type sets);
void				join_sets(
		std::set<ivec2> adj,
		sets_type& sets);

namespace jess {
	namespace maze
	{
		class base2 {
			public:
				base2(description2);
				void			print_maze(bool*);
				/** @breif adjacent wall to
				 *
				 * return set of indices of walls adjacent to cell at index @c a
				 */
				std::set<ivec2>		adjacent_wall_to(ivec2);

				bool&			get(ivec2 const & i);

				description2		desc_;

				bool*			wall_;

		};
	}
}


#endif
