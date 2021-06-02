#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Check if trasmissions are successfull") 
{
 SendInput inputdataofBMS= file;
 REQUIRE(SendInput (inputdataofBMS) == OK);
}

TEST_CASE("Testcase to check if the console print is happening periodically") 
{
 
SendInput inputdataofBMS = file;
BMS_outputtype outputvaluefetch = printtoconsole;
REQUIRE(SendInput (inputdataofBMS) == OK);
REQUIRE(SendOutput  (outputdataofBMS) == OK);
}
