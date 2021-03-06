
/* PSP2007 (osd_config_fuantei_070807.c) */

/*
 * Configuration routines.
 *
 */

#include "driver.h"
#include <ctype.h>
/* types of monitors supported */
//#include "psp_main.h"
//#include "psp_menu.h"

#include "inc_rc.h"

extern SETTING setting;
extern int keyorientation;

extern int blitMode;

//int get_config_id(const char *section, const char *name, int def);
//char **get_config_argv(const char *section, const char *name, int *argc);
//const char *get_config_text(const char *msg);


//void set_config_file(const char *filename) {}

//const char *get_config_string(const char *section, const char *name, const char *def) {	return(def);}
//int get_config_int(const char *section, const char *name, int def) {	return (def);}
//float get_config_float(const char *section, const char *name, float def) {	return (def);}

//void set_config_string(const char *section, const char *name, const char *val) { }
//void set_config_int(const char *section, const char *name, int val) { }
//void set_config_float(const char *section, const char *name, float val) { }
//void set_config_id(const char *section, const char *name, int val) { }

//============================================================
//	LOCAL VARIABLES
//============================================================

//#if (1==PSP_USE_SYS_LOG)
static FILE *logfile;
static const char *s_errorlog="error.log";
static int b_flusherrorlog=0;
static int b_closeerrorlog=0;
//#endif // (1==PSP_USE_SYS_LOG)




//extern int frontend_help(char *gamename);

static char *dos_basename(char *filename);
static char *dos_dirname(char *filename);
static char *dos_strip_extension(char *filename);

/* from video.c */
//extern int triple_buffer;
extern /*int*/UINT8 wait_vsync;
extern /*int*/UINT8 limit_max_speed;
//extern float screen_aspect;
//extern int keep_aspect;

extern int frameskip,autoframeskip;
//extern int throttle;
//extern int vscanlines, hscanlines;
//extern int video_sync;
//extern int stretch;
//extern int always_synced;
extern int gfx_skiplines;
extern int gfx_skipcolumns;
extern int gfx_mode;
//extern int gfx_depth;
//extern int monitor_type;
//extern int use_keyboard_leds;

//static float f_beam;
//static float f_flicker;
//static float f_intensity;
//static int use_artwork = 1;
//static int use_backdrops = -1;
//static int use_overlays = -1;
//static int use_bezels = -1;
//static char *aspect;
//static const char *s_depth;
//static const char *s_scanlines;
//static const char *resolution;
//static const char *debugres;
//static const char *vectorres;
//static const char *monitorname;
//static const char *vesamode;
//static const char *s_frameskip;
//static const char *s_cheatfile;
//static const char *s_language;
//static const char *s_artres;
//static const char *s_screenaspect;
//static const char *joyname;
#if (1==LINK_BIOS)
static const char *s_bios;
#endif //(1==LINK_BIOS)
//static int config_norotate = 0;
//static int config_flipy = 0;
//static int config_flipx = 0;
//static int config_ror = 0;
//0static int config_rol = 0;
//static int config_autoror = 0;
//static int config_autorol = 0;
//#if (1==PSP_USE_SYS_LOG)
static int maxlogsize;
static int curlogsize;
static int errorlog;
//#endif
//0static int createconfig;
//static int showusage;
static int ignorecfg;
//static const char *playbackname;
//static const char *recordname;
//const char *g_s_resolution;

/* from sound.c */
int enable_sound;
extern int soundcard;
extern int usestereo;
extern int sampleratedetect;
extern int attenuation;

#if 0
/* from input.c */
//extern int use_mouse;
//extern int joystick;
//extern int steadykey;
#endif

/* from cheat.c */
//extern char *cheatfile;

/* from datafile.c */
//const char *history_filename;
//const char *mameinfo_filename;

char *rompath_extra;

//const char *cheatdir;

//#define CHEAT_NAME	"CHEAT.DAT"
//#define HISTRY_NAME "HISTORY.DAT"
//#define CONFIG_FILE "mame.cfg"

/* from video.c, for centering tweaked modes */
//extern int center_x;
//extern int center_y;

/*from video.c flag for 15.75KHz modes (req. for 15.75KHz Arcade Monitor Modes)*/
//extern int arcade_mode;

/*from svga15kh.c flag to allow delay for odd/even fields for interlaced displays (req. for 15.75KHz Arcade Monitor Modes)*/
//extern int wait_interlace;

/* from video.c for blit rotation */
extern int video_flipx;
extern int video_flipy;
extern int video_swapxy;

static int mame_argc;
static char **mame_argv;
static int game;
static char srcfile[10];

//int use_dirty; /* not used, keep for future dirty vector updating */


void set_config_string(const char *section, const char *name, const char *val) { }
void set_config_int(const char *section, const char *name, int val) { }
void set_config_float(const char *section, const char *name, float val) { }
void set_config_id(const char *section, const char *name, int val) { }

/*
 * gets some boolean config value.
 * 0 = false, >0 = true, <0 = auto
 * the shortcut can only be used on the commandline
 */
static int get_bool( const char *section, const char *option, const char *shortcut, int res/*def*/ )
{
//	const char *yesnoauto;
//	int res, i;

//	res = def;

	//if (0 ignorecfg) goto cmdline;

	/* look into mame.cfg, [section] */
//	if (def == 0)		yesnoauto = /*get_config_string(section, option,*/ "no"		/*)*/;
//	else if (def > 0)	yesnoauto = /*get_config_string(section, option,*/ "yes"	/*)*/;
//	else /* def < 0 */	yesnoauto = /*get_config_string(section, option,*/ "auto"	/*)*/;

	/* if the option doesn't exist in the cfgfile, create it */
//	if (get_config_string(section, option, "#") == "#")		set_config_string(section, option, yesnoauto);

//	if( game >= 0 )
//	{
//		/* look into mame.cfg, [srcfile] */
//		yesnoauto = get_config_string(srcfile, option, yesnoauto);
//		/* look into mame.cfg, [gamename] */
//		yesnoauto = get_config_string((char *)drivers[game]->name, option, yesnoauto);
//	}

	/* also take numerical values instead of "yes", "no" and "auto" */
	if		(/*stricmp(yesnoauto, "no"  ) == 0*/(/*def*/res == 0)) res = 0;
	else if (/*stricmp(yesnoauto, "yes" ) == 0*/(/*def*/res  > 0)) res = 1;
	else /*if (stricmp(yesnoauto, "auto") == 0(// def // res < 0))*/ res = -1;
//	else	res = atoi (yesnoauto);

//cmdline:
	/* check the commandline */
	int i;
	for (i = 1; i < mame_argc; i++)
	{
		if( mame_argv[ i ][ 0 ] == '-' )
		{
			/* look for "-option" / "-shortcut" */
			if( stricmp( &mame_argv[ i ][ 1 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 1 ], shortcut ) == 0 ) )
			{
				if( i + 1 < mame_argc )
				{
					if( stricmp( mame_argv[ i + 1 ], "no" ) == 0 )
					{
						i++;
						res = 0;
					}
					else if( stricmp( mame_argv[ i + 1 ], "yes" ) == 0 )
					{
						i++;
						res = 1;
					}
					else if( stricmp( mame_argv[ i + 1 ], "auto" ) == 0 )
					{
						i++;
						res = -1;
					}
					else if( isdigit( mame_argv[ i + 1 ][ 0 ] ) )
					{
						i++;
						res = atoi( mame_argv[ i ] );
					}
					else
					{
						res = 1;
					}
				}
				else
				{
					res = 1;
				}
			}
			else if( strnicmp( &mame_argv[ i ][ 1 ], "no", 2 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 3 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 3 ], shortcut ) == 0 ) ) )
			{
				res = 0;
			}
			else if( strnicmp( &mame_argv[ i ][ 1 ], "auto", 4 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 5 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 5 ], shortcut ) == 0 ) ) )
			{
				res = -1;
			}
		}
	}
	return res;
}

int get_config_int(const char *section, const char *name, int def) {
	return (def);
}


