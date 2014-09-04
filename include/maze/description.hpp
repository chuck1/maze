#ifndef __JESS_MAZE_DESCRIPTION_HPP__
#define __JESS_MAZE_DESCRIPTION_HPP__

#include <vector>
#include <set>

#include <maze/typedef.hpp>

/*struct ivec2 {
  ivec2(int nx, int ny): x(nx), y(ny) {}
  ivec2		operator+(ivec2 const & rhs) const {
  return ivec2(x + rhs.x, y + rhs.y);
  }
  bool		operator<(ivec2 const & rhs) const {
  if(x == rhs.x) return (y < rhs.y);
  return (x < rhs.x);
  }
  int x,y;
  };*/
template<int D> int	prod(typename maze::traits<D>::ivec v) {
	int p = 1;
	for(int d = 0; d < D; d++) {
		p *= v[d];
	}
	return p;
}
template<int D> int	offset(typename maze::traits<D>::ivec index, typename maze::traits<D>::ivec size) {

	int block_size = prod<D>(size);

	int i = 0;
	
	for(int d = D-1; d >= 0; d--)
	{
		block_size /= size[d];

		i += block_size * index[D-d-1];
	}
	return i;
}
template<int D> typename maze::traits<D>::ivec		vector(int i, typename maze::traits<D>::ivec size) {

	int block_size = prod<D>(size);

	typename maze::traits<D>::ivec index;
	
	for(int d = D-1; d >= 0; d--)
	{
		block_size /= size[d];
		
		index[D-d-1] = (i - (i % block_size)) / block_size;
		
		i -= block_size * index[D-d-1];
	}
	return index;
}


namespace maze {


	template<int D> struct description {

		typedef typename traits<D>::ivec	ivec;
		typedef typename traits<D>::vec		vec;

		description();

		description(ivec size):
			size_(size)
		{
		}
		set_type<D>		adjacent_to(ivec i) {

			//std::cout << "adjacent_to" << std::endl;

			set_type<D> ret;

			for(int d = 0; d < D; d++)
			{
				ivec p(0);
				ivec n(0);

				p[d] = 1;
				n[d] = -1;

				if(i[d] < (size_[d] - 1))	ret.insert(i + p);
				if(i[d] > 0)			ret.insert(i + n);
			}

			return ret;
		}
	
		ivec			size_;

	};
}

#endif
