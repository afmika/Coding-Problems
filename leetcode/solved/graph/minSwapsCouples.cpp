class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
		int n_count = 0;
		size_t start_index = 1;
		size_t length = row.size();
		while( true ) {
			bool done = true;
			for(size_t i = start_index; i < length; i++) {
				const int pair = row[ i - 1 ] 
                    + ( row[ i - 1 ] % 2 ?  -1 : 1  );
				if( pair != row[i] ) {
					for(size_t k = 0; k < length; k++ ) {
						if( row[ k ] == pair ) {
							const int temp = row[ k ];
							row[ k ] = row[ i ];
							row[ i ] = temp;
							break;
						}
					}
					start_index = i;
					n_count++;
					done = false;
					break;
				} else {
					i++;
				}
			}
			if ( done ) 
				break;
		}
		return n_count;
    }
};