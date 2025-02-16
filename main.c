// NDIS System used to track hours worked for clients. 
// ovh.feminine216@passinbox.com


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


int clientExists = 0;
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
  remove(pathConcat);
  clients = fopen("clients.txt", "r");
  char clientFileContent[50];
  int counter = 0;
  while (fgets(clientFileContent, 50, clients)) {
    clientFileContent[strcspn(clientFileContent, "\n")] = 0;
    int clientComparison = strcmp(clientName, clientFileContent);
    counter++;
    if (clientComparison != 0) {
      FILE* reWriteContents;
      reWriteContents = fopen("clients.txt", "w");
      fprintf(reWriteContents, clientFileContent);  
      printf("\n[!] client deleted!");
      fclose(reWriteContents);
      fclose(clients);
      sleep(2000);
      return;
    }
  }
  if (counter == 1) {
    FILE* removeContent;
    removeContent = fopen("clients.txt", "w");
    printf("\n    [!] client deleted!");
    fclose(clients);
    fclose(removeContent);
    sleep(2000);
    return;
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
    printf("\n\n\n\thours: %s", clientHourBuffer);
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
  printf("\n\thours worked: ");
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
    printf("\n\n    [!] hours clocked!");
  }
  fclose(hoursRead);
  fclose(hoursWrite);
  sleep(2000);
  return;
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
  if (selectionOptions == 1) {
    clockClientHours(clientName, selection);
    manageClientHours(selection);
  }
  else if (selectionOptions == 2) {
    viewClientHours(clientName);
  }
  else if (selectionOptions == 3) {
    deleteClient(clientName);
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
  int checkPreExistingUsers = strlen(clients);
  if (checkPreExistingUsers < 2) {
    fclose(readClientFile);
    printf("\n    [!] you have no clients, add some.");
    sleep(2000);
    return;
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
      printf("\n\n    [!] this client already exists.");
      sleep(2000);
      clientExists = 1;
      return; 
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
  if (clientExists == 1) {
    return;
  }
  else if (clientExists == 0) {
    add = fopen("clients.txt", "a");
    fprintf(add, "%s\n", client);
    makeFiles(client);
    printf("\n\n    [!] client added!\n\n\t");
    sleep(2000);
    fclose(add);
  }
}


int main() {
  clearScreen();
  int selection;
  printf("----------------------------------------------------");
  printf("\n\n\t\tNDIS Logging System");
  printf("\n\n\n\t1) add client");
  printf("\n\t2) view clients | clock hours");
  printf("\n\t3) exit");
  printf("\n\n\n\tmain: ");
  scanf("%d", &selection);
  if (selection == 1) {
    addClient();
    main();
  }
  else if (selection == 2) {
    viewClients();
    main();
  }
  else if (selection == 3) {
    printf("\n\tgoodbye!");
    sleep(1000);
    exit(1);
  }
}
