

  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Sender.h"


float Temperature_values[DATA_QUANT];
float SOC_Values[DATA_QUANT];

Status (*ScanDatafromfile[])(float Temperature_values[],float SOC_Values[])={Scandata};
Status (*DatatoConsole[])(float Temperature_values[],float SOC_Values[])={ToConsole};




Status Scandata(float Temperature_values[], float SOC_Values[])
{
  /*Status transmission = NOT_OK;
  float temperature,soc;
  int i=0;
  File * file = fopen("./Sender/data.txt","r");
  
  if(file)
  {
    for( i=0; fscanf(file, "%f\t\t%f\n", &temperature,&soc)!=EOF,i++)
    {
      Temperature_values[i] = temperature;
      SOC_Values[i]         = soc;
    }
    transmission = OK;
  }
  fclose(file);*/
  return OK;
}




Status InputtotheSystem(SendInput inputdataofBMS)
{
    Status IsSuccess = NOT_OK;
    IsSuccess=(*ScanDatafromfile[inputdataofBMS])(Temperature_values,SOC_Values);
    return IsSuccess;
}



Status OutputoftheSyatem(SendOutput outputdataofBMS)
{
    Status IsSuccess = NOT_OK;
    IsSuccess=(*DatatoConsole[outputdataofBMS])(Temperature_values,SOC_Values);
    return IsSuccess;
}









Status ToConsole(float Temperature_values[],float SOC_Values[]);
{
   /* for(int i=0;i<DATA_QUANT;i++)
    {
        printf("Temperature value is %f and StateOfCharge value is %f\n",Temperature_values[i],SOC_Values[i]);
    }*/
    return OK;


}


















