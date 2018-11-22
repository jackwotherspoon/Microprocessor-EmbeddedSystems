#ifndef _TIMER_H_
#define _TIMER_H_


/* define pointer macros for accessing the timer interface registers */

#define TIMER_STATUS	((volatile unsigned int *) 0x10002000)

#define TIMER_CONTROL	((volatile unsigned int *) 0x10002004)

#define TIMER_START_LO	((volatile unsigned int *) 0x10002008)

#define TIMER_START_HI	((volatile unsigned int *) 0x1000200C)

#define TIMER_SNAP_LO	((volatile unsigned int *) 0x10002010)

#define TIMER_SNAP_HI	((volatile unsigned int *) 0x10002014)

//initialize timer 0
#define T0_STATUS	((volatile unsigned int *) 0x10004000)

#define T0_CONTROL	((volatile unsigned int *) 0x10004004)

#define T0_START_LO	((volatile unsigned int *) 0x10004008)

#define T0_START_HI	((volatile unsigned int *) 0x1000400C)

#define T0_SNAP_LO	((volatile unsigned int *) 0x10004010)

#define T0_SNAP_HI	((volatile unsigned int *) 0x10004014)



//initialize timer 1
#define T1_STATUS	((volatile unsigned int *) 0x10004020)

#define T1_CONTROL	((volatile unsigned int *) 0x10004024)

#define T1_START_LO	((volatile unsigned int *) 0x10004028)

#define T1_START_HI	((volatile unsigned int *) 0x1000402C)

#define T1_SNAP_LO	((volatile unsigned int *) 0x10004030)

#define T1_SNAP_HI	((volatile unsigned int *) 0x10004034)

//initialize push button
#define BUTTONS_MASK	((volatile unsigned int *) 0x10000058)

#define BUTTONS_EDGE	((volatile unsigned int *) 0x1000005C)


#define TIMER_TO_BIT 0x1

#endif /* _TIMER_H_ */
