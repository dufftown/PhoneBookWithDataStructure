#ifndef _PB_UI_H_
#define _PB_UI_H_

#define TRUE 1
#define FALSE 0

#define COM_SIZE 30
#define DATA_SIZE 50

enum {PRINT_MENU, SELECT_MENU, COMMAND, DATA_INPUT, INT_INPUT};

typedef struct _u_input_type {
    int flag;
    int control;
    int userSelect;
    char* command;
    char* szData;
    int nData;
} UInput;

int Display(UInput* input);

void InitInput(UInput* pInput);

void UserInput(UInput* pInput, int mode);

#endif