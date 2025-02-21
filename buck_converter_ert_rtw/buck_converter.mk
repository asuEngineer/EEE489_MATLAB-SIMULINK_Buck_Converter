###########################################################################
## Makefile generated for component 'buck_converter'. 
## 
## Makefile     : buck_converter.mk
## Generated on : Fri Feb 21 13:25:15 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/buck_converter.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = buck_converter
MAKEFILE                  = buck_converter.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/burly/OneDrive/Desktop/matlab_buck_converter_EEE489
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
ARDUINO_RP2040_LIB_PATH   = C:/Users/burly/DOCUME~1/MATLAB/R2024b/ARDUIN~1/RASPBE~1/FASTER~1
SLIB_PATH                 = C:/Users/burly/DOCUME~1/MATLAB/R2024b/ARDUIN~2/RASPBE~1/FASTER~1
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Arduino ARM RP2040
# Supported Version(s):    
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PACKAGES_TOOLS_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU

#-----------
# MACROS
#-----------

SHELL                       = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_UF2                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).uf2
ARDUINO_TOOLS               = $(ARDUINO_RP2040_TOOLS_ROOT)/pqt-gcc/$(ARDUINO_RP2040_GCC_VERSION)/bin

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lcore  "C:\ProgramData\MATLAB\SupportPackages\R2024b\aCLI\data\packages\rp2040\hardware\rp2040\3.7.0\lib\ota.o" "C:\ProgramData\MATLAB\SupportPackages\R2024b\aCLI\data\packages\rp2040\hardware\rp2040\3.7.0\lib\libbearssl.a" "C:\Users\burly\DOCUME~1\MATLAB\R2024b\ARDUIN~1\RASPBE~1\FASTER~1\MW_libpico.a" "C:\Users\burly\DOCUME~1\MATLAB\R2024b\ARDUIN~1\RASPBE~1\FASTER~1\MW_libpicow-noipv6-nobtc-noble.a" -lm -lc -lstdc++ -lc -Wl,--end-group

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM RP2040 Assembler
AS_PATH = $(ARDUINO_TOOLS)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: Arduino ARM RP2040 C Compiler
CC_PATH = $(ARDUINO_TOOLS)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: Arduino ARM RP2040 Linker
LD_PATH = $(ARDUINO_TOOLS)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: Arduino ARM RP2040 C++ Compiler
CPP_PATH = $(ARDUINO_TOOLS)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: Arduino ARM RP2040 C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: Arduino ARM RP2040 Archiver
AR_PATH = $(ARDUINO_TOOLS)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPY_PATH = $(ARDUINO_TOOLS)
OBJCOPY = "$(OBJCOPY_PATH)/arm-none-eabi-objcopy"

# UF2 Converter: UF2 Converter
UF2CONVERTER_PATH = $(ARDUINO_RP2040_TOOLS_ROOT)/pqt-elf2uf2/$(ARDUINO_RP2040_GCC_VERSION)/
UF2CONVERTER = "$(UF2CONVERTER_PATH)/elf2uf2"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = rcs
ASFLAGS              = -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/pico-sdk/src/rp2040/hardware_regs/include/" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/pico-sdk/src/common/pico_binary_info/include"  $(ASFLAGS_ADDITIONAL) 
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -c -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040  -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -MMD "-iprefix$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/" "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_inc.txt" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/include" -std=gnu17 -g -pipe  \
                       -Os
CPPFLAGS             = -c -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040  -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -MMD "-iprefix$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/" "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_inc.txt" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/include" -fno-rtti -std=gnu++17 -g -pipe  \
                       -Os
