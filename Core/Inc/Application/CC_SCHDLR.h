/*
 * CC_SCHDLR.h
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */

#ifndef INC_CC_SCHDLR_H_
	#define INC_CC_SCHDLR_H_
	//Headers
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//Constants
	#define CC_SCHDLR_MAX_ALLOWED_MISS_INT 100	//Max overflowings on the planner
	#define CC_SCHDLR_BASE_TIME 1				//Scheduler's base time in ms
	#define CC_SCHDLR_MAX_THREADS 10			//Thus every task is executed every

	//Data types
	struct CC_SCHDLR_task_t
	{
		void* function;						//Function/procedure to execute
		void* input_param1;					//Input parameter
		void* input_param2;
		void* input_param3;
//		float SchdlrUsageRatio;				//Usage ratio (%)
	};
	typedef struct CC_SCHDLR_task_t CC_SCHDLR_task_t;

	struct CC_SCHDLR_Scheduler_t
	{
		CC_SCHDLR_task_t Task2Launch[CC_SCHDLR_MAX_THREADS];	//Keep in mind that depending on the tasks number and timer adjust, their frequency will change.
		uint8_t BaseTimems;
		uint64_t IntCount;
		uint8_t TaskOngoing;
		uint64_t MissIntCnt;
	};
	typedef struct CC_SCHDLR_Scheduler_t CC_SCHDLR_Scheduler_t;

	struct CC_SCHDLR_Usage_t
	{
		float TaskUsageRatio[CC_SCHDLR_MAX_THREADS];
		uint32_t TaskUsageCounts[CC_SCHDLR_MAX_THREADS];
		uint32_t TotalAvailableCounts[CC_SCHDLR_MAX_THREADS];
	};
	typedef struct CC_SCHDLR_Usage_t CC_SCHDLR_Usage_t;

	//Variables Prototypes
	extern CC_SCHDLR_Usage_t CC_SCHDLR_MainSchedulerUsage;
	extern CC_SCHDLR_Scheduler_t CC_SCHDLR_FastScheduler;
	extern CC_SCHDLR_Scheduler_t CC_SCHDLR_SlowScheduler;

	//Function Prototypes
	void CC_SCHDLR_Scheduler(void*, void*, void*);					//CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_InitFastScheduler(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_InitSlowScheduler(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_CheckForSchedulerOverflow(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_SchedulerUsage(CC_SCHDLR_Usage_t*, const uint8_t);


#endif /* INC_CC_SCHDLR_H_ */
