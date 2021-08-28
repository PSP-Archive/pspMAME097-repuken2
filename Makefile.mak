###########################################################################
#
#   PSPMAME Makefile
#
#   Core makefile for building MAME and derivatives
#
#   Copyright (c) 1996-2007, Nicola Salmoria and the MAME Team.
#   Visit http://mamedev.org for licensing and usage restrictions.
#
###########################################################################


#PSP SLIM STUFF -repuken2-

PSP_LARGE_MEMORY = 1
BUILD_PRX = 1

# set this to mame, mess or the destination you want to build.



#################
# ���Ԃ񓮂�(?)����
#################

#---- TAITO ����

#TARGET = ninjya_warriors
#TARGET = darius
#TARGET = taitoB
#TARGET = taitoAX
#TARGET = halleys

#TARGET = night_striker
	# GFX(psp�̃�����)������Ȃ��̂Ŗ������\���B��ʂ��o�O��B

#---- namco ����

#TARGET = namcoNA
#TARGET = mappy
#TARGET = pacman
	# ���Fpengo �� �Z�K ������ �i���R�����B

#TARGET = namcos86
	# namcos86 : mame�ł� �x���̂ŁA�����܂Ŏ����p�BNJ���̐�p�Ŏg�����B
	# ���Fmame�ł̎����F������b�o�t���̌݊������ؗp�r�B

#---- UPL/capcom ���� (UVC : UPL vs CAPCOM)

#TARGET = ninjya_kun2

#---- capcom ����

#TARGET = street_fighter
#TARGET = makai_mura
#TARGET = gun_smoke

#---- SEGA ����

#TARGET = turbo_outrun
#TARGET = fantasy_zone
	#fantasy_zone ok[20070124]
	#fantasy_zone ng[20070206]�I���ł��Ȃ�

#---- IREM ����

#TARGET = m72
	#��ptilemap��蒼���Ȃ��ƃo�O��BCPU���s����B

#---- TOUA ����
#TARGET = zerowing
#TARGET = raizing
	#raizing ok[20070124]

#---- NMK����
#TARGET = nmk

#---- SETA ����

#TARGET = seta

#---- Nichibutu ����

#TARGET = terracre
	#terracre ng[20070323](YM3526_ng psg_ok)
	#terracre ok[20070617]�h���C�o(src/drivers/terracre.c)(ym3526_info11)�̃o�O��FA.
#TARGET = crazy_climber

#---- konami ����

#TARGET = ajax
#############NEW MAKES!!!

#TARGET = konami2
TARGET = konami3

#TARGET = thunder_cross
	#thunder_cross ok[20070319](�ł���2151(test c)�I�J�V�C)
#TARGET = bubblesys
	#bubblesys ng[20070206]
	#bubblesys ok[20070621](�ł������~�L�V���O��)

#TARGET = circus_charlie

#---- kaneko ����

#TARGET = air_buster
	#air_buster ok[20070203](z80s2)

#---- DECO ����

#TARGET = darwin4078
	#darwin4078 ok[20070619]

#---- tecmo/tehkan ����

#TARGET = starforce

#---- nintendo ����

#TARGET = mario_bros

#---- UNIVERSAL ����

#TARGET = mr_do

#---- SNK ����

#TARGET = aso



#################��������ς���̂ł����B


#################
# �ꉞ�������A�i������b�o�t���́j�������ړI�Ȃ���
#################

#---- TAITO ����

#TARGET = qix
	# qix : (���Fdiscrete�����A�����p) �ƂĂ��Ȃ��x�����āA
	# �i�p�����[�^�[��\�߃Z�b�g���ĕʂɃ����_�����O�Ƃ��j�������@�ς��Ȃ�����A
	# ������p���͂Ȃ��B


#---- DECO ����

#TARGET = battlera
	# battlera : (���FHuC6280�����p) (HuC6280������)�x�����Č�����p���͂Ȃ��B


#################
# ���������J���i�C(���Ԃ񓮂��Ȃ�)����
#################

#################
#TARGET = darius2_dual
#TARGET = block_block

#################���߂��B

#---- TAITO ����

#TARGET = full_throttle
#TARGET = chuuka_taisen

#TARGET = syvalion

#TARGET = taitoF1
#TARGET = metal_black
#TARGET = taitoF2
#TARGET = darius2d
#TARGET = nightstr
#TARGET = taitoZ
#TARGET = taitoA2
#TARGET = taito2

#---- namco ����

