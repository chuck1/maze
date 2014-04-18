#include <jess/maze/base.hpp>

namespace jess
{
	namespace maze
	{
		class rk:
			public jess::maze::base
		{
			public:
				rk( jess::maze::description );
				void	run();
		};
	}
}
