// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void sleep(int a) {
  Sleep(a);
}


void clearScreen() {
  system("cls");
}


void callScript() {
  system("main");
}


void addClient() {
  FILE* add;
  clearScreen();
  printf("----------------------------------------------------");
  printf("\n\n\t\tAdd Client");
  char client[20];
  printf("\n\n\n\tClient name: ");
  scanf("%s", &client);
  add = fopen("clients.txt", "a");
  fprintf(add, "%s\n", client);
  fclose(add);
  printf("\n\n\tClient added!\n\n\t");
  sleep(2000);
  callScript();
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
  if (selection == 1) {
    addClient();
  }
  return 0;
}
