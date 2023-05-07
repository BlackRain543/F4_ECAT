#ifndef _LED_H_
#define _LED_H_

#include "port/peripheral_port.hpp"

namespace LED
{
	constexpr uint8_t MODE_ALWAYS_OFF 	= 0b00000000;
	constexpr uint8_t MODE_ALWAYS_ON 	= 0b11111111;

	constexpr uint8_t MODE_ONCE_FLASH	= 0b00000001;
	constexpr uint8_t MODE_TWICE_FLASH  = 0b00001010;
	constexpr uint8_t MODE_TRIPLE_FLASH = 0b00101010;
	constexpr uint8_t MODE_QUADRA_FLASH = 0b10101010;

	constexpr uint32_t TIME_1024_MILLI_SEC_MASK = (0x00000001<<(8+2)) - 1;
	constexpr uint32_t UNIT_TIME_SHIFT_BITS = 7;		// 1024/8 = 128 = 2^(7)

	constexpr uint32_t CYCLE_TIME_DEFAULT = 7;
	constexpr uint32_t MODE_DEFAULT = MODE_ALWAYS_OFF;

	class LED
	{
		public:
			LED(Port::GPIO 	&gpio,
				uint32_t periodMask = TIME_1024_MILLI_SEC_MASK,
				uint8_t	polarity = 1);

			~LED();
			void SetMode(uint8_t mode);
			void Display();

		private:
			Port::GPIO 		&gpio_;
			uint8_t			mode_;
			uint32_t		periodMask_;
			uint8_t			polarity_;

			void			TurnOn();
			void			TurnOff();
	};
}

#endif
