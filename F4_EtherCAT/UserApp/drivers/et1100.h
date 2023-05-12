
#ifndef DRIVERS_ET1100_H_
#define DRIVERS_ET1100_H_

#include "port/typedef_port.h"
#include "port/peripheral_port.hpp"

#include <string.h>
#include "esc_soes.h"


#define GPIO_ECAT_RESET    			1 	 /* specific function to hold ESC reset on startup
                              	  	  	  * when emulating EEPROM
                              	  	  	  */

class ET1100
{
	public:
		ET1100(
				Port::SPIComm 	&spi,
				Port::CS 		&cs,
				Port::EXIT 		&spiIrq,
				Port::EXIT 		&sync0,
				Port::EXIT 		&sync1,
				Port::TIM		&tim,
				Port::GPIO		&eepromLoaded
				);
		virtual ~ET1100();
		constexpr static uint8_t MAX_READ_SIZE  = 128;

		constexpr static uint8_t ESC_CMD_NOP 	= 0x00;
		constexpr static uint8_t ESC_CMD_READ 	= 0x02;
		constexpr static uint8_t ESC_CMD_READWS = 0x03;
		constexpr static uint8_t ESC_CMD_WRITE 	= 0x04;

		constexpr static uint8_t ESC_TERM       = 0xff;
		constexpr static uint8_t ESC_NEXT       = 0x00;

		constexpr static uint16_t ESCREG_TYPE	= 0x0001;					// ET1100:0x11
		constexpr static uint16_t ESCREG_SYNCMANAGERS_SUPPORTED = 0x0005;	// ET1100:8
		constexpr static uint16_t ESCREG_RAM_SIZE = 0x0006;					// ET1100:8

		constexpr static uint16_t ESCREG_AL_STATUS_1	= 0x0130;
		constexpr static uint16_t ESCREG_AL_STATUS_2 	= 0x0131;
		constexpr static uint16_t ESCREG_PDI_CONTROL 	= 0x0140;
		constexpr static uint16_t ESCREG_ESC_CONFIG 	= 0x0141;

		constexpr static uint8_t SYNC_OUT_UNIT_CONTROL_MASK = 0x01;
		constexpr static uint8_t SYNC_OUT_ECAT_CONTROL 		= 0x00;
		constexpr static uint8_t SYNC_OUT_PDI_CONTROL 		= 0x01;

		constexpr static uint16_t ESCREG_SYNC_START_TIME    = 0x0990;

		constexpr static uint8_t  DC_SYNC_OUT                = 0x04;
		constexpr static uint16_t ESCREG_CYCLIC_UNIT_CONTROL= 0x0980;

		// measured with 21MHz SPI PDI
		constexpr static uint32_t SYNC_START_OFFSET			= 2342840;


		void 		EscInit(const esc_cfg_t * config);
		uint32_t 	EscEnableDC();

		void 		EscAddress (uint16_t address, uint8_t command);
		void 		EscRead (uint16_t address, void *buf, uint16_t len);
		void 		EscWrite (uint16_t address, void *buf, uint16_t len);

		void 		EscInterruptEnable (uint32_t mask);
		void 		EscInterruptDisable (uint32_t mask);

	private:
		Port::SPIComm 	&spi_;
		Port::CS 		&cs_;
		Port::EXIT		&spiIrq_;
		Port::EXIT		&sync0_;
		Port::EXIT		&sync1_;
		Port::TIM		&tim_;
		Port::GPIO		&eepromLoaded_;

		uint8_t 		spiTxData_[2];
//		uint8_t 		spiRxData_[2];

		uint8_t 		read_termination_[MAX_READ_SIZE] = { 0 };
};

#endif