static int get_int( const char *section, const char *option, const char *shortcut, int def )
{
	int res,i;

	res = def;

	if (!ignorecfg)
	{
		/* if the option does not exist, create it */
		if (get_config_int (section, option, -777) == -777)
			set_config_int (section, option, def);

		/* look into mame.cfg, [section] */
		res = get_config_int (section, option, def);

		if( game >= 0 )
		{
			/* look into mame.cfg, [srcfile] */
			res = get_config_int (srcfile, option, res);

			/* look into mame.cfg, [gamename] */
			res = get_config_int ((char *)drivers[game]->name, option, res);
		}
	}

	/* get it from the commandline */
	for (i = 1; i < mame_argc; i++)
	{
		if( mame_argv[ i ][ 0 ] == '-' )
		{
			if( stricmp( &mame_argv[ i ][ 1 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 1 ], shortcut ) == 0 ) )
			{
				if( i + 1 < mame_argc && isdigit( mame_argv[ i + 1 ][ 0 ] ) )
				{
					i++;
					res = atoi( mame_argv[ i ] );
				}
				else
				{
					res = def;
				}
			}
			else if( strnicmp( &mame_argv[ i ][ 1 ], "no", 2 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 3 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 3 ], shortcut ) == 0 ) ) )
			{
				res = 0;
			}
		}
	}
	return res;
}

//static int get_int( const char *section, const char *option, const char *shortcut, int def )
//{
//	int res,i;
//	res = def;
//	//if (!0 ignorecfg)
//	{
//		/* if the option does not exist, create it */
//		if (get_config_int (section, option, -777) == -777)
//			set_config_int (section, option, def);
//		/* look into mame.cfg, [section] */
//		res = get_config_int (section, option, def);
//
//		if( game >= 0 )
//		{
//			/* look into mame.cfg, [srcfile] */
//			res = get_config_int (srcfile, option, res);
//			/* look into mame.cfg, [gamename] */
//			res = get_config_int ((char *)drivers[game]->name, option, res);
//		}
//	}
//	/* get it from the commandline */
//	for (i = 1; i < mame_argc; i++)
//	{
//		if( mame_argv[ i ][ 0 ] == '-' )
//		{
//			if( stricmp( &mame_argv[ i ][ 1 ], option ) == 0 ||
//				( shortcut && stricmp( &mame_argv[ i ][ 1 ], shortcut ) == 0 ) )
//			{
//				if( i + 1 < mame_argc && isdigit( mame_argv[ i + 1 ][ 0 ] ) )
//				{
//					i++;
//					res = atoi( mame_argv[ i ] );
//				}
//				else
//				{
//					res = def;
//				}
//			}
//			else if( strnicmp( &mame_argv[ i ][ 1 ], "no", 2 ) == 0 &&
//				( stricmp( &mame_argv[ i ][ 3 ], option ) == 0 ||
//				( shortcut && stricmp( &mame_argv[ i ][ 3 ], shortcut ) == 0 ) ) )
//			{
//				res = 0;
//			}
//		}
//	}
//	return res;
//}

#if 00
static float get_float( const char *section, const char *option, const char *shortcut, float def, float lower, float upper )
{
	int i;
	float res;

	res = def;

	//if (!0 ignorecfg)
	{
		/* if the option does not exist, create it */
		if (get_config_float (section, option, 9999.0) == 9999.0)
			set_config_float (section, option, def);

		/* look into mame.cfg, [section] */
		res = get_config_float (section, option, def);

		if( game >= 0 )
		{
//			/* look into mame.cfg, [srcfile] */
//			res = get_config_float (srcfile, option, res);

			/* look into mame.cfg, [gamename] */
			res = get_config_float ((char *)drivers[game]->name, option, res);
		}
	}

	/* get it from the commandline */
	for (i = 1; i < mame_argc; i++)
	{
		if( mame_argv[ i ][ 0 ] == '-' )
		{
			if( stricmp( &mame_argv[ i ][ 1 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 1 ], shortcut ) == 0 ) )
			{
				if( i + 1 < mame_argc && isdigit( mame_argv[ i + 1 ][ 0 ] ) )
				{
					i++;
					res = atof( mame_argv[ i ] );
				}
				else
				{
					res = upper;
				}
			}
			else if( strnicmp( &mame_argv[ i ][ 1 ], "no", 2 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 3 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 3 ], shortcut ) == 0 ) ) )
			{
				res = lower;
			}
		}
	}
	if( res < lower )
	{
		return lower;
	}
	else if( res > upper )
	{
		return upper;
	}
	return res;
}
#endif

static const char *get_string( const char *section, const char *option, const char *shortcut, const char *def, const char *no, const char *yes, const char *s_auto )
{
	const char *res;
	int i;

	res = def;

//	//if (!0 ignorecfg)
//	{
//		/* if the option does not exist, create it */
//		if (get_config_string (section, option, "#") == "#" )	set_config_string (section, option, def);
//		/* look into mame.cfg, [section] */
//		res = get_config_string(section, option, def);
//		if( game >= 0 )
//		{
//			/* look into mame.cfg, [srcfile] */
//			res = get_config_string(srcfile, option, res);
//			/* look into mame.cfg, [gamename] */
//			res = get_config_string((char*)drivers[game]->name, option, res);
//		}
//	}

	/* get it from the commandline */
	for (i = 1; i < mame_argc; i++)
	{
		if( mame_argv[ i ][ 0 ] == '-' )
		{
			if( stricmp( &mame_argv[ i ][ 1 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 1 ], shortcut ) == 0 ) )
			{
				i++;
				if ( i < mame_argc && mame_argv[ i ][ 0 ] != '-' )
				{
					res = mame_argv[ i ];
				}
				else if( yes != NULL && no != NULL && stricmp( res, no ) == 0 )
				{
					res = yes;
				}
			}
			else if( no != NULL && strnicmp( &mame_argv[ i ][ 1 ], "no", 2 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 3 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 3 ], shortcut ) == 0 ) ) )
			{
				res = no;
			}
			else if( s_auto != NULL && strnicmp( &mame_argv[ i ][ 1 ], "auto", 4 ) == 0 &&
				( stricmp( &mame_argv[ i ][ 5 ], option ) == 0 ||
				( shortcut && stricmp( &mame_argv[ i ][ 5 ], shortcut ) == 0 ) ) )
			{
				res = s_auto;
			}
		}
	}
	return res;
}

#if 00
static void extract_resolution( const char *s_resolution )
{
	if( stricmp( s_resolution, "auto" ) != 0 )
	{
		int width;
		int height;
		char *tmp;
		char tmpres[ 20 ];
		strncpy( tmpres, s_resolution, 20 );
		tmp = strtok( tmpres, "xX" );
		width = atoi( tmp );
		tmp = strtok( 0, "xX" );
		if( tmp != NULL )
		{
			height = atoi( tmp );
		}
		else
		{
			height = 0;
		}
		//options.debug_width = width;
		//options.debug_height = height;
		//options.vector_width = width;
		//options.vector_height = height;
		//g_s_resolution = s_resolution;
	}
}
#endif

//#include "rc.h"
//#ifndef RC_MACROS_H
//#define RC_MACROS_H
#if 0

/* Little helpers for magnitude conversions */
#define RES_K(res) ((double)res*1e3)
#define RES_M(res) ((double)res*1e6)
#define CAP_U(cap) ((double)cap*1e-6)
#define CAP_N(cap) ((double)cap*1e-9)
#define CAP_P(cap) ((double)cap*1e-12)

#endif
extern struct rc_option fileio_opts[];

static void get_fileio_opts( void )
{
	int i;
	int s;
	const char *name;
	const char *shortname;
	const char *dest;

	struct
	{
		const char *name;
		const char *shortname;
	} shortcuts[] =
	{
		{ "inipath", NULL },
		{ "cfg_directory", "cfg" },
		{ "nvram_directory", "nvram" },
		{ "memcard_directory", "memcard" },
//		{ "input_directory", "inp" },
//		{ "hiscore_directory", "hi" },
		{ "state_directory", "sta" },
//		{ "artwork_directory", "artwork" },
//		{ "snapshot_directory", "snap" },
//		{ "diff_directory", "diff" },
//		{ "cheat_directory", "cheat" },
//		{ "history_file", NULL },
//		{ "mameinfo_file", NULL },
//		{ "cheat_file", NULL },
//		{ "ctrlr_directory", "ctrlr" },
		{ NULL, NULL }
	};

	i = 0;
	while( fileio_opts[ i ].name != NULL )
	{
		if( fileio_opts[ i ].type == rc_string )
		{
			*( (char **)fileio_opts[ i ].dest ) = NULL;

			name = fileio_opts[ i ].name;
			shortname = fileio_opts[ i ].shortname;

			s = 0;
			while( shortcuts[ s ].name != NULL )
			{
				if( strcmp( shortcuts[ s ].name, name ) == 0 )
				{
					name = shortcuts[ s ].shortname;
					shortname = shortcuts[ s ].name;
					break;
				}
				s++;
			}

			if( name != NULL )
			{
				dest = get_string( "directory", name, shortname, fileio_opts[ i ].deflt, "", NULL, NULL );
				if( dest != NULL )
				{
					*( (char **)fileio_opts[ i ].dest ) = malloc( strlen( dest ) + 1 );
					if( *( (char **)fileio_opts[ i ].dest ) == NULL )
					{
						osd_die( "config.c: out of memory\n" );
						//exit(1);
					}
					strcpy( *( (char **)fileio_opts[ i ].dest ), dest );
					if( fileio_opts[ i ].func != NULL )
					{
						( *fileio_opts[ i ].func )( &fileio_opts[ i ], NULL, 0 );
					}
				}
			}
		}
		i++;
	}
}

