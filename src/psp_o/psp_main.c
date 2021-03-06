//============================================================
//
//	psp_main.c - PSP main
//
//============================================================
#include <time.h>
#include "driver.h"

//#include "pg.h"
#include "syscall.h"
#include "menu.h"

#define PATHLIST_H 20
#define MAXPATH   0x108
int	dlist_num;
int	dlist_start;
int	dlist_curpos;
extern SETTING setting;

int psp_exit =0;



//#include "psp_main.h"
//#include "pg.h"
//#include "syscall.h"
//#include "psp_menu.h"



//============================================================
//	PSP module info section
//============================================================

#ifdef KERNEL_MODE
PSP_MODULE_INFO("pspMAME86", 0x1000, 0, 4);
PSP_MAIN_THREAD_ATTR(0);
#else
PSP_MODULE_INFO("pspMAME86", 0x0000, 0, 4);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);
#endif



//============================================================
//	GLOBAL VARIABLES
//============================================================

extern SETTING setting;

volatile int psp_loop;
volatile int psp_sleep;



//============================================================
//	PROTOTYPES
//============================================================

int run_mame(int argc, char **argv);



//============================================================
//	HOME?L?[?֘A
//============================================================

//============================================================
//	ExitCallback
//============================================================

static SceKernelCallbackFunction/*int*/ ExitCallback(int arg1, int arg2, void *arg)
{
	psp_loop = 0;
	psp_sleep = 0;
	return 0;
}



//============================================================
//	PowerCallback
//============================================================

static SceKernelCallbackFunction/*int*/ PowerCallback(int unknown, int pwrflags, void *arg)
{
	if (pwrflags & PSP_POWER_CB_POWER_SWITCH)
	{
		psp_sleep = 1;
	}
	else if (pwrflags & PSP_POWER_CB_RESUME_COMPLETE)
	{
		psp_sleep = 0;
	}

	int cbid;
	cbid = sceKernelCreateCallback("Power Callback", ( int (*)(int, int, void*) )PowerCallback, NULL);
	scePowerRegisterCallback(0, cbid);
	return 0;
}



//============================================================
//	CreateCallbackThread
//============================================================
/*--------------------------------------------------------
	?R?[???o?b?N?X???b?h?쐬
--------------------------------------------------------*/

static int CallbackThread(SceSize/*int*/ args, void *argp)
{
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", ( int (*)(int, int, void*) )ExitCallback, NULL);
	sceKernelRegisterExitCallback(cbid);

	cbid = sceKernelCreateCallback("Power Callback", ( int (*)(int, int, void*) )PowerCallback, NULL);
	scePowerRegisterCallback(0, cbid);

	sceKernelSleepThreadCB();
	return 0;
}



/*--------------------------------------------------------
	?R?[???o?b?N?X???b?h?ݒ?
--------------------------------------------------------*/

/* Sets up the callback thread and returns its thread id */
static /*int*/void SetupCallbacks(void)
{
	SceUID/*int*/ thread_id = 0;

	thread_id = sceKernelCreateThread("Update Thread", CallbackThread, 0x12, 0xFA0, 0, NULL);
	if (thread_id >= 0)
	{
		sceKernelStartThread(thread_id, 0, 0);
	}

//	return thread_id;
}


//============================================================
//	???C??
//============================================================

#ifdef KERNEL_MODE
static int user_main(SceSize args, void *argp)
#else
int main(int argc, char *argv[])
#endif //KERNEL_MODE
{
//	int res = 0;
	char *_argv[5];
	int _argc = 0;

	psp_loop = 1;
	psp_sleep = 0;

	SetupCallbacks();

	psp_video_init();
	sceCtrlSetSamplingCycle(0);//sceCtrlInit(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG/*1*/);//sceCtrlSetAnalogMode(1);

	openLog("pspLogDelOrto.txt");
    logWrite("arranco la cuestion!\n");
	//psp_printf_init();
	//pgcInit();
#ifndef KERNEL_MODE
	setCurDir(argv[0]);/* ???[?U?[???[?h???̂ݎg?p */
#endif //KERNEL_MODE
	_argv[_argc++] = getCurDir();

	Get_DriverList();

	load_config();
	load_menu_bg();
	bgbright_change();

	while (psp_loop)
	{
		Draw_All();

		switch (Control())
		{
		case 2:
			Draw_Confirm();
			if (Confirm_Control())
			{
				psp_clear_screen();
				_argv[_argc] = (char *)drivers[dlist_curpos]->name;
				switch (setting.cpu_clock)
				{
				case 0: scePowerSetClockFrequency(222, 222, 111); break;
				case 1: scePowerSetClockFrequency(266, 266, 133); break;
				case 2: scePowerSetClockFrequency(300, 300, 150); break;
				default:
				case 3: scePowerSetClockFrequency(333, 333, 166); break;
				}
				psp_loop = 2;
				/*res =*/ run_mame(_argc + 1, _argv);
				scePowerSetClockFrequency(222, 222, 111);
				Confirm_Control();
			}
			break;

		case 3:
			psp_menu();
			break;
		}
	}

	save_config();
	psp_video_exit();

	closeLog();
#ifndef KERNEL_MODE
	sceKernelExitGame();/* ???[?U?[???[?h???̂ݎg?p */
#endif
	return 0;
}

#ifdef KERNEL_MODE
static SceUID/*int*/ main_thread;

void main_thread_set_priority(int priority)
{
	sceKernelChangeThreadPriority(main_thread, priority);
}

int main(int argc, char *argv[])
{
	setCurDir(argv[0]);/* ?J?[?l?????[?h?̏ꍇ?͂????ŁB */

	main_thread = sceKernelCreateThread(
		"User Mode Thread",
		user_main,
		0x11,
		256 * 1024,
		PSP_THREAD_ATTR_USER,
		NULL);

	sceKernelStartThread(main_thread, 0, 0);
	sceKernelWaitThreadEnd(main_thread, NULL);

	sceKernelExitGame();/* ?J?[?l?????[?h?̏ꍇ?͂????ŁB */

	return 0;
}
#endif

