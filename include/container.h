/** @file: container.h
\brief macros and meta-header for container types
*/
#pragma once

#define MAP_CAP    8                      /*< base container capacity */
#define OFFSET     2                      /*< size of container offset */
#define VLEN(v)    (v)->ptr[0]            /*< length */
#define VCAP(v)    (v)->ptr[1]            /*< capacity */
#define VPTR(v, i) (v)->ptr[OFFSET + (i)] /* pointer to data */

typedef uintptr_t vtype; /*< base type for containers, size of a pointer */

#include "vector.h"
#include "m_vector.h"
#include "map.h"
#include "scope.h"
