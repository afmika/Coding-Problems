#include <string.h>
bool checkRecord(char * s){
	int a_count = 0;
	int l_continuous = 0;
	for(size_t i = 0; i < strlen(s); i++) {
		if(s[i] == 'L') {
			l_continuous++;
			if(l_continuous >= 3)
				return false;
		} else {
			l_continuous = 0;
		}
		if(s[i] == 'A')
			a_count++;
	}
	return a_count <= 1;
}