//extern struct rc_option frontend_opts[];
static int help = 0;
struct rc_option frontend_opts[] = {
	{ "Frontend Related", NULL,	rc_seperator, NULL, NULL, 0, 0,	NULL, NULL },
	{ "help", "h", rc_set_int, &help, NULL, 1, 0, NULL, "show help message" },
	{ NULL, NULL, rc_end, NULL, NULL, 0, 0, NULL, NULL }
};
static void get_rc_opts( struct rc_option *p_rcopt )
{
	int i;
	int j;

	i = 0;
	while( p_rcopt[ i ].name != NULL )
	{
		if( p_rcopt[ i ].type == rc_set_int ||
			p_rcopt[ i ].type == rc_bool )
		{
			if( p_rcopt[ i ].deflt != NULL )
			{
				*( (int *)p_rcopt[ i ].dest ) = atoi( p_rcopt[ i ].deflt );
			}
			else
			{
				*( (int *)p_rcopt[ i ].dest ) = 0;
			}
		}
		i++;
	}

	i = 0;
	while( p_rcopt[ i ].name != NULL )
	{
		for( j = 1; j < mame_argc; j++ )
		{
			if( mame_argv[ j ][ 0 ] == '-' )
			{
				if( stricmp( &mame_argv[ j ][ 1 ], p_rcopt[ i ].name ) == 0 ||
					( p_rcopt[ i ].shortname != NULL && stricmp( &mame_argv[ j ][ 1 ], p_rcopt[ i ].shortname ) == 0 ) )
				{
					if( p_rcopt[ i ].type == rc_set_int )
					{
						*( (int *)p_rcopt[ i ].dest ) = p_rcopt[ i ].min;
					}
					else if( p_rcopt[ i ].type == rc_bool )
					{
						*( (int *)p_rcopt[ i ].dest ) = 1;
					}
					else if( p_rcopt[ i ].type == rc_int )
					{
						j++;
						*( (int *)p_rcopt[ i ].dest ) = atoi( mame_argv[ j ] );
						if( p_rcopt[ i ].func != NULL )
						{
							( *p_rcopt[ i ].func )( &p_rcopt[ i ], mame_argv[ j ], 0 );
						}
					}
					else if( p_rcopt[ i ].type == rc_string )
					{
						j++;
						*( (char **)p_rcopt[ i ].dest ) = malloc( strlen( mame_argv[ j ] ) + 1 );
						if( *( (char **)p_rcopt[ i ].dest ) == NULL )
						{
							osd_die( "config.c: out of memory\n" );
							//exit(1);
						}
						strcpy( *( (char **)p_rcopt[ i ].dest ), mame_argv[ j ] );
						if( p_rcopt[ i ].func != NULL )
						{
							( *p_rcopt[ i ].func )( &p_rcopt[ i ], mame_argv[ j ], 0 );
						}
					}
				}
				else if( strnicmp( &mame_argv[ j ][ 1 ], "no", 2 ) == 0 &&
					( stricmp( &mame_argv[ j ][ 3 ], p_rcopt[ i ].name ) == 0 ||
					( p_rcopt[ i ].shortname != NULL && stricmp( &mame_argv[ j ][ 3 ], p_rcopt[ i ].shortname ) == 0 ) ) )
				{
					if( p_rcopt[ i ].type == rc_bool )
					{
						*( (int *)p_rcopt[ i ].dest ) = 0;
					}
				}
			}
		}
		i++;
	}
}

//static int video_set_beam(struct rc_option *option, const char *arg, int priority)
//{
//	options.beam = (int)(f_beam * 0x00010000);
//	if (options.beam < 0x00010000)		options.beam = 0x00010000;
//	if (options.beam > 0x00100000)		options.beam = 0x00100000;
//	option->priority = priority;
//	return 0;
//}
//static int video_set_flicker(struct rc_option *option, const char *arg, int priority)
//{
//	options.vector_flicker = (int)(f_flicker * 2.55);
//	if (options.vector_flicker < 0)		options.vector_flicker = 0;
//	if (options.vector_flicker > 255)	options.vector_flicker = 255;
//	option->priority = priority;
//	return 0;
//}
//static int video_set_intensity(struct rc_option *option, const char *arg, int priority)
//{
//	options.vector_intensity = f_intensity;
//	option->priority = priority;
//	return 0;
//}

//============================================================
//	video_set_resolution
//============================================================
#if 00
static int video_set_resolution(struct rc_option *option, const char *arg, int priority)
{
	int width;
	int height;
	if (!strcmp(arg, "auto"))
	{
		width = 0;
		height = 0;
		//options.vector_width = 0;
		//options.vector_height = 0;
	}
	else if( sscanf( arg, "%dx%d", &width, &height ) < 2 )
	{
		width = height = 0;
		//options.vector_width = options.vector_height = 0;
		osd_die("error: invalid value for resolution: %s\n", arg);
		return -1;
	}
//	if ((gfx_depth != 0) &&
//		(gfx_depth != 16) &&
//		(gfx_depth != 24) &&
//		(gfx_depth != 32))
//	{
//		width = height = 0;
//		options.vector_width = options.vector_height = 0;
//		osd_die( "error: invalid value for resolution: %s\n", arg);
//		return -1;
//	}
	//options.vector_width = width;
	//options.vector_height = height;

	option->priority = priority;
	return 0;
}
#endif

//static int video_set_debugres(struct rc_option *option, const char *arg, int priority)
//{
//	options.debug_depth = 8;
//	if (!strcmp(arg, "auto"))
//	{
//		options.debug_width = 640;
//		options.debug_height = 480;
//	}
//	else if(sscanf(arg, "%dx%d", &options.debug_width, &options.debug_height) != 2)
//	{
//		options.debug_width = options.debug_height = 0;
//		osd_die( "error: invalid value for debugres: %s\n", arg);
//		return -1;
//	}
//	option->priority = priority;
//	return 0;
//}

//static int init_errorlog(struct rc_option *option, const char *arg, int priority)
//{
//	/* provide errorlog from here on */
//	if (errorlog && !logfile)
//	{
//		logfile = fopen(s_errorlog,"wa");
//		curlogsize = 0;
//		if (!logfile)
//		{
//			osd_die("unable to open log file\n");
//			//exit(1);
//		}
//	}
//	option->priority = priority;
//	return 0;
//}

//============================================================
//	decode_aspect
//============================================================

//static int decode_aspect(struct rc_option *option, const char *arg, int priority)
//{
//	int num, den;
//	if (sscanf(arg, "%d:%d", &num, &den) != 2 || num == 0 || den == 0)
//	{
//		osd_die( "error: invalid value for aspect ratio: %s\n", arg);
//		return -1;
//	}
//	//screen_aspect = (float)num / (float)den;
//	option->priority = priority;
//	return 0;
//}

