#!/bin/sh

function clean () {
  rm -f a.out test.log
}

function compile () {
  cc -I../include "$1" ../libgwion_util.a
}

function run () {
  valgrind --leak-check=yes --log-file=test.log ./a.out
}

function test_error () {
  printf "leak in test file '%s'" "$file"
}

# run each C test
for file in *.c
do
  compile "$file"
  run || {
   test_error
   break
  }
done

# do not forget to ...
clean
