#BINPATH=~/sat/bin

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###################################################

# Check for valid float argument
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

###################################################

vpath %.c real

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m4

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
else
CFLAGS += -msoft-float
endif

CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Ireal -Ipub
	
SRCS = mp3dec.c mp3tabs.c bitstream.c buffers.c dct32.c dequant.c dqchan.c
SRCS += huffman.c hufftabs.c imdct.c polyphase.c scalfact.c
SRCS += stproc.c subband.c trigtabs_fixpt.c

OBJS = $(SRCS:.c=.o)

.PHONY: libhelix.a

all: libhelix.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libhelix.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libhelix.a