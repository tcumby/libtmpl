################################################################################
#                                   LICENSE                                    #
################################################################################
#   This file is part of libtmpl.                                              #
#                                                                              #
#   libtmpl is free software: you can redistribute it and/or modify            #
#   it under the terms of the GNU General Public License as published by       #
#   the Free Software Foundation, either version 3 of the License, or          #
#   (at your option) any later version.                                        #
#                                                                              #
#   libtmpl is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
#   GNU General Public License for more details.                               #
#                                                                              #
#   You should have received a copy of the GNU General Public License          #
#   along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.          #
################################################################################
#   Author:     Ryan Maguire                                                   #
#   Date:       August 31, 2021                                                #
################################################################################

TARGET_LIB := libtmpl.so
BUILD_DIR := ./build
SRC_DIRS := ./src

# Some functions make use of OpenMP with parallel for-loops. If using tmpyl,
# the Python wrapper for libtmpl, it is advised to compile with OpenMP support
# if possible.
ifdef OMP
CFLAGS := -fopenmp -I../ -O3 -fPIC -flto -DNDEBUG -c
LFLAGS := -fopenmp -O3 -flto -shared -lm
else
CFLAGS := -I../ -O3 -fPIC -flto -DNDEBUG -c
LFLAGS := -O3 -flto -shared -lm
endif

CWARN := -Wall -Wextra -Wpedantic

ifdef NO_INLINE
INLINE_FLAG :=
INLINE_EXCLUDE :=
else
INLINE_FLAG := -DTMPL_SET_INLINE_TRUE
INLINE_EXCLUDE := \
	-not -name "tmpl_abs_double.c" -and \
	-not -name "tmpl_abs_float.c" -and \
	-not -name "tmpl_abs_ldouble.c" -and \
	-not -name "tmpl_complex_abs_squared.c" -and \
	-not -name "tmpl_complex_add.c" -and \
	-not -name "tmpl_complex_addto.c" -and \
	-not -name "tmpl_complex_quick_abs.c" -and \
	-not -name "tmpl_copysign_float.c" -and \
	-not -name "tmpl_copysign_double.c" -and \
	-not -name "tmpl_copysign_ldouble.c" -and
endif

ifdef NO_MATH
MATH_FLAG :=
else
MATH_FLAG := -DTMPL_SET_USE_MATH_TRUE
endif

ifdef NO_IEEE
IEEE_FLAG := -DTMPL_SET_TMPL_USE_IEEE_FALSE
else
IEEE_FLAG :=
endif

uname_m := $(shell uname -m)

# If the user does not want to use any assembly code (that is, C only) only
# include .c files. Ignore all .S or .fasm files. For x86_64/amd64, aarch64,
# and armv7l (armhf) this is only advised if your C compiler cannot compile
# assembly code. GCC, Clang, and PCC can. I'm unsure about TCC.
ifdef NO_ASM
SRCS := $(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) -name "*.c")

# Else for ifdef NO_ASM
# amd64/x86_64 have various functions built-in, such as sqrt. Use assembly code
# if possible for performance boosts.
else ifeq ($(uname_m),$(filter $(uname_m),x86_64 amd64))

# Some function for x86_64 are written in FASM, the Flat Assembler, and have
# much better times than the default C code.
ifdef FASM
SRCS := \
	$(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) \
	-not -name "tmpl_sqrt_double.c" -and \
	-not -name "tmpl_sqrt_float.c" -and \
	\( -name "*.c" -or -name "*x86_64.fasm" \))

# The default is to use assembly code that GCC can understand. LLVM's clang and
# the Portable C Compiler (PCC) are also able to compile this, tested on
# Debian GNU/Linux 11.
else
SRCS := \
	$(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) \
	-not -name "tmpl_trailing_zeros_char.c" -and \
	-not -name "tmpl_trailing_zeros_int.c" -and \
	-not -name "tmpl_trailing_zeros_long.c" -and \
	-not -name "tmpl_trailing_zeros_short.c" -and \
	-not -name "tmpl_trailing_zeros_uint.c" -and \
	-not -name "tmpl_trailing_zeros_uchar.c" -and \
	-not -name "tmpl_trailing_zeros_ulong.c" -and \
	-not -name "tmpl_trailing_zeros_ushort.c" -and \
	-not -name "tmpl_sqrt_double.c" -and \
	-not -name "tmpl_sqrt_float.c" -and \
	-not -name "tmpl_sqrt_ldouble.c" -and \
	\( -name "*.c" -or -name "*x86_64.S" \))
