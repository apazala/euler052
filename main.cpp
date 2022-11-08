#include <stdio.h>

int digitsignature(int v){
	int digits[10] = { 0 };
	int d;
	while (v > 9) {
		d = v % 10;
		digits[d]++;
		v /= 10;
	}
	digits[v]++;

	int sig = 0;
	for (int i = 9; i >= 0; i--) {
		d = digits[i];
		while (d-- > 0) {
			sig = 10 * sig + i;
		}
	}

	return sig;
}

int main()
{
    int found = 0;
    int i;
    for(i = 9; !found ; i+=9){
        int signature = digitsignature(i);
        found = 1;
        for(int j = 6*i; found && j>i; j-=i){
            found = (digitsignature(j) == signature);
        }
    }
    i--;
    for(int j = i, k = 0; k < 6; k++, j+=i){
        printf("%d ", j);
    }
    printf("\n");

}