#if 0
//struct rc_option config_opts[] =
//{
//	{ NULL, NULL, rc_link, frontend_opts, NULL, 0, 0, NULL, NULL },
//	{ NULL, NULL, rc_link, fileio_opts, NULL, 0, 0, NULL, NULL },
//
//	// name, shortname, type, dest, deflt, min, max, func, help
//	{ "MSDOS video options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "frameskip", "fs", rc_int, &frameskip, "0", 0, 12, NULL, "set frameskip" },
//	{ "waitvsync", NULL, rc_bool, &wait_vsync, "0", 0, 0, NULL, "wait for vertical sync (reduces tearing)" },
//	{ "triplebuffer", "tb", rc_bool, &triple_buffer, "0", 0, 0, NULL, "triple buffering" },
//	{ "stretch", NULL, rc_bool, &stretch, "1", 0, 0, NULL, "stretch image" },
//	{ "resolution", "r", rc_string, &resolution, "auto", 0, 0, video_set_resolution, "set resolution" },
//	{ "vectorres", NULL, rc_string, &vectorres, "auto", 0, 0, NULL, "set resolution for vector games" },
//	{ "scanlines", "sl", rc_string, &s_scanlines, "yes", 0, 0, NULL, "enable scanline effect" },
//	{ "keepaspect", "ka", rc_bool, &keep_aspect, "1", 0, 0, NULL, "enforce aspect ratio" },
//	{ "throttle", NULL, rc_bool, &throttle, "1", 0, 0, NULL, "throttle speed to the game's framerate" },
//	{ "screen_aspect", NULL, rc_string, &aspect, "4:3", 0, 0, decode_aspect, "specify an alternate monitor aspect ratio" },
//	{ "vsync", NULL, rc_bool, &video_sync, "0", 0, 0, NULL, "syncronize only to the monitor refresh" },
//	{ "vesamode", "vesa", rc_string, &vesamode, "vesa3", 0, 0, NULL, "use vesa modes" },
//	{ "dirty", NULL, rc_bool, &use_dirty, "1", 0, 0, NULL, NULL },
//	{ "alwayssynced", NULL, rc_bool, &always_synced, "0", 0, 0, NULL, "use tweaked vsync frequency" },
//	{ "depth", NULL, rc_string, &s_depth, "auto", 0, 0, NULL, "screen mode depth" },
//	{ "skiplines", NULL, rc_int, &gfx_skiplines, "-1", 0, 0, NULL, "lines to skip if screen is too short" },
//	{ "skipcolumns", NULL, rc_int, &gfx_skipcolumns, "-1", 0, 0, NULL, "columns to skip of screen is too narrow" },
//	{ "monitor", NULL, rc_string, &monitorname, "standard", 0, 0, NULL, "set the monitor type" },
//	{ "centerx", NULL, rc_int, &center_x, "0", 0, 0, NULL, NULL },
//	{ "centery", NULL, rc_int, &center_y, "0", 0, 0, NULL, NULL },
//	{ "waitinterlace", NULL, rc_bool, &wait_interlace, "0", 0, 0, NULL, NULL },

//	{ "MSDOS sound options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
	{ "soundcard", NULL, rc_int, &soundcard, "-1", 0, 0, NULL, "select sound card" },
	{ "stereo", NULL, rc_bool, &usestereo, "1", 0, 0, NULL, "selects stereo or mono output" },
	{ "sampleratedetect", NULL, rc_bool, &sampleratedetect, "1", 0, 0, NULL, "detect the sample rate of the sound card" },

	/* name, shortname, type, dest, deflt, min, max, func, help */
//	{ "Input device options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "mouse", NULL, rc_bool, &use_mouse, "1", 0, 0, NULL, "enable mouse input" },
//	{ "joystick", "joy", rc_string, &joyname, "none", 0, 0, NULL, "set joystick type" },
//	{ "lightgun", "gun", rc_bool, &use_lightgun, "0", 0, 0, NULL, "enable lightgun input" },
//	{ "dual_lightgun", "dual", rc_bool, &use_lightgun_dual, "0", 0, 0, NULL, "enable dual lightgun input" },
//	{ "offscreen_reload", "reload", rc_bool, &use_lightgun_reload, "0", 0, 0, NULL, "offscreen shots reload" },
//	{ "steadykey", "steady", rc_bool, &steadykey, "0", 0, 0, NULL, "enable steadykey support" },
//	{ "keyboard_leds", "leds", rc_bool, &use_keyboard_leds, "1", 0, 0, NULL, "enable keyboard LED emulation" },
//	{ "led_mode", NULL, rc_string, &ledmode, "ps/2", 0, 0, decode_ledmode, "LED mode (ps/2|usb)" },
//	{ "a2d_deadzone", "a2d", rc_float, &a2d_deadzone, "0.3", 0.0, 1.0, NULL, "minimal analog value for digital input" },
//	{ "ctrlr", NULL, rc_string, &options.controller, 0, 0, 0, NULL, "preconfigure for specified controller" },
//	{ "paddle", NULL, rc_string, &dummy, "joystick", ANALOG_TYPE_PADDLE, 0, decode_analog_select, "enable (keyboard|mouse|joystick) if a paddle control is present" },
//	{ "adstick", NULL, rc_string, &dummy, "joystick", ANALOG_TYPE_ADSTICK, 0, decode_analog_select, "enable (keyboard|mouse|joystick|lightgun) if an analog joystick control is present" },
//	{ "lightgun", NULL, rc_string, &dummy, "mouse", ANALOG_TYPE_LIGHTGUN, 0, decode_analog_select, "enable (keyboard|mouse|joystick|lightgun) if a lightgun control is present" },
//	{ "pedal", NULL, rc_string, &dummy, "joystick", ANALOG_TYPE_PEDAL, 0, decode_analog_select, "enable (keyboard|mouse|joystick|lightgun) if a pedal control is present" },
//	{ "dial", NULL, rc_string, &dummy, "mouse", ANALOG_TYPE_DIAL, 0, decode_analog_select, "enable (keyboard|mouse|joystick|lightgun) if a dial control is present" },
//	{ "trackball", NULL, rc_string, &dummy, "mouse", ANALOG_TYPE_TRACKBALL, 0, decode_analog_select, "enable (keyboard|mouse|joystick|lightgun) if a trackball control is present" },
//	{ "digital", NULL, rc_string, &dummy, "none", 1, 0, decode_digital, "mark certain joysticks or axes as digital (none|all|j<N>*|j<N>a<M>[,...])" },

	/* options supported by the mame core */
	/* video */
//	{ "Mame CORE video options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "norotate", NULL, rc_bool, &config_norotate, "0", 0, 0, NULL, "do not apply rotation" },
//	{ "ror", NULL, rc_bool, &config_ror, "0", 0, 0, NULL, "rotate screen clockwise" },
//	{ "rol", NULL, rc_bool, &config_rol, "0", 0, 0, NULL, "rotate screen anti-clockwise" },
//	{ "autoror", NULL, rc_bool, &config_autoror, "0", 0, 0, NULL, "automatically rotate screen clockwise for vertical games" },
//	{ "autorol", NULL, rc_bool, &config_autorol, "0", 0, 0, NULL, "automatically rotate screen anti-clockwise for vertical games" },
//	{ "flipx", NULL, rc_bool, &config_flipx, "0", 0, 0, NULL, "flip screen left-right" },
//	{ "flipy", NULL, rc_bool, &config_flipy, "0", 0, 0, NULL, "flip screen upside-down" },
//	{ "debug_resolution", "dr", rc_string, &debugres, "auto", 0, 0, video_set_debugres, "set resolution for debugger window" },
//	//{ "gamma", NULL, rc_float, &options.gamma, "1.0", 0.5, 2.0, NULL, "gamma correction"},
//	//{ "brightness", "bright", rc_float, &options.brightness, "1.0", 0.5, 2.0, NULL, "brightness correction"},
//	//{ "pause_brightness", NULL, rc_float, &options.pause_bright, "0.65", 0.5, 2.0, NULL, "additional pause brightness"},

//	/* vector */
//	{ "Mame CORE vector game options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "antialias", "aa", rc_bool, &options.antialias, "1", 0, 0, NULL, "draw antialiased vectors" },
//	{ "translucency", "tl", rc_bool, &options.translucency, "1", 0, 0, NULL, "draw translucent vectors" },
//	{ "beam", NULL, rc_float, &f_beam, "1.0", 1.0, 16.0, video_set_beam, "set beam width in vector games" },
//	{ "flicker", NULL, rc_float, &f_flicker, "0.0", 0.0, 100.0, video_set_flicker, "set flickering in vector games" },
//	{ "intensity", NULL, rc_float, &f_intensity, "1.5", 0.5, 3.0, video_set_intensity, "set intensity in vector games" },

	/* sound */
//	{ "Mame CORE sound options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "samplerate", "sr", rc_int, &options.samplerate, "5512", 5512, 44100, NULL, "set samplerate" },
//	{ "samples", NULL, rc_bool, &options.use_samples, "1", 0, 0, NULL, "use samples" },
//	{ "resamplefilter", NULL, rc_bool, &options.use_filter, "1", 0, 0, NULL, "resample if samplerate does not match" },
//	{ "sound", NULL, rc_bool, &enable_sound, "1", 0, 0, NULL, "enable/disable sound and sound CPUs" },
//	{ "volume", "vol", rc_int, &attenuation, "0", -32, 0, NULL, "volume (range [-32,0])" },

	/* misc */
