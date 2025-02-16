#include <stdio.h>


int main() {
  char hex[15] = "123456789ABCDEF";
  char rawConversion[20] = "";
  char decToHex[20] = "";
  int nVal = 20;
  int hexLength = 0; 
  while (nVal != 0) {
    int nd = nVal / 16;
    int nq = nVal % 16;
    rawConversion[hexLength] = hex[nq - 1];
    hexLength++;
    nVal = nd;
  }
  int iterFinal = hexLength;
  int addElements = 0;
  while (hexLength != 0) {
    decToHex[addElements] = rawConversion[hexLength - 1];
    printf("%c", decToHex[addElements]);
    hexLength--;
    addElements++;
  }
}
