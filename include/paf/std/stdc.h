/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_STDC_H
#define _PAF_STD_STDC_H


#if defined(__SNC__) || defined(__vita__)

#include <paf/std/ngp/assert.h>
#include <paf/std/ngp/stdint.h>
#include <paf/std/ngp/stddef.h>
#include <paf/std/ngp/stdlib.h>
#include <paf/std/ngp/stdio.h>
#include <paf/std/ngp/string.h>
#include <paf/std/ngp/wchar.h>
#include <paf/std/ngp/wctype.h>
#include <paf/std/ngp/math.h>
#include <paf/std/ngp/setjmp.h>
#include <paf/std/ngp/globalheapsize.h>
#include <paf/std/ngp/__stdc__.h>

#elif defined(_WIN32)

#include <paf/std/generic/assert.h>
#include <paf/std/generic/stdint.h>
#include <paf/std/generic/stddef.h>
#include <paf/std/generic/stdlib.h>
#include <paf/std/generic/stdio.h>
#include <paf/std/generic/string.h>
#include <paf/std/generic/wchar.h>
#include <paf/std/generic/wctype.h>
#include <paf/std/generic/math.h>
#include <paf/std/generic/setjmp.h>
#include <paf/std/generic/globalheapsize.h>
#include <paf/std/generic/__stdc__.h>

#else
#error Current target platform is not supported or no target platform defined
#endif

#endif /* _PAF_STD_STDC_H */