//	{ "Mame CORE misc options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "artwork", "art", rc_bool, &use_artwork, "1", 0, 0, NULL, "use additional game artwork (sets default for specific options below)" },
//	{ "use_backdrops", "backdrop", rc_bool, &use_backdrops, "1", 0, 0, NULL, "use backdrop artwork" },
//	{ "use_overlays", "overlay", rc_bool, &use_overlays, "1", 0, 0, NULL, "use overlay artwork" },
//	{ "use_bezels", "bezel", rc_bool, &use_bezels, "1", 0, 0, NULL, "use bezel artwork" },
//	{ "artwork_crop", "artcrop", rc_bool, &options.artwork_crop, "0", 0, 0, NULL, "crop artwork to game screen only" },
//	{ "artwork_resolution", "artres", rc_int, &options.artwork_res, "0", 0, 0, NULL, "artwork resolution (0 for auto)" },
//	{ "cheat", "c", rc_bool, &options.cheat, "0", 0, 0, NULL, "enable/disable cheat subsystem" },
//	{ "debug", "d", rc_bool, &options.mame_debug, "0", 0, 0, NULL, "enable/disable debugger (only if available)" },
//	{ "playback", "pb", rc_string, &playbackname, NULL, 0, 0, NULL, "playback an input file" },
//	{ "record", "rec", rc_string, &recordname, NULL, 0, 0, NULL, "record an input file" },
//	{ "log", NULL, rc_bool, &errorlog, "0", 0, 0, init_errorlog, "generate error.log" },
//	{ "maxlogsize", NULL, rc_int, &maxlogsize, "10000", 0, 2000000, NULL, "maximum error.log size (in KB)" },
//	{ "oslog", NULL, rc_bool, &erroroslog, "0", 0, 0, NULL, "output error log to debugger" },
//	{ "language", NULL, rc_string, &s_language, "english", 0, 0, NULL, NULL },
//	{ "skip_disclaimer", NULL, rc_bool, &options.skip_disclaimer, "0", 0, 0, NULL, "skip displaying the disclaimer screen" },
//	{ "skip_gameinfo", NULL, rc_bool, &options.skip_gameinfo, "0", 0, 0, NULL, "skip displaying the game info screen" },
//	{ "skip_validitychecks", NULL, rc_bool, &options.skip_validitychecks, "0", 0, 0, NULL, "skip doing the code validity checks" },
//1	{ "crconly", NULL, rc_bool, &options.crc_only, "0", 0, 0, NULL, "use only CRC for all integrity checks" },
//#if (1==LINK_BIOS)
//	{ "bios", NULL, rc_string, &options.bios, "default", 0, 14, NULL, "change system bios" },
//#endif //(1==LINK_BIOS)
	/* config options */
//	{ "Configuration options", NULL, rc_seperator, NULL, NULL, 0, 0, NULL, NULL },
//	{ "createconfig", "cc", rc_set_int, &createconfig, NULL, 1, 0, NULL, "create the default configuration file" },
//	{ "showconfig", "sc", rc_set_int, &showconfig, NULL, 1, 0, NULL, "display running parameters in rc style" },
//	{ "showusage", "su", rc_set_int, &showusage, NULL, 1, 0, NULL, "show this help" },
//	{ "ignorecfg", NULL, rc_set_int, &ignorecfg, NULL, 1, 0, NULL, "use default settings" },
//	{ "verbose", "v", rc_bool, &verbose, "0", 0, 0, NULL, "display additional diagnostic information" },
//	{ NULL,	NULL, rc_end, NULL, NULL, 0, 0,	NULL, NULL }
//};
#endif

