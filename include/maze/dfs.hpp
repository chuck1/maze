#ifndef __JESS_MAZE_DFS_HPP__
#define __JESS_MAZE_DFS_HPP__

#include <iostream>
#include <stdlib.h>

#include <maze/base.hpp>

//#define PRINTVAR(x) std::cout<<#x<<"="<<(x)<<std::endl
#define PRINTVAR(x)




namespace maze {

	template<int D> class dfs: public base<D> {
		public:
			typedef typename traits<D>::ivec	ivec;
			typedef typename traits<D>::vec		vec;

			dfs(description<D> desc):
				maze::base<D>(desc),
				i_(0) {}

			void	run()
			{

				int N = prod<D>(base<D>::desc_.size_);

				ispath = new bool[N];
				dead = new bool[N];
				unvisited = new bool[N];

				for(int i = 0; i < N; i++) {
					ispath[i] = false;
					dead[i] = false;
					unvisited[i] = true;
				}

				PRINTVAR( N );

				while( 1 ) {
					//std::cout << "i_=" << i_.x << " " << i_.y << std::endl;

					get_ispath(i_) = true;
					get_unvisited(i_) = false;

					//print_maze(ispath);
					//print_maze(unvisited);

					//std::cin.get();

					visit_cells_with_high_wall_adjacency();

					if(randomly_select_unvisited_neighbor()) {
						continue;
					} else {
						if(backtrack()) {
							continue;
						}
						else
						{
							break;
						}
					}
				}
				//base<D>::print_maze(ispath);
				//base<D>::print_maze(unvisited);

			}	
			void	visit_cells_with_high_wall_adjacency()
			{
				//std::cout << "visit cells with high adjacency" << std::endl;

				int count;

				for(int i = 0; i < prod<D>(base<D>::desc_.size_); i++ ) {
					ivec v = vector<D>(i, base<D>::desc_.size_);

					if( get_unvisited(v) ) {

						auto adj = base<D>::desc_.adjacent_to(v);
						PRINTVAR( adj.size() );

						count = 0;
						for(auto a : adj) {
							//std::cout << "a = " << a.x << " " << a.y << std::endl;
							if(get_ispath(a)) {
								count++;
							}
						}

						if(count > 1) {
							//std::cout << "visiting" << std::endl;
							get_unvisited(v) = false;
						}

						// aditional checks
					}
				}
			}
			bool	randomly_select_unvisited_neighbor() {
				//std::cout << "randomly_select" << std::endl;

				auto adj = base<D>::desc_.adjacent_to(i_);

				PRINTVAR( adj.size() );


				//std::cout << "\tfilter out visited" << std::endl;

				auto it = adj.begin();
				while( it != adj.end() )
				{
					//PRINTVAR( *it );

					if(!get_unvisited( *it )) {
						//std::cout << "erase" << std::endl;

						it = adj.erase( it );
					}
					else
					{
						++it;
					}
				}

				PRINTVAR( adj.size() );

				if( adj.empty() )
				{
					//std::cout << "randomly_select exit" << std::endl;
					return false;
				}

				PRINTVAR( adj.size() );

				int a = rand() % adj.size();

				//PRINTVAR( a );

				it = adj.begin();
				std::advance( it, a );

				i_ = *it;

				//std::cout << "randomly_select exit" << std::endl;
				return true;
			}
			bool	backtrack()
			{
				//std::cout << "backtrace" << std::endl;

				bool progress = false;

				while( 1 )
				{

					get_dead( i_ ) = true;

					progress = false;

					auto adj = base<D>::desc_.adjacent_to( i_ );
					//PRINTVAR( adj.size() );

					for( auto it = adj.begin(); it != adj.end(); it++ ) {

						if(get_ispath(*it) && (!get_dead(*it))) {

							progress = true;

							i_ = *it;

							if( randomly_select_unvisited_neighbor() )
							{
								return true;
							}

							break;
						}
					}

					if(!progress) {
						//std::cout << "no progress" << std::endl;
						return false;
					}
				}
			}
			bool&		get_ispath(ivec const & i) {
				return ispath[offset<D>(i, base<D>::desc_.size_)];
			}
			bool&		get_dead(ivec const & i) {
				return dead[offset<D>(i, base<D>::desc_.size_)];
			}
			bool&		get_unvisited(ivec const & i) {
				return unvisited[offset<D>(i, base<D>::desc_.size_)];
			}




			ivec			i_;
			bool*			ispath;
			bool*			dead;
			bool*			unvisited;




	};
}



#endif




