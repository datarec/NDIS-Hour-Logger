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
  fclose(clientFileCreation);
}


void sleep(int t) {
  Sleep(t);
}


void clearScreen() {
  system("cls");
}


void deleteClient(char *clientName) {
  FILE* clients;
  clientName[strcspn(clientName, "\n")] = 0;
  char pathConcat[50];
  int clientPath = snprintf(pathConcat, 50, "clients\\%s.txt", clientName);
  printf("\nREMOVE PATH");
  remove(pathConcat);
  clients = fopen("clients.txt", "r");
  char clientFileContent[50];
  int counter = 0;
  while (fgets(clientFileContent, 50, clients)) {
    clientFileContent[strcspn(clientFileContent, "\n")] = 0;
    //printf("\n%s : %s", clientName, clientFileContent); // DEBUG
    int clientComparison = strcmp(clientName, clientFileContent);
    //printf("\n%d", clientComparison); // DEBUG
    counter++;
    if (clientComparison != 0) {
      FILE* reWriteContents;
      reWriteContents = fopen("clients.txt", "w");
      fprintf(reWriteContents, clientFileContent);  
      printf("\nClient deleted!");
    }
  }
  if (counter == 1) {
    FILE* removeContent;
    removeContent = fopen("clients.txt", "w");
    printf("\n\tClient deleted");
    fclose(clients);
    fclose(removeContent);
  }
}


void viewClientHours(char clientName[]) {
  clientName[strcspn(clientName, "\n")] = 0;
  clearScreen();
  FILE* clientHourRead;
  printf("----------------------------------------------------");
  printf("\n\n\t\tView client: %s hours", clientName);
  char clientBuffer[50];
  int clientPath = snprintf(clientBuffer, 50, "clients\\%s.txt", clientName);
  clientHourRead = fopen(clientBuffer, "r");
  char clientHourBuffer[50];
  while (fgets(clientHourBuffer, 50, clientHourRead)) {
    printf("\n\n\n\tHours: %s", clientHourBuffer);
    sleep(2000);
  }
}


void clockClientHours(char *clientName, int selection) {
  clientName[strcspn(clientName, "\n")] = 0;
  FILE* hoursRead;
  FILE* hoursWrite;
  clearScreen();
  float hoursWorked; 
  printf("----------------------------------------------------");
  printf("\n\n\t\tClock hours for: %s\n\n", clientName);
  printf("\n\tHours worked: ");
  scanf("%f", &hoursWorked);
  char hourPath[100];
  int hourPathTmp = snprintf(hourPath, 100, "clients\\%s.txt", clientName);
  hoursRead = fopen(hourPath, "r");
  char hourContent[50];
  while (fgets(hourContent, 50, hoursRead)) {
    hoursWrite = fopen(hourPath, "w");
    float hourConvert = atof(hourContent);
    float hoursAllTogether = hourConvert + hoursWorked;
    fprintf(hoursWrite, "%.2f", hoursAllTogether);
    printf("\n\n\thours clocked!");
  }
  fclose(hoursRead);
  fclose(hoursWrite);
  sleep(2500);
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
  printf("\n\n\t1) clock hours\n");
  printf("\t2) view hours\n");
  printf("\t3) delete client\n");
  printf("\t4) main menu");
  printf("\n\n\n\toption: ");
  scanf("%d", &selectionOptions);
  fclose(client);
  switch (selectionOptions) {
    case 1:
      clockClientHours(clientName, selection); 
    case 2:
      viewClientHours(clientName);
    case 3:
      deleteClient(clientName);
    case 4:
      printf("\nHi");
    default: 
      exit(1);
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
    count++;
  }
  printf("\n\n\tclient: ");
  scanf("%d", &selection);
  fclose(readClientFile);
  manageClientHours(selection);
}


void checkClientExists(char *client) {
  FILE* clientFile;
  clientFile = fopen("clients.txt", "r");
  char nameCheck[50];
  while (fgets(nameCheck, 50, clientFile)) {
    nameCheck[strcspn(nameCheck, "\n")] = 0;
    int nameCheckInt = strcmp(client, nameCheck);
    if (nameCheckInt == 0) {
      printf("\n\n\tThis client already exists.");
      sleep(4000);
      exit(1);
    }
  }
}


void addClient() {
  FILE* add;
  clearScreen();
  printf("----------------------------------------------------");
  printf("\n\n\t\tAdd Client");
  char client[20];
  printf("\n\n\n\tclient name: ");
  scanf("%s", &client);
  checkClientExists(client); 
  add = fopen("clients.txt", "a");
  fprintf(add, "%s\n", client);
  makeFiles(client);
  printf("\n\n\tclient added!\n\n\t");
  sleep(2000);
  fclose(add);
  exit(1);
}


int main() {
  clearScreen();
  int selection;
  printf("----------------------------------------------------");
  printf("\n\n\t\tNDIS Logging System");
  printf("\n\n\n\t1) add client");
  printf("\n\t2) view clients | Clock hours");
  printf("\n\t3) exit");
  printf("\n\n\n\tmain: ");
  scanf("%d", &selection);
  switch (selection) {
    case 1:
      addClient();
    case 2:
      viewClients();
    case 3:
      exit(1);
    default:
      exit(1);
  }
}
