// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


void makeFiles(char cname[]) {
  FILE* clientFileCreation; 
  clientFileCreation = fopen("clienthours.txt", "a");
  fprintf(clientFileCreation, "0");
}


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
  int selection;
  int count = 1;
  FILE* readClientFile;
  clearScreen();
  printf("----------------------------------------------------");
  printf("\n\n\t\tView clients | Clock hours\n\n\n");
  readClientFile = fopen("clients.txt", "r");
  char clients[100];
  while (fgets(clients, 100, readClientFile)) {
    printf("\t%d) %s", count, clients);
    count = count + 1;
  }
  printf("\n\n\n\tSelection: ");
  scanf("%d", selection);
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
  makeFiles(client);
  printf("\n\n\tClient added!\n\n\t");
  sleep(2000);
  fclose(add);
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
  switch (selection) {
    case 1:
      addClient();
    case 2:
      viewClients();
    case 3:
      exit(1);
  }
}
