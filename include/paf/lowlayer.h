/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_LOWLAYER_H
#define _VDSUITE_USER_PAF_LOWLAYER_H

#include <libdeflt.h>
#include <kernel.h>

namespace paf {

	namespace deflt
	{
		/**
		* Decompress DEFLATE data from memory. This function wraps sceDeflateDecompress()
		*
		* @param[in] pDst - Buffer address which is to receive the expanded data
		* @param[in] uiBufSize - Size of the buffer which is to receive the expanded data
		* @param[in] pSrcDeflate - Start address of the DEFLATE-compressed compressed data
		* @param[out] ppNext - address immediately following the processed compressed data
		*
		* @return 0 on success, < 0 on error.
		*/
		extern SceInt32 Decompress(ScePVoid pDst, SceUInt32 uiBufSize, const ScePVoid pSrcDeflate, const ScePVoid *ppNext);
	};
}

#endif /* _VDSUITE_USER_PAF_LOWLAYER_H */
