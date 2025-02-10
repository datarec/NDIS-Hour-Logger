// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


void makeFiles(char cname[]) {
  FILE* clientFileCreation;
  char clientBuffer[50];
  int concatFile = snprintf(clientBuffer, 50, "clients\\%s.txt", cname);
  clientFileCreation = fopen(clientBuffer, "a");
  fprintf(clientFileCreation, "0\n");
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


void clockClientHours(char *clientName, int selection) {
  clearScreen();
  float hoursWorked; 
  printf("----------------------------------------------------");
  printf("\n\n\t\tClock hours for: %s\n\n", clientName);
  printf("\tHours worked: ");
  scanf("%f", &hoursWorked);
}


void manageClientHours(int selection) {
  FILE* client;
  int selectionOptions;
  int findName = 0;
  clearScreen();
  printf("----------------------------------------------------");
  client = fopen("clients.txt", "r");
  char clientName[20]; 
  while (fgets(clientName, 20, client)) {
    findName++;
    if (findName == selection) {
      break;
    }
  }
  printf("\n\n\t\tClient: %s", clientName);
  printf("\n\n\t1) Clock hours\n");
  printf("\t2) View hours\n");
  printf("\t3) Delete client\n");
  printf("\t4) Exit");
  printf("\n\n\n\tOption: ");
  scanf("%d", &selectionOptions);
  switch (selectionOptions) {
    case 1:
      clockClientHours(clientName, selection);
      
  }
  fclose(client);
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
  printf("\n\n\tClient: ");
  scanf("%d", &selection);
  fclose(readClientFile);
  manageClientHours(selection);
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
  printf("\n\n\n\tMain: ");
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
