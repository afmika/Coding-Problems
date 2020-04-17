/**
 * I used a few math tricks to solve this problem in O (log2 (N))
 * I am a little bit proud since it doesn t matter what the output is
 * this little boy will find the solution.
 */
 
int kthGrammar(int N, int K){
	if(K == 1)
		return 0;
	/**
	* how does it work ?
	* if (N, K) = (N-1, ceil( K / 2) )
	* then (N, K) = (N-2, ceil( ceil( K / 2) /2 ) )
	*      ... ... ...
	* which is equal to
	* ... = (1, ceil( .... ceil(K /2) /2 ... /2 ))
	*/	
	
	// ex : the K-th node will produce the 2*K-th node in the next generation
	// this little trick will help us to determine which direction to take
	K = 2 * K;
    int cur_state[2] = {0, 1};
	while( K > 1 ) {
		K = (K / 2) + K % 2; //  K = ceil( K / 2)
        if( cur_state[ (K+1) % 2 ] == 1 ) {
            cur_state[0] = 1;
            cur_state[1] = 0;
        } else {
            cur_state[0] = 0;
            cur_state[1] = 1;           
        }
	}
	// K = 1 ->(2*K - 1, 2*K) = '1 0'
	// K = 0 ->(2*K - 1, 2*K) = '0 1'
	// the first index will never change in the 2*K-th generation
	return cur_state[ 0 ];
}