CPP_LDFLAGS          =  -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_wrap.txt" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common "-Wl,--script=$(ARDUINO_TARGET_ROOT)/src/rp2040_memmap_default.ld" "-Wl,-Map,$(PRODUCT_NAME).map" -Wl,--no-warn-rwx-segments -Wl,--start-group 
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_wrap.txt" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common "-Wl,--script=$(ARDUINO_TARGET_ROOT)/src/rp2040_memmap_default.ld" "-Wl,-Map,$(PRODUCT_NAME).map" -Wl,--no-warn-rwx-segments -Wl,--start-group 
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =
OBJCOPYFLAGS_UF2     = $(PRODUCT) $(PRODUCT_UF2)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/buck_converter.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_ROOT)/toolbox/target/shared/svd/common/include -IC:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/include -I$(START_DIR)/buck_converter_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/cores/rp2040 -I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/cores/rp2040/sdkoverride -I$(VARIANT_HEADER_PATH) -IC:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/include -IC:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/scheduler/include -I$(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/include -I$(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/xcp/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -D_ARDUINO_RP2040_ALARM_1_ -DMW_ALARM_RESOLUTION=1000 -DMW_SCHEDULERCOUNTER=1 -DARDUINO_NUM_SERIAL_PORTS=3 -DARDUINO_SERIAL_RECEIVE_BUFFER_SIZE=64 -D_RTT_BAUDRATE_SERIAL0_=9600 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_BAUDRATE_SERIAL2_=9600 -D_RTT_CONFIG_SERIAL0_=SERIAL_8N1 -D_RTT_CONFIG_SERIAL1_=SERIAL_8N1 -D_RTT_CONFIG_SERIAL2_=SERIAL_8N1 -D_RTT_ANALOG_REF_=0 -DMW_NUM_PINS=26 -D_RTT_PWM_BLOCKS_ -DARDUINO_DEFAULT_PWM_FREQUENCY=200000 -DARDUINO_RP2040_DEFAULT_PWM_PRESCALER=1 -DARDUINO_RP2040_DEFAULT_PWM_PERIOD=664 -D_ONBOARD_EEPROM_SIZE_=0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=buck_converter -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_AnalogInput.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c $(START_DIR)/buck_converter_ert_rtw/buck_converter.c $(START_DIR)/buck_converter_ert_rtw/buck_converter_data.c "$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/boot2/boot2_w25q080_2_padded_checksum.S" C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/scheduler/src/arduinoARM_M0plus_RP2040_Scheduler.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/scheduler/src/MW_arduinoNanoRP2040_multitasking.c

MAIN_SRC = $(START_DIR)/buck_converter_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_AnalogInput.o ArduinoPinHandleMap.o MW_PWM.o MW_PWMDriver.o buck_converter.o buck_converter_data.o boot2_w25q080_2_padded_checksum.S.o MW_ArduinoHWInit.o io_wrappers.o arduinoARM_M0plus_RP2040_Scheduler.o MW_arduinoNanoRP2040_multitasking.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SLIB_PATH)/MW_RebuildSrc_Core.o $(SLIB_PATH)/libcore.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -DUSBD_PID=0x000a "-DUSB_PRODUCT=\"Pico\"" "-DARDUINO_VARIANT=\"rpipico\"" -DF_CPU=133000000L -DARDUINO=10819 -DARDUINO_RASPBERRY_PI_PICO "-DBOARD_NAME=\"RASPBERRY_PI_PICO\"" -DARDUINO_ARCH_RP2040 -DWIFICC=CYW43_COUNTRY_WORLDWIDE -DPICO_DISABLE_SHARED_IRQ_HANDLERS=1
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -DUSBD_PID=0x000a "-DUSB_PRODUCT=\"Pico\"" "-DARDUINO_VARIANT=\"rpipico\"" -DF_CPU=133000000L -DARDUINO=10819 -DARDUINO_RASPBERRY_PI_PICO "-DBOARD_NAME=\"RASPBERRY_PI_PICO\"" -DARDUINO_ARCH_RP2040 -DWIFICC=CYW43_COUNTRY_WORLDWIDE -DPICO_DISABLE_SHARED_IRQ_HANDLERS=1
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(SLIB_PATH)"

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(SLIB_PATH)"

LDFLAGS += $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include arduino_macros.mk
-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	echo "### Done invoking postbuild tool."
	echo "### Invoking postbuild tool "UF2 Converter" ..."
	$(UF2CONVERTER) $(OBJCOPYFLAGS_UF2)
	echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/buck_converter_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/buck_converter_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/buck_converter_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/buck_converter_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/buck_converter_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/buck_converter_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/buck_converter_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_AnalogInput.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_AnalogInput.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ArduinoPinHandleMap.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWM.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWMDriver.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


buck_converter.o : $(START_DIR)/buck_converter_ert_rtw/buck_converter.c
	$(CC) $(CFLAGS) -o "$@" "$<"


buck_converter_data.o : $(START_DIR)/buck_converter_ert_rtw/buck_converter_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/buck_converter_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


boot2_w25q080_2_padded_checksum.S.o : $(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/boot2/boot2_w25q080_2_padded_checksum.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


MW_ArduinoHWInit.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


io_wrappers.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


arduinoARM_M0plus_RP2040_Scheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/scheduler/src/arduinoARM_M0plus_RP2040_Scheduler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_arduinoNanoRP2040_multitasking.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinotarget/scheduler/src/MW_arduinoNanoRP2040_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	echo "### OBJCOPYFLAGS_UF2 = $(OBJCOPYFLAGS_UF2)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


