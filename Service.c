
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI.h"
#include "Service.h"
#include "PhoneBook.h"

UInput *MainLogic()
{
    UInput *newInput = (UInput *)malloc(sizeof(UInput));
    PhoneBook *pb = CreatePhoneBook();

    int idx;
    char pName[DATA_SIZE];
    char pPhone[DATA_SIZE];

    
    InitInput(newInput);

    UserInput(newInput, PRINT_MENU);

    while (Display(newInput))
    {
        UserInput(newInput, SELECT_MENU);
        system("clear");
        switch (newInput->userSelect)
        {
        case 0:
            
            printf("Index? \n");
            UserInput(newInput, INT_INPUT);
            idx = newInput->nData;

            printf("Name? \n");
            UserInput(newInput, DATA_INPUT);
            strcpy(pName, newInput->szData);

            printf("Phone? \n");
            UserInput(newInput, DATA_INPUT);
            strcpy(pPhone, newInput->szData);

            AddToPhoneBook(pb, idx, pName, pPhone);

            newInput->control = DATA_INPUT;
            break;

        case 1:
            ListPhoneBook(pb);
            newInput->control = PRINT_MENU;
            break;

        case 2:
            printf("Index of a data to be deleted? \n");
            UserInput(newInput, INT_INPUT);
            idx = newInput->nData;
            DeleteByIDX(pb, idx);
            newInput->control = PRINT_MENU;
            break;

        case 3:
            printf("Name of a person to be deleted? \n");
            UserInput(newInput, DATA_INPUT);
            //strcpy(pName,newInput->szData);
            DeleteByNAME(pb, newInput->szData);
            newInput->control = PRINT_MENU;
            break;

        case 4:
            printf("Name of a person to be updated? \n");
            UserInput(newInput, DATA_INPUT);
            LData updated;

            updated = UpdateByNAME(pb, newInput->szData);
            printf("New Phone number\n");
            UserInput(newInput, DATA_INPUT);
            strcpy(updated->szPhone ,newInput->szData);
            newInput->control = PRINT_MENU;
            break;

        case -1:
            newInput->flag = FALSE;
        }
    }

    return newInput;
}
