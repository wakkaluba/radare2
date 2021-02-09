include ../../global.mk

NAME=r_asm
R2DEPS=r_syscall r_lang r_util r_parse
R2DEPS+=r_flag r_cons r_reg
CFLAGS+=-DR2_PLUGIN_INCORE -Iarch/include -Iarch -I../../shlr
CURDIR=p/

include $(TOP)/libr/config.mk

include p/capstone.mk
LDFLAGS+=${CS_LDFLAGS}
include $(STOP)/java/deps.mk
include $(STOP)/capstone.mk

.PHONY: alle plugins

alle:
	${MAKE} -C d all
	${MAKE} -C p all
	${MAKE} $(LIBSO)
	${MAKE} $(LIBAR)

EXTRA_CLEAN=doclean
$(EXTRA_CLEAN):
	$(MAKE) -C d clean
	$(MAKE) -C p clean
	rm -f `find arch/| grep '\.o$$'`

include ${STATIC_ASM_PLUGINS}
STATIC_OBJS=$(subst ..,p/..,$(subst asm_,p/asm_,$(STATIC_OBJ)))
OBJS=${STATIC_OBJS} asm.o acode.o aop.o binutils_as.o aplugs.o
OBJS+=${SHARED2_OBJ}

include $(TOP)/libr/rules.mk
