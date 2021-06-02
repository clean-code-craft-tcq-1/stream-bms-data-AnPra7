#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Check if trasmissions are successfull") 
{
 SendInput inputdataofBMS= file;
 REQUIRE(InputtotheSystem(inputdataofBMS) == OK);
}

TEST_CASE("Testcase to check if the console print is happening periodically") 
{
 
SendInput inputdataofBMS = file;
SendOutput outputdataofBMS = toConsole;
REQUIRE(InputtotheSystem(inputdataofBMS) == OK);
REQUIRE(OutputoftheSyatem(outputdataofBMS) == OK);
}