#TARGET = pacland
	#pacland ng[20070205]
	#pacland ng[20070319]
	# pacland : ���s���낵��������[20070915]�����Ȃ��B�����s���B
	#�\�[�X�͐F�X�ς���(���������Ɩ߂�����)�̂Ő̂̕���舫���B

#TARGET = namcos1	# �N�����Ȃ��B

#---- SEGA ����

#TARGET = space_harrier	# ���x�B
#TARGET = cotton

#---- konami ����
#TARGET = gaia_police

#---- TOUA ����
#TARGET = slapfight	# �N�����Ȃ��B

#---- DECO ����
#TARGET = srd08
#TARGET = deco16
#TARGET = kuga
	# kuga : �N�����Ȃ��B
#TARGET = the_great_ragtime_show
	# decoic16 ���G����...orz

#---- sega ����
#TARGET = sys16	# �N�����Ȃ��B

#---- JALECO ����
#TARGET = megasys1	# ���x�B�o�O��B�s����B

#---- tecnos ����
#TARGET = ddragon	# ���x�B�o�O��B�s����B

#---- capcom ����
# black draon �� tilemap �g������u������������Ȃ���PSP�ŋN���ł��Ȃ��v�ł��B
#TARGET = black_dragon	# �N�����Ȃ��B

#---- SEIBU ����
#TARGET = raiden	# �N�����Ȃ��B


#------------------------------------------------------------------------------
# Auto Adjusts
#------------------------------------------------------------------------------

#TARGET = mame
#TARGET = mess
# example for a tiny compile
#TARGET = tiny
ifeq ($(TARGET),)
TARGET = mame
endif

# customize option
OPT_DEFS = -D$(TARGET)=1


#------------------------------------------------------------------------------
# Configurations
#------------------------------------------------------------------------------

# ���FOSD�͏����Ή��������C������P�h �܂�����ĂȂ��ł��Bpsp�ȊO�̓R���p�C���o���܂���B
# set this the operating system you're building for. ... but now only "psp".
  OSD = psp
# OSD = msdos
# OSD = windows

# psp     for PSPSDK 4.0.2 'http://www.xorloser.com/PSPDevWin32.zip (2nd December 2006)'
# windows for MINGW  3.2.0 'http://www.mame.net/zips/mingw-mame-20070617.exe' 'http://www.mame.net/zips/dx80_mgw.zip'
# msdos   for DJGPP  3.2.1

ifndef OSD
OSD = windows
endif

ifndef TARGETOS
ifeq ($(OSD),windows)
TARGETOS = win32
else
TARGETOS = psp
endif
endif

OPT_DEFS += -D$(OSD)=1



NAME = $(TARGET)$(TARGETOS)

# build the targets in different object dirs, since mess changes
# some structures and thus they can't be linked against each other.

SRC = src
OBJ = obj/$(NAME)

OBJ_CPU     = $(OBJ)/cpu
OBJ_AUDIO   = $(OBJ)/audio
OBJ_SOUND   = $(OBJ)/sound
OBJ_DRIVERS = $(OBJ)/drivers
OBJ_MACHINE = $(OBJ)/machine
#OBJ_VIDEO   = $(OBJ)/video
OBJ_VIDEO   = $(OBJ)/vidhrdw

# CPU core include paths
#VPATH=src $(wildcard $(SRC)/cpu/*)

# uncomment next line to use the new multiwindow debugger
#NEW_DEBUGGER = 1 # �p�~


#------------------------------------------------------------------------------
# Compiler Defines
#------------------------------------------------------------------------------

CDEFS = \
	-DLSB_FIRST \
	-DINLINE="static __inline__" \
	-DPI=M_PI 

#	-DCRLF=3 # �p�~
#	-DPSP=1  # �ʂŐݒ�
#	-DCLOCKS_PER_SEC=1000000 # �p�~
#	-include psp/psp_main.h  # �ʂŐݒ�

#ifdef NEW_DEBUGGER
#CDEFS += -DNEW_DEBUGGER # �p�~
#endif


#------------------------------------------------------------------------------
# Compiler Flags
#------------------------------------------------------------------------------

#PSPSDK_HEADER_FIX_WARNING =1
ifdef PSPSDK_HEADER_FIX_WARNING
CFLAGS = -Wstrict-prototypes
else
CFLAGS = 
endif

