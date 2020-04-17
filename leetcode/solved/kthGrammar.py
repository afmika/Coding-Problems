import math

class Solution(object):
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        if K == 1 :
            return '0'
        
        map = { '0' : '01', '1' : '10' }
        
        K = 2 * K
        cur_state = '01'
        
        while K > 1 :
            K = (K // 2) + K % 2; #  K = Math.ceil( K / 2)
            cur_state = map[ cur_state[  (K+1) % 2 ] ] # index child -> ... -> index root
        
        # K = 1 ->(2*K - 1, 2*K) = '1 0'
        # K = 0 ->(2*K - 1, 2*K) = '0 1'
        # the first index will never change at the 2*K-th generation
        return cur_state[ 0 ]