static void parse_cmdline( int argc, char **argv, int game_index )
{
//	int i;
	int orientation;
	struct InternalMachineDriver/*machine_config*/ drv;

	game = game_index;

	/* force third mouse button emulation to "no" otherwise Allegro will default to "yes" */
//	set_config_string( 0, "emulate_three", "no" );

	get_fileio_opts();

	/* read graphic configuration */
//	s_scanlines					= get_string( "config", "scanlines", "sl", "yes", "no", "yes", "yes" );
//	stretch						= get_bool( "config", "stretch", NULL, 1 );
//	use_artwork					= get_bool( "config", "artwork", "art", 1 );
//	use_backdrops				= get_bool( "config", "use_backdrops", "backdrop", 1 );
//	use_overlays				= get_bool( "config", "use_overlays", "overlay", 1 );
//	use_bezels					= get_bool( "config", "use_bezels", "bezel", 1 );
//	options.artwork_crop		= get_bool( "config", "artwork_crop", "artcrop", 0 );
//	s_artres					= get_string( "config", "artwork_resolution", "artres", "auto", NULL, NULL, "auto" );
	options.use_samples			= get_bool( "config", "samples", NULL, 1 );
//	video_sync					= get_bool( "config", "vsync", NULL, 0 );
//	wait_vsync					= get_bool( "config", "waitvsync", NULL, 0 );
//	triple_buffer				= get_bool( "config", "triplebuffer", "tb", 0 );
//	vesamode					= get_string( "config", "vesamode", "vesa", "vesa3", "no", "yes", "yes" );
//	use_dirty					= get_bool( "config", "dirty", NULL, -1 );
//	options.antialias			= get_bool( "config", "antialias", "aa", 1 );
//	options.translucency		= get_bool( "config", "translucency", "tl", 1 );
//	always_synced				= get_bool( "config", "alwayssynced", NULL, 0 );
//	s_depth						= get_string( "config", "depth", NULL, "auto", NULL, NULL, "auto" );
//	gfx_skiplines				= get_int( "config", "skiplines", NULL, -1 );
//	gfx_skipcolumns				= get_int( "config", "skipcolumns", NULL, -1 );
//	f_beam						= get_float( "config", "beam", NULL, 1.0, 1.0, 16.0 );
//	f_flicker					= get_float( "config", "flicker", NULL, 0.0, 0.0, 100.0 );
//	f_intensity					= get_float( "config", "intensity", NULL, 1.5, 0.3, 3.0 );
//	options.gamma				= get_float( "config", "gamma", NULL, 1.0, 0.5, 2.0 );
//	options.brightness			= get_float( "config", "brightness", "bright", 1.0, 0.5, 2.0 );
//	s_frameskip					= get_string( "config", "frameskip", "fs", "auto", "0", "auto", "auto" );
//	throttle					= get_bool( "config", "throttle", NULL, 1 );
//	config_norotate				= get_bool( "config", "norotate", NULL, 0 );
//	config_ror					= get_bool( "config", "ror", NULL, 0 );
//	config_rol					= get_bool( "config", "rol", NULL, 0 );
//	config_autoror				= get_bool( "config", "autoror", NULL, 0 );
//	config_autorol				= get_bool( "config", "autorol", NULL, 0 );
//	config_flipx				= get_bool( "config", "flipx", NULL, 0 );
//	config_flipy				= get_bool( "config", "flipy", NULL, 0 );
//	keep_aspect					= get_bool( "config", "keepaspect", "ka", 1 );
//TMK	s_screenaspect				= get_string( "config", "screen_aspect", NULL, "4:3", NULL, NULL, "4:3" );
//	s_screenaspect				= get_string( "config", "screen_aspect", NULL, "480:272", NULL, NULL, "480:272" );

	/* sound configuration */
	soundcard					= get_int( "config", "soundcard",  NULL, -1 );
	enable_sound				= get_bool( "config", "sound", NULL, 1 );
	options.samplerate			= get_int( "config", "samplerate", "sr", 5512 );
	usestereo					= get_bool( "config", "stereo", NULL, 1 );
	attenuation 				= get_int( "config", "volume", "vol", 0 );
	sampleratedetect			= get_bool( "config", "sampleratedetect", NULL, 1 );
//	options.use_filter			= get_bool( "config", "resamplefilter", NULL, 1 );

	/* input configuration */
//	use_mouse					= get_bool( "config", "mouse", NULL, 1 );
//	joyname						= get_string( "config", "joystick", "joy", "none", "none", "auto", "auto" );
//	steadykey					= get_bool( "config", "steadykey", "steady", 0 );
	//use_keyboard_leds			= get_bool( "config", "keyboard_leds", "leds", 1 );
//	options.controller			= get_string( "config", "ctrlr", NULL, NULL ,"", NULL, NULL );

	/* misc configuration */
//	options.cheat				= get_bool( "config", "cheat", "c", 0 );
//#ifdef MAME_DEBUG
//	options.mame_debug			= get_bool( "config", "debug", "d", 0 );
//#endif
//	s_cheatfile					= get_string( "config", "cheatfile", "cf", CHEAT_NAME, "", NULL, NULL );
//	history_filename			= get_string( "config", "historyfile", "history_file", HISTRY_NAME, "", NULL, NULL );
//	mameinfo_filename			= get_string( "config", "mameinfofile", "mameinfo_file", "MAMEINFO.DAT", "", NULL, NULL );

	/* read resolution configuration */
//	resolution					= get_string( "config", "resolution", "r", "auto", NULL, NULL, "auto" );
//	vectorres					= get_string( "config", "vectorres", NULL, "auto", NULL, NULL, "auto" );
//	debugres					= get_string( "config", "debug_resolution", "dr", "auto", NULL, NULL, "auto" );

	/* read language configuration */
//	s_language					= get_string( "config", "language", NULL, "english", "", NULL, NULL );

	/* monitor configuration */
//	monitorname					= get_string( "config", "monitor", NULL, "standard", NULL, NULL, NULL );
//	center_x					= get_int( "config", "centerx", NULL, 0 );
//	center_y					= get_int( "config", "centery", NULL, 0 );
//	wait_interlace				= get_bool( "config", "waitinterlace", NULL, 0 );

	/* process language configuration */
	//options.language_file		= mame_fopen( 0, s_language, FILETYPE_LANGUAGE, 0 );

	//options.pause_bright		= get_float( "config", "pause_brightness", NULL, 0.65, 0.5, 2.0 );
//	options.skip_disclaimer		= get_bool( "config", "skip_disclaimer", NULL, 0 );
//	options.skip_gameinfo		= get_bool( "config", "skip_gameinfo", NULL, 0 );
//	options.skip_validitychecks	= get_bool( "config", "skip_validitychecks", NULL, 0 );
//1	options.crc_only			= get_bool( "config", "crconly", NULL, 0 );
#if (1==LINK_BIOS)
	s_bios						= get_string( "config", "bios", NULL, "default", NULL, NULL, NULL );
#endif //(1==LINK_BIOS)
//	maxlogsize					= get_int( "config", "maxlogsize", NULL, 0 );
//TMK ADD
//		stretch =1;
//		stretch =0;
//		keep_aspect =1;
//		keep_aspect =0;


//#if (0!=LINK_ROT)
//#if (1000!=LINK_ROT)
	if (SCR_ROT==setting.screensize)
	{
//		config_autoror =1;
		/*config_ror =*/keyorientation =1;
	}
	else
//#endif// (1000!=LINK_ROT)
//#endif// (0!=LINK_ROT)
	{
//		config_autoror =0;
		/*config_ror =*/keyorientation =0;
	}

    char algo[256];
    sprintf(algo,"osd_config: enchufando setting.screensize=='%d'",setting.screensize);
    logWriteX(algo,"","",678);

    setBlitMode(setting.screensize);

	wait_vsync      = setting.vsync_ON_OFF;
	limit_max_speed = setting.limit_ON_OFF;

	enable_sound =soundcard;//	soundcard =*/setting.sound_ON_OFF;

//	switch((setting.sound_rate)/*&7*/)
//	{
//	case SND_44100:	options.samplerate = 44100;	break;
//	case SND_22050:	options.samplerate = 22050;	break;
//	case SND_14700:	options.samplerate = 14700;	break;
//	case SND_11025:	options.samplerate = 11025;	break;
//	case SND_08820:	options.samplerate =  8820;	break;
//	case SND_07350:	options.samplerate =  7350;	break;
//	case SND_06300:	options.samplerate =  6300;	break;
//	case SND_05512:	options.samplerate =  5512;	break;
//	}

	/* MODEL2
	if(0==(setting.sound_rate))	{options.samplerate = 0;	}
	else{options.samplerate = 44100/(setting.sound_rate);	}
*/

    /*if (0 ==setting.sound_rate)
		options.samplerate =44100;
	else if (0 ==setting.sound_rate)
		options.samplerate =22050;
	else
		options.samplerate =11025;*/

		if(0==(setting.sound_rate))	{options.samplerate = 0;	}
	else{options.samplerate = 44100/(setting.sound_rate);	}

        char dbg2[128];
        sprintf(dbg2,"options.samplerate=='%d',setting.sound_rate=='%d'",options.samplerate,setting.sound_rate);
        logWriteX("OSD_CONFIG-SOUND- : ",dbg2,"",666);

//TMK ADD END

//	options.beam = (int)( f_beam * 0x00010000 );
//	if( options.beam < 0x00010000 )	{	options.beam = 0x00010000;	}
//	if( options.beam > 0x00100000 )	{	options.beam = 0x00100000;	}
//	options.vector_flicker = (int)(f_flicker * 2.55);
//	if (options.vector_flicker < 0)	{	options.vector_flicker = 0;	}
//	if (options.vector_flicker > 255){	options.vector_flicker = 255;	}
//	options.vector_intensity = f_intensity;

//	{
//		int num;
//		int den;
//		if( sscanf( s_screenaspect, "%d:%d", &num, &den) == 2 && num != 0 && den != 0 )
//		{
//			//screen_aspect = (float)num / (float)den;
//		}
//	}

//TMK	if( stricmp( s_frameskip ,"auto" ) == 0 )
	if(0 ==setting.frameskip)
	{
		frameskip = 0;
		autoframeskip = 1;
	}
	else
	{
//TMK		frameskip = atoi( s_frameskip );
		frameskip = setting.frameskip-1;
		autoframeskip = 0;
	}

	/* any option that starts with a digit is taken as a resolution option */
	/* this is to handle the old "-wxh" commandline option. */
	//for( i = 1; i < argc; i++ )
	//{
	//	if( argv[ i ][ 0 ] == '-' && isdigit( argv[ i ][ 1 ] ) && ( strstr( argv[ i ], "x" ) || strstr( argv[ i ], "X" ) ) )
	//	{
	//		resolution = &argv[ i ][ 1 ];
	//		//vectorres = resolution;
	//		debugres = resolution;
	//	}
	//}

	/* get monitor type from supplied name */
//TMK	monitor_type = MONITOR_TYPE_STANDARD; /* default to PC monitor */
//	monitor_type = 0;

	//gfx_depth = atoi( s_depth );
//	if( options.mame_debug )
//	{
//		options.debug_depth = 8;
//		options.debug_width = 640;
//		options.debug_height = 480;
//		g_s_resolution = "640x480x0";
//		extract_resolution( debugres );
//		use_dirty = 0;
//	}
//	else
//	{
		//g_s_resolution = "0x0x0";
		/* break up resolution into width and height */
//		extract_resolution( resolution );

		/* break up vector resolution into width and height */
		expand_machine_driver( drivers[ game ]->drv, &drv );
	//	if( drv.video_attributes & VIDEO_TYPE_VECTOR )
	//	{
	//		extract_resolution( vectorres );
	//	}
//	}

	//if( gfx_depth != 8 && gfx_depth != 15 && gfx_depth != 16 && gfx_depth != 24 && gfx_depth != 32 )
	//{
	//	gfx_depth = 0; /* auto */
	//}

//	options.use_artwork = ARTWORK_USE_ALL;
//	if( !use_backdrops ){		options.use_artwork &= ~ARTWORK_USE_BACKDROPS;	}
//	if( !use_overlays )	{		options.use_artwork &= ~ARTWORK_USE_OVERLAYS;	}
//	if( !use_bezels )	{		options.use_artwork &= ~ARTWORK_USE_BEZELS;	}
//	if( !use_artwork )	{		options.use_artwork = ARTWORK_USE_NONE;	}
	//options.use_artwork = ARTWORK_USE_NONE;
	//options.artwork_res = atoi( s_artres );

	/* first start with the game's built in orientation */
	orientation = drivers[ game_index ]->flags & ORIENTATION_MASK;
	options.ui_orientation = orientation;

	if( options.ui_orientation & ORIENTATION_SWAP_XY )
	{
		/* if only one of the components is inverted, switch them */
		if( ( options.ui_orientation & ROT180 ) == ORIENTATION_FLIP_X ||
			( options.ui_orientation & ROT180 ) == ORIENTATION_FLIP_Y )
		{
			options.ui_orientation ^= ROT180;
		}
	}

	/* override if no rotation requested */
//	if( config_norotate )
//	{
//		orientation = options.ui_orientation = ROT0;
//	}

	/* rotate right */
	if( 1 == /*config_ror*/keyorientation )
	{
		/* if only one of the components is inverted, switch them */
		if( ( orientation & ROT180 ) == ORIENTATION_FLIP_X ||
			( orientation & ROT180 ) == ORIENTATION_FLIP_Y )
		{
			orientation ^= ROT180;
		}
		orientation ^= ROT90;
	}

	/* rotate left */
//	if( config_rol == 1 )
//	{
//		/* if only one of the components is inverted, switch them */
//		if( ( orientation & ROT180 ) == ORIENTATION_FLIP_X ||
//			( orientation & ROT180 ) == ORIENTATION_FLIP_Y )
//		{
//			orientation ^= ROT180;
//		}
//		orientation ^= ROT270;
//	}

//	keyorientation =0;
#if 0
	/* auto-rotate right (e.g. for rotating lcds), based on original orientation */
	if( /*config_autoror*/0 && ( drivers[ game_index ]->flags & ORIENTATION_SWAP_XY ) != 0 )
	{
		/* if only one of the components is inverted, switch them */
		if( ( orientation & ROT180 ) == ORIENTATION_FLIP_X ||
			( orientation & ROT180 ) == ORIENTATION_FLIP_Y )
		{
			orientation ^= ROT180;
		}
		orientation ^= ROT90;

//		keyorientation =1;
	}

	/* auto-rotate left (e.g. for rotating lcds), based on original orientation */
	if( /*config_autorol*/0 && ( drivers[ game_index ]->flags & ORIENTATION_SWAP_XY ) )
	{
		/* if only one of the components is inverted, switch them */
		if( ( orientation & ROT180 ) == ORIENTATION_FLIP_X ||
			( orientation & ROT180 ) == ORIENTATION_FLIP_Y )
		{
			orientation ^= ROT180;
		}
		orientation ^= ROT270;
	}
#endif
	/* flip X/Y */
	//if( config_flipx ){		orientation ^= ORIENTATION_FLIP_X;	}
	//if( config_flipy ){		orientation ^= ORIENTATION_FLIP_Y;	}

	video_flipx = ( ( orientation & ORIENTATION_FLIP_X ) != 0 );
	video_flipy = ( ( orientation & ORIENTATION_FLIP_Y ) != 0 );
	video_swapxy = ( ( orientation & ORIENTATION_SWAP_XY ) != 0 );

//	if( ( stricmp( s_scanlines, "yes" ) == 0 && !video_swapxy ) ||
//		stricmp( s_scanlines, "horizontal" ) == 0 )
//	{
//		hscanlines = 1;
//		vscanlines = 0;
//	}
//	else if( ( stricmp( s_scanlines, "yes" ) == 0 && video_swapxy ) ||
//		stricmp( s_scanlines, "vertical" ) == 0 )
//	{
//		hscanlines = 0;
//		vscanlines = 1;
//	}
//	else
//	{
//		hscanlines = 0;
//		vscanlines = 0;
//	}

//	if( video_swapxy )
//	{
//		int temp;
//		temp = options.vector_width;
//		options.vector_width = options.vector_height;
//		options.vector_height = temp;
//	}

	/* process sound options */
//	if( options.samplerate <  5512 ){		options.samplerate =  5512;	}
//	if( options.samplerate > 44100 ){		options.samplerate = 44100;	}
	/* no sound is indicated by a 0 samplerate */
//	if (!enable_sound)				{		options.samplerate =     0;	}
//	if( setting.sound_ON_OFF == 0)	{		options.samplerate =     0;	}

//	if( attenuation < -32 )	{		attenuation = -32;	}
//	if( attenuation > 0 )	{		attenuation = 0;	}

	/* process input configuration */
//	joystick = -2; /* default to invalid value */
//	if (joystick == -2)
//	{
//		logerror("%s is not a valid entry for a joystick\n", joyname);
//		joystick = JOY_TYPE_NONE;
//		joystick = 0;
//	}

	#if (1==LINK_BIOS)
	options.bios = malloc( strlen( s_bios ) + 1 );
	strcpy( options.bios, s_bios );
	#endif //(1==LINK_BIOS)

	/* process misc configuration */
//	cheatfile = malloc( strlen( s_cheatfile ) + 1 );
//	strcpy( cheatfile, s_cheatfile );
//	logerror("cheatfile = %s - cheatdir = %s\n",cheatfile,cheatdir);
}
#if 00
/*
 * Penalty string compare, the result _should_ be a measure on
 * how "close" two strings ressemble each other.
 * The implementation is way too simple, but it sort of suits the
 * purpose.
 * This used to be called fuzzy matching, but there's no randomness
 * involved and it is in fact a penalty method.
 */