CFLAGS += \
	-fomit-frame-pointer \
	-fno-strict-aliasing \
	-Wno-sign-compare \
	-Wunused \
	-Wpointer-arith \
	-Wundef \
	-Wformat \
	-Wwrite-strings \
	-Wdisabled-optimization \
	-Wbad-function-cast

#	-std=gnu99 
#	-G0 

# extra options needed *only* for the osd files
#CFLAGSOSDEPEND = $(CFLAGS)

# the windows osd code at least cannot be compiled with -pedantic
#CFLAGSPEDANTIC = $(CFLAGS) -pedantic


#------------------------------------------------------------------------------
# File include path
#------------------------------------------------------------------------------

INCDIR = \
	$(SRC) \
	$(SRC)/includes \
	$(SRC)/debug \
	$(SRC)/$(OSD) \
	$(SRC)/zlib


#------------------------------------------------------------------------------
# Linker Flags
#------------------------------------------------------------------------------

LIBDIR =
#LDFLAGS = -s
LDFLAGS      = -losl -lpspgum_vfpu -lpspvfpu
#LDFLAGS      = -L$(PSPDEV)/lib -lstdc++ -lSDL_mixer -lSDL -lSDL_gfx -lm -lGL -lvorbisidec
#LDFLAGS     += -L$(PSPSDK)/lib -lpspvfpu -lpspdebug -lpspgu -lpspctrl -lpspge -lpspdisplay -lpsphprm -lpspsdk -lpsprtc -lpspaudio -lc -lpspuser -lpsputility -lpspkernel -lpspnet_inet -lpsppower 



#------------------------------------------------------------------------------
# Library
#------------------------------------------------------------------------------

ZLIB = $(OBJ)/libz.a


#------------------------------------------------------------------------------
# Include Make Files
#------------------------------------------------------------------------------

CPUOBJS   = 
SOUNDOBJS = $(OBJ)/sndintrf.o $(OBJ_SOUND)/streams.o $(OBJ)/sound/flt_vol.o $(OBJ)/sound/flt_rc.o \

# windows/dos extra include. 'make all' only, need it at first ???. 
# windows �� dos �� gcc(ming)�� make.exe(3.X.X. ??) �� 'make all' �̋@�\�����S�Ŗ����~�^�C�B(_$(OSD).mak�ɏ����Ă�����)
# �����炱���̏ꏊ�ɕK�v�B
ifeq ($(OSD),msdos)
all:	maked_directry $(EXTRA_TARGETS)
endif
ifeq ($(OSD),windows)
all:	maked_directry $(EXTRA_TARGETS)
endif

# include the various .mak files
include ./makes/$(TARGET).mak
include $(SRC)/_cpu.mak
include $(SRC)/_sound.mak
include $(SRC)/_emu.mak
include $(SRC)/$(OSD)/_$(OSD).mak

#------------------------------------------------------------------------------
# Object Directory
#------------------------------------------------------------------------------

OBJDIRS += \
	obj \
	$(OBJ) \
	$(OBJ)/$(OSD) \
	$(OBJ_CPU) \
	$(OBJ_AUDIO) \
	$(OBJ_SOUND) \
	$(OBJ_DRIVERS) \
	$(OBJ_MACHINE) \
	$(OBJ_VIDEO) \
	$(OBJ)/etc \
	$(OBJ)/zlib \
	pbp \
	pbp/$(TARGET)


CDEFS += $(CPUDEFS) $(SOUNDDEFS) $(COREDEFS) $(DRVDEFS) $(OPT_DEFS)
OBJS  += $(CPUOBJS) $(SOUNDOBJS) $(COREOBJS) $(DRVLIBS) $(OSOBJS) $(ZLIB)

# $(OBJ)/tiny.o
#	$(sort $(CPUOBJS)) 
#	$(sort $(SOUNDOBJS)) 


#------------------------------------------------------------------------------
# Include build.mak for PSPSDK
#------------------------------------------------------------------------------

# ���F ������  pspsdk �̓s����A�u��v�ɃC���N���[�h�B

ifeq ($(OSD),psp)
USE_MY_PSPSDK = 1
ifdef USE_MY_PSPSDK
	PSPSDK=$(shell psp-config --pspsdk-path)
	include $(PSPSDK)/lib/build.mak
#else
	# �unjemu_source_20070223 �݊��v + �uEBOOT.PBP ���s���k �Ή��v
#	include $(SRC)/$(OSD)/_build.mak
#endif
else
	include $(SRC)/$(OSD)/_win_build.mak
endif
endif

