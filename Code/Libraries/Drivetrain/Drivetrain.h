#ifndef Drivetrain_h
#define Drivetrain_h

#include "Arduino.h"
#include <Pixy.h>
#include <SPI.h>

/**
 * The drivetrain for the robot. Controls the motors driving where the robot goes.
 */
class Drivetrain
{
  public:
	/**
	* Constructor. Sets the pins for all the motors.
	* center: Where the robot aims when it detects a block. Valid values are 0 - 319.
	* deadZone: How big the "center" of the robot is. Smaller values will cause robot to wiggle more.
	* power: How much power for wheel motors. Valid values are 0 - 255.
	* *stepTimes: An array where each element is how much time in milliseconds should be spent at each step of rotation.
	*/
    Drivetrain(const byte leftMotorForward, const byte leftMotorBackward, const byte rightMotorForward,
               const byte rightMotorBackward, int center, byte deadZone, byte power, 
               int *stepTimes);
    ~Drivetrain();

	/**
	* Gives power to motors, keeping the center of the block aligned with the requested center
	* set in the Drivetrain constructor.
	*/
    void goToFish(Block block);

	/**
	* Rotates an amount based on what step we're on. StepNum > 0
	*/
    void rotate(int stepNum);

	/**
	* Gives all motors 0 power.
	*/
    void stopMotors();

	/**
	* Gives all forward motors power. Since our motors move at different rates given the same power, it will inevitably turn.
	* Need encoders or a reference (like the pixy) to go in a straight line.
	*/
	void goStraight(int power);

	/**
	* Give the right forward motor power.
	*/
	void turnLeft(int power);

	/**
	* Give the left forward motor power.
	*/
	void turnRight(int power);

  private:
    byte _leftMotorForward; //Pin for left motor forward.
    byte _rightMotorForward; //Pin for right motor forward.
    byte _leftMotorBackward; //Pin for left motor backward.
    byte _rightMotorBackward; //Pin for right motor backward.
    int _center; //Where the robot aims when it detects a block. Valid values are 0 - 319.
    byte _deadZone; //How big the "center" of the robot is. Smaller values will cause robot to wiggle more.
    byte _power; //How much power for wheel motors. Valid values are 0 - 255.
    int *_stepTimes; //An array where each element is how much time in milliseconds should be spent at each step of rotation.
};

#endif