int penalty_compare (const char *s, const char *l)
{
	int gaps = 0;
	int match = 0;
	int last = 1;
	for (; *s && *l; l++)
	{
		if (*s == *l)													match = 1;
		else if (*s >= 'a' && *s <= 'z' && (*s - 'a') == (*l - 'A'))	match = 1;
		else if (*s >= 'A' && *s <= 'Z' && (*s - 'A') == (*l - 'a'))	match = 1;
		else
			match = 0;

		if (match)
			s++;

		if (match != last)
		{
			last = match;
			if (!match)
				gaps++;
		}
	}
	/* penalty if short string does not completely fit in */
	for (; *s; s++)
		gaps++;
	return gaps;
}
/*
 * We compare the game name given on the CLI against the long and
 * the short game names supported
 */
void show_approx_matches(void)
{
	struct { int penalty; int index; } topten[10];
	int i,j;
	int penalty; /* best fuzz factor so far */

	for (i = 0; i < 10; i++)
	{
		topten[i].penalty = 9999;
		topten[i].index = -1;
	}

	for (i = 0; (drivers[i] != 0); i++)
	{
		int tmp;

		penalty = penalty_compare (gamename, drivers[i]->description);
		tmp = penalty_compare (gamename, drivers[i]->name);
		if (tmp < penalty) penalty = tmp;

		/* eventually insert into table of approximate matches */
		for (j = 0; j < 10; j++)
		{
			if (penalty >= topten[j].penalty) break;
			if (j > 0)
			{
				topten[j-1].penalty = topten[j].penalty;
				topten[j-1].index = topten[j].index;
			}
			topten[j].index = i;
			topten[j].penalty = penalty;
		}
	}

	for (i = 9; i >= 0; i--)
	{
		if (topten[i].index != -1)
			osd_die( "%-10s%s\n", drivers[topten[i].index]->name, drivers[topten[i].index]->description);
	}
}
#endif


//============================================================
//	mame_set_to_options_samplerate
//============================================================

extern void sr_set(int snd_rate);//"src/sound/namco86"
void mame_set_to_options_samplerate(void)
{
	/* process sound options */
	sr_set(setting.sound_rate);

	if (0==setting.sound_rate)
	{
		options.samplerate =     0;
	}
	else
	{
		options.samplerate = 44100/(setting.sound_rate);
	}

//	switch(setting.sound_rate)
//	{
//	case SND_OFF:		options.samplerate =     0;		break;/* 44100=44100/1 */
//	case SND_44100:		options.samplerate = 44100;		break;/* 44100=44100/1 */
//	case SND_22050:		options.samplerate = 22050;		break;/* 22050=44100/2 */
//	case SND_14700:		options.samplerate = 14700;		break;/* 14700=44100/3 */
//	case SND_11025:		options.samplerate = 11025;		break;/* 11025=44100/4 */
//	case SND_08820:		options.samplerate =  8820;		break;/*  8820=44100/5 */
//	case SND_07350:		options.samplerate =  7350;		break;/*  7350=44100/6 */
//	case SND_06300:		options.samplerate =  6300;		break;/*  6300=44100/7 */
//	case SND_05512:		options.samplerate =  5512;		break;/*  5512=44100/8 */
//	}
//	if (options.samplerate <     0) options.samplerate =     0;
//	if (options.samplerate > 44100) options.samplerate = 44100;
}


//============================================================
//	cli_frontend_init
//============================================================

