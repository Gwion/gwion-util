TRANSLATION_TARGET ?=

pot := $(wildcard po/*.pot)
po := $(wildcard po/*/*.po)
mo := $(po:.po=.mo)

TRANSLATION_CHARSET ?= .UTF-8

__translation_check = (echo TRANSLATION_TARGET is not set; exit 1)
_translation_check = test ${TRANSLATION_TARGET} || $(call __translation_check)
_translation_locale = ${TRANSLATION_TARGET}${TRANSLATION_CHARSET}

translation-init: ${pot}
	@$(call _translation_check)
	@mkdir -p po/${TRANSLATION_TARGET}
	@msginit --no-translator -i ${pot} -l $(_translation_locale) -o po/${TRANSLATION_TARGET}/${PACKAGE}.po

translation-edit: ${pot}
	@$(call _translation_check)
	@${EDITOR} po/${TRANSLATION_TARGET}/${PACKAGE}.po

translation-update: ${po} ${src}/*.c
	@$(info updating translations)
	@xgettext -k_ -o ${pot} -i ${src}
	@mv ${pot}.tmp ${pot}
	@for a in ${po}; do msgmerge -Uq $$a ${pot}; done

translation-generate: ${mo}

translation-install: translation-generate
	@$(info installing translations)
	for a in ${mo}; do echo $$a; mkdir -p ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/; cp $$a ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/${PACKAGE}.mo; done

translation-uninstall:
	@$(info uninstalling translations)
	@for a in ${mo}; do rm ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/${PACKAGE}.mo; done

translation-clean:
	@$(info cleaning translations)
	@for a in ${mo}; do rm -f $$a; done


translation-commit:
	@$(call _translation_check)
	@$(info commiting translations)
	@rm -f po/${TRANSLATION_TARGET}/gwion.po~
	@git add po/${TRANSLATION_TARGET}
	@git commit -m":briefcase: Updating ${TRANSLATION_TARGET} [skip ci]"

define _translation-name
$(shell basename `dirname $1`)
endef

.SUFFIXES: .po .mo
.po.mo:
	@which msgfmt || return true
	$(info generate $(call _translation-name, $<) translations)
	@msgfmt $< -o $(<:.po=.mo)

