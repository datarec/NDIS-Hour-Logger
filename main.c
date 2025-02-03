// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void sleep(int t) {
  Sleep(t);
}


void clearScreen() {
  system("cls");
}


void callScript() {
  system("main");
}

void viewClients() {
  int count = 1;
  FILE* readClientFile;
  clearScreen();
  printf("----------------------------------------------------");
  printf("\n\n\t\tView clients | Clock hours");
  readClientFile = fopen("clients.txt", "r");
  char clients[100];
  while (fgets(clients, 100, readClientFile)) {
    printf("\n\n\t%d) %s", count, clients);
    count = count + 1;
  }
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
  printf("\n\t2) View clients | Clock hours");
  printf("\n\t3) Exit");
  printf("\n\n\n\tSelection: ");
  scanf("%d", &selection);
  if (selection == 1) {
    addClient();
  }
  else if (selection == 2) {
    viewClients();
  }
  return 0;
}
