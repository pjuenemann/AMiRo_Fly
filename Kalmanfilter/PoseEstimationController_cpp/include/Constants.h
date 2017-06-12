#ifndef AMIRO_CONSTANTS_H_
#define AMIRO_CONSTANTS_H_

/*! \brief Constants regarding the AMiRo platform
 *
 *  This header contains constant variables
 *  regarding the AMiRo platform, which means that
 *  these values do not change during runtime.
 *  Constants are e.g. physical ones like seconds per minute
 *  or geometrical ones like the circumference of wheel.
 *  All physical constants (therefore all values with a
 *  physical unit) are implicitly in µ iff the variable
 *  is of type integer, unless it is explicitly named in
 *  the variable.
 *  All physical constants (therefore all values with a
 *  physical unit) are implicitly without prefix (e.g. µ)
 *  iff the variable is of type float, unless it is
 *  explicitly named in the variable. The SI prefix is
 *  used, iff the variable is of type float and therefor
 *  in SI units.
 */

#include <math.h>
#include <stdint.h>

/* CAN_* defines start */

/** \brief Controller Area Network specific defines
 *
 * These CAN_* defines are used in ControllerAreaNetworkRx.h
 * and ControllerAreaNetworkTx.h
 */

/* CAN_* defines end */

namespace amiro {
namespace CAN {

	const uint32_t PERIODIC_TIMER_ID         = 1;
	const uint32_t RECEIVED_ID               = 2;

	const uint32_t BOARD_ID_SHIFT            = 0x00u;
	const uint32_t BOARD_ID_MASK             = 0x07u;
	const uint32_t DEVICE_ID_SHIFT           = 0x03u;
	const uint32_t DEVICE_ID_MASK            = 0xFFu;
	const uint32_t INDEX_ID_SHIFT            = 0x03u;
	const uint32_t INDEX_ID_MASK             = 0x07u;

	const uint32_t DI_WHEEL_DRIVE_ID         = 1;
	const uint32_t POWER_MANAGEMENT_ID       = 2;
	const uint32_t LIGHT_RING_ID             = 3;
	const uint32_t COGNITION                 = 4;

	inline constexpr uint32_t MAGNETOMETER_ID(uint8_t axis) {return 0x54 | ((axis) & 0x03);}
	const uint32_t GYROSCOPE_ID              = 0x58;

	const uint32_t PROXIMITY_FLOOR_ID        = 0x51;
	const uint32_t ODOMETRY_ID               = 0x50;
	const uint32_t BRIGHTNESS_ID             = 0x40;
	inline constexpr uint32_t COLOR_ID(uint32_t index)             {return 0x38 | ((index) & 0x7);}
	inline constexpr uint32_t PROXIMITY_RING_ID(uint32_t index)    {return 0x30 | ((index) & 0x7);}
	const uint32_t SET_KINEMATIC_CONST_ID    = 0x22;
	const uint32_t TARGET_POSITION_ID        = 0x21;
	const uint32_t ACTUAL_SPEED_ID           = 0x20;
	const uint32_t SET_ODOMETRY_ID           = 0x12;
	const uint32_t TARGET_RPM_ID             = 0x11;
	const uint32_t TARGET_SPEED_ID           = 0x10;
	const uint32_t POWER_STATUS_ID           = 0x60;
	const uint32_t BROADCAST_SHUTDOWN        = 0x80u;

	const uint32_t CALIBRATE_PROXIMITY_FLOOR = 0x81u;
	const uint32_t CALIBRATE_PROXIMITY_RING  = 0x82u;

	const uint32_t SHUTDOWN_MAGIC            = 0xAA55u;
}

namespace constants {

	/** \brief Amount of seconds per minute */
	const int32_t secondsPerMinute = 60;

	/** \brief Amount of minutes per hour */
	const int32_t minutesPerHour = 60;

	/** \brief Amount of milliseconds per second */
	const int32_t millisecondsPerSecond = 1000;

	/** \brief Amount of millimeter per meter */
	const int32_t millimeterPerMeter = 1000;

	/** \brief Amount of millimeter per meter */
	const float meterPerMillimeter = 0.001f;

