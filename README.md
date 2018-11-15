[![BCH compliance](https://bettercodehub.com/edge/badge/fennecdjay/gwion-util?branch=master)](https://bettercodehub.com/)
[![Build Status](https://travis-ci.org/fennecdjay/gwion-util.svg?branch=master)](https://travis-ci.org/fennecdjay/gwion-util)
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Ffennecdjay%2Fgwion-util.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Ffennecdjay%2Fgwion-util?ref=badge_shield)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/fennecdjay/gwion-util.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/fennecdjay/gwion-util/context:cpp)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/e336051285f64f3a913b0b3494ffe679)](https://www.codacy.com/app/fennecdjay/gwion-util?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=fennecdjay/gwion-util&amp;utm_campaign=Badge_Grade)
# Gwion-utils

Provides common common utility, and lexer/parser/preprocessor for 
[Gwion](https://github.com/fennecdjay/gwion)  
Meant to be used as a gwion submodule, and to help develop tooling.

## Building
look in config.mk, then
```sh
make
```

## TODO
  * [ ] make two (static) libraries
    + gwion_util
    + gwion_ast (depends on the former)
  * [ ] testing
  * improve hash
  * list utilities


## License
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Ffennecdjay%2Fgwion-util.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Ffennecdjay%2Fgwion-util?ref=badge_large)
