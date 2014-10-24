/* 
 * 参考链接：
 * https://github.com/mofaph/csapp/blob/master/exercise/ex3-57.c
 */	

int cread_alt(int *xp) {
	int t = 0;

	return *(xp ? xp : &t);
}
