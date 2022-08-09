#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI.h"

int Display(UInput *input)
{
    if (input->flag)
    {
        switch (input->control)
        {
        case PRINT_MENU:
            printf("[0].Insert\n[1].ListAll\n[2].Delete\n[3].Delete By Name\n[4].Update\n[-1].Exit\n");
            break;

        case SELECT_MENU:
            printf("\nmenu [%d] selected\n", input->userSelect);
            break;

        case COMMAND:
            printf("\n");
            printf("%s ...commanding\n", input->command);
            break;

        case DATA_INPUT:
            printf("(%s) data processed. \n", input->szData);
            break;

        default:
            printf(">>");
            break;
        }
        return TRUE;
    }
    else
    {
        printf("Exit Console ... \n");
        return FALSE;
    }
}

void InitInput(UInput *pInput)
{
    pInput->flag = 1;
    pInput->control = 0;
    pInput->userSelect = -1;
    pInput->command = NULL;
    pInput->szData = NULL;
}

void UserInput(UInput *pInput, int mode)
{
    switch (mode)
    {
    case PRINT_MENU:
        pInput->control = mode;
        break;

    case SELECT_MENU:
        printf("Select menu: ");
        pInput->control = mode;
        scanf("%d", &(pInput->userSelect));
        break;

    case COMMAND:
        printf("Input command: ");
        pInput->control = mode;
        pInput->command = (char *)malloc(sizeof(char) * COM_SIZE);
        scanf("%s", pInput->command);
        break;

    case DATA_INPUT:
        pInput->control = mode;
        printf("Input data: ");
        pInput->szData = (char *)malloc(sizeof(char) * DATA_SIZE);
        scanf("%s", pInput->szData);
        break;

    case INT_INPUT:
        pInput->control = mode;
        printf("Input number: ");
        scanf("%d", &(pInput->nData));
        break;

    default:
        break;
    }
}
