#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char Name[50];
    char From[50];
    char To[50];
    char TicketNumber[20];
    char BookingDate[20];
    char Class[20];
    char status[20];
}Passenger_t;


typedef struct
{
    char FlightNo[50];
    char DepTime[10];
    char ArrTime[10];
    char DepPlace[50];
    char ArrPlace[50];
}FlightInfo_t;


Passenger_t p[100]; //global declaration
FlightInfo_t f[10]; //global declaration


void WelcomePrint();
void EndingPrint();
void FlightInfoEntry(char PlaneInfo[1000][20],int countFInfo);
void PassInfoEntry(char PassInfo[1000][20],int countPInfo);
void ShowFlightInfo();


int main()
{
    char option,choose,c,approved,cont;

    int i, count=1 , countInfo=0 , j , compareDepString , compareArrString, compareName;

    char words[20];
    char name[20];
    char from[20];
    char to[20];
    char InfoList[1000][20];
    char temp1[20],temp2[20];

    FILE *writePassInfo;
    FILE *readPassInfo;
    FILE *flightInfo;
    FILE *PassStatus;

    flightInfo = fopen("Flights.txt","r");

    for(i=0; fgets(words,sizeof(words),flightInfo) != NULL; i++)
    {
        strcpy(InfoList[i],words);
        countInfo++;
    }

    fclose(flightInfo);

    FlightInfoEntry(InfoList,countInfo);

    while(1)
    {
        WelcomePrint(); //printing from welcome.txt file

        printf("* For Ticket Booking           -> Press '1'\n");
        printf("* For official Activity        -> Press '2'\n");
        printf("* To Check the Ticket Approval -> Press '3'\n");
        printf("* To Exit                      -> Press '4'\n");
        printf("\n");


        printf("<< Please Enter Valid Option key >>\n");
        scanf("%c",&choose);

        system("cls");

        if(choose == '1')
        {
            printf("<< Welcome To The TICKET BOOKING Portion >>\n");

            writePassInfo = fopen("Passengers.txt","a");
            PassStatus = fopen("CheckPassStatus.txt","a");

            countInfo = 0;

            for(i=0; (c = getchar())!=EOF;  i++)
            {
                printf("<< Enter Your Name >>\n");
                gets(p[i].Name);
                fputs("Name              :: ",writePassInfo);
                fputs(p[i].Name,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].Name,PassStatus);
                fputs("\n",PassStatus);

                printf("<< Enter Your Departure place >>\n");
                gets(p[i].From);
                fputs("Departure Place   :: ",writePassInfo);
                fputs(p[i].From,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].From,PassStatus);
                fputs("\n",PassStatus);

                printf("<< Enter Your Destination place >>\n");
                gets(p[i].To);
                fputs("Destination Place :: ",writePassInfo);
                fputs(p[i].To,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].To,PassStatus);
                fputs("\n",PassStatus);

                printf("* For First Class Ticket    -> type 'first'\n");
                printf("* For Business Class Ticket -> type 'business'\n");
                printf("* For Economy Class Ticket  -> type 'economy'\n");

                gets(p[i].Class);
                fputs("Class             :: ",writePassInfo);
                fputs(p[i].Class,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].Class,PassStatus);
                fputs("\n",PassStatus);

                printf("<< Enter Your Booking Date >>\n");
                gets(p[i].BookingDate);
                fputs("Booking Date      :: ",writePassInfo);
                fputs(p[i].BookingDate,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].BookingDate,PassStatus);
                fputs("\n",PassStatus);

                printf("<< Enter Total Ticket Number >>\n");
                gets(p[i].TicketNumber);
                fputs("Total Ticket      :: ",writePassInfo);
                fputs(p[i].TicketNumber,writePassInfo);
                fputs("\n",writePassInfo);
                fputs(p[i].TicketNumber,PassStatus);
                fputs("\n",PassStatus);

                fputs("--------------------------------\n\n",writePassInfo);

                strcpy(p[i].status,"pending");
                fputs(p[i].status,PassStatus);

                printf("<< FOLLOWING FLIGHTS ARE AVAIABLE >>\n");

                for(j=0;j<10;j++)
                {
                    strcpy(temp1,f[j].DepPlace);
                    strcpy(temp2,p[i].From);
                    strcpy(from,p[i].From);
                    strcat(temp2,"\n");
                    compareDepString = strcmp(temp1,temp2);

                    strcpy(temp1,f[j].ArrPlace);
                    strcpy(temp2,p[i].To);
                    strcpy(to,p[i].To);
                    strcat(temp2,"\n");
                    compareArrString = strcmp(temp1,temp2);


                    if(compareDepString == 0 && compareArrString == 0)
                    {
                        printf(" * Flight No.      -> %s",f[j].FlightNo);
                        printf(" * Departure Place -> %s",f[j].DepPlace);
                        printf(" * Arrival Place   -> %s",f[j].ArrPlace);
                        printf(" * Departure Time  -> %s",f[j].DepTime);
                        printf(" * Arrival Time    -> %s",f[j].ArrTime);
                        printf("--------------------------\n");
                        break;
                    }
                }

                printf("<< Do You Want to Book Again , (Type n->no or y->yes) >>\n");
                scanf("%c",&choose);

                if(choose == 'n')
                    break;
                else
                {
                    count++;
                    system("cls");
                }
            }

            fclose(writePassInfo);
            fclose(PassStatus);

            readPassInfo = fopen("CheckPassStatus.txt","r");

            for(i=0; fgets(words,sizeof(words),readPassInfo) != NULL; i++)
            {
                strcpy(InfoList[i],words);
                countInfo++;
            }

            fclose(readPassInfo);

            PassInfoEntry(InfoList,countInfo);
        }

        else if(choose == '2')
        {
            printf("<< Welcome To The official Activity Portion >>\n\n");

            printf("* To Know About Flight Information   -> Press '1'\n");
            printf("* To Approve the Ticket Request      -> Press '2'\n");
            printf("\n");

            printf("<< Please Enter Valid Option key >>\n");
            scanf("%c",&option);
            scanf("%c",&option);

            countInfo = 0;
            readPassInfo = fopen("CheckPassStatus.txt","r");

            for(i=0; fgets(words,sizeof(words),readPassInfo) != NULL; i++)
            {
                strcpy(InfoList[i],words);
                countInfo++;
            }

            fclose(readPassInfo);
            PassInfoEntry(InfoList,countInfo);

            if(option == '1')
            {
                ShowFlightInfo();
                printf("<< Press y to continue  >>\n");
                scanf("%c",&cont);
            }
            else if(option == '2')
            {
                printf("<< Passengers requested for the tickets = %d >>\n",(countInfo/7));

                i=0;
                while((c=getchar() != EOF))
                {
                    printf("* Name          -> %s",p[i].Name);
                    printf("* Departure     -> %s",p[i].From);
                    printf("* Destination   -> %s",p[i].To);
                    printf("* Booking Date  -> %s",p[i].BookingDate);
                    printf("* Class         -> %s",p[i].Class);
                    printf("* Ticket Number -> %s",p[i].TicketNumber);
                    printf("* Current Status-> %s",p[i].status);
                    printf("\n");

                    printf("<< Do you want to approve the ticket for %s >>\n",p[i].Name);
                    printf("<< Press 'y' or 'n >>\n");
                    scanf("%c",&approved);

                    if(approved == 'y')
                    {
                        strcpy(p[i].status,"Approved\n");
                    }

                    i++;
                    if(i==(countInfo/7))
                        break;

                }

                printf("<< Press y to continue  >>\n");
                scanf("%c",&cont);
            }

            readPassInfo = fopen("CheckPassStatus.txt","w");

            for(i=0;i<countInfo;i++)
            {
                //printf("%s",p[i].Name);
                fputs(p[i].Name,readPassInfo);
                //printf("%s",p[i].From);
                fputs(p[i].From,readPassInfo);
                //printf("%s",p[i].To);
                fputs(p[i].To,readPassInfo);
                //printf("%s",p[i].BookingDate);
                fputs(p[i].BookingDate,readPassInfo);
                //printf("%s",p[i].Class);
                fputs(p[i].Class,readPassInfo);
                //printf("%s",p[i].TicketNumber);
                fputs(p[i].TicketNumber,readPassInfo);
                //printf("%s",p[i].status);
                fputs(p[i].status,readPassInfo);
            }

            fclose(readPassInfo);
        }

        else if(choose == '3')
        {
            printf("<< You want to check your ticket approval >>\n\n");
            printf("\n");

            countInfo = 0;
            readPassInfo = fopen("CheckPassStatus.txt","r");

            for(i=0; fgets(words,sizeof(words),readPassInfo) != NULL; i++)
            {
                strcpy(InfoList[i],words);
                countInfo++;
            }
            fclose(readPassInfo);
            PassInfoEntry(InfoList,countInfo);

            printf("-------------------------------\n");
            for(i=0;i<(countInfo/7);i++)
            {
                    printf("* Name          -> %s",p[i].Name);
                    printf("* Departure     -> %s",p[i].From);
                    printf("* Destination   -> %s",p[i].To);
                    printf("* Booking Date  -> %s",p[i].BookingDate);
                    printf("* Class         -> %s",p[i].Class);
                    printf("* Current Status-> %s",p[i].status);
                    printf("\n");
            }
            printf("-------------------------------\n\n");

            printf("<< Press y to continue  >>\n");
            scanf("%c",&cont);
        }

        else if(choose == '4')
        {
            printf("<< You Have Choose Exit Option >>\n");
            break;
        }

        else
        {
            printf("\n<< You Have entered Invalid Option key >>\n\n");
            printf("<< Please Try Again >>\n\n");
            continue;
        }
    }

    EndingPrint(); // printing from Thanks.txt file

    return 0;
}

