#ifndef MAZE_RK_HPP
#define MAZE_RK_HPP

#include <maze/base.hpp>

namespace maze
{
	template<int D> class rk: public maze::base<D>
	{
		public:
			typedef typename traits<D>::ivec	ivec;
			typedef typename traits<D>::vec		vec;

			rk( maze::description<D> desc):
				maze::base<D>( desc ) {}

			void run()
			{
				//std::cout << "running..." << std::endl;
				//std::cout << "size = " << base<D>::desc_.size_.x << " " << base<D>::desc_.size_.y << std::endl;

				int N = prod<D>(base<D>::desc_.size_);

				base<D>::wall_ = new bool[N];


				set_type<D> unvisited;
				sets_type<D> sets(N, set_type<D>());

				for(int i = 0; i < N; i++) {
						
						ivec v = vector(i, base<D>::desc_.size_);
						
						unvisited.insert(v);

						sets.at(i).insert(v);
				}

				//print_maze(base<D>::wall_);

				int i = 0;
				while(!unvisited.empty()) {

					i = rand() % unvisited.size();
					//std::cout << "i=" << i << " unvisited.size()=" << unvisited.size() << std::endl;

					auto it = unvisited.begin();
					std::advance(it,i);

					auto a = *it;

					//std::cout << "cell " << a.x << " " << a.y << std::endl;

					unvisited.erase(it);

					auto adj = base<D>::adjacent_wall_to( a );

					//std::cout << "adj.size() = " << adj.size() << std::endl;

					if( are_of_different_sets(adj, sets) ) {

						//std::cout << "\tremoving wall" << std::endl;

						base<D>::get(a) = 0;

						join_sets( adj, sets );

						//std::cout << "sets.size()=" << sets.size() << std::endl;
					} else {
						//std::cout << "\twall not removed" << std::endl;
					}

					//print_wall();
				}

				//print_maze( base<D>::wall_ );
			}

	};
}

#endif