#------------------------------------------------------------------------------
# Make Rules
#------------------------------------------------------------------------------

$(OBJ)/libz.a: \
	$(OBJ)/zlib/adler32.o \
	$(OBJ)/zlib/crc32.o \
	$(OBJ)/zlib/inflate.o \
	$(OBJ)/zlib/inftrees.o \
	$(OBJ)/zlib/inffast.o \
	$(OBJ)/zlib/zutil.o

#	$(OBJ)/zlib/trees.o 
#	$(OBJ)/zlib/compress.o 
#	$(OBJ)/zlib/deflate.o 

#	$(OBJ)/zlib/gzio.o 
#	$(OBJ)/zlib/infback.o 
#	$(OBJ)/zlib/uncompr.o 

# zlib only sized optimized (-O1)
$(OBJ)/zlib/%.o: $(SRC)/zlib/%.c
	@echo Compiling Zlib $<...
	@$(CC) $(CDEFS) -O1 $(CFLAGS) -c $< -o $@

# speed optimized (-O3)
$(OBJ)/%.o: $(SRC)/%.c
	@echo Compiling $<...
	@$(CC) $(CDEFS) -O3 $(CFLAGS) -c $< -o $@

$(OBJ)/%.a:
	@echo Archiving $@...
	@$(AR) -r $@ $^

# �ȉ��Q�s�� �s�v �A����Ă��\��Ȃ��B # �p�~
#$(sort $(OBJDIRS)):                   # �p�~
#	@$(MD) -p $(subst //,\,$@)         # �p�~
# �s�v �́A�����܂ŁB                  # �p�~

pspclean:
	@echo Remove all object files and directories.
	@$(RM) -f -rd $(OBJ)

#maketree:
#	@echo Making object tree...

# maketree $(sort $(OBJDIRS))


maked_directry:
	@echo Making object tree for $(TARGET) ...
	@$(MD) -p $(subst //,\,$(sort $(OBJDIRS)))
	@$(RM) -f PARAM.SFO

copy_bak_pbp: 
	@cp EBOOT.PBP pbp/$(TARGET)
	@ls -l EBOOT.PBP

## re-make the M68000
68:
	@echo Delete M68000 object ...
	@$(RM) -f $(OBJ)/cpu/m68000/*.o
	@$(RM) -f $(OBJ)/cpu/n68000/*.o
	@$(RM) -f $(OBJ)/cpu/na68000/*.o
	@$(RM) -f $(OBJ)/cpu/nb68000/*.o
	@$(RM) -f $(OBJ)/cpu/da68000/*.o

## re-make the src/cpuint.o for adjust IRQ_LINE
int:
	@echo Delete intrrupt object ...
	@$(RM) -f $(OBJ)/cpuint.o

## re-make the src/tiny.o for makes/game_name.mak
tiny:
	@echo Delete the tiny base file object ...
	@$(RM) -f $(OBJ)/tiny.o

## re-make the font. (src/psp/psp_data.o)
font:
	@echo Delete font object ...
	@$(RM) -f $(OBJ)/psp/psp_data.o

## re-make the tilemap. (src/tilemap00.o)
tile:
	@echo Delete mame tilemap system object ...
	@$(RM) -f $(OBJ)/tilemap00.o

## re-make the psp_sound. (src/psp/psp_sound.o)
sound:
	@echo Delete sound interface object ...
	@$(RM) -f $(OBJ)/psp/psp_menu.o
	@$(RM) -f $(OBJ)/psp/psp_sound.o
	@$(RM) -f $(OBJ)/psp/osd_config.o
	@$(RM) -f $(OBJ)/mame.o
	@$(RM) -f $(OBJ)/drivers/*.o
	@$(RM) -f $(OBJ)/psp_sound/*.o

delpbp:
	@echo Delete all pbp tree ...
	@$(RM) -f -rd pbp


ifeq ($(OSD),windows)
#DELTREE = deltree /Y obj     # �p�~
#DELTREE = $(RM) -f -r $(OBJ) # �p�~
DELTREE = $(RM) -f -r obj
endif

ifeq ($(OSD),msdos)
DELTREE = deltree /Y obj
endif

ifeq ($(OSD),psp)
DELTREE = @$(RM) -f -rd obj
endif

rr:
	@echo Remove all temporaly files.
	@$(RM) -f PARAM.SFO
	@$(RM) -f *.elf
	@$(DELTREE)

lse:
	ls -al *.PBP

