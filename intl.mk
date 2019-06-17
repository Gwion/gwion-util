pot := $(wildcard po/*.pot)
po := $(wildcard po/*/*.po)
mo := $(po:.po=.mo)

generate-lang: ${mo}

init-lang: ${pot}
	@test ${TRANSLATION_TARGET} || echo TRANSLATION_TARGET is not set
	@mkdir -p po/${TRANSLATION_TARGET}
	cp ${pot} po/${TRANSLATION_TARGET}/$(notdir $(pot:.pot=.po))

update-lang: ${src}
	$(info updating translations)
	@xgettext -k_ -o ${pot} -i ${src}
	for a in ${po}; do msgmerge $$a ${pot} -o $$a; done

install-lang: generate-lang
	$(info installing translations)
	@for a in ${mo}; do cp $$a ${PREFIX}/share/locale/$$(basename $$(dirname $$a))/LC_MESSAGES/$$(basename $$a); done

clean-lang:
	$(info cleaning translations)
	@rm -f po/*/*.mo

.SUFFIXES: .po .mo
.po.mo:
	@msgfmt $< -o $(<:.po=.mo)
