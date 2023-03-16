#include <stdio.h>
#include <stdlib.h>

int main() {

  int v[10] = {0,0,0,0,0,0,0,0,0,0}, num, e = 0;

  scanf("%i", &num);

  for (v[9] = 0; v[9] <= 4; v[9]++) {
  	for (v[8] = 0; v[8] <= 4; v[8]++) {
      for (v[7] = 0; v[7] <= 4; v[7]++) {
        for (v[6] = 0; v[6] <= 4; v[6]++) {
          for (v[5] = 0; v[5] <= 4; v[5]++) {
            for (v[4] = 0; v[4] <= 4; v[4]++) {
              for (v[3] = 0; v[3] <= 4; v[3]++) {
           			for (v[2] = 0; v[2] <= 4; v[2]++) {
               		for (v[1] = 0; v[1] <= 4; v[1]++) {
              			for (v[0] = 0; v[0] <= 4; v[0]++) {
                      e = v[0] * 1 + v[1] * 2 + v[2] * 3 + v[3] * 4 + v[4] * 5 +
                          v[5] * 6 + v[6] * 7 + v[7] * 8 + v[8] * 9 + v[9] * 10;
											
                      if (e == num) {
                        printf("%i %i %i %i %i %i %i %i %i %i\n", v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9]);
                      }
                    }
                  }
                }
              }
            }
          }
        }
    	}
    }
  }

  return (EXIT_SUCCESS);
}