	/** \brief Distance between wheels in meter */
	const float wheelBaseDistanceSI = 0.069f;

	/** \brief Distance between wheels in micrometer */
	const int32_t wheelBaseDistance = wheelBaseDistanceSI * 1e6;

	/** \brief Wheel diameter in meter */
	const float wheelDiameterSI = 0.05571f;

	/** \brief Wheel diameter */
	const int32_t wheelDiameter = wheelDiameterSI * 1e6;

	/** \brief Wheel circumference in meter */
	const float wheelCircumferenceSI = M_PI * wheelDiameterSI;

	/** \brief Wheel circumference in micrometer */
	const int32_t wheelCircumference = wheelCircumferenceSI * 1e6;

	/** \brief Wheel error in meter (topview left:0, right:1) */
	const float wheelErrorSI[2] = {0.1, 0.1};

	/** \brief Wheel error in meter (topview left:0, right:1) */
	const int32_t wheelError[2] = {(int32_t) (wheelErrorSI[0] * 1e6), (int32_t) (wheelErrorSI[1] * 1e6)};

	/** \brief Motor increments per revolution
	 *
	 *  The increments are produced by 2 channels á 16
	 *  pulses per revolution with respect to the rising
	 *  and falling signal => 2*2*16 pulses/revolution.
	 *  The gearbox is 22:1 => 2*2*16*22 pulses/revolution
	 */
	const int32_t incrementsPerRevolution = 2 * 2 * 16 * 22;

	/** \brief Index of the proximity sensors
	 *
	 * Bottom view of the AMiRo sensors and their indices (F:Front, B:Back):
	 *  _____
	 * / 0F3 \
	 * |1   2|
	 * \__B__/
	 */
	enum sensorIdx {PROX_WL = 1, PROX_WR = 2, PROX_FL = 0, PROX_FR = 3};

	/** \brief Index of the wheels
	 *
	 * Top view of the AMiRo wheels and their indices (F:Front, B:Back):
	 *  _____
	 * /| F |\
	 * |0   1|
	 * \|_B_|/
	 */
	enum wheelIdx {LEFT_WHEEL = 0, RIGHT_WHEEL = 1};
}

namespace ringproximity {

	/** \brief Sensor count on the proximity sensor ring.
	 *
	 * Top view with sensor IDs (F:Front, B:Back):
	 *      ___
	 *     3   4
	 *   /   F   \
	 *  2         5
	 *  |         |
	 *  1         6
	 *   \   B   /
	 *     0___7
	 */
	static const int SENSOR_COUNT = 8;

	/** \brief Angular distance between the sensors.
	 *
	 * Top view with sensor IDs (F:Front, B:Back):
	 *      ___
	 *     3   4
	 *   /   F   \
	 *  2         5
	 *  |         |
	 *  1         6
	 *   \   B   /
	 *     0___7
	 */
	static const float SENSOR_DIST_ANGULAR = M_PI/4.0;

	/** \brief Angular distance between the AMiRo's front and the next (left or right) sensor.
	 *
	 * On the ring there isn't a sensor directly measuring the front, but there are two measuring the front
	 * with an angular difference to the front of 22.5°.
	 *
	 * Top view of the front (*:Sensor, +:Center):
	 *      ___
	 *     *   *
	 *   /       \
	 *  *         *
	 *  |    +    |
	 */
	static const float SENSOR_ANGULAR_FRONT_OFFSET = M_PI/8.0;

	/** \brief Angular orientation of the first sensor.
	 *
	 * The first sensor is the first left sensor at the back.
	 * Top view with sensor IDs and the robot coordinate system orientation (F:Front, B:Back, +:Center):
	 *      ___
	 *     3   4             ^ x
	 *   /   F   \           |
	 *  2         5          |
	 *  |    +    |          |
	 *  1         6          |
	 *   \   B   /   <-------+--
	 *     0___7       y     |
	 *
	 * The robot coordinate system is in the center of the robot.
	 * Due to the robot coordinate system, the angular orientation of the first sensor is 157.5°.
	 */
	static const float SENSOR_ANGULAR_POS_FIRST = M_PI - M_PI/8.0;
}

}

#endif /* AMIRO_CONSTANTS_H_ */
