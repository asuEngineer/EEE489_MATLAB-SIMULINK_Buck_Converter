###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          Arduino ARM RP2040


###########################################################################
## FILE INCLUSIONS
###########################################################################
-include arduino_macros.mk
-include codertarget_assembly_flags.mk


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PACKAGES_TOOLS_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
SHELL = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_UF2 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).uf2
ARDUINO_TOOLS = $(ARDUINO_RP2040_TOOLS_ROOT)/pqt-gcc/$(ARDUINO_RP2040_GCC_VERSION)/bin


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM RP2040 Assembler
AS_PATH := $(ARDUINO_TOOLS)
AS := $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM RP2040 C Compiler
CC_PATH := $(ARDUINO_TOOLS)
CC := $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM RP2040 Linker
LD_PATH = $(ARDUINO_TOOLS)
LD := $(LD_PATH)/arm-none-eabi-g++


# C++ Compiler: Arduino ARM RP2040 C++ Compiler
CPP_PATH := $(ARDUINO_TOOLS)
CPP := $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM RP2040 C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD := $(CPP_LD_PATH)/arm-none-eabi-g++

# Archiver: Arduino ARM RP2040 Archiver
AR_PATH := $(ARDUINO_TOOLS)
AR := $(AR_PATH)/arm-none-eabi-ar

# Indexing: Arduino ARM RP2040 Ranlib
RANLIB_PATH := $(ARDUINO_TOOLS)
RANLIB := $(RANLIB_PATH)/arm-none-eabi-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = C:/Program Files/MATLAB/R2024b/bin/win64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = rcs
ASFLAGS              = -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/pico-sdk/src/rp2040/hardware_regs/include/" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/pico-sdk/src/common/pico_binary_info/include"  $(ASFLAGS_ADDITIONAL) 
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -c -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040  -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -MMD "-iprefix$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/" "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_inc.txt" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/include" -std=gnu17 -g -pipe  \
                       -Os
CPPFLAGS             = -c -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040  -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -MMD "-iprefix$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/" "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_inc.txt" "-I$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/include" -fno-rtti -std=gnu++17 -g -pipe  \
                       -Os
CPP_LDFLAGS          =  -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_wrap.txt" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common "-Wl,--script=$(ARDUINO_TARGET_ROOT)/src/rp2040_memmap_default.ld" "-Wl,-Map,$(PRODUCT_NAME).map" -Wl,--no-warn-rwx-segments -Wl,--start-group 
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Werror=return-type -Wno-psabi -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSBD_VID=0x2e8a -DUSBD_MAX_POWER_MA=250 "-DUSB_MANUFACTURER=\"Raspberry Pi\"" -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DCYW43_LWIP=1 -DLWIP_IPV6=0 -DLWIP_IPV4=1 -DLWIP_IGMP=1 -DLWIP_CHECKSUM_CTRL_PER_NETIF=1 -DTARGET_RP2040 -DPICO_FLASH_SIZE_BYTES=2097152 -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -DARM_MATH_CM0_FAMILY -DARM_MATH_CM0_PLUS -Os -u _printf_float -u _scanf_float "@$(ARDUINO_RP2040_ROOT)/hardware/rp2040/$(ARDUINO_RP2040_LIB_VERSION)/lib/platform_wrap.txt" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common "-Wl,--script=$(ARDUINO_TARGET_ROOT)/src/rp2040_memmap_default.ld" "-Wl,-Map,$(PRODUCT_NAME).map" -Wl,--no-warn-rwx-segments -Wl,--start-group 
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =
OBJCOPYFLAGS_UF2     = $(PRODUCT) $(PRODUCT_UF2)


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
CPP_LDFLAGS_SKIPFORSIL = 
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = 
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL = 
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL = 
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=C:/PROGRA~3/MATLAB/SUPPOR~1/R2024b/toolbox/target/SUPPOR~1/ARDUIN~1/STATIC~1
MODELMK=buck_converter_w_feedback_alternative.mk
SLIB_PATH=C:/Users/burly/DOCUME~1/MATLAB/R2024b/ARDUIN~2/RASPBE~1/FASTER~1
VARIANT_HEADER_PATH=$(ARDUINO_RP2040_ROOT)/hardware/rp2040/3.7.0/variants/rpipico
ARDUINO_SKETCHBOOK_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2024b/aCLI/user/LIBRAR~1
ARDUINO_BASESUPPORTPKG_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2024b/toolbox/target/SUPPOR~1/ARDUIN~1


###########################################################################
## Export Variables
###########################################################################
export AR
export RANLIB
export AS
export CC
export CPP
export ASFLAGS
export CFLAGS
export CPPFLAGS
export ARFLAGS
export SLIB_PATH
export VARIANT_HEADER_PATH
export ARDUINO_SKETCHBOOK_ROOT
export ARDUINO_BASESUPPORTPKG_ROOT


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j5 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f rp2040core.mk all
	"$(MAKE)" -j5 SHELL="$(SHELL)" -f "$(MODELMK)" all

