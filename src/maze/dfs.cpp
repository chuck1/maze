#include <iostream>
#include <stdlib.h>

#include <maze/dfs.hpp>

//#define PRINTVAR(x) std::cout<<#x<<"="<<(x)<<std::endl
#define PRINTVAR(x)

jess::maze::dfs2::dfs2(jess::maze::description2 desc):
	jess::maze::base2(desc),
	i_(0,0)
{

}

void	jess::maze::dfs2::run()
{
	if ( !desc_.check() )
	{
		return;
	}

	int N = desc_.size_.x * desc_.size_.y;

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
	print_maze(ispath);
	print_maze(unvisited);

}	
void	jess::maze::dfs2::visit_cells_with_high_wall_adjacency()
{
	std::cout << "visit cells with high adjacency" << std::endl;

	int count;

	for( int i = 0; i < desc_.size_.x; i++ ) {
		for( int j = 0; j < desc_.size_.y; j++ ) {
			ivec2 v(i,j);

			if( get_unvisited(v) ) {
				
				auto adj = desc_.adjacent_to(v);
				PRINTVAR( adj.size() );

				count = 0;
				for(auto a : adj) {
					std::cout << "a = " << a.x << " " << a.y << std::endl;
					if(get_ispath(a)) {
						count++;
					}
				}

				if(count > 1) {
					std::cout << "visiting" << std::endl;
					get_unvisited(v) = false;
				}

				// aditional checks
			}
		}
	}
}
bool	jess::maze::dfs2::randomly_select_unvisited_neighbor() {
	//std::cout << "randomly_select" << std::endl;
	
	auto adj = desc_.adjacent_to(i_);
	
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

	std::cout << "randomly_select exit" << std::endl;
	return true;
}
bool	jess::maze::dfs2::backtrack()
{
	std::cout << "backtrace" << std::endl;

	bool progress = false;


	while( 1 )
	{

		get_dead( i_ ) = true;

		progress = false;

		auto adj = desc_.adjacent_to( i_ );
		PRINTVAR( adj.size() );

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
			std::cout << "no progress" << std::endl;
			return false;
		}
	}



}
bool&		jess::maze::dfs2::get_ispath(ivec2 const & i) {
	return ispath[i.x * desc_.size_.x + i.y];
}
bool&		jess::maze::dfs2::get_dead(ivec2 const & i) {
	return dead[i.x * desc_.size_.x + i.y];
}
bool&		jess::maze::dfs2::get_unvisited(ivec2 const & i) {
	return unvisited[i.x * desc_.size_.x + i.y];
}








