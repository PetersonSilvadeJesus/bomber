#pragma once

// Link to GDK libraries
#include "AGK.h"

// some help macros
#define	CREATE(type)						(new (std::nothrow) type)
#define CREATE_ARRAY(type, count)			(new (std::nothrow) type[count])
#define RELEASE(obj)						delete obj
#define RELEASE_ARRAY(obj)					delete [] obj

// some user defined and sharing var's and def's