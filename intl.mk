TRANSLATION_TARGET ?=

pot := $(wildcard po/*.pot)
po := $(wildcard po/*/*.po)
mo := $(po:.po=.mo)

translation-init: ${pot}
	@test ${TRANSLATION_TARGET} || echo TRANSLATION_TARGET is not set
	@mkdir -p po/${TRANSLATION_TARGET}
	@cp ${pot} po/${TRANSLATION_TARGET}/${PACKAGE}.po
translation-edit: ${pot}
	@test ${TRANSLATION_TARGET} || echo TRANSLATION_TARGET is not set
	@$EDITOR po/${TRANSLATION_TARGET}/${PACKAGE}.po
translation-update: ${po}
	@$(info updating translations)
	@xgettext -k_ -o ${pot} -i ${src}
	@for a in ${po}; do msgmerge -Uq $$a ${pot}; done
translation-generate: ${mo}
translation-install: ${translation-generate}
	@$(info installing translations)
	@for a in ${mo}; do cp $$a ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/${PACKAGE}.mo; done
translation-uninstall:
	@$(info uninstalling translations)
	@for a in ${mo}; do rm ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/${PACKAGE}.mo; done
translation-clean:
	@$(info cleaning translations)
	@for a in ${mo}; do rm -f $$a; done

define _translation-name
$(shell basename `dirname $1`)
endef

.SUFFIXES: .po .mo
.po.mo:
	$(info generate $(call _translation-name, $<) translations)
	@msgfmt $< -o $(<:.po=.mo)

