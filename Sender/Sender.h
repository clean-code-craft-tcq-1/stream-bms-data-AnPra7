/*!
***     \file        Sender.h
***
***     \author      pratik
***
\par    File_description Header for the  data streaming source file
*\n*/
                  
/*********************************************************************************/

//Definitions and macros

#define DATA_QUANT 50
extern float Temperature_values[DATA_QUANT];
extern float SOC_Values[DATA_QUANT];

// Enums and functions

typedef enum
{
  NOT_OK,
  OK
}Status;

typedef enum
{
  toConsole,
  toController
}SendOutput;

typedef enum
{
  file,
  server
}SendInput;


/*------------------------------Functions---------------------------------------------*/

/*------------------------------Declarations------------------------------------------*/

Status InputtotheSystem(SendInput inputdataofBMS);
Status OutputoftheSyatem(SendOutput outputdataofBMS);
Status Scandata(float Temperature_values[],float SOC_Values[]);
Status ToConsole(float Temperature_values[],float SOC_Values[]);
