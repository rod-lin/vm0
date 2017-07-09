#ifndef VM0_STD_COM_H
#define VM0_STD_COM_H

/* common */

#include "std/type.h"

#define STD_STATIC static

#ifdef __GNUC__
	#if (__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1))
		#define STD_INLINE STD_STATIC __inline__ __attribute__((always_inline))
	#else
		#define STD_INLINE STD_STATIC __inline__
	#endif
#elif defined(_MSC_VER)
	#define STD_INLINE STD_STATIC __forceinline
#elif (defined(__BORLANDC__) || defined(__WATCOMC__))
	#define STD_INLINE STD_STATIC __inline
#else
	#define STD_INLINE STD_STATIC inline
#endif

#define std_ptrdiff(a, b, size) ((std_size_t)(((std_uptr_t)a - (std_uptr_t)b) / (size)))

#endif
