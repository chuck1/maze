//#include <jess/except.hpp>
#include <iostream>

#include <maze/rk.hpp>
#include <maze/base.hpp>




jess::maze::rk2::rk2( jess::maze::description2 desc ):
	jess::maze::base2::base2( desc )
{

}


void jess::maze::rk2::run()
{
	std::cout << "running..." << std::endl;
	std::cout << "size = " << desc_.size_.x << " " << desc_.size_.y << std::endl;
	if( !desc_.check() )
	{
		return;
	}

	int N = desc_.size_.x * desc_.size_.y;

	wall_ = new bool[N];
	

	set_type unvisited;
	sets_type sets( N, set_type() );

	for( int i = 0; i < desc_.size_.x; i++ ) {
		for( int j = 0; j < desc_.size_.y; j++ ) {

			unvisited.insert(ivec2(i,j));
			
			int o = i * desc_.size_.x + j;
			
			sets.at(o).insert(ivec2(i,j));
		}
	}

	print_maze(wall_);

	int i = 0;
	while(!unvisited.empty()) {
		
		i = rand() % unvisited.size();
		std::cout << "i=" << i << " unvisited.size()=" << unvisited.size() << std::endl;

		auto it = unvisited.begin();
		std::advance(it,i);

		auto a = *it;

		std::cout << "cell " << a.x << " " << a.y << std::endl;

		unvisited.erase(it);

		auto adj = adjacent_wall_to( a );

		std::cout << "adj.size() = " << adj.size() << std::endl;

		if( are_of_different_sets(adj, sets) ) {
			
			std::cout << "\tremoving wall" << std::endl;

			get(a) = 0;

			join_sets( adj, sets );

			std::cout << "sets.size()=" << sets.size() << std::endl;
		} else {
			std::cout << "\twall not removed" << std::endl;
		}

		//print_wall();
	}

	print_maze( wall_ );
}




















