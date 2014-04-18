//#include <jess/except.hpp>
#include <iostream>

#include <galaxy/maze/base.hpp>

jess::maze::base::base( jess::maze::description desc ):
	desc_(desc)
{

}


typedef std::pair< bool, std::set<int> > ret_pair;
typedef std::vector< std::set<int> > sets_type;

std::set<int>	sets_containing( std::set<int> ind, sets_type sets )
{
	std::set<int> set_i;

	for( auto it = ind.begin(); it != ind.end(); it++ )
	{
		for( unsigned int a = 0; a < sets.size(); a++ )
		{
			if( sets.at(a).find(*it) != sets.at(a).end() )
			{
				set_i.insert(a);
				break;
			}
		}
	}

	return set_i;
}

bool	are_of_different_sets( std::set<int> adj, sets_type sets )
{
	// returns false if all cells in adj are of the same set, otherwise true.

	std::set<int> set_i = sets_containing( adj, sets );
	std::cout << "set_i=(";
	auto it = set_i.begin();
	while ( 1 )
	{
		std::cout << *it;

		it++;
		if( it != set_i.end() )
		{
			std::cout << ",";
		}
		else
		{
			break;
		}
	}
	std::cout << ")" << std::endl;

	std::set<int> first_set = sets.at( *set_i.begin() );

	for( auto it = adj.begin(); it != adj.end(); it++ )
	{
		if( first_set.find( *it ) == first_set.end() )
		{
			return true;
		}
	}

	return false;
}

void	join_sets( std::set<int> adj, std::vector< std::set<int> >& sets )
{
	std::set<int> set_i = sets_containing( adj, sets );

	std::cout << "join sets" << std::endl;
	std::cout << "set_i.size()=" << set_i.size() << std::endl;

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
		
		std::cout << "sets.size()=" << sets.size() << std::endl;
		sets.erase(next_set);
		std::cout << "sets.size()=" << sets.size() << std::endl;
		
		it++;
	}

	std::cout << "join sets exit" << std::endl;
}

void jess::maze::base::print_maze( std::vector<bool> m )
{
	std::vector<int> v( 2, 0 );
	for( int x = 0; x < desc_.size_[0]; x++ )
	{
		for( int y = 0; y < desc_.size_[1]; y++ )
		{
			v.at(0) = x;
			v.at(1) = y;
			std::cout << m.at( desc_.comp_to_flat( v ) );
		}
		std::cout << std::endl;
	}

}	








