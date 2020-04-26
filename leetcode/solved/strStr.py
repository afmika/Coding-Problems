class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        for k in range(0, len(haystack)) :
            if haystack[k] == needle[0] and (k + len(needle) - 1) < len(haystack):
                pass_count = 1
                for q in range(1, len(needle)):
                    if haystack[k + q] == needle[q] :
                        pass_count = pass_count + 1
                if pass_count == len(needle) :
                    return k
        return -1