#include "gtest/gtest.h"

extern "C"
{
#include <avr/io.h>
#include "led/led_driver.h"
#include "keys/key_driver.h"
}

class ledDriverTest : public ::testing::Test
{
protected:
	void SetUp() override 
	{
		init_leds();
		init_keys();
	}
	void TearDown() override
	{

	}
};

TEST_F(ledDriverTest, setUpLed) {
	EXPECT_EQ(0xff, PORTA);
}

TEST_F(ledDriverTest, Set_bit_in_PortA) {
	set_led(1, 1);
	EXPECT_EQ(0b11111110, PORTA);
}
TEST_F(ledDriverTest, Off_bit_in_PortA) {
	set_led(1, 0);
	EXPECT_EQ(0b11111111, PORTA);
}

TEST_F(ledDriverTest, initSwitchDDR) {
	EXPECT_EQ(0b00000000, DDRD);
	EXPECT_EQ(0b00000000, DDRC);
}
TEST_F(ledDriverTest, initSwitchPORTS) {
	EXPECT_EQ(0b00001100, PORTD);
	EXPECT_EQ(0b00111111, PORTC);
}
TEST_F(ledDriverTest, getSwitchPORTD) {
	EXPECT_EQ(1, get_key(7));
}
TEST_F(ledDriverTest, getSwitchPORTC) {
	EXPECT_EQ(0, get_key(1));
}
