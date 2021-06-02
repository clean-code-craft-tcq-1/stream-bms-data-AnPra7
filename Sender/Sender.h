#ifndef SENDER_H__
#define SENDER_H__


//Definitions and macros

#define DATA_QUANT 50

//--------------------------Declarations------------------------------------------------
//--------------------------------------------------------------------------------------
extern float Temperature_values[DATA_QUANT];
extern float SOC_Values[DATA_QUANT];

//------------------------- Enums and functions-----------------------------------------


//---------------------------------------------------------------------------------------
//*****This Enum is defined to check the status/result of the transmission***************
//The main agenda of this enum is to contribute to the test driven development so that it
//can be tested when this data type is returned with the functions defined***************
typedef enum
{
  NOT_OK,//There is some issue with the transmission or copying of the data or the file is corrupt or has no values
  OK      // Everything is working fine
}Status;

//----------------------------------------------------------------------------------------
//This is to define the output location of the program : console,controller,server--------
//----------------------------------------------------------------------------------------
typedef enum
{
  toConsole // 
// toController
// toServer   
}SendOutput;

//----------------------------------------------------------------------------------------
//This is to define the input type  of the data :text file,pdf file,sensor----------------
//----------------------------------------------------------------------------------------
typedef enum
{
  file // text file or pdf file
  //from the server
  //from the sensor
}SendInput;


/*------------------------------Functions---------------------------------------------*/

/*------------------------------Declarations------------------------------------------*/

Status InputtotheSystem(SendInput inputdataofBMS);
Status OutputoftheSyatem(SendOutput outputdataofBMS);
Status Scandata(float Temperature_values[],float SOC_Values[]);
Status ToConsole(float Temperature_values[],float SOC_Values[]);

#endif