endif
# End of ifdef FASM.

# Else for ifdef NO_ASM
# Same idea, but for aarch64 (arm64). sqrt is also a built-in function.
else ifeq ($(uname_m),$(filter $(uname_m),aarch64 arm64))

SRCS := \
	$(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) \
	-not -name "tmpl_sqrt_double.c" -and \
	-not -name "tmpl_sqrt_float.c" -and \
	\( -name "*.c" -or -name "*aarch64.S" \))

# Else for ifdef NO_ASM
# Same idea, but for armv7l (armhf). sqrt is also a built-in function.
else ifeq ($(uname_m),$(filter $(uname_m),armv7l))

SRCS := \
	$(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) \
	-not -name "tmpl_sqrt_double.c" -and \
	-not -name "tmpl_sqrt_float.c" -and \
	-not -name "tmpl_sqrt_ldouble.c" -and \
	\( -name "*.c" -or -name "*armv7l.S" \))

# Else for ifeq ($(uname_p),x86_64). Only amd64/x86_64 and aarch64/arm7l have
# assembly code support. This may change in the future. The rest of the C
# code has been tested on ppc64, mips, and many other architectures using
# emulation and worked as expected.
else

# For all other architectures, use only C code. No assembly.
SRCS := $(shell find $(SRC_DIRS) $(INLINE_EXCLUDE) -name "*.c")

# End of ifdef NO_ASM.
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: clean install uninstall all

all: $(BUILD_DIR) include/tmpl_config.h $(TARGET_LIB)

include/tmpl_config.h: ./config.c
	$(CC) $(INLINE_FLAG) $(MATH_FLAG) $(IEEE_FLAG) config.c -o config.out
	./config.out
	rm -f config.out

$(TARGET_LIB): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@

$(BUILD_DIR)/%.c.o: %.c
	$(CC) $(CWARN) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.S.o: %.S
	$(CC) $(CWARN) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.fasm.o: %.fasm
	fasm $< $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/src/bytes/
	mkdir -p $(BUILD_DIR)/src/complex/
	mkdir -p $(BUILD_DIR)/src/euclidean_planar_geometry/
	mkdir -p $(BUILD_DIR)/src/euclidean_spatial_geometry/
	mkdir -p $(BUILD_DIR)/src/fft/
	mkdir -p $(BUILD_DIR)/src/graph_theory/
	mkdir -p $(BUILD_DIR)/src/interpolate/
	mkdir -p $(BUILD_DIR)/src/knots/
	mkdir -p $(BUILD_DIR)/src/math/
	mkdir -p $(BUILD_DIR)/src/number_theory/
	mkdir -p $(BUILD_DIR)/src/numerical/
	mkdir -p $(BUILD_DIR)/src/optics/
	mkdir -p $(BUILD_DIR)/src/polynomial/
	mkdir -p $(BUILD_DIR)/src/ppm/
	mkdir -p $(BUILD_DIR)/src/rational/
	mkdir -p $(BUILD_DIR)/src/special_functions/
	mkdir -p $(BUILD_DIR)/src/spherical_geometry/
	mkdir -p $(BUILD_DIR)/src/string/
	mkdir -p $(BUILD_DIR)/src/svg/
	mkdir -p $(BUILD_DIR)/src/vector/
	mkdir -p $(BUILD_DIR)/src/void_pointer/
	mkdir -p $(BUILD_DIR)/src/window_functions/

clean:
	rm -rf $(BUILD_DIR)
	rm -f include/tmpl_config.h
	rm -f $(TARGET_LIB)

install:
	mkdir -p /usr/local/include/libtmpl/include/
	cp ./include/*.h /usr/local/include/libtmpl/include/
	cp $(TARGET_LIB) /usr/local/lib/$(TARGET_LIB)

uninstall:
	rm -rf $(BUILD_DIR)
	rm -f include/tmpl_config.h
	rm -f $(TARGET_LIB)
	rm -rf /usr/local/include/libtmpl/
	rm -f /usr/local/lib/$(TARGET_LIB)

-include $(DEPS)

