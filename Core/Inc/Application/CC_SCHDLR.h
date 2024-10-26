/*
 * CC_SCHDLR.h
 *
 *  Created on: Sep 18, 2024
 *      Author: Xavier Alsina
 *
Disclaimer:
This project, including all associated documentation and code, is provided "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, or non-infringement.

In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

The code and documentation generated as part of this project are released under the following terms:
1.	Use and Distribution: You are free to use, modify, and distribute the code and documentation in any medium, provided that proper attribution to the original authors is given.
2.	Non-Commercial Use: This project may be used for personal, educational, or non-commercial purposes. If you intend to use any part of this project to generate revenue or for commercial purposes, explicit written permission from the author is required.
3.	No Warranty: The authors make no guarantees about the correctness, reliability, or stability of the code. It is your responsibility to test and verify that the code functions as required in your environment.
4.	Liability: Under no circumstances shall the authors or contributors be held liable for any direct, indirect, incidental, special, or consequential damages arising out of the use of the code or documentation.
5.	Contribution: Any contributions made to this project, including pull requests, are assumed to be provided under the same license and terms as the original project.
6.	Licensing: This project may be subject to additional licensing terms and conditions, particularly if integrating with third-party libraries or systems. It is the user's responsibility to ensure compliance with any such licenses.
 *
 */

#ifndef INC_CC_SCHDLR_H_
	#define INC_CC_SCHDLR_H_
	//HEADERS
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//CONSTANTS
	#define CC_SCHDLR_MAX_ALLOWED_MISS_INT 100	//Max overflowings on the planner
	#define CC_SCHDLR_BASE_TIME 1				//Scheduler's base time in ms
	#define CC_SCHDLR_MAX_THREADS 10			//Thus every task is executed every

	//DATA TYPES
	struct CC_SCHDLR_task_t
	{
		void* function;						//Function/procedure to execute
		void* input_param1;					//Input parameter
		void* input_param2;
		void* input_param3;
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

	//VARIABLES PROTOTYPES
	extern CC_SCHDLR_Usage_t CC_SCHDLR_MainSchedulerUsage;
	extern CC_SCHDLR_Scheduler_t CC_SCHDLR_MainScheduler;
	extern CC_SCHDLR_Scheduler_t CC_SCHDLR_NestedScheduler;

	//FUNCTIONS PROTOTYPES
	void CC_SCHDLR_Scheduler(void*, void*, void*);					//CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_InitScheduler(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_InitNestedScheduler(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_CheckForSchedulerOverflow(CC_SCHDLR_Scheduler_t*);
	void CC_SCHDLR_SchedulerUsage(CC_SCHDLR_Usage_t*, const uint8_t);

#endif /* INC_CC_SCHDLR_H_ */
