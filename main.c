/*
 * main.c
 *
 *  Created on: Sep 11, 2014
 *      Author: jcobb
 */

#define F_CPU	8000000

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include "i2c/i2c.h"
#include "util/log.h"
#include "util/clock.h"
#include "imu/imu.h"


unsigned char messageBuf[4];
unsigned char TWI_targetSlaveAddress;
unsigned char temp;
uint8_t TWI_operation = 0;

// log debugging
static const char _tag[] PROGMEM = "main: ";
volatile char term_in = 0;

// local porototypes
void read_imu();

void terminal_in_cb(uint8_t c)
{
	term_in = c;
	LOG("input=%c\r\n", c);


}


uint8_t reading = 0;
volatile bool test = 0;

uint16_t ax, ay, az;
uint16_t gx, gy, gz;
uint16_t mx, my, mz;


void main()
{

	debug_init(terminal_in_cb);
	clock_init();

	LOG("spike_328p_i2c started...\r\n");

	sei();




	/*
	test_timeout(1000);
	test_timeout(2000);
	test_timeout(3000);
	*/


	// First we need to join the I2C bus
	i2c_begin();


	LOG("imu_init\r\n");
	imu_init();
	LOG("imu_test\r\n");
	test = imu_test();
	LOG("imu_test: %c\r\n", test);




	/*
	i2c_begin_transmission(0x68);
	i2c_write_byte(0x02);

	i2c_end_transmission(0);

	_delay_ms(70); // delay 70 milliseconds


	i2c_request_from(11, 2, 0);
	*/


	/*
	while(i2c_available() > 2)
	{
		reading = i2c_read();
		reading = reading <<8;
		reading |= i2c_read();
		LOG("i2c_reading: %c\r\n", reading);

		_delay_ms(100);
	}
	*/


	//LOG("starting loop...\r\n");
	//_delay_ms(100);



	while(1)
	{
		// Skip code
		//_delay_ms(500);
		//continue;

		read_imu();
		_delay_ms(100);

	}
}

void read_imu()
{
	//imu_getmotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
	imu_read9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
	LOG("a/g/m:\t");
	LOG("%d\t", ax);
	LOG("%d\t", ay);
	LOG("%d\t", az);
	LOG("%d\t", gx);
	LOG("%d\t", gy);
	LOG("%d\t", gz);
	LOG("%d\t", mx);
	LOG("%d\t", my);
	LOG("%d\t", mz);
	LOG("\r\n");

	_delay_ms(100);
}
