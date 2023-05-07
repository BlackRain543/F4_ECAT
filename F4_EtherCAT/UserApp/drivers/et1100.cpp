
#include <drivers/et1100.h>

ET1100::ET1100(
		Port::SPIComm 	&spi,
		Port::CS 		&cs,
		Port::EXIT 		&spiIrq,
		Port::EXIT 		&sync0,
		Port::EXIT 		&sync1,
		Port::TIM		&tim,
		Port::GPIO		&eepromLoaded
		)
: spi_(spi),
  cs_(cs),
  spiIrq_(spiIrq),
  sync0_(sync0),
  sync1_(sync1),
  tim_(tim),
  eepromLoaded_(eepromLoaded)
{


}

ET1100::~ET1100()
{

}


