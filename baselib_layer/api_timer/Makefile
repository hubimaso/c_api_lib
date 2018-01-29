release = no
cover   = no
ut = no
#默认debian
os      = centos

CC  = gcc
CPP = g++
LD  = ld
AR  = ar

#第三方库
THIRD_DIR = ../../thirdlib_layer


#内部依赖头文件
INCS       =  -I./public -I./private

#外部依赖头文件
#INCS      += -I $(THIRD_DIR)/libcli/inc


#外部依赖库
LIBS      += -lpthread

CSRC_DIR   = ./source
BUILD_DIR  = ./build

#libsrc,src及其子目录下的所有.c文件
CSRCS   = $(wildcard $(CSRC_DIR)/*.c) 

#所有的.o文件列表
BUILD   := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(CSRCS)))

#
CFLAGS   += $(INCS)

ifeq ($(release), no)
CFLAGS   += -Wall -Werror -g  -fPIC -mcmodel=medium
else
CFLAGS   += -Wall -Werror -O3 -fPIC 
endif


ifeq ($(cover),yes)
CFLAGS   += -DCOVER -fprofile-arcs -ftest-coverage
LIBS     += -lgcov
endif

TARGET_LIB = $(BUILD_DIR)/libapi_timer.a

all : chkobjdir $(TARGET_LIB) #$(TARGET_BIN)

chkobjdir:
	@if test ! -d $(BUILD_DIR); \
	then \
		mkdir $(BUILD_DIR);\
	fi

$(BUILD_DIR)/%.o:$(CSRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET_LIB) : $(BUILD)
	@echo "AR $(TARGET_LIB)"
	@$(AR) cr $(TARGET_LIB) $(BUILD)

#$(TARGET_BIN) : $(BUILD)
#	@echo "LINK $(TARGET_BIN)"
#	@$(CC) -o $(TARGET_BIN)  $^ $(LIBS)

.PHONY:clean 

clean:
	@echo "CLEAN LIBAPI_TIMER DONE"
	@rm -rf $(BUILD)
	@rm -rf $(BUILD_DIR)
