
#-------------------------------------------------
# customizing sound set
#-------------------------------------------------



#ifeq ($(TARGET),ARIENAI)

	# ��p�T�E���h�̏ꍇ�A�f�B���N�g���[��ǉ��B
	OBJDIRS += $(OBJ)/psp_sound 

## direct stream ����


	ifeq ($(TARGET),namcos86)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_namcos86.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=0
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

	# ���x���x���J��
	ifeq ($(TARGET),turbo_outrun)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_outrun.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

	# ������������Ȃ��J��
#	ifeq ($(TARGET),cotton)
#	SOUNDOBJS = $(OBJ)/psp_sound/sound_cotton.o
#	OPT_DEFS += -DPSP_DIRECT_STREAM=1
#	OPT_DEFS += -DLINK_MAME_SOUND=0
#	endif

	# �i���g�i�N
	ifeq ($(TARGET),fantasy_zone)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_outrun.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

	# ���x���x���J��
	ifeq ($(TARGET),taitoB)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_2610_8MHz.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

	# ���x���x���J��
	ifeq ($(TARGET),night_striker)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_2610_8MHz.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

# ��(ADPCM)����������
	# ���x���x���J��
	ifeq ($(TARGET),ninjya_warriors)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_2610_8MHz.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

#	# ���x���x���J��
#	ifeq ($(TARGET),zerowing)
#	SOUNDOBJS = $(OBJ)/psp_sound/sound_3526_3812_4MHz.o
#	OPT_DEFS += -DPSP_DIRECT_STREAM=1
#	OPT_DEFS += -DLINK_MAME_SOUND=0
#	endif

	# �i���g�i�N
	ifeq ($(TARGET),namcoNA)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_NA.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

	# �i���g�i�N
	ifeq ($(TARGET),ajax)
	SOUNDOBJS = $(OBJ)/psp_sound/sound_a_jax.o
	OPT_DEFS += -DPSP_DIRECT_STREAM=1
	OPT_DEFS += -DLINK_MAME_SOUND=1
	OPT_DEFS += -DLINK_MAME_SPEAKER=0
	endif

#����(����ĂȂ�)
#	# �T�C�h�A�[�� �s����̈�
#	ifeq ($(TARGET),ninjya_kun2)
#	SOUNDOBJS = $(OBJ)/psp_sound/sound_ninjya_kun2.o
#	OPT_DEFS += -DPSP_DIRECT_STREAM=1
#	OPT_DEFS += -DLINK_MAME_SOUND=1
#	OPT_DEFS += -DLINK_MAME_SPEAKER=0
#	endif


#endif
