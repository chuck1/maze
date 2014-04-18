#include <iostream>
#include <stdlib.h>

#include <galaxy/maze/dfs.hpp>

#define PRINTVAR(x) std::cout<<#x<<"="<<(x)<<std::endl

jess::maze::dfs::dfs( jess::maze::description desc ):
	jess::maze::base( desc )
{

}

void	jess::maze::dfs::run()
{
	if ( !desc_.check() )
	{
		return;
	}

	ispath = std::vector<bool>( desc_.N_, 0 );
	dead = std::vector<bool>( desc_.N_, 0 );
	unvisited = std::vector<bool>( desc_.N_, 1 );

	PRINTVAR( ispath.size() );
	PRINTVAR( dead.size() );
	PRINTVAR( unvisited.size() );

	i_ = 0;

	while( 1 )
	{
		std::cout << "i_=" << i_ << std::endl;

		ispath.at(i_) = true;
		unvisited.at(i_) = false;
		
		visit_cells_with_high_wall_adjacency();
		
		if( randomly_select_unvisited_neighbor() )
		{
			continue;
		}
		else
		{
			if( backtrack() )
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	print_maze( ispath );
}	
void	jess::maze::dfs::visit_cells_with_high_wall_adjacency()
{
	std::vector<int> adj;
	int count;

	for( int i = 0; i < desc_.N_; i++ )
	{
		if( unvisited.at(i) )
		{
			adj = desc_.adjacent_to( i );
			count = 0;
			for( auto it = adj.begin(); it != adj.end(); it++ )
			{
				if( ispath.at( *it ) )
				{
					count++;
				}
			}

			if( count > 1 )
			{
				unvisited.at(i) = false;
			}

			// aditional checks
		}
	}
}
bool	jess::maze::dfs::randomly_select_unvisited_neighbor()
{
	//std::cout << "randomly_select" << std::endl;

	std::vector<int> adj = desc_.adjacent_to( i_ );

	//PRINTVAR( adj.size() );


	// filter out visited
	auto it = adj.begin();
	while( it != adj.end() )
	{
		//PRINTVAR( *it );
		
		if( !unvisited.at( *it ) )
		{
			//std::cout << "erase" << std::endl;
			
			adj.erase( it );
		}
		else
		{
			++it;
		}
	}

	if( adj.empty() )
	{
		//std::cout << "randomly_select exit" << std::endl;
		return false;
	}

	//PRINTVAR( adj.size() );

	int a = rand() % adj.size();

	//PRINTVAR( a );
	
	it = adj.begin();
	std::advance( it, a );

	i_ = *it;
	//std::cout << "randomly_select exit" << std::endl;
	return true;
}
bool	jess::maze::dfs::backtrack()
{
	std::cout << "backtrace" << std::endl;
	
	bool progress = false;

	std::vector<int> adj;

	while( 1 )
	{

		dead.at( i_ ) = true;

		progress = false;

		adj = desc_.adjacent_to( i_ );

		for( auto it = adj.begin(); it != adj.end(); it++ )
		{
			if( ispath.at( *it ) && !dead.at( *it ) )
			{
				progress = true;

				i_ = *it;

				if( randomly_select_unvisited_neighbor() )
				{
					return true;
				}

				break;
			}
		}

		if( !progress )
		{
			return false;
		}
	}



}











