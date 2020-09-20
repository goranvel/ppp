#include <iostream>

namespace myDS { // DS stands for data structure
	class vector {
			int size;
			double *elem;
		public:
			vector (int v_size);

			int size () const {
				return size;
			}
	}
}