void WelcomePrint()
{
    FILE *welcometxt;
    welcometxt = fopen("welcome.txt","r");
    char WelcomeChar;

    while((WelcomeChar = fgetc(welcometxt)) != EOF)
    {
        printf("%c",WelcomeChar);
    }
    printf("\n");
    printf("\n");
}

void EndingPrint()
{
    FILE *Endingtxt;
    Endingtxt = fopen("Thanks.txt","r");
    char EndChar;

    while((EndChar = fgetc(Endingtxt)) != EOF)
    {
        printf("%c",EndChar);
    }
    printf("\n");
    printf("\n");
}

void FlightInfoEntry(char PlaneInfo[1000][20],int countFInfo)
{
    int i,j;

    j=0;
    for(i=0;i<countFInfo;i=i+5)
    {
        //printf("%d %s",i,PlaneInfo[i]);
        strcpy(f[j].FlightNo,PlaneInfo[i]);
        j++;
    }

    j=0;
    for(i=1;i<countFInfo;i=i+5)
    {
        //printf("%d %s",i,PlaneInfo[i]);
        strcpy(f[j].DepTime,PlaneInfo[i]);
        j++;
    }

    j=0;
    for(i=2;i<countFInfo;i=i+5)
    {
        //printf("%d %s",i,PlaneInfo[i]);
        strcpy(f[j].ArrTime,PlaneInfo[i]);
        j++;
    }

    j=0;
    for(i=3;i<countFInfo;i=i+5)
    {
        //printf("%d %s",i,PlaneInfo[i]);
        strcpy(f[j].DepPlace,PlaneInfo[i]);
        j++;
    }


    j=0;
    for(i=4;i<countFInfo;i=i+5)
    {
        //printf("%d %s",i,PlaneInfo[i]);
        strcpy(f[j].ArrPlace,PlaneInfo[i]);
        j++;
    }
}

void PassInfoEntry(char PassInfo[1000][20],int countPInfo)
{
    int i,j;

    j=0;
    for(i=0;i<countPInfo;i=i+7)
    {
        strcpy(p[j].Name,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=1;i<countPInfo;i=i+7)
    {
        strcpy(p[j].From,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=2;i<countPInfo;i=i+7)
    {
        strcpy(p[j].To,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=3;i<countPInfo;i=i+7)
    {
        strcpy(p[j].Class,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=4;i<countPInfo;i=i+7)
    {
        strcpy(p[j].BookingDate,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=5;i<countPInfo;i=i+7)
    {
        strcpy(p[j].TicketNumber,PassInfo[i]);
       // printf("%s",PassInfo[i]);
        j++;
    }

    j=0;
    for(i=6;i<countPInfo;i=i+7)
    {
        strcpy(p[j].status,PassInfo[i]);
        //printf("%s",PassInfo[i]);
        j++;
    }

}

void ShowFlightInfo()
{
    FILE *printInfo;
    printInfo = fopen("FlightInfoShow.txt","r");
    char infoChar;

    while((infoChar = fgetc(printInfo)) != EOF)
    {
        printf("%c",infoChar);
    }
    printf("\n");
    printf("\n");
}