int cli_frontend_init( int argc, char **argv )
{
///*static*/ char *gamename;
	char *gamename = argv[1];
	int i;
	int game_index;

	mame_argc = argc;
	mame_argv = argv;

//	gamename = NULL;
	game_index = -1;

	/* clear all core options */
	memset(&options,0,sizeof(options));

	/* these are not available in mame.cfg */
	//0 ignorecfg = 0;
	//0 createconfig = 0;
//	showusage = 0;
//	logfile = 0;
//	playbackname = NULL;
//	recordname = NULL;

#if 0
	for( i = 1; i < argc; i++ )
	{
		if//( argv[ i ][ 0 ] != '-')
			( gamename == NULL )
		{	gamename = argv[ i ];		}
//		else if( stricmp( argv[ i ], "-ignorecfg" ) == 0 )
//		{	ignorecfg = 1;	}
//		else if( stricmp( argv[ i ], "-createconfig" ) == 0 || stricmp( argv[ i ], "-cc" ) == 0 )
//		{	createconfig = 1;	}
//		else if( stricmp( argv[ i ], "-showusage" ) == 0 || stricmp( argv[ i ], "-su" ) == 0 )
//		{	showusage = 1;	}
//		else if( stricmp( argv[ i ], "-log" ) == 0 )
//		{	errorlog = 1;	}
	}
#endif

//#if (1==PSP_USE_SYS_LOG)
	if (errorlog)
	{
		logfile = fopen(s_errorlog, "w"/*"wa"*/);
		if (logfile == NULL)
		{
			psp_printf_bbb("failed to open '%s'\n", s_errorlog);
		}
		curlogsize = 0;
	}
//#endif // (1==PSP_USE_SYS_LOG)

//	if (showusage)
//	{
//		char *cmd_name;
//		struct rc_struct *rc;
//		cmd_name = dos_strip_extension(dos_basename(argv[0]));
//		if (!cmd_name)
//		{
//			osd_die( "who am I? cannot determine the name I was called with\n");
//			return -1;
//		}
//		fprintf(stdout, "Usage: %s [game] [options]\n" "Options:\n", cmd_name);
//		if (!(rc = rc_create()))
//		{
//			osd_die( "error on rc creation\n");
//			return -1;
//		}
//		if (rc_register(rc, config_opts))
//		{
//			osd_die( "error on registering opts\n");
//			return -1;
//		}
//		/* actual help message */
//		rc_print_help(rc, stdout);
//		return -1;
//	}

	//set_config_file( CONFIG_FILE );

	//if( 0 createconfig )
	//{
	//	game_index = 0;
	//}
	//else
	{
		get_fileio_opts();
		get_rc_opts( frontend_opts );

		/* since the cpuintrf structure is filled dynamically now, we have to init first */
		cpuintrf_init();
		#ifndef PSP_DIRECT_STREAM
		/* ???p?T?E???h???????????????D */
		sndintrf_init();
		#endif // PSP_DIRECT_STREAM
	}

	rompath_extra = dos_dirname( gamename );

	if( rompath_extra && strlen( rompath_extra ) == 0 )
	{
		free( rompath_extra );
		rompath_extra = NULL;
	}

	gamename = dos_basename( gamename );
	gamename = dos_strip_extension( gamename );

	/* If not playing back a new .inp file */
	if( game_index == -1 )
	{
		i = 0;
		while( drivers[ i ] != NULL )
		{
			if( stricmp( gamename, drivers[i]->name ) == 0 )
			{
				game_index = i;
				break;
			}
			i++;
		}
	}
//#ifdef MAME_DEBUG
//	if (game_index == -1)
//	{
//		/* pick a random game */
//		if (stricmp(gamename,"random") == 0)
//		{
//			struct timeval t;
//			i = 0;
//			while (drivers[i]) i++;	/* count available drivers */
//			gettimeofday(&t,0);
//			srand(t.tv_sec);
//			game_index = rand() % i;
//			printf("Running %s (%s) [press return]\n",drivers[game_index]->name,drivers[game_index]->description);
//			getchar();
//		}
//	}
//#endif
	/* we give up. print a few approximate matches */
	if (game_index == -1)
	{
	//	osd_die( "\n\"%s\" approximately matches the following\n"
	//			"supported games (best match first):\n\n", gamename);
	//	show_approx_matches();
		return -1;
	}

//	sprintf( srcfile, "%s", &drivers[ game_index ]->source_file[ 12 ] );
//	srcfile[ strlen( srcfile ) - 2 ] = 0;

	/* parse generic (os-independent) options */
	parse_cmdline( argc, argv, game_index );


//////////

	/* process sound options */
#if 00
	options.samplerate = 11025 << (2 - setting.sound_rate);
	if (options.samplerate < 11025) options.samplerate = 11025;
	if (options.samplerate > 44100) options.samplerate = 44100;
#else
	mame_set_to_options_samplerate();
#endif
	/* no sound is indicated by a 0 samplerate */
//	if (!setting.sound_ON_OFF) options.samplerate = 0;
	if (SND_OFF==setting.sound_rate) options.samplerate = 0;

/////////


	//if( 0 createconfig )
	//{
	//	return -1;
	//}
	return game_index;
}

//============================================================
//	cli_frontend_exit
//============================================================

void cli_frontend_exit(void)
{
//	if (options.playback)		mame_fclose (options.playback);
//	if (options.record)			mame_fclose (options.record);
//	if (options.language_file)	mame_fclose (options.language_file);
//#if (1==PSP_USE_SYS_LOG)
	/* close open files */
	if (logfile)
	{
		fclose(logfile);
		logfile = NULL;
	}
//#endif //(1==PSP_USE_SYS_LOG)
}


//============================================================
//	logerror
//============================================================
//#if (1==PSP_USE_SYS_LOG)
void CLIB_DECL logerror(const char *text, ...)
{
	va_list arg;
	va_start(arg,text);

	if (errorlog)
	{
		if (logfile)
		{
			curlogsize += vfprintf(logfile, text, arg);
			if (maxlogsize > 0)
			{
				if (curlogsize > maxlogsize * 1024)
				{
					osd_close_display();
					osd_exit();
					cli_frontend_exit();
					sceKernelExitGame();
					//exit(1);
				}
			}
			if (b_flusherrorlog)
			{
				fflush(logfile);
			}
			if (b_closeerrorlog)
			{
				fclose(logfile);
				logfile = fopen(s_errorlog, "a");
			}
		}
	}
	va_end(arg);
}
//#endif

//============================================================
//	osd_printf
//============================================================

void CLIB_DECL osd_printf(const char *text, ...)
{
	char buf[128];

	va_list va;
	va_start(va, text);
	vsprintf(buf, text, va);
	va_end(va);

	psp_printf_bbb(buf);
	Confirm_Control();
}

#if 0
//============================================================
//	osd_die
//============================================================

void CLIB_DECL osd_die(const char *text, ... )
{
	char buf[128];

	va_list va;
	va_start(va, text);
	vsprintf(buf, text, va);
	va_end(va);

	psp_printf_bbb(buf);
	Confirm_Control();

	sceKernelExitGame();
	//exit(1);
}
#endif

//============================================================
//	dos_basename
//============================================================

static char *dos_basename(char *filename)
{
	char *c;

	// NULL begets NULL
	if (!filename)
		return NULL;

	// start at the end and return when we hit a slash or colon
	for (c = filename + strlen(filename) - 1; c >= filename; c--)
		if (*c == '\\' || *c == '/' || *c == ':')
			return c + 1;

	// otherwise, return the whole thing
	return filename;
}



//============================================================
//	dos_dirname
//============================================================

static char *dos_dirname(char *filename)
{
	char *s_dirname;
	char *c;

	// NULL begets NULL
	if (!filename)
		return NULL;

	// allocate space for it
	s_dirname = malloc(strlen(filename) + 1);
	if (!s_dirname)
	{
		osd_die( "error: malloc failed in dos_dirname\n");
		return NULL;
	}

	// copy in the name
	strcpy(s_dirname, filename);

	// search backward for a slash or a colon
	for (c = s_dirname + strlen(s_dirname) - 1; c >= s_dirname; c--)
		if (*c == '\\' || *c == '/' || *c == ':')
		{
			// found it: NULL terminate and return
			*(c + 1) = 0;
			return s_dirname;
		}

	// otherwise, return an empty string
	s_dirname[0] = 0;
	return s_dirname;
}



//============================================================
//	dos_strip_extension
//============================================================

static char *dos_strip_extension(char *filename)
{
	char *newname;
	char *c;

	// NULL begets NULL
	if (!filename)
		return NULL;

	// allocate space for it
	newname = malloc(strlen(filename) + 1);
	if (!newname)
	{
		osd_die( "error: malloc failed in osd_newname\n");
		return NULL;
	}

	// copy in the name
	strcpy(newname, filename);

	// search backward for a period, failing if we hit a slash or a colon
	for (c = newname + strlen(newname) - 1; c >= newname; c--)
	{
		// if we hit a period, NULL terminate and break
		if (*c == '.')
		{
			*c = 0;
			break;
		}

		// if we hit a slash or colon just stop
		if (*c == '\\' || *c == '/' || *c == ':')
			break;
	}

	return newname;
}
