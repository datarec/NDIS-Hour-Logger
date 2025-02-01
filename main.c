// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
  system("cls");
}


void addClient() {
  clearScreen();
  printf("----------------------------------------------------");
  printf("\n\n\t\tAdd Client");
  FILE* add;
  char client[] = "";
  printf("\n\nClient name: ");
  add = fopen("clients.txt", "a");
  scanf("%s", client);
}


int main() {
  clearScreen();
  int selection;
  printf("----------------------------------------------------");
  printf("\n\n\t\tNDIS Logging System");
  printf("\n\n\n\t1) Add client");
  printf("\n\t2) View clients");
  printf("\n\t3) Exit");
  printf("\n\n\n\tSelection: ");
  scanf("%d", &selection);
  printf("%d", selection);
  if (selection == 1) {
    addClient();
  }
  return 0;
}
