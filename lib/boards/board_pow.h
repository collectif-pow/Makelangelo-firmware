#ifndef BOARD_POW_H
#define BOARD_POW_H

// POW ROBOT!!


#if MOTHERBOARD == BOARD_POW
#define MAX_MOTORS                 (2)

#define MOTOR_0_DIR_PIN           (5)
#define MOTOR_0_STEP_PIN          (4)
#define MOTOR_0_ENABLE_PIN        (3)
// TODO: change? remove?
#define MOTOR_0_LIMIT_SWITCH_PIN  (26)

#define MOTOR_1_DIR_PIN           (8)
#define MOTOR_1_STEP_PIN          (7)
#define MOTOR_1_ENABLE_PIN        (6)
// TODO: change? remove?
#define MOTOR_1_LIMIT_SWITCH_PIN  (27)

#define MAX_BOARD_SERVOS          (1)
#define SERVO0_PIN                (9)

#endif


#endif  // BOARD_POW_H
