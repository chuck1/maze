#ifndef __JESS_MAZE_BASE_HPP__
#define __JESS_MAZE_BASE_HPP__

#include <vector>
#include <set>

#include <maze/description.hpp>


/*
 * return indices of sets in \c sets containing cells at \c ind
 */
std::set<std::size_t>		sets_containing(
		set_type ind,
		sets_type sets );
bool				are_of_different_sets(
		set_type adj,
		sets_type sets);
void				join_sets(
		set_type adj,
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
				set_type		adjacent_wall_to(ivec2);

				bool&			get(ivec2 const & i);

				description2		desc_;

				bool*			wall_;

		};
	}
}


#endif
