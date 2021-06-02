/**
@copyright
Robert Bosch GmbH reserves all rights even in the event of industrial property rights.
We reserve all rights of disposal such as copying and passing on to third parties.
*/
/*
 * Sender.c
 * Created on: 6.02.2021
 * Author: Pratik Jaiswal
*/

/*  --> This program is for transmitting the data received from  the sensor/file to the console/controller
	-->   It implements the send and recieve functiona and also  functions that facilitate testing of the functionality
*/

//--------------------------------------------------------------------------------------------------------------- 
//                                    Includes
//---------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Sender.h"

//--------------------------------------------------------------------------------------------------------------- 
//                                    Declarartions and Definitions
//---------------------------------------------------------------------------------------------------------------
float Temperature_values[DATA_QUANT]={};
float SOC_Values[DATA_QUANT]={};

Status (*ScanDatafromfile[])(float Temperature_values[],float SOC_Values[])={Scandata};
Status (*DatatoConsole[])(float Temperature_values[],float SOC_Values[])={ToConsole};



/*---------------------------------------------------------------------------*/
/*     FUNCTION:    Scandata
 */
/*!    \brief      to read the data from the sensor/file/pdf
 * 
 *     \param       temperature values and soc value
 *     \returns     the status if the copying or reading of data was successfull
 *
*//*------------------------------------------------------------------------*/
Status Scandata(float Temperature_values[], float SOC_Values[])
{
  Status transmission = NOT_OK;
  float temperature,soc;
  
 
  FILE* file = fopen("./Sender/data.txt","r");
  
  if(file)
  {
    for(int i=0;fscanf(file, "%f\t\t%f\n", &temperature,&soc)!=EOF ;i++)
    {
      
      Temperature_values[i] = temperature;
      SOC_Values[i]         = soc;
    }
    transmission = OK;
  }
  fclose(file);
  return transmission;
}



/*---------------------------------------------------------------------------*/
/*     FUNCTION:    InputtotheSystem
 */
/*!    \brief      to determine the success status of the reading of data
 * 
 *     \param       the type of input : file/pdf/sensor data directly
 *     \returns     the status if the copying or reading of data was successfull
 *
*//*------------------------------------------------------------------------*/
Status InputtotheSystem(SendInput inputdataofBMS)
{
    Status IsSuccess = NOT_OK;
    IsSuccess=(*ScanDatafromfile[inputdataofBMS])(Temperature_values,SOC_Values);
    return IsSuccess;
}


/*---------------------------------------------------------------------------*/
/*     FUNCTION:    OutputoftheSyatem
 */
/*!    \brief      to determine the success status of the sending the value to the console
 * 
 *     \param       the type of output : Console/Controller
 *     \returns     the status if the copying or reading of data was successfull
 *
*//*------------------------------------------------------------------------*/
Status OutputoftheSyatem(SendOutput outputdataofBMS)
{
    Status IsSuccess = NOT_OK;
    IsSuccess=(*DatatoConsole[outputdataofBMS])(Temperature_values,SOC_Values);
    return IsSuccess;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    ToConsole
 */
/*!    \brief      to send the value to the console and return the success ststus
 * 
 *     \param       temperature values and soc value
 *     \returns     the status if the sending of data was successfull
 *
*//*------------------------------------------------------------------------*/

Status ToConsole(float Temperature_values[],float SOC_Values[])
{
    for(int i=0;i<20;i++)
    {
        printf("Temperature value is %f and StateOfCharge value is %f\n",Temperature_values[i],SOC_Values[i]);
    }
    return OK;


}
