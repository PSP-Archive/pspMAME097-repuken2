

#MY_NAME =""

#include $(SRC)/$(OSD)_sound/_psp_sound.mak

# only PSP specific output files and rules
OSOBJS = \
$(OBJ)/psp/psp.o $(OBJ)/psp/video.o $(OBJ)/psp/blit.o \
	$(OBJ)/psp/sound.o $(OBJ)/psp/input.o $(OBJ)/psp/rc.o $(OBJ)/psp/misc.o \
	$(OBJ)/psp/ticker.o $(OBJ)/psp/config.o $(OBJ)/psp/fronthlp.o \
	$(OBJ)/psp/fileio.o $(OBJ)/psp/debugwin.o \
	$(OBJ)/psp/syscalls.o \
        $(OBJ)/psp/pg.o $(OBJ)/psp/pspmain.o $(OBJ)/psp/menu.o \
	$(OBJ)/psp/y_malloc.o \
	$(OBJ)/psp/v_malloc.o \
	$(OBJ)/psp/debugPsp.o \


#	psp_font��blit��Z���B   $(OBJ)/psp/blit.o 

#	$(OBJ)/psp/y_malloc.o 
#	$(OBJ)/psp/v_malloc.o 
#	$(OBJ)/psp/rc.o 
##$(OBJ)/psp/misc.o 
#$(OBJ)/psp/debugwin.o 
#$(OBJ)/psp/fronthlp.o 
#	$(OBJ)/psp/malloc.o 
#	$(OBJ)/psp/y_malloc.o 
#	$(OBJ)/psp/malloc.o 
#	$(OBJ)/psp/v_malloc.o 
#	$(OBJ)/psp/fpgnulib.o 

#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------

##MD = -mkdir.exe
##MD = mkdir -p
#MD = mkdir
##RM = rm -rd
#RM = rm -f

ifeq ($(PSPDEV),)
MD = -mkdir
RM = -rm
else
MD = -mkdir.exe
RM = -rm.exe
endif

#------------------------------------------------------------------------------
# PSPSDK settings
#------------------------------------------------------------------------------

## [��p icon�w��]�̏ꍇ
ifneq ($(filter ICON,$(PSP_EXTENSION_OPTS)),)
	PSP_EBOOT_ICON = icon/$(TARGET).png
endif

## �^�C�g���������ꍇ�ɐݒ�
ifeq ($(PSP_EBOOT_TITLE),)
PSP_EBOOT_TITLE = "MAME 0.97 $(TARGET)"
endif

## �A�C�R���������ꍇ�ɕW����ݒ�
ifeq ($(PSP_EBOOT_ICON),)
PSP_EBOOT_ICON = icon/icon0.png
endif


## �z�z�\�[�X(zip size)���傫���Ȃ肷����̂ŁA�b��I�ɃA�C�R������
#PSP_EBOOT_ICON = icon/icon0.png

EXTRA_TARGETS = maked_directry EBOOT.PBP copy_bak_pbp
EXTRA_CLEAN = pspclean


#------------------------------------------------------------------------------
# Configurations
#------------------------------------------------------------------------------

#SPRITE_OLD = 1

#���J�[�l�����[�h�ɂ������Ȃ�#���O���ăR���p�C�����ĂˁB
#KERNEL_MODE = 1


ifdef KERNEL_MODE
CDEFS += -DKERNEL_MODE=1
endif

#------------------------------------------------------------------------------
# Library
#------------------------------------------------------------------------------

USE_PSPSDK_LIBC = 1

LIBS = -lm -lc -lpspaudio -lpspgu -lpsppower -lpsprtc -losl

