#!/bin/sh

clean () {
  rm -f a.out test.log
}

compile () {
  cc -I../include "$1" ../libgwion_util.a -lpthread
}

test_error () {
  printf "leak in test file '%s'" "$file"
}

# run each C test
for file in *.c
do
  compile "$file"
  ./a.out || {
   test_error
   break
  }
done

# do not forget to ...
clean
