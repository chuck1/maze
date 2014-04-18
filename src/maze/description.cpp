#include <iostream>

#include <galaxy/maze/description.hpp>

jess::maze::description::description( int x, int y )
{
	size_ = new int[2];
	size_[0] = x;
	size_[1] = y;
	c_ = 2;

	N_ = x*y;
}

bool	jess::maze::description::check()
{
	if ( !( ( c_ == 2 ) || ( c_ == 3 ) ) )
	{
		return 0;
	}

	return 1;
}
int	jess::maze::description::comp_to_flat( std::vector<int> v )
{
	int i = 0;
	int size = 1;
	for( int c = 0; c < c_; c++ )
	{
		i += v.at(c) * size;

		size *= size_[c];
	}

	if ( i > N_ )
	{
		//throw jess::except("out of range");
	}

	return i;
}
std::vector<int>	jess::maze::description::flat_to_comp( int i )
{
	std::vector<int> ret( c_, 0 );

	int a = i;

	ret.at(0) = a % size_[0];

	for( int d = 1; d < c_; d++ )
	{
		a = ( a - ret.at(d-1) ) / size_[d-1];

		ret.at(d) = a % size_[d];
	}

	return ret;
}
std::vector<int>	jess::maze::description::adjacent_to( int i )
{
	//std::cout << "adjacent_to" << std::endl;

	std::vector<int> ret;
	
	int a = 0;
	
	std::vector<int> v = flat_to_comp( i );

	for( int c = 0; c < c_; c++ )
	{	
		v.at(c)++;
		if ( v.at(c) < size_[c] )
		{
			a = comp_to_flat( v );
			//std::cout << "\t" << a << std::endl;
			
			ret.push_back( a );
		}
		v.at(c)-=2;
		if ( v.at(c) >= 0 )
		{
			a = comp_to_flat( v );
			//std::cout << "\t" << a << std::endl;
			
			ret.push_back( a );
		}
		v.at(c)++;
	}
	
	//std::cout << "adjacent_to" << std::endl;
	return ret;
}


