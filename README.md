[![BCH compliance](https://bettercodehub.com/edge/badge/fennecdjay/gwion-util?branch=master)](https://bettercodehub.com/)
[![Build Status](https://travis-ci.org/fennecdjay/gwion-util.svg?branch=master)](https://travis-ci.org/fennecdjay/gwion-util)

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
