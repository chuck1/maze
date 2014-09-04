#ifndef __JESS_MAZE_BASE_HPP__
#define __JESS_MAZE_BASE_HPP__

#include <vector>
#include <set>

#include <maze/description.hpp>


/*
 * return indices of sets in \c sets containing cells at \c ind
 */

template<int D> std::set<size_t>		sets_containing(set_type<D> ind, sets_type<D> sets) {
	//std::cout << "sets_containing" << std::endl;
	//std::cout << "ind.size() = " << ind.size() << std::endl;
	std::set<size_t> set_i;

	for(auto i : ind) {
		for( unsigned int a = 0; a < sets.size(); a++ ) {
			if( sets.at(a).find(i) != sets.at(a).end() ) {
				set_i.insert(a);
				break;
			}
		}
	}

	return set_i;

}
template<int D> bool				are_of_different_sets(set_type<D> adj, sets_type<D> sets) {

	// returns false if all cells in adj are of the same set, otherwise true.

	std::set<size_t> set_i = sets_containing( adj, sets );
	//std::cout << "set_i = (";
	//for(auto i : set_i) {
	//std::cout << i << ",";
	//}
	//std::cout << ")" << std::endl;

	auto first_set = sets.at( *set_i.begin() );

	for( auto it = adj.begin(); it != adj.end(); it++ )
	{
		if( first_set.find( *it ) == first_set.end() )
		{
			return true;
		}
	}

	return false;
}

template<int D> void				join_sets(set_type<D> adj, sets_type<D> & sets) {

	auto set_i = sets_containing( adj, sets );

	//std::cout << "join sets" << std::endl;
	//std::cout << "set_i.size() = " << set_i.size() << std::endl;

	auto it = set_i.begin();

	// first set
	auto first_set = sets.begin();
	std::advance( first_set, *it );

	// next set
	it++;
	auto next_set = sets.begin();

	while( it != set_i.end() )
	{
		next_set = sets.begin();

		//std::cout << *it << std::endl;

		std::advance( next_set, *it );

		(*first_set).insert( (*next_set).begin(), (*next_set).end() );

		//std::cout << "sets.size()=" << sets.size() << std::endl;
		sets.erase(next_set);
		//std::cout << "sets.size()=" << sets.size() << std::endl;

		it++;
	}

	//std::cout << "join sets exit" << std::endl;
}

namespace maze {
	template<int D> class base {
		public:
			typedef typename traits<D>::ivec	ivec;
			typedef typename traits<D>::vec		vec;


			/** @breif adjacent wall to
			 *
			 * return set of indices of walls adjacent to cell at index @c a
			 */


			base( maze::description<D> desc ): desc_(desc) {}



			set_type<D>		adjacent_wall_to(ivec a) {
				// get all adjacent cells
				auto ret = desc_.adjacent_to(a);

				// erase those which are not walls
				auto it = ret.begin();
				while(it != ret.end()) {
					if(get(*it)) {
						it++;
						continue;
					}

					it = ret.erase(it);
				}
				return ret;

			}
			void			print_maze(bool* m) {
				std::cout << "print_maze" << std::endl;

				for(int i = 0; i < desc_.size_.x; i++ ) {
					for(int j = 0; j < desc_.size_.y; j++ ) {
						std::cout << m[i * desc_.size_.x + j];
					}
					std::cout << std::endl;
				}

			}	
			bool&			get(ivec const & i) {
				return wall_[offset(i, desc_.size_)];
			}







			description<D>		desc_;

			bool*			wall_;

	};
}



#endif
