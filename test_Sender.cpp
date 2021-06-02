#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Check if trasmissions are successfull") 
{
 SendInput inputdataofBMS= file;
 REQUIRE(InputtotheSystem(inputdataofBMS) == OK);
}

TEST_CASE("check if the data is copied in the system the console prints") 
{
 
SendInput inputdataofBMS = file;
SendOutput outputdataofBMS = toConsole;
REQUIRE(InputtotheSystem(inputdataofBMS) == OK);
REQUIRE(OutputoftheSyatem(outputdataofBMS) == OK);
}

TEST_CASE("check if the data to the console prints") 
{
 
SendInput inputdataofBMS = file;
SendOutput outputdataofBMS = toConsole;
REQUIRE(OutputoftheSyatem(outputdataofBMS) == OK);
}
