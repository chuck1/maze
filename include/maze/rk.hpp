#include <maze/base.hpp>

namespace jess
{
	namespace maze
	{
		class rk2:
			public jess::maze::base2
		{
			public:
				rk2(jess::maze::description2);
				void	run();
		};
	}
}
